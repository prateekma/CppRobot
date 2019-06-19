#include "controllers/FlywheelCoeffs.h"
#include <Eigen/Core>

using namespace frc5190;

// ReSharper disable CppInconsistentNaming
frc::StateSpacePlantCoeffs<1, 1, 1> frc5190::MakeFlywheelUErrorPlantCoeffs() {
    Eigen::Matrix<double, 1, 1> A;

    A(0, 0) = 0.8874693809340451;
    Eigen::Matrix<double, 1, 1> B;
    B(0, 0) = 3.193530562090648;
    Eigen::Matrix<double, 1, 1> C;
    C(0, 0) = 1;
    Eigen::Matrix<double, 1, 1> D;
    D(0, 0) = 0;
    return {A, B, C, D};
}

frc::StateSpaceControllerCoeffs<1, 1, 1>
frc5190::MakeFlywheelUErrorControllerCoeffs() {
    Eigen::Matrix<double, 1, 1> K;
    K(0, 0) = 0.24408418649576497;
    Eigen::Matrix<double, 1, 1> Kff;
    Kff(0, 0) = 0.2715324580971726;
    Eigen::Matrix<double, 1, 1> Umin;
    Umin(0, 0) = -12.0;
    Eigen::Matrix<double, 1, 1> Umax;
    Umax(0, 0) = 12.0;
    return {K, Kff, Umin, Umax};
}

frc::StateSpaceObserverCoeffs<1, 1, 1>
frc5190::MakeFlywheelUErrorObserverCoeffs() {
    Eigen::Matrix<double, 1, 1> K;
    K(0, 0) = 0.9999000178720369;
    return frc::StateSpaceObserverCoeffs<1, 1, 1>(K);
}

frc::StateSpaceLoop<1, 1, 1> frc5190::MakeFlywheelUErrorLoop() {
    return frc::StateSpaceLoop<1, 1, 1>(
        frc5190::MakeFlywheelUErrorPlantCoeffs(),
        frc5190::MakeFlywheelUErrorControllerCoeffs(),
        frc5190::MakeFlywheelUErrorObserverCoeffs());
}

// ReSharper restore CppInconsistentNaming
