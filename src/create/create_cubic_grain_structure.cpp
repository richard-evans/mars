//-----------------------------------------------------------------------------
//
// This source file is part of the ARM open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <cmath>
#include <iostream>

// Program headers
#include "create.hpp"
#include "vars.hpp"

namespace arm{

//-----------------------------------------------------------------------------
// Function to generate cubic grain structure
//-----------------------------------------------------------------------------
void create_cubic_grain_structure(){

   // determine size of cell + spacing between cells
   const double repeat_size = arm::grain_size+arm::grain_spacing;

   // determine number of cells in x,y,z
   int nx = ceil(arm::system_size_x/repeat_size);
   int ny = ceil(arm::system_size_y/repeat_size);
   int nz = ceil(arm::system_size_z/repeat_size);

   std::cout << nx << "\t" << ny << "\t" << nz << "\t" << std::endl;
   
   // Resize grains to zero length
   arm::grains.resize(0);
   
   // Loop over x,y,z and generate centred grain coordinates
   for(int z=0; z<nz; ++z){
      for(int y=0; y<ny; ++y){
         for(int x=0; x<nx; ++x){

            // Determine grain coordinates
            const double cx = (double(x)+0.5)*repeat_size;
            const double cy = (double(y)+0.5)*repeat_size;
            const double cz = (double(z)+0.5)*repeat_size;

            // Determine grain material type
            const int material=arm::set_material(x,y,z);

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

         }
      }
   }

   std::cout << grains.size() << std::endl;
   return;

}

}