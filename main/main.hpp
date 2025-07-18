#ifndef MAIN_HPP  // Header guard to prevent multiple inclusions
#define MAIN_HPP

#include "../math/math.hpp"
#include <fstream>
#include <vector>
#include <string>

// Constants
constexpr double a_x = 1e-10;
constexpr double b_x = 1.01;
constexpr double tol_np = 1e-3;
constexpr double tol_V = 1e-3;
constexpr int max_iter = 1000;
constexpr double q = 1.6e-19;     // Elementary charge
constexpr double kb = 1.38e-23;  // Boltzmann constant
constexpr double e_0 = 8.85e-12; // Vacuum permittivity
constexpr double e_si = 11.7 * e_0; // Silicon permittivity
constexpr double e_ox = 3.9 * e_0; // Oxide permittivity
constexpr double tau_n = 1e-6;  // Electron lifetime
constexpr double tau_p = 1e-6;  // Hole lifetime
constexpr double dampingFactor = 0.25;

// Global variables
extern double NA, ND;
extern double T;               // Temperature in Kelvin (default 300)
extern double Vt;              // Thermal voltage
extern int x_points;           // Number of grid points
extern int n_VG;               // Number of points for VG
extern int start_SC;           // Starting point for semiconductor region
extern std::vector<double> x;  // Grid of positions
extern double mu_n, mu_p;
extern double delta_t;

// Enum for simulation conditions
enum Condition {
    EQUILIBRIUM,
    DC,
    AC
};

void consistent(const std::vector<double>& x, Matrix& V, Matrix& n, Matrix& p, Condition cond);

void save_x_based(const std::string& filename, const std::vector<double>& x, const Matrix& V, const Matrix& n, const Matrix& p, int time_step);
void save_capacitance_data(const std::string& filename, const std::vector<std::pair<double, double>>& data);

#endif
