//-----------------------------------------------------------------------------
//
// This source file is part of the ARM open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers

// Program headers
#include "grain.hpp"
#include "vars.hpp"

//-----------------------------------------------------------------------------
// Variables used in the code to specify program parameters
//-----------------------------------------------------------------------------

namespace arm{

   // grain data
   std::vector<grain_t> grains;
   std::vector<grain_neighbour_t> grain_neighbours; // vector of grain_neighbour_t

   // create variables
   grain_structure_t grain_structure=cubic; // type of structure to be generated

   double system_size_x = 100.0; // nm
   double system_size_y = 100.0;
   double system_size_z =   5.0;

   double grain_size = 5; //nm
   double grain_spacing = 0.0; //nm
   





}