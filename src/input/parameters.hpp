//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------
//
//  Shared class definition for parameter set
//
//-----------------------------------------------------------------------------

#ifndef INPUT_PARAMETERS_H_
#define INPUT_PARAMETERS_H_

// Standard library headers
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// input library headers
#include "keywords.hpp"
#include "vectors.hpp"
#include "tensors.hpp"

//-----------------------------------------------------------------------------
// All functions and classes encapsulated in input namespace
//-----------------------------------------------------------------------------
namespace input{
   
//---------------------------------------------------------------
// main class definition of input library
//---------------------------------------------------------------
class parameters{
   
public:
   
   // interface functions for adding parameters
   //void add_bool_parameter         (std::string parameter_name, input::quantity_t quantity, int& variable, std::string manual_page);
   //void add_string_parameter       (std::string parameter_name, input::quantity_t quantity, std::string& variable, std::string manual_page);
   //void add_unsigned_int_parameter (std::string parameter_name, input::quantity_t quantity, unsigned int minimum, unsigned int maximum, unsigned int& variable, std::string manual_page);
   void add_new_int_parameter          (std::string parameter_name, input::quantity_t quantity, int minimum, int maximum, int& variable, std::string manual_page);
   //void add_float_parameter        (std::string parameter_name, input::quantity_t quantity, float minimum, float maximum, float& variable, std::string manual_page);
   //void add_double_parameter       (std::string parameter_name, input::quantity_t quantity, double minimum, double maximum, double& variable, std::string manual_page);
   //void add_vector_parameter       (std::string parameter_name, input::quantity_t quantity, input::vec_t minimum, input::vec_t maximum, input::vec_t& variable, std::string manual_page);
   //void add_tensor_parameter       (std::string parameter_name, input::quantity_t quantity, input::ten_t minimum, input::ten_t maximum, input::ten_t& variable, std::string manual_page);

   // interface function for adding units
   void add_new_unit(std::string unit_name, input::quantity_t quantity, double conversion_factor);
   
   // interface functions to parse input file
   //void parser(std::string& input_file_text);
   void parse(std::ifstream& input_file_stream);
   
   // interface functions for setting separator characters
   void set_unit_separator(std::string unit_separator_character);
   void set_comment_separator(std::string unit_separator_character);
   void set_value_separator(std::string unit_separator_character);
   void set_keyword_separator(std::string unit_separator_character);

   // functions to control verbose output
   void set_verbose_output();
   void unset_verbose_output();

private:
   
   // flag to enable verbose output to screen
   bool verbose;
   
   // containers for different parameter types
   //std::vector<input::input_keyword_t <bool> >         bool_parameters;
   //std::vector<input::input_keyword_t <unsigned int> > uint_parameters;
   std::vector<input::input_keyword_t <int> >          int_parameters;
   //input::input_keyword_t<int> int_parameters;
   //std::vector<input::input_keyword_t <float> >        float_parameters;
   //std::vector<input::input_keyword_t <double> >       double_parameters;
   //std::vector<input::input_keyword_t <input::vec_t> >        vector_parameters;
   //std::vector<input::input_keyword_t <input::ten_t> >        tensor_parameters;
   //std::vector<input::input_keyword_t <std::string> >  string_parameters;
   
   // 
  std::string comment_character; // = "#"
  std::string unit_separator; // = "!"
  std::string value_separator; // = "="
  std::string keyword_separator; // = ":"
   
   // internal class functions
   void parse_line(std::string& line, int line_number);
   input::line_variables_t extract_parameters_from_line(std::string& line, int line_number);
   
};   


//---------------------------------------------------------------
// Function to create a new int parameter in parameter list 
//---------------------------------------------------------------
void parameters::add_new_int_parameter(std::string parameter_name, input::quantity_t quantity, int minimum, int maximum, int& variable, std::string manual_page){

   // create temporary keyword variable using kyword class constructor
   input::input_keyword_t <int> new_int_parameter(parameter_name, minimum, maximum, variable);

   // add parameter to list
   parameters::int_parameters.push_back(new_int_parameter);

   return;

}

//---------------------------------------------------------------
// Function to create a new int parameter in parameter list 
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

void parameters::parse_line(std::string& line, int line_number){

   // loop over all lines in file

   // load line from file and extract contents
   input::line_variables_t line_contents = extract_parameters_from_line(line,line_number);

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
   /*if(!match_found) for(int i=0; i<float_parameters.size(); ++i){
      match_found = float_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all doubles
   if(!match_found) for(int i=0; i<double_parameters.size(); ++i){
      match_found = double_parameters.at(i).match(line_contents);
      if(match_found) break;
   }
   // loop over all vectors
   if(!match_found) for(int i=0; i<vector_parameters.size(); ++i){
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

input::line_variables_t parameters::extract_parameters_from_line(std::string& line, int line_number){

   // Array of string variable to contain parts
   std::vector<std::string> string_array(3,"");

   // Clear whitespace and tabs
   line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
   line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

   // Clear carriage return for dos formatted files
   line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

   // Set key characters for separating string to components
   const char* commentc=parameters::comment_character.c_str();
   const char* unitc=parameters::unit_separator.c_str();     // Value identifier
   const char* valuec=parameters::value_separator.c_str();    // Unit identifier
   const char* keywordc=parameters::keyword_separator.c_str();   // Comment identifier

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
   input::line_variables_t result;

   // Copy variables from string array
   result.keyword = string_array[0];
   result.value   = string_array[1];
   result.unit    = string_array[2];
   result.line_number = line_number;

   return result;

}

} // end of namespace input

#endif // _INPUT_PARAMETERS_H_
