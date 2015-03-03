//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

#ifndef INPUT_VECTORS_H_
#define INPUT_VECTORS_H_

// Standard library headers
#include <iostream>
#include <cmath>

namespace input{

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

} // end of namespace input

#endif // _INPUT_VECTORS_H_