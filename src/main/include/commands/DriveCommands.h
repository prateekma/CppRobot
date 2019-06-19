#pragma once

#include <frc/commands/Command.h>

namespace frc5190 {
class TeleopDriveCommand final : public frc::Command {
public:
    TeleopDriveCommand();
    void Execute() override;
    bool IsFinished() override { return false; }
};
}  // namespace frc5190
