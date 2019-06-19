#include "subsystems/Agitator.h"
#include "commands/AgitatorCommands.h"

using namespace frc5190;

void Agitator::Periodic() {
    switch (wanted_state_) {
        case State::kNothing:
            master_.NeutralOutput();
            break;
        case State::kOpenLoop:
            master_.Set(ControlMode::PercentOutput, periodic_io_.demand);
            break;
    }
    if (current_state_ != wanted_state_) current_state_ = wanted_state_;
}

void Agitator::SetOpenLoop(const double percent) {
    wanted_state_ = State::kOpenLoop;
    periodic_io_.demand = percent;
}

void Agitator::ZeroOutputs() { wanted_state_ = State::kNothing; }

void Agitator::InitDefaultCommand() {
    SetDefaultCommand(new DefaultAgitatorCommand);
}