/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "prototypes.h"

int main(int argc, char *argv[]){

  char directoryName[100];
  DIR *dir;

  //If there are an invalid number of commands, print error and stop
  if (argc > 3){
    fprintf(stderr, "Error: Invalid number of arguments\n" );
    return 0;
  }
   //if there are no arguments
  if (argc == 1){
    if(getcwd(directoryName, sizeof(directoryName))==NULL){             //get current working directory and verify it was received 
      fprintf(stderr, "Error, current working directory cannot be accessed.");   //if not received, print error
      return 1;         //close program
    }
    dir = opendir(directoryName);         //open current working directory
    if (dir == NULL){                     //verify opened
      fprintf(stderr, "Error, directory could not be opened.");     //if not opened, print error
      return 1;            //close program
    }
  }

  closedir(dir);        //close directory at end of program
  return 0;
}
