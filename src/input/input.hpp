//-----------------------------------------------------------------------------
//
//                                      input
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
#ifndef INPUT_H_
#define INPUT_H_

// include class definition
#include "parameters.hpp"

#endif
