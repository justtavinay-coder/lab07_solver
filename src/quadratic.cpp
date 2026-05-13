#include <lab07_solver/quadratic.hpp>

#include <cmath>
#include <stdexcept>

namespace lab07_solver {

std::vector<double> solve_quadratic(double a, double b, double c)
{
  if (a == 0.0)
  {
    throw std::invalid_argument("coefficient a must not be zero");
  }

  const double discriminant = b * b - 4.0 * a * c;
  if (discriminant < 0.0)
  {
    return {};
  }

  if (discriminant == 0.0)
  {
    return {-b / (2.0 * a)};
  }

  const double root = std::sqrt(discriminant);
  return {
    (-b - root) / (2.0 * a),
    (-b + root) / (2.0 * a),
  };
}

} // namespace lab07_solver
