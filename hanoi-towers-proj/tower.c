#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "mstack.h"

typedef mstack_t tower_t;

typedef struct hanoi{
  tower_t *tower1;
  tower_t *tower2;
  tower_t *tower3;
  int moves;
}hanoi_t;

tower_t* make_tower(){
  return make_mstack();
}
void free_tower(tower_t* tower){
  free_mstack(tower);
}

hanoi_t* make_hanoi(){
  hanoi_t* hanoi = (hanoi_t*) malloc(sizeof(hanoi_t));
  tower_t *tower1 = make_tower();
  tower_t *tower2 = make_tower();
  tower_t *tower3 = make_tower();
  int moves = 0;
  for (int i = 5; i > 0 ; i--){
    mstack_push(tower1, i);
  }
  hanoi->tower1 = tower1;
  hanoi->tower2 = tower2;
  hanoi->tower3 = tower3;
  hanoi->moves = moves;
  return hanoi;
}

void free_hanoi(hanoi_t* game){
  free_tower(game->tower1);
  free_tower(game->tower2);
  free_tower(game->tower3);
  free(game);
}

void move_disk(tower_t *src, tower_t *dest){
  mstack_push(dest, mstack_pop(src));
}

//in game play, check that src != tower1
bool is_complete_tower(tower_t *src){
  if(mstack_size(src) == 5){
    return true;
  }
  return false;
}

bool has_valid_move (tower_t *src, tower_t *dest){
  if(mstack_size(dest) == 0){
    return true;
  }
  else if (list_get(src , 0) < list_get(dest, 0)){
    return true;
  }
  return false;
}

void print_disk(int disk){
  //printing the spaces
  for(int j = 0; j < (5 - disk); j++){
      printf("%s", " ");
  }
  //printing the first half of the disk
  for(int i = 0; i < disk; i++){
    printf("%s", "-");
  }
  //printing the rod
  printf("%s", "|");
  //printing the second half of the disk
  for(int k = 0; k < disk; k++){
    printf("%s", "-");
  }
  printf("%s", "\n");
}

void print_tower(tower_t *t, int id){
  //printing title
  printf("Tower %d:\n", id);
  int floor = mstack_size(t) - 4;
  //printing the tower body
  while (floor <= 0){
    print_disk(0);
    floor++;
  }//while
  for(int i = 0; i < mstack_size(t); i++){
    print_disk(list_get(t, i));
    //print disk withthe contents of the ith element of thelist
  }//for

  //printing the base
  for (int i = 0; i < 11; i++){
    printf("%s", "=");
  }//for
  printf("\n");
}

void print_hanoi(hanoi_t *game){
  printf("Move: %d\n", game->moves);
  print_tower(game->tower1, 1);
  print_tower(game->tower2, 2);
  print_tower(game->tower3, 3);
}
void print_instructions(){
  printf("The goal of the puzzle is to move all of the disks from the first rod to the third rod subject to the following constraints:\n");
  printf("1. In a single step, you may move a single disk found on the top of one of the stacks by placing it on top of another stack.\n");
  printf("2.You may not move a larger disk on top of a smaller disk.\n"); 
}

int main(void){
  hanoi_t *game = make_hanoi();
  int source = 0;
  int dest = 0;
  tower_t *src = game->tower1;
  tower_t *dst = game->tower2;
  
  print_instructions();
  print_hanoi(game);
  
  while((is_complete_tower(game->tower2)==0) && (is_complete_tower(game->tower3)==0)){
    printf("Enter a source tower: ");
    scanf("%d", &source);
    printf("Enter a destination tower: ");
    scanf("%d", &dest);

    while ((source > 3) || (dest > 3)||(source < 1) || (dest < 1)){
      printf("Please enter a number between 1 and 3 for source and destination tower. Note: On the first round, the source tower must be 1\n");
     
      printf("Enter a source tower: ");
      scanf("%d", &source);
      printf("Enter a destination tower: ");
      scanf("%d", &dest);
    }


    //at this point, source and dest are valid inputs.
    if(source == 1){
      src = game->tower1;
    }//if
    else if(source == 2){
      src = game->tower2;
    }//else if
    else if(source == 3){
      src = game->tower3;
    }//else if
    if(dest == 1){
      dst = game->tower1;
    }//if
    else if(dest == 2){
      dst = game->tower2;
    }//else if
    else if(dest == 3){
      dst = game->tower3;
    }//else if
    
    if (has_valid_move(src, dst)){
      move_disk(src, dst);
      game->moves +=1;
    }//if
    else {
      printf("This is not a valid move. Remember, you can only stack smaller disks on top of larger disks.\n");      
      }//else
    
    print_hanoi(game);
  }
    printf("You won the game in %d steps!\n", game->moves);
    free_hanoi(game);
    return 0;
}


