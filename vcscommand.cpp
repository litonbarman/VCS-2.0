#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <direct.h>

#include "vcsutil.hpp"
#include "vcsmake.hpp"


void vcs::vcs_init(){

	FILE *makeit = fopen("makeit", "w");
	
	if(makeit != 0){
		fprintf(makeit, "# this is a comment for vcs maker");
		fclose(makeit);
	}
	else{
		fprintf(stderr, (char*)"Error : unable to add makeit to the project");
	}
	
	
	if(mkdir(".vcs") != 0){
		fprintf(stderr, (char*)"Error : VCS already initialized\n");
		rmdir(".vcs");
	}
	else{
	   FILE *file;
	   mkdir(".vcs");
	   chmod(".vcs", 0600);
	   system("attrib +H .vcs");
		
	   char hol[100];
	   strcpy(hol, ".vcs/");
	   strcat(hol, ".vcs");
		
	   file = fopen(hol, "w");
	
	   if(file != 0){

		   fprintf(file, "00.00.00.000\n");
		   fprintf(file, "files;\n");
		   fprintf(file, "makeit\n");
		   fprintf(file, "efiles;");
		   fprintf(file, "\n");
		   fprintf(file, "folders;\n");
		   fprintf(file, "efolders;");
	       fprintf(file, "\n");
		
		   fclose(file);
	   }
	   else{
		   fprintf(stderr, (char*)"Error : Access denied\n");
		   rmdir(".vcs");
	   }
	}

}

void vcs::vcs_uninit(){
	if(mkdir(".vcs")==0){
		fprintf(stderr, (char*)"Error : Project does't exit in this directory");
		rmdir(".vcs");
	}
	else{
		
	    char dir[200]; char temp[200];
	
        getcwd(dir,200);
	
	    strcpy(temp, dir);
	    strcat(temp, "/");
	    strcat(temp, ".vcs");
	
	    vcs_deldir(temp);

	    printf((char*)"Done");
	    rmdir(".vcs");
	}
}

void vcs::vcs_exit(){
	exit(0);
}


void vcs::vcs_add(int argc, char *argv[]){
	for(int a=0; a<(argc-2); a++){
	    vcs_utiladd((char*)(argv[a+2]), (char*)"files;");		
	}	
}

void vcs::vcs_addf(int argc, char *argv[]){
	for(int a=0; a<(argc-2); a++){
	    vcs_utiladd((char*)(argv[a+2]), (char*)"folders;");		
	}
}

void vcs::vcs_del(int argc, char *argv[]){
	for(int a=0; a<(argc-2); a++){
	    vcs_utildel((char*)(argv[a+2]), (char*)"files;");		
	}
}

void vcs::vcs_delf(int argc, char *argv[]){
	for(int a=0; a<(argc-2); a++){
	    vcs_utildel((char*)(argv[a+2]), (char*)"folders;");
	}
}

void vcs::vcs_make(){
	vcs_makeit();
}

void vcs::vcs_flag(){
	printf("flag\n");
}

void vcs::vcs_checkf(int argc, char *argv[]){
	
}

void vcs::vcs_update(){
	printf("update\n");
}

void vcs::vcs_push(){
	printf("push\n");
}

void vcs::vcs_pull(){
	printf("pull\n");
}

void vcs::vcs_status(){
	printf("status\n");
}

void vcs::vcs_command(){
	printf("command\n");
}

void vcs::vcs_clone(char *argv){
	
}