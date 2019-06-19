#pragma once

#include <frc/TimedRobot.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Flywheel.h"
#include "subsystems/Agitator.h"

namespace frc5190 {
class Robot final : public frc::TimedRobot {
public:
    void RobotInit() override;
    void RobotPeriodic() override;

    void DisabledInit() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void TestInit() override;
    void TestPeriodic() override;

    static std::shared_ptr<Drivetrain> drivetrain_;
    static std::shared_ptr<Flywheel> flywheel_;
    static std::shared_ptr<Agitator> agitator_;
};

}  // namespace frc5190