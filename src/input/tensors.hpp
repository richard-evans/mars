//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

#ifndef INPUT_TENSORS_H_
#define INPUT_TENSORS_H_

// Standard library headers
#include <iostream>

namespace input{

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

} // end of namespace input

#endif // _INPUT_TENSORS_H_
