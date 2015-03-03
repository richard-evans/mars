//-----------------------------------------------------------------------------
//
// This source file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

#include "input.hpp"

// Standard library headers

namespace mars{
  //-----------------------------------------------------------------------------
  // Interface namespace containing shared data structures and functions
  //-----------------------------------------------------------------------------
  namespace interface{

    // Declare single class variable for input parameters
    input::parameters mars_input_parameters;

  }
  /*myprogram_parameters.set_value_separator("=");
   //myprogram_parameters.set_verbose_output();
   
   int a=123,b=456; // default value
   
   // set up input file parameters
   //input::add_int_parameter("x-pixels", NONE, 1, 1000000, a);
   //  |-----------------------------80 characters wide------------------------------|
   {const char *text =
      "Controls the number of pixels along x where electrons are generated.\n"
      "concatenated into just a single string.\n";
   myprogram_parameters.add_new_int_parameter("x-pixels", input::NONE, 1, 1000000, a, text);}

   {const char *text =
      "Controls the number of pixels along y where electrons are generated.\n"
      "concatenated into just a single string.\n";
   myprogram_parameters.add_new_int_parameter("y-pixels", input::NONE, 1, 1000000, b, text);}

   std::ifstream ifile;
   ifile.open("ifile");
   
   myprogram_parameters.parse(ifile);
   
   ifile.close();
   
   std::cout << "New value: " << a << std::endl;
   std::cout << "New value: " << b << std::endl;
   
   //input::add_length_unit("nm",1.0e-9);
   
   // open input file
   
   // pass input file to parser
   
   //input::myprogram_parameters.print_manual("x-pixels");
   
   return 0;*/
   
} // end of namespace mars
