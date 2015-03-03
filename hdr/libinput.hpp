//-----------------------------------------------------------------------------
//
//                                    libinput
//
//               A minimal library for defining program parameters
//
//                         (c) Richard F L Evans 2014-2015
//
//-----------------------------------------------------------------------------
//
// This C++ class library is designed to provide a simple way of defining a
// set of program parameters in a free format text file and linking them to
// predefined variables in code. The text file is parsed by the library and
// matching keywords are used to update code variables. Although suitable for
// general use, the library has been designed with scientific software in mind.
//
// Notable features include:
//  o Support for several variable types, int, double, vectors, tensors etc
//  o Support for different scientific units, including custom definitions
//  o Each keyword can have an associated manual entry which can be recalled
//  o Support for parameter range checking and dimensionality (eg length, mass)
//
//-----------------------------------------------------------------------------
// Example usage
//

// Options
// set comment chars
// set ignore whitespace
//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014-2015. All rights reserved.
//
//-----------------------------------------------------------------------------

#ifndef LIBINPUT_H_
#define LIBINPUT_H_

// Standard library headers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//-----------------------------------------------------------------------------
// All functions and classes encapsulated in libinput namespace
//-----------------------------------------------------------------------------
namespace libinput{

// List of types of quantity
enum quantity_t {NONE=0, LENGTH=1, TIME=2, MASS=3, ENERGY=4, TEMPERATURE=5, CHARGE=6, ANGLE=7};

struct line_variables_t{
   
    unsigned int line_number;
    std::string keyword;
    std::string value;
    std::string unit;
   
};

//=========================================================================
// Vector class definition
//=========================================================================

class vec_t{
   
public:
   double x;
   double y;
   double z;

   // default constructor
   vec_t (){
      x = 0.0;
      y = 0.0;
      z = 0.0;
   }

   // constructor for single value
   vec_t (double initial){
      x = initial;
      y = initial;
      z = initial;
   }

   // constructor for three values
   vec_t (double initialx, double initialy, double initialz){
      x = initialx;
      y = initialy;
      z = initialz;
   }

   // function to output to screen
   void print(){
      std::cout << x << "\t" << y << "\t" << z << std::endl;
   }

   // function to return length of vector
   double length(){
      return sqrt(x*x + y*y + z*z);
   }

   // overloaded operator +
   vec_t operator+ (const vec_t& c) const
   {
      vec_t result;
      result.x = (this->x + c.x);
      result.y = (this->y + c.y);
      result.z = (this->z + c.z);
      return result;
   }

   // overloaded operator -
   vec_t operator- (const vec_t& c) const
   {
      vec_t result;
      result.x = (this->x - c.x);
      result.y = (this->y - c.y);
      result.z = (this->z - c.z);
      return result;
   }

   // overloaded operator <=
   bool operator<= (const vec_t& c) const
   {
      bool testx = this->x <= c.x;
      bool testy = this->y <= c.y;
      bool testz = this->z <= c.z;

      return testx && testy && testz;
   }

   // overloaded operator >=
   bool operator>= (const vec_t& c) const
   {
      bool testx = this->x >= c.x;
      bool testy = this->y >= c.y;
      bool testz = this->z >= c.z;

      return testx && testy && testz;
   }

};

//-----------------------------------------------------------------------------
//
//  Simple class for a tensor including custom constructors and operators
//
//-----------------------------------------------------------------------------
class ten_t{

public:
   double xx;
   double xy;
   double xz;

   double yx;
   double yy;
   double yz;

   double zx;
   double zy;
   double zz;

   // default constructor
   ten_t (){
      xx = 0.0;
      xy = 0.0;
      xz = 0.0;
      yx = 0.0;
      yy = 0.0;
      yz = 0.0;
      zx = 0.0;
      zy = 0.0;
      zz = 0.0;
   }

   // constructor for single value
   ten_t (double initial){
      xx = initial;
      xy = initial;
      xz = initial;
      yx = initial;
      yy = initial;
      yz = initial;
      zx = initial;
      zy = initial;
      zz = initial;
   }

   // constructor for nine values
   ten_t (double ixx, double ixy, double ixz,double iyx, double iyy, double iyz,double izx, double izy, double izz){
      xx = ixx;
      xy = ixy;
      xz = ixz;
      yx = iyx;
      yy = iyy;
      yz = iyz;
      zx = izx;
      zy = izy;
      zz = izz;
   }

   // function to output to screen
   void print(){
      std::cout << "[ " << xx << "\t" << xy << "\t" << xz << " ]" << std::endl;
      std::cout << "[ " << yx << "\t" << yy << "\t" << yz << " ]" << std::endl;
      std::cout << "[ " << zx << "\t" << zy << "\t" << zz << " ]" << std::endl;
   }

   // overloaded operator +
   ten_t operator+ (const ten_t& c) const
   {
      ten_t result;
      result.xx = (this->xx + c.xx);
      result.xy = (this->xy + c.xy);
      result.xz = (this->xz + c.xz);
      result.yx = (this->yx + c.yx);
      result.yy = (this->yy + c.yy);
      result.yz = (this->yz + c.yz);
      result.zx = (this->zx + c.zx);
      result.zy = (this->zy + c.zy);
      result.zz = (this->zz + c.zz);
      return result;
   }

