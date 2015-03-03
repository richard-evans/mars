//-----------------------------------------------------------------------------
//
// This header file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include<vector>

// Program headers
#include "libinput.hpp"

#ifndef INTERFACE_H_
#define INTERFACE_H_

namespace mars{

  namespace interface{

    // Shared variables
    extern libinput::parameters parameters;

    // Shared functions
    void initialise();
    void read_input_file();

  } // End of namespace cells

} // End of namespace mars

#endif // INTERFACE_H_
