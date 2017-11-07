/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>
#include "constants.h"
#include "prototypes.h"
#include "struct_def.h"
#include "externs.h"

//Prototype for function append
void append(char *s, char c);

//Function to browse through directories one at a time, checking for subdirectories with recursion
void browseDirectories(char* directoryName){
  //Declare a DIR pointer variable
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
  //Declare a FILE pointer variable
  FILE *fp;

  //If given file cannot be opened, print error message and stop
  if((fp = fopen(fileName, "a+"))== NULL){
    fprintf(stderr, "Error: File %s cannot be opened.\n", fileName);
    return;
  }

  //Add a space to the end of the file, then rewind
  fputs(" ", fp);
  rewind(fp);

  //Declare int variables to represent each char in file
  int c;
  //Declare char pointer to represent each word
  char *w = malloc(sizeof(char *));
  //Declare a conditional int, TRUE if within word of alphanumeric, FALSE otherwise
  int inWord = FALSE;

  //Loop through all the characters in the file, one by one
  while((c = fgetc(fp)) != EOF){

    //If the character is an alphabet or a digit, append it to the word in lowercase
    if (!(isalpha(c) == 0) || !(isdigit(c) == 0)){
      printf("%c", c);
      inWord = TRUE;
      append(w, tolower(c));
    }
    //Otherwise, reset the char pointer to be empty
    else{
      //If word just ended
      if (inWord){
        printf("\n%s\n", w);
        //Reset inWord to be false
        inWord = FALSE;

        //Push the word to the linked list
      }
      strcpy(w, "");
    }
  }

  //Close the file
  fclose(fp);
}



////////////////////////////////////////////
//Taken from https://stackoverflow.com/questions/12939370/c-appending-char-to-char
//Credited to "djechlin" on October 17, 2012
/////////////////////////////////////////////
void append(char *s, char c){
  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';
}

