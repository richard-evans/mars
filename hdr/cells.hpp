//-----------------------------------------------------------------------------
//
// This header file is part of the MaRS open source package under the
// BSD (2-clause) licence (see LICENCE file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// System headers
#include<vector>

// Program headers

#ifndef CELL_H_
#define CELL_H_

namespace mars{

  namespace cells{

    //-----------------------------------------------------------------------------
    // Simple struct for 3-vector
    //-----------------------------------------------------------------------------
    struct vec_t {
      double x;
      double y;
      double z;
    };

    //-----------------------------------------------------------------------------
    // Class containing cell constants
    //-----------------------------------------------------------------------------
    class cell_constants_t {

    public:

      // cell material type
      int type;

      // cell coordinates
      mars::cells::vec_t position; //nm

      // static cell properties
      double volume; // nm^3
      double magnetic_moment; // J/T (MsV)

      // cell simulation properties
      double kx; // uniaxial anisotropy unit vector
      double ky;
      double kz;
      double ku; // uniaxial Anisotropy constant J/grain

      double damping; // damping constant

      // temperature dependent properties
      double Tc; // Curie temperature K

    };

    //-----------------------------------------------------------------------------
    // Class containing grain neighbour properties
    //-----------------------------------------------------------------------------
    class cell_neighbour_t {

    public:

      int id; // grain id of neighbour
      double A; // exchange constant

    };

    //-----------------------------------------------------------------------------
    // Shared cell variables and functions
    //-----------------------------------------------------------------------------

    extern std::vector<vec_t> m;
    extern std::vector<vec_t> h
    extern std::vector<double> temperature;

    extern std::vector<cell_constants_t> constants;
    extern std::vector<cell_neighbour_t> neighbours;

  } // End of namespace cells

} // End of namespace mars

#endif // CELL_H_
