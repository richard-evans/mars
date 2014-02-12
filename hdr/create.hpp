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

#ifndef CREATE_H_
#define CREATE_H_
//-----------------------------------------------------------------------------
// Functions and variables local to system creation
//-----------------------------------------------------------------------------
namespace arm{

   void create();
   void create_grain_structure();
   void create_cubic_grain_structure();
   void create_voronoi_grain_structure();
  
   int set_material(int x,int y,int z);
   double set_damping(int material);
   double set_Tc(int material, double volume);  
   double set_magnetization(int material, double volume);
   double set_anisotropy(int material);
   
   void set_magnetization_direction(int material, double& mx, double& my, double& mz);
   void set_anisotropy_direction(int material, double& kx, double& ky, double& kz);
   
}

#endif /*CREATE_H_*/
