#pragma once
#include <frc/commands/Subsystem.h>
#include "Constants.h"
#include "controllers/FlywheelController.h"
#include <ctre/Phoenix.h>
#include <frc/Notifier.h>

namespace frc5190 {
class Flywheel final : public frc::Subsystem {


    TalonSRX master_{frc5190::constants::flywheel::kFlywheelId};
    frc::Notifier notifier_{[this]{ this->Update(); }};

    FlywheelController controller_;

    // ReSharper disable once CppInconsistentNaming
    struct PeriodicIO {
        double demand = 0.0;
        double raw_sensor_velocity = 0.0;
    };

    enum class State { kOpenLoop, kClosedLoop, kNothing };

    State wanted_state_ = State::kNothing;
    State current_state_ = State::kNothing;
    PeriodicIO periodic_io_;

    static constexpr double TicksToSi(const double ticks) {
        return ticks * 10 / constants::flywheel::kTicksPerRotation * 2 *
               constants::kPi;
    }

public:
    Flywheel();
    void InitDefaultCommand() override;
    void Update();
    void InitLoop();

    void SetOpenLoop(double percent);
    void SetClosedLoop(double speed);
    void ZeroOutputs();
};
}  // namespace frc5190
