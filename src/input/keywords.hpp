//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

#ifndef INPUT_KEYWORDS_H_
#define INPUT_KEYWORDS_H_

// Standard library headers
#include <cstdlib>
#include <sstream>
#include <string>

#include "vectors.hpp"
#include "tensors.hpp"

namespace input{

// List of types of quantity
enum quantity_t {NONE=0, LENGTH=1, TIME=2, MASS=3, ENERGY=4, TEMPERATURE=5, CHARGE=6, ANGLE=7};

struct line_variables_t{
   
    unsigned int line_number;
    std::string keyword;
    std::string value;
    std::string unit;
   
};

//-----------------------------------------------------------------------------
// base template class
//-----------------------------------------------------------------------------
template <class T> class input_keyword_base_t{

public:
   std::string keyword; // name of variable
   T minimum_value; // minimum variable value
   T maximum_value; // maximum variable value
   quantity_t quantity; // type of parameter eg. length
   T * variable_memory_address; // pointer to variable
   bool set_by_user; // flag indicating variable set by user
   std::string manual; // manual entry for keyword

   // constructor
   input_keyword_base_t (std::string ckeyword, T cminimum_value, T cmaximum_value, T& cvariable){
      keyword = ckeyword;
      minimum_value = cminimum_value;
      maximum_value = cmaximum_value;
      variable_memory_address = &cvariable;
   }

   // pure virtual functions
   virtual bool in_range(T value) = 0;
   virtual void assign_to_variable(T value) = 0;
   virtual bool match(line_variables_t& test) = 0;

};

// fake inheritence to allow template specialisation
//-----------------------------------------------------------------------------
// default derived class
//-----------------------------------------------------------------------------
template <typename T> class input_keyword_t : public input_keyword_base_t<T>
{

      using input_keyword_base_t<T>::minimum_value;
      using input_keyword_base_t<T>::maximum_value;
      using input_keyword_base_t<T>::variable_memory_address;

public:
   // constructor
   input_keyword_t (std::string ckeyword, T cminimum_value, T cmaximum_value, T& cvariable) : input_keyword_base_t<T>(ckeyword, cminimum_value, cmaximum_value, cvariable) { //, T* cvariable){
   }

   // templated function declarations
   bool in_range(T value);
   void assign_to_variable(T value);
   bool match(line_variables_t& test);

};

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

} // end of namespace input
  
#endif // _INPUT_KEYWORDS_H_
