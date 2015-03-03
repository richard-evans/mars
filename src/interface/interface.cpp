//-----------------------------------------------------------------------------
//
// This source file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// Standard library headers

// Program headers
#include "create.hpp"
#include "libinput.hpp"

namespace mars{
  //-----------------------------------------------------------------------------
  // Interface namespace containing shared data structures and functions
  //-----------------------------------------------------------------------------
  namespace interface{

    // Declare single class variable for input parameters
    libinput::parameters parameters;

    //-----------------------------------------------------------------------------
    // Wrapper function to initialise input file parameters
    //-----------------------------------------------------------------------------
    void initialise(){

      // Call module functions to initialise input file variables
      mars::create::initialise_interface();

      return;

    }

    //-----------------------------------------------------------------------------
    // Function to read and process input file
    //-----------------------------------------------------------------------------
    void read_input_file(){

      // open input file
      std::ifstream ifile;
      ifile.open("input");

      // process input file to set program parameters
      bool parse_error = mars::interface::parameters.parse(ifile);

      // close input file
      ifile.close();

      // check for parse error
      if(parse_error){
	std::cerr << "Fatal error: exiting program" << std::endl;
	exit(1);
      }

      return;

    }

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
