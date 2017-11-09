/*
Daniel Hug dhug@albany.edu: Leader
Alana Ruth Aruth@albany.edu : Recorder
Jessica Kanczura jKanczura@albany.edu : Monitor

Prototypes of browse and index functions
*/

void browseDirectories(char *directoryName);
void browseFile(char *fileName);
void indexGenerator(char *fileName);
void *checkMalloc(size_t numBytes); //Might not need this
void freeMem(void *p); //Might not need this
void swap(struct node *a, struct node *b);
void fileSwap(struct files *a, struct files *b);