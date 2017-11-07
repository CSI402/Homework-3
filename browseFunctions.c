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

//Prototype for local functions
void push(char *wd, char *fName);
void changeFileName(char *fName);
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

 //Change the file name (only does if needed)
  changeFileName(fileName);

  //Add a space to the end of the file, then rewind
  /*This is done so that in the case that the last char in the file
    is alphanumeric, the final word will still be counted*/
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
      inWord = TRUE;
      append(w, tolower(c));
    }
    //Otherwise, reset the char pointer to be empty
    else{
      //If word just ended
      if (inWord){
        printf("%s\n", w);
        //Reset inWord to be false
        inWord = FALSE;

        //Push the word to the linked list with the fileName
        push(w, fileName);
      }
      strcpy(w, "");
    }
  }

  //Close the file
  fclose(fp);
}
/*
Function to push the word to the linked list with the given fileName

If the list is null
  add the word, with given fileName and count = 1

-------------------------------------------
changeFileName
---------------------------------------------
Otherwise, iterate through nodes
  Iterate through fileNames
    if file exists
      numFileOccurances++ (starts at 0)

if (numFiles > 0)
  append fileName with numFiles

--------------------------------------------

isFile = FALSE;

Iterate through linked list again
  if word exists
    iterate through fileNames
      if file exists
        count++ and isFile = TRUE
    if (!isFile)
      add fileName to end and count = 1
  else (word does not exist)
    add word, given fileName, and count = 1 to end
*/

void push(char *wd, char *fName){

  //Set current node to be head
  pnode_t curr = h;
  //To hold the new node ---- MAYBE MOVE THIS, NOT ALWAYS USED
  pnode_t newNode = malloc(sizeof(pnode_t));
  //To hold the new file node ---- THIS TOO
  pfile_t newFileNode = malloc(sizeof(pfile_t));
  //If the list is empty
  if (curr == NULL){
    //Add the word
    newNode->word = malloc(sizeof(char *));
    strcpy(newNode->word, wd);
    newNode->next = NULL;

    //Add the file to the beginning of this word's file list with count = 1
    newFileNode->fileName = malloc(sizeof(char *));
    strcpy(newFileNode->fileName, fName);
    newFileNode->count = 1;
    newFileNode->nextFile = NULL;
    newNode->firstFile = newFileNode; //Maybe this works?
    return;
  }

  //If the list is not empty

  //Declare current file node
  pfile_t currFile;
  //Declare boolean isFile for whether or not the file is already in the word's list
  int isFile = FALSE;

  //Iterate through the nodes
  while (curr != NULL){

    //If the word exists
    if(strcmp(curr->word, wd) == 0){

      //Iterate through the fileNames in the nodes
      currFile = curr->firstFile;
      while (currFile != NULL){

        //If the file exists, set isFile to TRUE
        if(strcmp(currFile->fileName, fName) == 0)
          isFile = TRUE;

        //Go to the next file
        currFile = currFile->nextFile;
      }

    }

    //Go to the next node
    curr = curr->next;
  }

}


//If the given file name already exists in the list, append an appropriate number to the end of the file name
void changeFileName(char *fName){

  //Set current node to be head
  pnode_t curr = h;
  //Declare current file node
  pfile_t currFile;

  //Initialize numFile to be 0
  int numFiles = 0;

  //Iterate through the nodes
  while(curr != NULL){

    //Iterate through the fileNames in the nodes
    currFile = curr->firstFile;
    while (currFile != NULL){
      //If the file name exists, increment numFile counter
      if (strcmp(currFile->fileName, fName) == 0)
        numFiles++;

      //Go to the next file
      currFile = currFile->nextFile;
    }
    //Go to the next node
    curr = curr->next;
  }

  //If the file already exists, append its number to the name
  if(numFiles > 0)
    append(fName,(numFiles + '0'));

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
