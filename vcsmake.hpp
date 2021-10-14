#ifndef __VCSMAKE_HPP__
#define __VCSMAKE_HPP__

#include "vcsNonLib.hpp"


void vcs_makeit();


#ifdef _VCS_NON_LIB_
#include "vcsmake.cpp"
#endif

#endif