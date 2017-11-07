/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor
*/

//Structure for the mapping of the word, filename, count (frequency of word in file)
typedef struct node{
  char *word;
  char *fileName;
  int count;
  struct node *next;
} node_t, *pnode_t;
