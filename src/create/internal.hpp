//-----------------------------------------------------------------------------
//
// This header file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <vector>

// Program headers
#include "create.hpp"

#ifndef CREATE_INTERNAL_H_
#define CREATE_INTERNAL_H_

//------------------
// MaRS namespace
//------------------
namespace mars{

  //-----------------------------------------------------------------------------
  // Functions and variables local to system creation
  //-----------------------------------------------------------------------------
  namespace create{

    namespace internal{

      enum grain_structure_t {cubic=0, voronoi=1, single=2};

      // create variables
      extern grain_structure_t grain_structure; // type of structure to be generated

      extern double system_size_x; // nm
      extern double system_size_y;
      extern double system_size_z;

      extern double grain_size; //nm
      extern double grain_spacing; //nm

      // create functions
      void create();
      void create_grain_structure();
      void create_cubic_grain_structure();
      void create_single_grain();

      //void create_voronoi_grain_structure();
  
      //int set_material(int x,int y,int z);
      //double set_damping(int material);
      //double set_Tc(int material, double volume);  
      //double set_magnetization(int material, double volume);
      //double set_anisotropy(int material);
      
      //void set_magnetization_direction(int material, double& mx, double& my, double& mz);
      //void set_anisotropy_direction(int material, double& kx, double& ky, double& kz);

    } // End of internal namespace

  } // End of create namespace
  
} // End of mars namespace

#endif /*CREATE_INTERNAL_H_*/
