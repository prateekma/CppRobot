#include <utility>
#include "commands/AgitatorCommands.h"

#include "Robot.h"

using namespace frc5190;

OpenLoopAgitatorCommand::OpenLoopAgitatorCommand(
    std::function<double()> percent_source)
    : percent_source_{std::move(percent_source)} {

    Requires(Robot::agitator_.get());
}

void OpenLoopAgitatorCommand::Execute() {
    Robot::agitator_->SetOpenLoop(percent_source_());
}

DefaultAgitatorCommand::DefaultAgitatorCommand() {
    Requires(Robot::agitator_.get());
}

void DefaultAgitatorCommand::Initialize() { Robot::agitator_->ZeroOutputs(); }