   // overloaded operator -
   ten_t operator- (const ten_t& c) const
   {
      ten_t result;
      result.xx = (this->xx - c.xx);
      result.xy = (this->xy - c.xy);
      result.xz = (this->xz - c.xz);
      result.yx = (this->yx - c.yx);
      result.yy = (this->yy - c.yy);
      result.yz = (this->yz - c.yz);
      result.zx = (this->zx - c.zx);
      result.zy = (this->zy - c.zy);
      result.zz = (this->zz - c.zz);
      return result;
   }

   // overloaded operator <=
   bool operator<= (const ten_t& c) const
   {
      bool testxx = this->xx <= c.xx;
      bool testxy = this->xy <= c.xy;
      bool testxz = this->xz <= c.xz;
      bool testyx = this->yx <= c.yx;
      bool testyy = this->yy <= c.yy;
      bool testyz = this->yz <= c.yz;
      bool testzx = this->zx <= c.zx;
      bool testzy = this->zy <= c.zy;
      bool testzz = this->zz <= c.zz;

      return testxx && testxy && testxz && testyx && testyy && testyz && testzx && testzy && testzz;
   }

   // overloaded operator >=
   bool operator>= (const ten_t& c) const
   {
      bool testxx = this->xx >= c.xx;
      bool testxy = this->xy >= c.xy;
      bool testxz = this->xz >= c.xz;
      bool testyx = this->yx >= c.yx;
      bool testyy = this->yy >= c.yy;
      bool testyz = this->yz >= c.yz;
      bool testzx = this->zx >= c.zx;
      bool testzy = this->zy >= c.zy;
      bool testzz = this->zz >= c.zz;

      return testxx && testxy && testxz && testyx && testyy && testyz && testzx && testzy && testzz;
   }

};

//=========================================================================
// Keyword class declaration
//=========================================================================

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
  input_keyword_base_t (std::string ckeyword, T cminimum_value, T cmaximum_value, T& cvariable, std::string cmanual){
      keyword = ckeyword;
      minimum_value = cminimum_value;
      maximum_value = cmaximum_value;
      variable_memory_address = &cvariable;
      manual = cmanual;
   }

   // pure virtual functions
   virtual bool in_range(T value) = 0;
   virtual void assign_to_variable(T value) = 0;
   virtual bool match(line_variables_t& test) = 0;
   virtual bool get_manual(std::string keyword, std::string& manual_entry) = 0;

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
  input_keyword_t (std::string ckeyword, T cminimum_value, T cmaximum_value, T& cvariable, std::string cmanual) : input_keyword_base_t<T>(ckeyword, cminimum_value, cmaximum_value, cvariable, cmanual) { //, T* cvariable){
   }

   // templated function declarations
   bool in_range(T value);
   void assign_to_variable(T value);
   bool match(line_variables_t& test);
   bool get_manual(std::string keyword, std::string& manual_entry);
};

//=========================================================================
// Parameter class declaration
//=========================================================================

class parameters{
   
public:

   // constructor
   parameters();

   // interface functions for adding parameters
   //void add_bool_parameter         (std::string parameter_name, input::quantity_t quantity, int& variable, std::string manual_page);
   //void add_string_parameter       (std::string parameter_name, input::quantity_t quantity, std::string& variable, std::string manual_page);
   //void add_unsigned_int_parameter (std::string parameter_name, input::quantity_t quantity, unsigned int minimum, unsigned int maximum, unsigned int& variable, std::string manual_page);
   void add_new_int_parameter        (std::string parameter_name, libinput::quantity_t quantity, int minimum, int maximum, int& variable, std::string manual_page);
   //void add_float_parameter        (std::string parameter_name, input::quantity_t quantity, float minimum, float maximum, float& variable, std::string manual_page);
   void add_new_double_parameter     (std::string parameter_name, libinput::quantity_t quantity, double minimum, double maximum, double& variable, std::string manual_page);
   //void add_vector_parameter       (std::string parameter_name, input::quantity_t quantity, input::vec_t minimum, input::vec_t maximum, input::vec_t& variable, std::string manual_page);
   //void add_tensor_parameter       (std::string parameter_name, input::quantity_t quantity, input::ten_t minimum, input::ten_t maximum, input::ten_t& variable, std::string manual_page);

   // interface function for adding units
   void add_new_unit(std::string unit_name, libinput::quantity_t quantity, double conversion_factor);

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

   std::string get_manual(std::string keyword);

private:
   
   // flag to enable verbose output to screen
   bool verbose;
   
   // containers for different parameter types
   //std::vector<input::input_keyword_t <bool> >         bool_parameters;
   //std::vector<input::input_keyword_t <unsigned int> > uint_parameters;
   std::vector<libinput::input_keyword_t <int> >          int_parameters;
   //input::input_keyword_t<int> int_parameters;
   //std::vector<input::input_keyword_t <float> >        float_parameters;
   std::vector<libinput::input_keyword_t <double> >          double_parameters;
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
   libinput::line_variables_t extract_parameters_from_line(std::string& line, int line_number);
   
};   

} // end of namespace libinput

#endif // LIBINPUT_H_
