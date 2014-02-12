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
#include "create.hpp"
#include "vars.hpp"

namespace arm{

//-----------------------------------------------------------------------------
// Function to generate grain points
//-----------------------------------------------------------------------------
void create_grain_structure(){

   // Generate lattice points
   switch(arm::grain_structure){
      
      case(cubic): 
         arm::create_cubic_grain_structure();
         break;
      
      case(voronoi):
         arm::create_voronoi_grain_structure();
         break;
   
      default:
         create_cubic_grain_structure();

   }   
   
   // Generate grain lattice and neighbourlist
   // arm::create_grain_structure();

   // Calculate grain properties eg anisotropy, Tc dispersion
   // arm::create_grain_properties();

   // Create demagnetizing field tensor
   // arm::create_demagnetizing_field_tensor();

   return;

}

}
