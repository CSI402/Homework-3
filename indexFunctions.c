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



void swap (struct node *a, struct node *b){
  char* wordTemp = (char*) malloc(20*sizeof(char));
  strcpy(wordTemp,a->word);
  strcpy(a->word,b->word);
  strcpy(b->word,wordTemp);
  free(wordTemp);
}

void fileSwap (struct files *a, struct files *b){
  struct files *temp;
  temp = a;
  a = b;
  b = temp;
  free(temp);
}


//Function to alphabetize the words in all the files, then sort by count per file
//Right now, just prints info to the given fileName
void indexGenerator(char *fileName){
  //Declare a FILE pointer variable
  FILE *fp;
  //Sets head to head of linked list containing words
  struct node *curr = h;
  //If given file cannot be opened, print error message and stop
  if((fp = fopen(fileName, "w+"))== NULL){
    fprintf(stderr, "Error: File %s cannot be opened.\n", fileName);
    return;
  }
  printf("Calling index generator!\n");


  //If the list is empty, print so
  if (h == NULL){
    fprintf(stderr, "The list is empty.\n");
    return;
  }

  //Sort words alphabetically
  struct node *i, *j;
  for(i = curr; i->next != NULL; i = i->next){
    for(j = i->next; j->next != NULL; j = j->next){
      if(strcmp(i->word, j->word) > 0){
        swap(i,j);
      }
    }
  }

  //Sort file counts
  struct files *x, *y;
  while(curr != NULL){
    for(x = curr->firstFile; x->nextFile != NULL; x = x->nextFile){
      for(y = x->nextFile; y->nextFile != NULL; y = y->nextFile){
        if(x->count < y->count){
          fileSwap(x, y->nextFile);

        }
      }
    }
   curr = curr->next;
  }

  curr = h;


  struct files currFile;

  while (curr != NULL){
    printf("h is not null\n");

    fprintf(fp, "<list>\n");
    fprintf(fp,"%s\n", h->word);
    currFile = *curr->firstFile;

    while(currFile.fileName != NULL){
      fprintf(fp, "%s %d\n", (currFile.fileName), (currFile.count));

      currFile = *currFile.nextFile;
    }
    fprintf(fp, "</list>\n");
    printf("\n");
    curr = curr->next;
  }
}












