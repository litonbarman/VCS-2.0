#include <stdio.h>

#include "vcsctree.hpp"
#include "vcscommand.hpp"

using namespace vcs;


void vcs::vcsSegregateCommand(int argc, char *argv[]){
	
	if(argc > 1){
 	    vcs::vcsProcessCommand( vcs::commandTree.getCID(argv[1]), argc, argv );
	}
	
	
}


void vcs::vcsProcessCommand(int commandID, int argc, char* argv[]){
	
	switch( commandID ){
		
		case 0 : vcs_init();
		break;
		
		case 1 : vcs_uninit();
		break;
		
		case 2 : vcs_exit();
		break;
		
		case 3 : vcs_add(argc, argv);
		break;
		
		case 4 : vcs_addf(argc, argv);
		break;
		
		case 5 : vcs_del(argc, argv);
		break;
		
		case 6 : vcs_delf(argc, argv);
		break;
		
		case 7 : vcs_make();
		break;
		
		case 8 : vcs_flag();
		break;
		
		case 9 : vcs_update();
		break;
		
		case 10 : vcs_push();
		break;
		
		case 11 : vcs_pull();
		break;
		
		case 12 : vcs_status();
		break;
		
		case 13 : vcs_command();
		break;
		
		case 14 : vcs_clone(argv[2]);
		break;
		
		case 15 : vcs_checkf(argc, argv);
		break;
		
		default:
		          printf("Unknown command");
	}
	
}