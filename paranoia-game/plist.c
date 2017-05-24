#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include"plist.h"
#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2


pnode_t* make_node(char *name, pnode_t *next) {
  pnode_t *ret = (pnode_t*)malloc(sizeof(pnode_t));
  ret->name = name;
  ret->next = next;
  return ret;
}
plist_t* make_list(){
    plist_t *ret = (plist_t*)malloc(sizeof(plist_t));
  ret->first = NULL;
  return ret;
}

void free_node(pnode_t *node){
  free(node);
}
void free_all_nodes(pnode_t *n) {
  if (n == NULL) {
    return;
  }//if
  else{
    free_all_nodes(n->next);
    free(n->name);
    free(n);
  }//else
}

void free_list(plist_t *list){
  free_all_nodes(list->first);
  free(list);
}

void list_insert(plist_t *list, char *name){
  pnode_t *n = make_node(name, NULL);
  if(list->first == NULL) {
    list->first = n;
  }//if
  else{
    pnode_t *cur = list->first;
    while(cur->next != NULL){
      cur = cur->next;
    }//while
    cur->next = n;
  }//else
}

bool list_remove(plist_t *list, char *name){
  pnode_t * cur = list->first;
  if (cur == NULL){
    return false;
  }// end if
  else if (strcmp(cur->name, name) == 0) {
    pnode_t * t = cur;
    list->first = cur->next;
    free(t->name);
    free_node(t);
    return true;
  }// end if
  else{
  while (cur->next != NULL) {
    if (strcmp(cur->next->name, name) == 0) {
      pnode_t * t = cur->next;
      cur->next = cur->next->next;
      free(t->name);
      free_node(t);
      return true;
    }//if
    cur = cur->next;
  }// while
  return false;
  }//else
}
bool list_contains(plist_t *list, char * name){
  pnode_t * cur = list->first;
  if (cur == NULL){
    return false;
  }// if
  while(cur != NULL){
    if (strcmp(cur->name, name) == 0) {
     return true;
   }//if
   else{cur = cur->next;}
  }// while
  return false;
}
int list_size(plist_t *list){
  int sz = 0;
  pnode_t * cur = list->first;
  while (cur != NULL) {
    sz = sz + 1;
    cur = cur->next;
  }//while
  return sz;
}
void print_list(plist_t *list){
  pnode_t * cur = list->first;
  while(cur != NULL){
    printf("%s\n", cur->name);
    cur = cur->next;
  }//while
}
void printAsTargetRing (plist_t *list) {
  pnode_t * cur = list->first;
  if (cur == NULL) {
    printf("There are no targets left!\n");
  }//if
  else if(cur->next == NULL){
    printf("%s is the final person remaining!\n", cur->name);
    return;
  }//else if
  else {
    printf("Target Ring:\n");
    while(cur->next!= NULL) {
      printf("%s is stalking %s\n", cur->name, cur->next->name);
      cur = cur->next;
    }//while
    printf("%s is stalking %s\n", cur->name, list->first->name);
    }//else
}
void printAndTagTarget(plist_t *names, plist_t *tagged, char* target){
  if(list_contains(names, target)){
    printf("%s was tagged!\n", target);
    list_remove(names, target);
    list_insert(tagged, target);
  }//if
  else {
    printf("%s is not a target!\n", target);
  }//else
}
void printAsTaggedList (plist_t *names, plist_t *tagged) {
  if (list_size(tagged) == 0){
    printf("No people have been tagged yet\n");
  }//if
  else{
     printf("Tagged List:\n");
     print_list(tagged);
   }//else
  if (list_size(names) > 1) {
    printf("\nThere are %d people left!\n", list_size(names));
  }//if
}


// Ensures that the given buffer can accept additional elements.
char* ensure_capacity(char *buf, int *sz, int pos) {
    if (*sz == pos) {
        // N.B. realloc grows or shrinks its input buffer to the given size,
        // returning an updated pointer to the new buffer.  The elements of the
        // old buffer are copied automatically to the new buffer.
        char *newbuf = (char*) realloc(buf, *sz * GROWTH_FACTOR);
        if (newbuf == NULL) {
            free(buf);
            *sz = 0;
            return NULL;
        } else {
            *sz *= GROWTH_FACTOR;
            return newbuf;
        }
    } else {
        return buf;
    }
}

// Returns a heap-allocated line of input from the user or NULL if the
// allocation fails.  The caller of this function owns the resulting string.
char* fetchline(void) {
    int pos = 0;
    int sz  = INITIAL_SIZE;
    char *name = (char*) malloc(sizeof(char) * sz);
    if (name == NULL) { return NULL; }
    char ch = getchar();
    while (ch != '\n') {
        name = ensure_capacity(name, &sz, pos);
        if (name == NULL) { return NULL; }
        name[pos++] = ch;
        ch = getchar();
    }
    name = ensure_capacity(name, &sz, pos);
    if (name == NULL) { return NULL; }
    name[pos++] = '\0';
    return name;
}
