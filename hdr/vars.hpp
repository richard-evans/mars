//-----------------------------------------------------------------------------
//
// This header file is part of the ARM open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <vector>

// Program headers
#include "grain.hpp"

#ifndef VARS_H_
#define VARS_H_

// Enumerated lists for code readability
enum grain_structure_t {cubic=0, voronoi=1};

namespace arm{

   // grain data
   extern std::vector<grain_t> grains;
   extern std::vector<grain_neighbour_t> grain_neighbours; // vector of grain_neighbour_t

   // create variables
   extern grain_structure_t grain_structure; // type of structure to be generated

   extern double system_size_x; // nm
   extern double system_size_y;
   extern double system_size_z;

   extern double grain_size; //nm
   extern double grain_spacing; //nm

}

#endif /*VARS_H_*/