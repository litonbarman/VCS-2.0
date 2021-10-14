#ifndef __VCSMAIN_HPP__
#define __VCSMAIN_HPP__

#include "vcsNonLib.hpp"
#include "vcsctree.hpp"


namespace  vcs {
	
	vcs::vcsctree commandTree;
	
	void vcsSegregateCommand(int argc, char *argv[]);

	void vcsProcessCommand(int commandID, int argc, char *argv[]);

}




#ifdef _VCS_NON_LIB_
#include "vcsmain.cpp"
#endif


#endif