#include "shell.h"

#define BUFFER_LEN 1024

void Mini_Shell() {
  char line[BUFFER_LEN]; 
  char *argv[100];       
  char *path = "/bin/";  
  char progpath[20];    
  int argc;             

  while (1) {

    printf("SHELL "); // print shell 

    if (!fgets(line, BUFFER_LEN, stdin))
      break;

    size_t length = strlen(line);

    if (line[length - 1] == '\n')
      line[length - 1] = '\0';

    if (strcmp(line, "exit") == 0) { // check if exit
      break;
    }

    char *temp; // split into separate strings
    temp = strtok(line, " ");
    int i = 0;
    while (temp != NULL) {
      argv[i] = temp;
      temp = strtok(NULL, " ");
      i++;
    }
    argv[i] = NULL; // set last value to NULL for execvp

    argc = i; // get arg count
    for (i = 0; i < argc; i++) {
      printf("%s\n", argv[i]); // print command/args
    }
    strcpy(progpath, path);    // copy /bin/ to file path
    strcat(progpath, argv[0]); // add program to path

    for (i = 0; i < strlen(progpath); i++) { // delete newline
      if (progpath[i] == '\n') {
        progpath[i] = '\0';
      }
    }
    int pid = fork(); // fork child

    if (pid == 0) { // Child
      execvp(progpath, argv);
      fprintf(stderr, "Child process could not do execvp\n");

    } else { // Parent
      wait(NULL);
      printf("Child exited\n");
    }
  }
}
