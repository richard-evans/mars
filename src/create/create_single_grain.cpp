//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <cmath>

// Program headers
#include "create.hpp"

namespace mars{

  namespace create{

    namespace internal{
      
      //-----------------------------------------------------------------------------
      // Function to generate a single grain
      //-----------------------------------------------------------------------------
      void create_single_grain(){
  /*
   // Resize grains to zero length
   arm::grains.resize(0);
   
   // Determine grain coordinates
   const double cx = 0.0;
   const double cy = 0.0;
   const double cz = 0.0;

   // Always use first material
   const int material = 0;

   // Determine grain volume
   const double volume = arm::grain_size*arm::grain_size*arm::grain_size;

   // Define temporary instance of grain class
   grain_t temp;

   // Define grain properties
   temp.type    = material;
   temp.x       = cx;
   temp.y       = cy;
   temp.z       = cz;
   temp.volume  = volume;
   temp.damping = arm::set_damping(material);
   temp.Tc      = arm::set_Tc(material,volume);
   arm::set_magnetization_direction(material,temp.mx,temp.my,temp.mz);
   temp.magnetization = arm::set_magnetization(material,volume);
   arm::set_anisotropy_direction(material,temp.kx,temp.ky,temp.kz);
   temp.anisotropy = arm::set_anisotropy(material);

   // Add grain to list
   grains.push_back(temp);

   // resize neighbourlist array to 1
   arm::grain_neighbours.resize(grains.size());*/

	return;

      }

    } // End of namespace internal

  } // End of namespace create

} // End of namespace mars
