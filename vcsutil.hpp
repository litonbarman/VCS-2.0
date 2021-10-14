#ifndef __VCSUTIL_HPP__
#define __VCSUTIL_HPP__

#include "vcsNonLib.hpp"


void vcs_deldir(char*);

void vcs_utiladd(char*, char*);

void vcs_utildel(char*, char*);


#ifdef _VCS_NON_LIB_
#include "vcsutil.cpp"
#endif

#endif