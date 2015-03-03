//-----------------------------------------------------------------------------
//
// This source file is part of the libinput open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

// Standard library headers
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// libinput header
#include "libinput.hpp"

//-----------------------------------------------------------------------------
// All functions and classes encapsulated in libinput namespace
//-----------------------------------------------------------------------------
namespace libinput{

//--------------------------------------------------------------
// Default templated class functions
//--------------------------------------------------------------
   
//---------------------------------------------------------
// Function to check for matching keyword and assign value
//---------------------------------------------------------
template <class T>
bool input_keyword_t<T>::match(line_variables_t& test){

   // Test for match, if false return
   if(test.keyword!=this->keyword) return false;

   // Match found, now process for unit conversion and variable assignment
   T converted_value;

   // Use stringstreams for general variable interpretation
   std::stringstream stringstr(test.value);

   // Read string into variable
   stringstr >> converted_value;
   
   //check_value_range(converted_value);

   //set_value(converted_value);
   assign_to_variable(converted_value);

   // return true for matching keyword
   return true;

}

  //-------------------------------------------------------------
  // Function to check for matching keyword and get manual entry
  //-------------------------------------------------------------
  template <class T>
  bool input_keyword_t<T>::get_manual(std::string keyword, std::string& manual_entry){

    // Test for match, if false return
    if(keyword!=this->keyword) return false;

    // If match found, copy manual and return
    manual_entry = this->manual;

    //std::cout << "I am here " << keyword << "\t" << this->keyword << "\t" << this->manual << std::endl;

    // return true for matching keyword
    return true;

  }

//-------------------------------------------
// Function to check value is in range
//-------------------------------------------
template <class T>
bool input_keyword_t<T>::in_range(T value){
   if(value >= minimum_value && value <= maximum_value) return true;
   else return false;
}

//-------------------------------------------
// Function to assign value to variable
//-------------------------------------------
template <class T>
void input_keyword_t<T>::assign_to_variable(T value){
   *variable_memory_address = value; // assign contents of value to location pointed to by variable_memory_address
   return;
}
   
//--------------------------------------------------------------
// Function specialization of only certain functions
//
// see http://stackoverflow.com/a/3911108
//
//--------------------------------------------------------------

//-----------------------------------------------------------------------------
// template specialisation for bool
//-----------------------------------------------------------------------------
template<>
bool input_keyword_t<bool>::in_range(bool value){
   return true;
}

//-----------------------------------------------------------------------------
// template specialisation for std::string
//-----------------------------------------------------------------------------
template<>
bool input_keyword_t<std::string>::in_range(std::string value){
   if(value.size() <=256) return true;
   else return false;
}

//vector --
//matrix -- check all elements

//-----------------------------------------------------------------------------
// class template specialisation for bool (for info)
//-----------------------------------------------------------------------------
/*template <> class input_keyword_t<bool> : public input_keyword_base_t<bool>
{
    public:
   // constructor (passes arguments to base constructor)
   input_keyword_t (std::string ckeyword, bool cminimum_value, bool cmaximum_value, bool& cvariable) : 
      input_keyword_base_t<bool>(ckeyword, cminimum_value,cmaximum_value, cvariable) {}

   bool in_range(bool value){
      return true;
   }
   
   // must define other templated functions here
};*/

//---------------------------------------------------------------
// Constructor for parameter class
//---------------------------------------------------------------
parameters::parameters(){

  // set default values
  parameters::set_value_separator("=");

  return;

}

//---------------------------------------------------------------
// Function to create a new int parameter in parameter list 
//---------------------------------------------------------------
void parameters::add_new_int_parameter(std::string parameter_name, libinput::quantity_t quantity, int minimum, int maximum, int& variable, std::string manual_page){

   // create temporary keyword variable using kyword class constructor
   libinput::input_keyword_t <int> new_int_parameter(parameter_name, minimum, maximum, variable, manual_page);

   // add parameter to list
   parameters::int_parameters.push_back(new_int_parameter);

   return;

}

//---------------------------------------------------------------
// Function to create a new int parameter in parameter list 
//---------------------------------------------------------------
void parameters::add_new_double_parameter(std::string parameter_name, libinput::quantity_t quantity, double minimum, double maximum, double& variable, std::string manual_page){

   // create temporary keyword variable using kyword class constructor
  libinput::input_keyword_t <double> new_double_parameter(parameter_name, minimum, maximum, variable, manual_page);

   // add parameter to list
   parameters::double_parameters.push_back(new_double_parameter);

   return;

}

//---------------------------------------------------------------
// Function to set the character separating values (default "=" )
//---------------------------------------------------------------
void parameters::set_value_separator(std::string value_separator_character){

   // set class value separator
   parameters::value_separator = value_separator_character;

   return;

}

//---------------------------------------------------------------
// Function to set verbose output
//---------------------------------------------------------------
void parameters::set_verbose_output(){
   parameters::verbose=true;
   return;
}
   
//---------------------------------------------------------------
// Function to unset verbose output
//---------------------------------------------------------------
void parameters::unset_verbose_output(){
   parameters::verbose=false;
   return;
}

//---------------------------------------------------------------
// Function to parse input string for parameters 
//---------------------------------------------------------------
/*void parameters::parse(std::string& file_text){

   // declare line as string
   std::string line;

   //bool error=false; // flag to check for error

   // convert input string to string stream
   std::stringstream file(file_text);

   while (std::getline(file, line)){
      parameters::parse_line(line);
   }

   //return error;

}*/

//---------------------------------------------------------------
// Function to parse input file stream for parameters 
//---------------------------------------------------------------
void parameters::parse(std::ifstream& ifile){

   // check file is open
   if(!ifile.is_open()){
      std::cerr << "Error input file stream is not open: unable to process input file parameters" << std::endl;
      return;
   }
   
   // declare line counter variable
   int line_counter = 0;
   
   // declare line as string
   std::string line;

   // read all lines in file
   while (std::getline(ifile, line)){

      // print lines to screen if verbose output requested
      if(parameters::verbose) std::cout << line_counter << "\t" << line << std::endl;

      // pass each line to parser
      parameters::parse_line(line,line_counter);
      
      // increment line number
      line_counter++;

   }

   return;

}

std::string parameters::get_manual(std::string keyword){

  // result variable
  std::string manual_page;

  // Ugly but simple loop over all parameters
  //------------------------------------------------------------------------
  bool match_found = false;

  // loop over all ints
  if(!match_found) for(unsigned int i=0; i<int_parameters.size(); ++i){
      match_found = int_parameters.at(i).get_manual(keyword,manual_page);
      if(match_found) break;
  }
  // loop over all doubles
  if(!match_found) for(unsigned int i=0; i<double_parameters.size(); ++i){
      match_found = double_parameters.at(i).get_manual(keyword,manual_page);
      if(match_found) break;
  }
  // Check for no matching parameters and print error message
  if(!match_found){
    std::cout << "No manual entry for '" << keyword << "'" << std::endl;
  }

  return manual_page;

}

void parameters::parse_line(std::string& line, int line_number){

   // loop over all lines in file

   // load line from file and extract contents
   libinput::line_variables_t line_contents = extract_parameters_from_line(line,line_number);

   // print lines to screen if verbose output requested
   if(parameters::verbose){
      std::cout << "\t" << "keyword: " << line_contents.keyword << std::endl;
      std::cout << "\t" << "value:   " << line_contents.value << std::endl;
      std::cout << "\t" << "unit:    " << line_contents.unit << std::endl;
      std::cout << "\t" << "line:    " << line_contents.line_number << std::endl;
   }

   // Ugly but simple loop over all parameters
   //------------------------------------------------------------------------
   bool match_found = false;

   // loop over all bools
   /*if(!match_found) for(int i=0; i<bool_parameters.size(); ++i){
      match_found = bool_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all uints
   if(!match_found) for(int i=0; i<uint_parameters.size(); ++i){
      match_found = uint_parameters.at(i).match(line_contents);
      if(match_found) break;
   }*/
   // loop over all ints
   if(!match_found) for(unsigned int i=0; i<int_parameters.size(); ++i){
      match_found = int_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all floats
   //if(!match_found) for(int i=0; i<float_parameters.size(); ++i){
   //   match_found = float_parameters.at(i).match(line_contents);
   //   if(match_found) break;
   //}
   // loop over all doubles
   if(!match_found) for(unsigned int i=0; i<double_parameters.size(); ++i){
      match_found = double_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all vectors
   /*if(!match_found) for(int i=0; i<vector_parameters.size(); ++i){
      match_found = vector_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all tensors
   if(!match_found) for(int i=0; i<tensor_parameters.size(); ++i){
      match_found = tensor_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all strings
   if(!match_found) for(int i=0; i<string_parameters.size(); ++i){
      match_found = string_parameters.at(i).match(line_contents);
      if(match_found) break;
   }*/

   // Check for no matching parameters and print error message
   if(!match_found){
      std::cerr << "Error! No matching parameter found for keyword '" << line_contents.keyword << "' on line ";
      std::cerr << line_contents.line_number << " of input file." << std::endl;
   }
}

libinput::line_variables_t parameters::extract_parameters_from_line(std::string& line, int line_number){

   // Array of string variable to contain parts
   std::vector<std::string> string_array(3,"");

   // Clear whitespace and tabs
   line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
   line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

   // Clear carriage return for dos formatted files
   line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

   // Set key characters for separating string to components
   const char* commentc = parameters::comment_character.c_str();
   const char* unitc    = parameters::unit_separator.c_str();     // Value identifier
   const char* valuec   = parameters::value_separator.c_str();    // Unit identifier
   const char* keywordc = parameters::keyword_separator.c_str();   // Comment identifier

   // Declare variable to string container index
   unsigned int idx = 0;

   // Loop over all characters in line
   for(unsigned int i=0;i<line.length();i++){

      // get character at position i
      char c=line.at(i);

      // if key character found change string array value and continue to next position
      if(c == *keywordc){
         idx = 0;
         continue;
      }
      else if(c == *valuec){
         idx = 1;
         continue;
      }
      else if(c == *unitc){
         idx = 2;
         continue;
      }
      else if(c == *commentc){
         // All characters after comment key are ignored
         break;
      }

      // If character is not key character add characters to string
      string_array[idx].push_back(c);
   }

   // Declare result variable
   libinput::line_variables_t result;

   // Copy variables from string array
   result.keyword = string_array[0];
   result.value   = string_array[1];
   result.unit    = string_array[2];
   result.line_number = line_number;

   return result;

}

} // end of namespace libinput
