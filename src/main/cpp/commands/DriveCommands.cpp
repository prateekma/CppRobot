#include "commands/DriveCommands.h"
#include <Robot.h>

using namespace frc5190;

TeleopDriveCommand::TeleopDriveCommand() { Requires(Robot::drivetrain_.get()); }

void TeleopDriveCommand::Execute() { Robot::drivetrain_->SetOpenLoop(0.2, 0.2); }