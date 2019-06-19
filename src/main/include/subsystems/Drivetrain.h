#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

namespace frc5190 {
class Drivetrain final : public frc::Subsystem {

    TalonSRX left_master_{constants::drivetrain::kLeftMasterId};
    TalonSRX right_master_{constants::drivetrain::kRightMasterId};
    TalonSRX left_slave_{constants::drivetrain::kLeftSlaveId};
    TalonSRX right_slave_{constants::drivetrain::kRightSlaveId};

    // ReSharper disable once CppInconsistentNaming
    struct PeriodicIO {
        double left_demand = 0.0;
        double right_demand = 0.0;
    };

    enum class State { kNothing, kOpenLoop };

    State wanted_state_ = State::kNothing;
    State current_state_ = State::kNothing;

    PeriodicIO periodic_io_{0, 0};

public:
    Drivetrain();
    void InitDefaultCommand() override;
    void Periodic() override;

    void SetOpenLoop(double left, double right);
    void ZeroOutputs();
};
}  // namespace frc5190
