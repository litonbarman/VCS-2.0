#include "vcsmake.hpp"

#include <iostream>
#include <stdio.h>
#include <string.h>


int getSComnt(char line[500]);



void vcs_makeit(){
	
	FILE* file = fopen("makeit", "r+");
	char line[500];
    //int res = fscanf(file, "%s\n", line);

    if(file == NULL){
		fprintf(stderr, "ERROR : makeit script not found\n");
		return;
	}

    while(fgets(line, 500, file)){
		
        int hold = getSComnt(line);
 		
		if(hold == -1){ //       found a valid code
		    printf("%s\n", line);

		}		
	}	
	
	fclose(file);
	
};


int getSComnt(char line[500]){
	
	if(strcmp((char*)line, "\n") == 0){
		return -2;
	}
	
	for(int a=0; a < strlen(line); a++){
		
		if( line[a] != ' ' ){
			
			if( line[a] == '#' ){
				return a;
			}
			else{
				return -1;
			}
			
		}
		
	}
	
	return -1;
};