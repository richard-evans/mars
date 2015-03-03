//-----------------------------------------------------------------------------
//
// This header file is part of the input open source library under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// Standard library headers
#include <iostream>
#include <string>

// List of types of quantity
enum quantity_list {Length=0, Time=1, Mass=2, Energy=3, Temperature=4, Charge=5, Angle=6};

class unit_t{
   
public:
   quantity_t quantity;
   std::string unit_name;
   double conversion_factor;
   
   // simple constructor
   unit_t(quantity_t iquantity, std::string iunit_name, double iconversion_factor){
      quantity = iquantity;
      unit_name = iunit_name;
      conversion_factor = iconversion_factor;
   }

};

//extern std::vector<unit_t> unit_list;

void initialise_units(){
   
   unit_t(length,std::string("m"),1.0);
   
   
   
   
   
   
   
   
   
}


//search for quantity in list eg length has m, cm, nm etc.

int main(){
 
   initialise_units();
   
   return 0;
}