//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <cmath>
#include <iostream>

// Program headers
#include "create.hpp"
#include "internal.hpp"

namespace mars{

  namespace create{

    namespace internal{

      //-----------------------------------------------------------------------------
      // Function to generate cubic grain structure
      //-----------------------------------------------------------------------------
      void create_cubic_grain_structure(){

	/*
	// determine size of cell + spacing between cells
	const double repeat_size = arm::grain_size+arm::grain_spacing;

	// determine number of cells in x,y,z
	int nx = ceil(arm::system_size_x/repeat_size);
	int ny = ceil(arm::system_size_y/repeat_size);
	int nz = ceil(arm::system_size_z/repeat_size);

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

	//-------------------------------------
	// Create simple cubic neighbour list
	//-------------------------------------
	const double radius_sq = 1.1*repeat_size*repeat_size;
	const double area = arm::grain_size*arm::grain_size; // L x L

	// resize neighbourlist array
	arm::grain_neighbours.resize(grains.size());

	// Loop over all grains
	for(unsigned int i=0; i< grains.size(); i++){
	  for(unsigned int j=0; j< grains.size(); j++){
	    const double rx = grains[j].x-grains[i].x;
	    const double ry = grains[j].y-grains[i].y;
	    const double rz = grains[j].z-grains[i].z;
	    const double r_sq = rx*rx + ry*ry + rz*rz;
	    if((r_sq < radius_sq) && (i!=j)){
	      grain_neighbour_t temp;
	      temp.id = j;
	      temp.A = set_exchange(grains[i].type, grains[j].type, area);
	      arm::grain_neighbours[i].push_back(temp);
	    }
	  }
	}
	*/
	return;

      }

    } // End of internal namespace

  } // End of create namespace

} // End of mars namespace
