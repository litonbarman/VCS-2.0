#ifndef __VCSCOMMAND_HPP__
#define __VCSCOMMAND_HPP__

#include "vcsNonLib.hpp"

namespace vcs{

    void vcs_init();
    void vcs_uninit();
    void vcs_exit();
    void vcs_add(int argc, char *argv[]);
    void vcs_addf(int argc, char *argv[]);
    void vcs_del(int argc, char *argv[]);
    void vcs_delf(int argc, char *argv[]);
    void vcs_make();
    void vcs_flag();
	void vcs_checkf(int argc, char *argv[]);
    void vcs_update();
    void vcs_push();
    void vcs_pull();
    void vcs_status();
    void vcs_command();
	void vcs_clone(char *argv);

}



#ifdef _VCS_NON_LIB_
#include "vcscommand.cpp"
#endif

#endif