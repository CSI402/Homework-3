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

//Function to alphabetize the words in all the files, then sort by count per file
  //Right now, just prints info to the given fileName
  void indexGenerator(char *fileName){
  printf("Calling index generator!\n");

  //Declare a FILE pointer variable
  FILE *fp;

  //If given file cannot be opened, print error message and stop
  if((fp = fopen(fileName, "w"))== NULL){
    fprintf(stderr, "Error: File %s cannot be opened.\n", fileName);
    return;
  }


  //If the list is empty, print so
  if (h == NULL){
    fprintf(stderr, "The list is empty.\n");
    return;
  }

  pfile_t currFile;


  while (h != NULL){
    printf("h is not null\n");

    fprintf(fp, "<list>\n");
    fprintf(fp,"%s\n", h->word);
    currFile = h->firstFile;

    while(currFile != NULL){
      fprintf(fp, "%s %d\n", currFile->fileName, currFile->count);

      currFile = currFile->nextFile;
    }
    fprintf(fp, "</list>\n");
    printf("\n");
    h = h->next;
  }
}


