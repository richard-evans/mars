//-----------------------------------------------------------------------------
//
// This source file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <iostream>

// Program headers
#include "create.hpp"
#include "interface.hpp"

int main(){

   // Output Program Header
   //----------------------------------------------------------------------------------------------------------
   std::cout << std::endl;
   std::cout << "                           __  __       ____  ____" << std::endl;
   std::cout << "                          |  \\/  | __ _|  _ \\/ ___|" << std::endl;
   std::cout << "                          | |\\/| |/ _` | |_) \\___ \\ " << std::endl;
   std::cout << "                          | |  | | (_| |  _ < ___) |" << std::endl;
   std::cout << "                          |_|  |_|\\__,_|_| \\_\\____/" << std::endl;
   std::cout << std::endl;
   std::cout << "                         Magnetic Recording Simulator" << std::endl;
   std::cout << std::endl;
   std::cout << "                      Version 1.0.0 " << __DATE__ << " " << __TIME__ << std::endl;
   std::cout << std::endl;

   std::cout << "  Licensed under the BSD (2-Clause) License. See licence file for details." << std::endl;
   std::cout << std::endl;
   std::cout << "  Lead Developers: Lewis Atkinson and Richard F L Evans" << std::endl;
   std::cout << std::endl;
   std::cout << "  Contributors:" << std::endl;
   std::cout << std::endl;
   std::cout << "--------------------------------------------------------------------------------" << std::endl;

   // Initialise program interface
   mars::interface::initialise();

   // Process input file to set program parameters
   mars::interface::read_input_file();

   // Create system
   mars::create::initialise();

   // Initialise integrators
   //mars::integrators::initialise();

   // Initialise fields
   // mars::fields::initialise();

   // Simulate system
   //mars::simulate();

   return 0;

}
