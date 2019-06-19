#pragma once

#include <frc/commands/Command.h>
#include <units.h>

namespace frc5190 {
class OpenLoopFlywheelCommand final : public frc::Command {
    std::function<double()> percent_source_;

public:
    explicit OpenLoopFlywheelCommand(std::function<double()> percent_source);
    void Execute() override;

    bool IsFinished() override { return false; }
};

class ClosedLoopFlywheelCommand final : public frc::Command {
    double speed_;

public:
    explicit ClosedLoopFlywheelCommand(double speed);
    explicit ClosedLoopFlywheelCommand(
        units::angular_velocity::radians_per_second_t speed);

    void Initialize() override;
    bool IsFinished() override { return false; }
    void End() override;
};

class DefaultFlywheelCommand final : public frc::Command {
public:
    DefaultFlywheelCommand();
    void Initialize() override;
    bool IsFinished() override { return false; }
};
}  // namespace frc5190
