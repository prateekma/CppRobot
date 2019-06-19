#include "Robot.h"
#include <frc/commands/Scheduler.h>

using namespace frc5190;

std::shared_ptr<Drivetrain> Robot::drivetrain_;
std::shared_ptr<Flywheel> Robot::flywheel_;
std::shared_ptr<Agitator> Robot::agitator_;

void Robot::RobotInit() {
    drivetrain_.reset(new Drivetrain);
    flywheel_.reset(new frc5190::Flywheel);
    agitator_.reset(new frc5190::Agitator);

    flywheel_->InitLoop();
}
void Robot::RobotPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::DisabledInit() {
    drivetrain_->ZeroOutputs();
    flywheel_->ZeroOutputs();
    agitator_->ZeroOutputs();
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
