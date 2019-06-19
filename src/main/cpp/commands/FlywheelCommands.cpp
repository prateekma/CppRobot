#include <utility>
#include "commands/FlywheelCommands.h"
#include "Robot.h"

using namespace frc5190;

OpenLoopFlywheelCommand::OpenLoopFlywheelCommand(
    std::function<double()> percent_source)
    : percent_source_{std::move(percent_source)} {
    Requires(Robot::flywheel_.get());
}

void OpenLoopFlywheelCommand::Execute() {
    Robot::flywheel_->SetOpenLoop(percent_source_());
}

ClosedLoopFlywheelCommand::ClosedLoopFlywheelCommand(const double speed)
    : speed_{speed} {}

ClosedLoopFlywheelCommand::ClosedLoopFlywheelCommand(
    const units::angular_velocity::radians_per_second_t speed)
    : speed_{units::unit_cast<double>(speed)} {}

void ClosedLoopFlywheelCommand::Initialize() {
    Robot::flywheel_->SetClosedLoop(speed_);
}

void ClosedLoopFlywheelCommand::End() { Robot::flywheel_->ZeroOutputs(); }

DefaultFlywheelCommand::DefaultFlywheelCommand() {
    Requires(Robot::flywheel_.get());
}

void DefaultFlywheelCommand::Initialize() { Robot::flywheel_->ZeroOutputs(); }

