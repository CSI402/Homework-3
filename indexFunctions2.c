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
void insertionSort(/*pnode_t *head_ref*/);
void sortedInsert(pnode_t *head_ref, pnode_t newNode);

/*void sortFiles();
void sortNodes();
int areFilesSorted();
int areNodesSorted();
*/

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
 // while(!areNodesSorted())
   // sortNodes();
  
  
  //Sort the list
  insertionSort(/*&h*/);

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

//Function to sort the linked list with insertion sort
void insertionSort(/*pnode_t *head_ref*/){

  //Initialize sorted linked list
  pnode_t sorted = NULL;
  //Current pointer
  pnode_t curr = h;

  //Loop through the nodes
  while(curr != NULL){

    printf("---Inserting %s...\n", curr->word);

    //Insert current in sorted linked list
    sortedInsert(&sorted, temp);

    curr = curr->next;
  }

  //Update head to point to sorted list
  h = sorted;
}

//Function to insert a new node into the list (similar to push)
void sortedInsert(pnode_t *newHead, pnode_t newNode){

  //If the head is null or the new word is less than the head's
  if(*newHead == NULL || (strcmp((*newHead)->word, newNode->word) > 0)){
    printf("---Inserting %s at head.\n", newNode->word);

    //Inset the node at the end
    newNode->next = *newHead;
    *newHead = newNode;
  }
  else{
    printf("---Inserting %s in middle.\n", newNode->word);

    //Locate the node before the point of insertion
    pnode_t curr = *newHead;
    while(curr->next != NULL && (strcmp(curr->next->word, newNode->word) < 0))
      curr = curr->next;

    //Insert the node at the right spot
    newNode->next = curr->next;
    curr->next = newNode;

  }
}



/*
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
*/
