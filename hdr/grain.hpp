//-----------------------------------------------------------------------------
//
// This header file is part of the ARM open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers

// Program headers

#ifndef GRAIN_H_
#define GRAIN_H_
//-----------------------------------------------------------------------------
// Class containing grain properties
//-----------------------------------------------------------------------------
class grain_t {

   public:

      // grain material type
      int type;

      // grain coordinates
      double x; //nm
      double y;
      double z;

      // static grain properties
      double volume; // nm^3

      double damping; // damping constant
      double Tc; // Curie temperature K

      double mx; // magnetization unit vector
      double my;
      double mz;
      double magnetization; // J/T/m^3

      // grain simulation properties
      double kx; // anisotropy unit vector
      double ky;
      double kz;
      double anisotropy; // Anisotropy constant J/grain

};

//-----------------------------------------------------------------------------
// Class containing grain neighbour properties
//-----------------------------------------------------------------------------
class grain_neighbour_t {
   public:

      int id; // grain id of neighbour
      double A; // exchange constant

};

#endif /*GRAIN_H_*/
