#include "subsystems/Flywheel.h"
#include "commands/FlywheelCommands.h"

using namespace frc5190;

Flywheel::Flywheel() : Subsystem("Flywheel") {
    master_.ConfigFactoryDefault();

    master_.ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative);
    master_.SetNeutralMode(NeutralMode::Coast);
    master_.SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0, 5);

    master_.SetSensorPhase(true);

    master_.ConfigPeakOutputReverse(0.0);
    master_.SetInverted(true);
}

void Flywheel::InitLoop() { notifier_.StartPeriodic(0.02); }

void Flywheel::Update() {
    periodic_io_.raw_sensor_velocity = master_.GetSelectedSensorVelocity(0);

    controller_.SetMeasuredState(TicksToSi(periodic_io_.raw_sensor_velocity));
    controller_.Update();

    if (wanted_state_ == State::kClosedLoop)
        controller_.SetReference(periodic_io_.demand);

    switch (wanted_state_) {
        case State::kNothing:
            master_.NeutralOutput();
            break;
        case State::kOpenLoop:
            master_.Set(ControlMode::PercentOutput, periodic_io_.demand);
            break;
        case State::kClosedLoop:
            master_.Set(ControlMode::PercentOutput,
                         controller_.GetControllerVoltage());
            break;
    }

    if (current_state_ != wanted_state_) current_state_ = wanted_state_;
}

void Flywheel::SetOpenLoop(const double percent) {
    wanted_state_ = State::kOpenLoop;
    periodic_io_.demand = percent;
}

void Flywheel::SetClosedLoop(const double speed) {
    wanted_state_ = State::kClosedLoop;
    periodic_io_.demand = speed;
}

void Flywheel::ZeroOutputs() { wanted_state_ = State::kNothing; }

void Flywheel::InitDefaultCommand() {
    SetDefaultCommand(new DefaultFlywheelCommand);
}