Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor

Structure definitions
*/

//Structure for the fileNames and their counts (frequency of word in file)
typedef struct files{
  char *fileName;
  int count;
  struct files *nextFile;
} files_t;


//Structure for the mapping of the word, filename, count (frequency of word in file)
typedef struct node{
  char *word;
  files_t *firstFile;
  struct node *next;
} *pnode_t;

