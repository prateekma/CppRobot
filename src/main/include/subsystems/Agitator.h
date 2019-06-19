#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

namespace frc5190 {
class Agitator : public frc::Subsystem {
private:
    TalonSRX master_{constants::agitator::kAgitatorId};

    // ReSharper disable once CppInconsistentNaming
    struct PeriodicIO {
        double demand = 0;
    };

    enum class State { kOpenLoop, kNothing };

    State wanted_state_ = State::kNothing;
    State current_state_ = State::kNothing;
    PeriodicIO periodic_io_;

public:
    Agitator() : Subsystem("Agitator"){};

    void SetOpenLoop(double percent);
    void ZeroOutputs();

    void InitDefaultCommand() override;
    void Periodic() override;
};
}  // namespace frc5190
