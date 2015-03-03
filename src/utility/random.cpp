//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <functional>
#include <random>

// Program headers

namespace mars{

   // Integrator random numbers
   std::mt19937 eng(12345); // This is the Mersenne Twister
   // Gaussian (normal) distribution, mean = 0, sigma=1.0
   std::normal_distribution<double> dist(0.0,1.0);
   // Create bound auto object for rng, get new numbers using irnd()
   auto irnd = std::bind (dist,eng);

}
