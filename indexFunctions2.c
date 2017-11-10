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
void insertionSort();
void sortedInsert(pnode_t *head_ref, pnode_t newNode);
void insertionSortFiles(pfile_t headFile);
void sortedInsertFiles(pfile_t *headFile, pfile_t newFile);

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

  //Sort the nodes
  insertionSort();

  //Sort the files
  pnode_t curr = h;
  pfile_t currFile;
  while(curr != NULL){
    currFile = curr->firstFile;
    insertionSortFiles(currFile);
    free(currFile);
    curr = curr->next;
  }

  //change all printf to be fprintf to fp at the end
  //Print the entire sorted list to the output file
  pfile_t currFile2;

  while (h != NULL){

    printf("<list> %s\n", h->word);
  currFile2 = h->firstFile;

    while(currFile2 != NULL){
      printf("%s %d ", currFile2->fileName, currFile2->count);

      currFile2 = currFile2->nextFile;
    }

    printf("\n</list>\n");
    h = h->next;
  }
}

//Function to sort the linked list with insertion sort
void insertionSort(){

  //Initialize sorted linked list
  pnode_t sorted = NULL;
  //Current pointer
  pnode_t curr = h;
  //Loop through the nodes
  while(curr != NULL){

    pnode_t next = curr->next;

    //Insert current in sorted linked list
    //insertionSortFiles(&(curr->firstFile));
    sortedInsert(&sorted, curr);

    curr = next;
  }

  //Update head to point to sorted list
  h = sorted;
}

//Function to insert a new node into the list (similar to push)
void sortedInsert(pnode_t *newHead, pnode_t newNode){

  //If the head is null or the new word is less than the head's
if(*newHead == NULL || (strcmp((*newHead)->word, newNode->word) > 0)){

    //Insert the node at the beginning
    newNode->next = *newHead;
    *newHead = newNode;
  }
  else{

    //Locate the node before the point of insertion
    pnode_t curr = *newHead;
    while(curr->next != NULL && (strcmp(curr->next->word, newNode->word) < 0))
      curr = curr->next;

    //Insert the node at the right spot
    newNode->next = curr->next;
    curr->next = newNode;
  }
}

//Function to sort the files within each node
void insertionSortFiles(pfile_t headFile){
  //Declare sorted and current file pointers
  pfile_t sortedFiles;
  pfile_t currFile = headFile;

  //Loop through nodes
  while(currFile != NULL){

    pfile_t next = currFile->nextFile;

    //Insert currFile in sorted file list
    sortedInsertFiles(&sortedFiles, currFile);

    //Advance to next file
    currFile = next;
  }

  //Update head to sorted list
  headFile = sortedFiles;
}

//Function to insert the file into the correct order in a list
void sortedInsertFiles(pfile_t *headFile, pfile_t newFile){

  //Declare current file pointer
  pfile_t currFile;

  //Insert at head
  if(*headFile == NULL || (*headFile)->count >= newFile->count){
    newFile->nextFile = *headFile;
    *headFile = newFile;
  }
  //Insert in correct spot
  else{
    currFile = *headFile;
    while (currFile->nextFile != NULL && currFile->nextFile->count < newFile->count)
      currFile = currFile->nextFile;

    newFile->nextFile = currFile->nextFile;
    currFile->nextFile = newFile;
  }
}
