//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <iostream>

// Program headers
#include "create.hpp"
#include "interface.hpp"
#include "internal.hpp"

namespace mars{

  namespace create{

    void initialise_interface(){

      std::cout << "initialising create interface" << std::endl;
      
      // create variables
      //grain_structure_t grain_structure; // type of structure to be generated

    //double grain_size; //nm
    //  double grain_spacing; //nm

      //  |-----------------------------80 characters wide------------------------------|
      {const char *manual =
          "\n"
	  " Syntax:\n\n"
          "    create:system-size-x = <x> [!<unit>]\n\n"
          " system-size-x specifies the size of the system along the x coordinate\n"
          " direction. The system size can be specified between 1 nanometre and\n"
          " 100 micrometres.\n\n"
	  " The default units are nanometres, but may be set using the optional unit\n"
	  " character (!). Valid units include nanometres (nm), micrometres (um),\n"
	  " metres (m) and inches (in).\n\n";
	mars::interface::parameters.add_new_double_parameter("create:system-size-x", libinput::NONE, 1, 100000, mars::create::internal::system_size_x, manual);}

      //  |-----------------------------80 characters wide------------------------------|
      {const char *manual =
	  "\n"
	  " Syntax:\n\n"
	  "    create:system-size-y = <y> [!<unit>]\n\n"
	  " system-size-y specifies the size of the system along the y coordinate\n"
	  " direction. The system size can be specified between 1 nanometre and\n"
	  " 100 micrometres.\n\n"
	  " The default units are nanometres, but may be set using the optional unit\n"
	  " character (!). Valid units include nanometres (nm), micrometres (um),\n"
	  " metres (m) and inches (in).\n\n";
	mars::interface::parameters.add_new_double_parameter("create:system-size-y", libinput::NONE, 1, 100000, mars::create::internal::system_size_y, manual);}

      //  |-----------------------------80 characters wide------------------------------|
      {const char *manual =
	  "\n"
	  " Syntax:\n\n"
	  "    create:system-size-z = <z> [!<unit>]\n\n"
	  " system-size-z specifies the size of the system along the z coordinate\n"
	  " direction. The system size can be specified between 1 nanometre and\n"
	  " 100 micrometres.\n\n"
	  " The default units are nanometres, but may be set using the optional unit\n"
	  " character (!). Valid units include nanometres (nm), micrometres (um),\n"
	  " metres (m) and inches (in).\n\n";
	mars::interface::parameters.add_new_double_parameter("create:system-size-z", libinput::NONE, 1, 100000, mars::create::internal::system_size_z, manual);}

      //  |-----------------------------80 characters wide------------------------------|
      {const char *manual =
	  "\n"
	  " Syntax:\n\n"
	  "    create:grain-size = <a> [!<unit>]\n\n"
	  " create:grain-size specifies the lateral size of each grain in the system.\n"
	  " direction. The grain size can be specified between 1 and 100 nanometres.\n\n"
	  " The default units are nanometres, but may be set using the optional unit\n"
	  " character (!). Valid units include nanometres (nm), micrometres (um),\n"
	  " metres (m) and inches (in).\n\n";
	mars::interface::parameters.add_new_double_parameter("create:grain-size", libinput::NONE, 1, 100, mars::create::internal::grain_size, manual);}

      //  |-----------------------------80 characters wide------------------------------|
      {const char *manual =
	  "\n"
	  " Syntax:\n\n"
	  "    create:grain-spacing = <a> [!<unit>]\n\n"
	  " create:grain-spacing specifies the spacing between grains in the system.\n"
	  " The grain spacing can be specified between 1 and 100 nanometres.\n\n"
	  " The default units are nanometres, but may be set using the optional unit\n"
	  " character (!). Valid units include nanometres (nm), micrometres (um),\n"
	  " metres (m) and inches (in).\n\n";
	mars::interface::parameters.add_new_double_parameter("create:grain-spacing", libinput::NONE, 1, 100, mars::create::internal::grain_spacing, manual);}

      //std::cout << "\033[32m" << "system-size-x" << "\033[0m" << std::endl;
        //std::cout << mars::interface::parameters.get_manual("system-size-x") << std::endl;

      return; 
    }
    
  } // end of namespace create
    
} // end of namespace mars
