#pragma once

namespace frc5190 {
namespace constants {

static constexpr double kPi = 3.1415926535;

namespace drivetrain {

static constexpr int kLeftMasterId = 1;
static constexpr int kLeftSlaveId = 2;
static constexpr int kRightMasterId = 3;
static constexpr int kRightSlaveId = 4;

}  // namespace drivetrain

namespace flywheel {
static constexpr int kFlywheelId = 13;
static constexpr int kTicksPerRotation = 4096 * 40 / 18;
static constexpr double kClosedLoopTolerance = 50.;
}  // namespace flywheel

namespace agitator {
static constexpr int kAgitatorId = 11;
}

}  // namespace constants
}  // namespace frc5190