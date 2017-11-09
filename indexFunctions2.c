/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor

Contains function that creates the index
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "constants.h"
#include "prototypes.h"
#include "struct_def.h"
#include "externs.h"

//Local function prototypes
void sortFiles();
void sortNodes();
int areFilesSorted();
int areNodesSorted();

//Function to alphabetize the words in all the files, then sort by count per file
//Right now, just prints info to the given fileName
void indexGenerator(char *fileName){

  //Declare a FILE pointer variable
  FILE *fp;

  //If given file cannot be opened, print error message and stop
  if((fp = fopen(fileName, "w"))== NULL){
    fprintf(stderr, "Error: File %s cannot be opened.\n", fileName);
    return;
  }

  //If the list is empty, print so to stderr and stop
  if (h == NULL){
    fprintf(stderr, "The list is empty.\n");
    return;
  }
 //If the list is not empty, sort file lists by counts then nodes by words
  //  while(!areFilesSorted())
  //sortFiles();
  while(!areNodesSorted())
    sortNodes();

  //change all printf to be fprintf to fp at the end
  //Print the entire sorted list to the output file
  pfile_t currFile;

  while (h != NULL){

    printf("<list> %s\n", h->word);

    currFile = h->firstFile;

    while(currFile != NULL){
      printf("%s %d ", currFile->fileName, currFile->count);

      currFile = currFile->nextFile;
    }
  printf("\n</list>\n");
    h = h->next;
  }
}

//Function to sort the files
void sortFiles(){

  //Declare local pointer to each node and file and count
  // pnode_t curr = h;
  //pfile_t currFile;
}

//Function to sort the nodes
void sortNodes(){

  //Declare local pointer to each node and word and file
  pnode_t curr = h;
  pnode_t tempNode = malloc(sizeof(node_t));
 //Loop through nodes
  while(curr->next != NULL){
    //If there is an istance where the next word is less than the current, swap and return
    if(strcmp(curr->word, curr->next->word) > 0){

      //Copy curr node to tempNode
      tempNode = curr;

      //Copy curr->next to curr
      curr = curr->next;

      //Copy tempNode to curr->next
      curr->next = tempNode;

      //free(tempNode);

      return;
    }
    curr = curr->next;
  }
}

//Function returns a boolean if the files are sorted or not
int areFilesSorted(){

  //Declare local pointers to each node and file
  pnode_t curr = h;
  pfile_t currFile;

  //Loop through nodes
  while(curr != NULL){

    currFile = curr->firstFile;

    while(currFile->nextFile != NULL){
      if(currFile->nextFile->count > currFile->count)
        return FALSE; //Immediately return that the files are not sorted

      currFile = currFile->nextFile;
    }

    curr = curr->next;
  }

   //Otherwise, return true;
  return TRUE;
}

//Function returns a boolean if the nodse are sorted or not
int areNodesSorted(){

  //Declare local pointer to each node
  pnode_t curr = h;

  //Loop through nodes
  while(curr->next != NULL){

    //If there is an istance where the next word is less than the current
    if(strcmp(curr->word, curr->next->word) > 0)
      return FALSE;

    curr = curr->next;
  }

  //Otherwise, return true
  return TRUE;
}
