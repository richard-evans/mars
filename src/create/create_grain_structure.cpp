//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers

// Program headers
#include "create.hpp"
#include "internal.hpp"

namespace mars{

  namespace create{

    namespace internal{

      //-----------------------------------------------------------------------------
      // Function to generate grain points
      //-----------------------------------------------------------------------------
      void create_grain_structure(){

	// Generate lattice points
	switch(mars::create::internal::grain_structure){

	case(cubic):
	  mars::create::internal::create_cubic_grain_structure();
	  break;

	case(voronoi):
	  //mars::create::internal::create_voronoi_grain_structure();
	  break;

	case(single):
	  mars::create::internal::create_single_grain();
	  break;

	default:
	  mars::create::internal::create_cubic_grain_structure();

	}

	return;

      }

    } // End of namespace internal

  } // End of namespace create

} // End of namespace mars
