//-----------------------------------------------------------------------------
//
// This source file is part of the ARM open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include <iostream>

// Program headers
#include "create.hpp"

int main(){

   // Output Program Header
   //----------------------------------------------------------------------------------------------------------
   std::cout << std::endl;
   std::cout << "                                  ,---.,---.,-.-." << std::endl;
   std::cout << "                                  ,---||    | | |" << std::endl;
   std::cout << "                                  `---^`    ` ' '" << std::endl;
   std::cout << std::endl;
   std::cout << "                      Version 1.0.0 " << __DATE__ << " " << __TIME__ << std::endl;
   std::cout << std::endl;

   std::cout << "  Licensed under the BSD (2-Clause) License. See licence file for details." << std::endl;
   std::cout << std::endl;
   std::cout << "  Lead Developer: Richard F L Evans" << std::endl;
   std::cout << std::endl;
   std::cout << "  Contributors:" << std::endl;
   std::cout << std::endl;
   std::cout << "--------------------------------------------------------------------------------" << std::endl;

   // Initialise system
   //arm::initialise(infile);

   // Create system
   arm::create();

   // Simulate system
   //arm::simulate();

   return 0;

}