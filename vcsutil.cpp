#include "vcsutil.hpp"

void vcs_utiladd(char* filename, char* at){

	FILE* file = fopen(".vcs/.vcs", "r+");
	FILE* temp1 = fopen(".vcs/.vcs_temp1", "w+");
	FILE* temp2 = fopen(".vcs/.vcs_temp2", "w+");
	
	
	if(file == NULL){
		fprintf(stderr, "ERROR::database not found\n");
	}
	
	char line[200];
	int eo = fscanf(file, "%s\n", line);
	
	
	bool flag = true;
	
	while(true){
	    
		if(eo == EOF){
			break;
		}
		else{		
			if(flag){
			    if(strcmp(line, at) == 0){
				    flag = false;
					eo = fscanf(file, "%s\n", line);
			    }	
			}
		}
		
		if(flag){  // pre
			fprintf( temp1, "%s\n", line );
		}
		else{      // post
		    fprintf( temp2, "%s\n", line );
		}
		
		eo = fscanf(file, "%s\n", line);
	}	
	
	fclose(temp1);
	fclose(temp2);
	fclose(file);
	
	file = fopen(".vcs/.vcs", "w+");
	temp1 = fopen(".vcs/.vcs_temp1", "r+");
	temp2 = fopen(".vcs/.vcs_temp2", "r+");
	
	
	while(fgets(line, 200, temp1)){
		fprintf(file, "%s", line);
	}
	fclose(temp1);
	
	fprintf(file, "%s\n", at);
	fprintf(file, "%s\n", filename);
	
	while(fgets(line, 200, temp2)){
		fprintf(file, "%s", line);
	}
	
	fclose(temp2);
	fclose(file);
	
}


void vcs_utildel(char* filename, char* type){
	
	FILE* file = fopen(".vcs/.vcs", "r+");
	FILE* temp1 = fopen(".vcs/.vcs_temp1", "w+");
	FILE* temp2 = fopen(".vcs/.vcs_temp2", "w+");
	
	
	if(file == NULL){
		fprintf(stderr, "ERROR::database not found\n");
	}
	
	char line[200];
	int eo = fscanf(file, "%s\n", line);
	
	
	bool flag = true;
	
	
	while(true){
	    
		if(eo == EOF){
			break;
		}
		else{		
			if(flag){
			    if(strcmp(line, type) == 0){
				    flag = false;
					eo = fscanf(file, "%s\n", line);
			    }	
			}
		}
		
		if(flag){  // pre
			fprintf( temp1, "%s\n", line );
		}
		else{      // post
		    if(strcmp(line, filename) != 0){
		        fprintf( temp2, "%s\n", line );
			}
		}
		
		eo = fscanf(file, "%s\n", line);
		
	}	
	
	fclose(temp1);
	fclose(temp2);
	fclose(file);
	
	file = fopen(".vcs/.vcs", "w+");
	temp1 = fopen(".vcs/.vcs_temp1", "r+");
	temp2 = fopen(".vcs/.vcs_temp2", "r+");
	
	
	while(fgets(line, 200, temp1)){
		fprintf(file, "%s", line);
	}
	fclose(temp1);
	
	fprintf(file, "%s\n", type);
	// fprintf(file, "%s\n", filename);
	
	while(fgets(line, 200, temp2)){
		fprintf(file, "%s", line);
	}
	
	fclose(temp2);
	fclose(file);
	
}


#ifdef _WIN32
#include <windows.h>

void vcs_deldir(char* sDir){

	WIN32_FIND_DATA fdFile;
    HANDLE hFile = NULL;
    
    char sPath[2048];
    sprintf(sPath, "%s\\*.*", sDir);
    
    if((hFile = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE){
		printf("Path not found : [%s]\n", sDir);
		return;
	}	
	
	do{
		if(strcmp(fdFile.cFileName, "..") != 0 && strcmp(fdFile.cFileName, "..") != 0){
			sprintf(sPath, "%s\\%s", sDir,fdFile.cFileName);
			
			if(fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
				printf("Directory : %s\n", sPath);
				rmdir(sPath);
				//vcsScanDir(sPath);
			}
			else{
				unlink(sPath);
				printf("File : %s\n", sPath);
			}
		}
	}
	while(FindNextFile(hFile, &fdFile));
}


#elif  __APPLE__
#include "vcsApple.h"

#elif  __linux__
#include "vcsLinux.h"

 
//#elif  __unix__

#endif