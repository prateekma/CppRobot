#pragma once

#include <frc/commands/Command.h>

namespace frc5190 {
class OpenLoopAgitatorCommand final : public frc::Command {
    std::function<double()> percent_source_;

public:
    OpenLoopAgitatorCommand(std::function<double()> percent_source);
    void Execute() override;
    bool IsFinished() override { return false; }
};

class DefaultAgitatorCommand : public frc::Command {
public:
    DefaultAgitatorCommand();
    void Initialize() override;
    bool IsFinished() override { return false; }
};
}  // namespace frc5190