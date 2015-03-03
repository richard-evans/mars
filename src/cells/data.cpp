//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers

// Program headers
#include "cells.hpp"

namespace mars{

  //-----------------------------------------------------------------------------
  // Namespace containing all cell variables
  //-----------------------------------------------------------------------------
  namespace cells{

    std::vector<vec_t> m;
    std::vector<vec_t> h;
    std::vector<double> temperature;                                                                                                                                           
    std::vector<cell_constants_t> constants;
    std::vector<cell_neighbour_t> neighbours;

  } // end of namespace cells

} // end of namespace mars

// example
// void function(std::vector<mars::vec_t>& m, std::vector<mars::cell_constants_t>& constants){
//   const int num_cells = m.size();
//   for(int cell=0; cell < num_cells; ++cell){
//     double mx = m[cell].x;
//     const double Tc = constants[cell].Tc;
//   }
// }
