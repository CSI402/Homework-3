/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //used for getcwd command
#include <dirent.h> //used to access parts of directory
#include "prototypes.h"

//Structure for the mapping of the word->fileNames
typedef struct node{
  char *word;
  struct node *next;
} node_t, *pnode_t;

int main(int argc, char *argv[]){

  char directoryName[100];  //used to store directory name 
  DIR *dir;                 //pointer to opened directory

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
  
    //if there is one argument
  if (argc == 2){
    if(!strchr(argv[1], '.')){ //if there is no file extension on file
      dir = opendir(argv[1]);  //open directory
      if (dir == NULL){ //check if file opened
        fprintf(stderr, "Error, directory could not be opened.");
        return 1;
      }
      //pass opened directory to propery
    }
    else{
      //pass file for reading and inserting into linked list
    }
  }

 //If there are two arguments, work on given directory/file and generate given fileName
  else if(argc == 3){

    //If the second argument is a directory
    if(strchr(argv[2], '.') == NULL){
      //////CALL BROWSEDIRECTORY WITH argv[2]
    }
    else{
      /////CALL BROWSEFILE WITH argv[2]
    }
  }

  closedir(dir);        //close directory at end of program
  return 0;
}
