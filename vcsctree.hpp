#ifndef __VCSCTREE_HPP__
#define __VCSCTREE_HPP__

#include <vector>
#include "stdio.h"
#include <string.h>

#include "vcsNonLib.hpp"

using namespace std;

namespace vcs {
	
	struct vcsctree_node {
		char commandName[8];
	}; 
	
	
	class vcsctree {
		
		private:
		    
			std::vector<vcsctree_node> command;
			
	    public:
		    
			vcsctree();
			
			void print();
			
			int getCID(const char*);
			
	};
	
}


#ifdef _VCS_NON_LIB_
#include "vcsctree.cpp"
#endif

#endif