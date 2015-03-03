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

    //-----------------------------------------------------------------------------
    // Master function to initialise cell properties
    //-----------------------------------------------------------------------------
    void initialise(){

      // Generate grain lattice and neighbourlist
      mars::create::internal::create_grain_structure();

      return;

    }

  } // End of create namespace

} // End of mars namespace
