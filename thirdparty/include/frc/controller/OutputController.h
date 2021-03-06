/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <vector>

#include <Eigen/Core>

#include "frc/controller/OutputControllerCoeffs.h"

namespace frc {

/**
 * Contains the controller coefficients and logic for an output controller.
 *
 * Output controllers generally use the control law u = -Ky.
 */
template <int Inputs, int Outputs>
class OutputController {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /**
   * Constructs a controller with the given coefficients and plant.
   *
   * @param controllerCoeffs Controller coefficients.
   * @param plant            The plant used for the feedforward calculation.
   */
  OutputController(
      const OutputControllerCoeffs<Inputs, Outputs>& controllerCoeffs);

  OutputController(OutputController&&) = default;
  OutputController& operator=(OutputController&&) = default;

  /**
   * Enables controller.
   */
  void Enable();

  /**
   * Disables controller, zeroing controller output U.
   */
  void Disable();

  /**
   * Returns the controller matrix K.
   */
  const Eigen::Matrix<double, Inputs, Outputs>& K() const;

  /**
   * Returns an element of the controller matrix K.
   *
   * @param i Row of K.
   * @param j Column of K.
   */
  double K(int i, int j) const;

  /**
   * Returns the reference vector r.
   */
  const Eigen::Matrix<double, Outputs, 1>& R() const;

  /**
   * Returns an element of the reference vector r.
   *
   * @param i Row of r.
   */
  double R(int i) const;

  /**
   * Returns the control input vector u.
   */
  const Eigen::Matrix<double, Inputs, 1>& U() const;

  /**
   * Returns an element of the control input vector u.
   *
   * @param i Row of u.
   */
  double U(int i) const;

  /**
   * Resets the controller.
   */
  void Reset();

  /**
   * Update controller without setting a new reference.
   *
   * @param y The current output y.
   */
  void Update(const Eigen::Matrix<double, Outputs, 1>& y);

  /**
   * Set a new reference and update the controller.
   *
   * @param nextR The next reference vector r.
   * @param y     The current output y.
   */
  void Update(const Eigen::Matrix<double, Outputs, 1>& nextR,
              const Eigen::Matrix<double, Outputs, 1>& y);

  /**
   * Sets the current controller to be "index", clamped to be within range. This
   * can be used for gain scheduling.
   *
   * @param index The controller index.
   */
  void SetIndex(int index);

  /**
   * Returns the currnet controller index.
   */
  int GetIndex() const;

  /**
   * Adds the given coefficients to the controller for gain scheduling.
   */
  void AddCoefficients(
      const OutputControllerCoeffs<Inputs, Outputs>& coefficients);

  /**
   * Returns the controller coefficients with the given index.
   *
   * @param index Index of coefficients.
   */
  const OutputControllerCoeffs<Inputs, Outputs>& GetCoefficients(
      int index) const;

  /**
   * Returns the current controller coefficients.
   */
  const OutputControllerCoeffs<Inputs, Outputs>& GetCoefficients() const;

 private:
  bool m_enabled = false;

  // Current reference.
  Eigen::Matrix<double, Outputs, 1> m_r;

  // Computed controller output after being capped.
  Eigen::Matrix<double, Inputs, 1> m_u;

  std::vector<OutputControllerCoeffs<Inputs, Outputs>> m_coefficients;
  int m_index = 0;

  void CapU();
};

}  // namespace frc

#include "frc/controller/OutputController.inc"
