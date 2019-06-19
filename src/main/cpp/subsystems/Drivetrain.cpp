#include "subsystems/Drivetrain.h"
#include "commands/DriveCommands.h"

using namespace frc5190;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
    left_slave_.Follow(left_master_);
    right_slave_.Follow(right_master_);

    left_master_.SetInverted(false);
    left_slave_.SetInverted(false);
    right_master_.SetInverted(true);
    right_slave_.SetInverted(true);

    left_master_.ConfigContinuousCurrentLimit(38);
    left_master_.ConfigPeakCurrentLimit(60);
    left_master_.ConfigPeakCurrentDuration(0.5);
    left_master_.EnableCurrentLimit(true);

    right_master_.ConfigContinuousCurrentLimit(38);
    right_master_.ConfigPeakCurrentLimit(60);
    right_master_.ConfigPeakCurrentDuration(0.5);
    right_master_.EnableCurrentLimit(true);
}

void Drivetrain::Periodic() {
    switch (wanted_state_) {
        case State::kNothing:
            left_master_.NeutralOutput();
            right_master_.NeutralOutput();
            break;
        case State::kOpenLoop:
            left_master_.Set(ControlMode::PercentOutput,
                             periodic_io_.left_demand);
            right_master_.Set(ControlMode::PercentOutput,
                              periodic_io_.right_demand);
            break;
    }
    if (current_state_ != wanted_state_) current_state_ = wanted_state_;
}

void Drivetrain::SetOpenLoop(const double left, const double right) {
    wanted_state_ = State::kOpenLoop;
    periodic_io_.left_demand = left;
    periodic_io_.right_demand = right;
}

void Drivetrain::ZeroOutputs() { wanted_state_ = State::kNothing; }

void Drivetrain::InitDefaultCommand() {
    SetDefaultCommand(new TeleopDriveCommand);
}
