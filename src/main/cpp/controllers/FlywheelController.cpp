#include "controllers/FlywheelController.h"

using namespace frc5190;

void FlywheelController::SetReference(double speed) { next_r_(0, 0) = speed; }

void FlywheelController::SetMeasuredState(double speed) { y_(0, 0) = speed; }

double FlywheelController::GetControllerVoltage() const {
    return controller_.U(0);
}

void FlywheelController::Update() {
    observer_.Correct(controller_.U(), y_);
    observer_.Predict(controller_.U());
    controller_.Update(next_r_, observer_.Xhat());
}