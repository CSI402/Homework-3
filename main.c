/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //used for getcwd command
#include "prototypes.h"
#include "struct_def.h"

int main(int argc, char *argv[]){

  char directoryName[1024];

  //If there are an invalid number of commands, print error and stop
  if (argc > 3){
    fprintf(stderr, "Error: Invalid number of arguments.\n" );
    return 0;
  }

  //If there are no arguments, work on current directory and generate the file "invind.txt"
  if (argc == 1){

    //If current working directory cannot be received, print error and stop
    if(getcwd(directoryName, sizeof(directoryName))==NULL){
      fprintf(stderr, "Error: Current working directory cannot be accessed.\n");
      return 0;
    }

    browseDirectories(directoryName);
  }

  //If there is one argument, work on given directory and generate the file "invind.txt"
  else if(argc == 2){

    //If there is no file extension, it is a directory
    if(strchr(argv[1], '.') == NULL){
      browseDirectories(argv[1]);
    }
    //Otherwise, print error and stop
    else{
      fprintf(stderr, "Error: Argument is not a directory.\n");
      return 0;
    }
  }

  //If there are two arguments, work on given directory/file and generate given fileName
  else if(argc == 3){

    //If the second argument is a directory
    if(strchr(argv[2], '.') == NULL){
      browseDirectories(argv[2]);
    }
//Otherwise, print error and stop
    else{
      fprintf(stderr, "Error: Argument is not a directory.\n");
      return 0;
    }
  }

  //If there are two arguments, work on given directory/file and generate given fileName
  else if(argc == 3){

    //If the second argument is a directory
    if(strchr(argv[2], '.') == NULL){
      browseDirectories(argv[2]);
    }
    else{
      browseFile(argv[2]);
    }
  }

  return 0;
}
