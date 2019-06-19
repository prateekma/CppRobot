#pragma once

#include <frc/controller/StateSpacePlant.h>
#include <frc/controller/StateSpaceController.h>
#include <frc/controller/StateSpaceObserver.h>
#include <units.h>
#include "controllers/FlywheelCoeffs.h"

namespace frc5190 {
class FlywheelController {
private:
    frc::StateSpacePlant<1, 1, 1> plant_{MakeFlywheelUErrorPlantCoeffs()};

    frc::StateSpaceController<1, 1, 1> controller_{
        MakeFlywheelUErrorControllerCoeffs(), plant_};

    frc::StateSpaceObserver<1, 1, 1> observer_{
        MakeFlywheelUErrorObserverCoeffs(), plant_};

    Eigen::Matrix<double, 1, 1> y_;
    Eigen::Matrix<double, 1, 1> next_r_;

public:
    void SetReference(double speed);
    void SetMeasuredState(double speed);
    void Update();

    double GetControllerVoltage() const;
};
}  // namespace frc5190
