//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers

// Program headers
#include "create.hpp"
#include "internal.hpp"

namespace mars{

  namespace create{

    namespace internal{

      // create variables
      grain_structure_t grain_structure; // type of structure to be generated

      double system_size_x; // nm
      double system_size_y;
      double system_size_z;

      double grain_size; //nm
      double grain_spacing; //nm   
      
    } // end of namespace create
    
  } // end of namespace cells

} // end of namespace mars
