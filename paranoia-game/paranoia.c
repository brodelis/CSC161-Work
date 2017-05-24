#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "plist.h"
int main(void) {
  plist_t * names = make_list();
  plist_t * tagged = make_list();
  //Starting Game
  printf("Enter a player's name (to begin game, press enter after typing a name): ");
  char *name = fetchline();
  if (strcmp(name, "") == 0) {
    free(name);
    printf("You have chosen not to begin the game\n");
    return;
  }//if
  while(strcmp(name, "") != 0){
    list_insert(names, name);
    print_list(names);
    printf("Enter another player's name: ");
    name = fetchline();
  }//while
  free(name);

  //Game has started
  printAsTargetRing(names);
  printAsTaggedList(names, tagged);
  printf("Enter a target: ");
  char* target = fetchline();
  printAndTagTarget(names, tagged, target);
  
  while (list_size(names) != 1){ 
    printAsTargetRing(names);
    printAsTaggedList(names, tagged);
    printf("Enter a target: ");
    target = fetchline();
    printAndTagTarget(names, tagged, target);
  }//while
    printAsTargetRing(names);
    printAsTaggedList(names, tagged);
    free_list(names);
    free_list(tagged);
  return 0;
}
