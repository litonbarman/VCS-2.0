#include <string.h>

#include "vcsctree.hpp"

vcs::vcsctree::vcsctree(){
	
	vcs::vcsctree_node temp;
	
	strcpy(temp.commandName, "init");    command.push_back(temp); // 0
	strcpy(temp.commandName, "uninit");  command.push_back(temp); // 1
	strcpy(temp.commandName, "exit");    command.push_back(temp); // 2
	strcpy(temp.commandName, "add");     command.push_back(temp); // 3
	strcpy(temp.commandName, "addf");    command.push_back(temp); // 4
	strcpy(temp.commandName, "del");     command.push_back(temp); // 5
	strcpy(temp.commandName, "delf");    command.push_back(temp); // 6
	strcpy(temp.commandName, "make");    command.push_back(temp); // 7
	strcpy(temp.commandName, "flag");    command.push_back(temp); // 8
	strcpy(temp.commandName, "update");  command.push_back(temp); // 9
	strcpy(temp.commandName, "push");    command.push_back(temp); // 10
	strcpy(temp.commandName, "pull");    command.push_back(temp); // 11
	strcpy(temp.commandName, "status");  command.push_back(temp); // 12
	strcpy(temp.commandName, "command"); command.push_back(temp); // 13
	strcpy(temp.commandName, "clone"); command.push_back(temp);   // 14
	strcpy(temp.commandName, "checkf"); command.push_back(temp);  // 15

}


int vcs::vcsctree::getCID(const char* commandString){
	
	for(int x=0; x<this->command.size(); x++){
		if(!strcmp(this->command[x].commandName, commandString ) ){
			return x;
		}
	}
	
	return -1;

}


void vcs::vcsctree::print(){
			
	printf("commandTree size : %d\n", this->command.size());
				
	for(int x=0; x<this->command.size(); x++){
		printf("%s\n", this->command[x].commandName);
	}
							
};