/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "prototypes.h"

//Function to browse through directories one at a time, checking for subdirectories with recursion
void browseDirectories(char* directoryName){
 //Declare the dir variable
  DIR *dir;

  //If given directory cannot be opened, print error message and stop
  if ((dir = opendir(directoryName)) == NULL){
    fprintf(stderr, "Error: Directory %s cannot be opened.\n", directoryName);
    return;
  }

  //Declare a directory entry pointer variable
  struct dirent *dentry;

  //Loop through all files and subdirectories in the directory
  while((dentry = readdir(dir)) != NULL){

    //If there is no file extension, it is a directory (so call this method recursively)
    if (strchr(dentry->d_name, '.') == NULL)
      browseDirectories(dentry->d_name);
    //Otherwise, call browseFile
    else
      browseFile(dentry->d_name);
  }

  //Close the directory
  closedir(dir);
}

//Function to browse through a file by separators (any non numerical/alphabetical char)
void browseFile(char* fileName){

}
