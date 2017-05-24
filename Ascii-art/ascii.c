#include <stdio.h>
#include <stdbool.h>
#define NUM_STEPS 3
/* warm up */
void reverse_triangle (void) { /*DONE */
  for (int i = 0; i < 6; i++) {
    for (int j = 6; j > i; j--) {
      printf("*");
    }
    printf("\n");
  }
}
void pyramid(void) { /*DONE */
  for (int i = 0; i < 6; i++) {
    for (int j = 5; j > i; j--) {
      printf(".");
    }
    for (int k = 0; k < i + 1; k++) {
      if (k == 0) {
        printf("#");
      }
      else { printf("##");
      }
    }
    for (int j = 5; j > i; j--) {
      printf(".");
    }
    printf("\n");
  }
}

void rs_top () {/*DONE */
  for (int i = 0; i < 5; i++) {
    for (int k = 5; k > i; k--){
      printf(" ");
    }
    for (int k = 0; k <= NUM_STEPS; k++){
      printf("  ");
    }
    printf("/");
    for (int j = 0; j < i; j++) {
      printf("/\\");
    }
    printf("\\\n");
  }
}
void rs_center_block () { /*DONE*/
  for (int i = 0; i < 3; i++) {
    if ( i % 2 == 0) {
      printf("-----");
      for ( int j = 1; j < NUM_STEPS; j++) {
        printf("--");
      }/*dashes*/
    }
    else {
      printf(" ");
      for ( int k = 0; k < NUM_STEPS + 1; k++) {
        printf("O ");
      } /* dots */
    }
    printf("| %%    %% |");
    if ( i % 2 == 0) {
      printf("-----");
      for ( int j = 1; j < NUM_STEPS; j++) {
        printf("--");
      }/*dashes*/
    }
    else {
      printf(" ");
      for ( int k = 0; k < NUM_STEPS + 1; k++) {
        printf("O ");
      } /* dots */
    }
    printf("\n");
  }
}

void rs_steps () {
  for (int m = NUM_STEPS, n = NUM_STEPS; m < NUM_STEPS * 2; m++, n--) {
    for (int x = 0; x < 2; x++) {
      for (int k =( 2 * n - x + 5); k > 2 ; k--){
        if ( k % 2 == 0 && x == 0) {
          printf("^");
        }
        else if ( k % 2 == 1 && x == 0) {
          printf("~");
        }
        else if ( k % 2 == 1 && x == 1) {
          printf("~");
        }
        else if ( k % 2 == 0 && x == 1) {
          printf("^");
        }
      } 
      printf("/");
      for (int j = 0; j < (4 + x + 2* (m - NUM_STEPS)); j++) {
        printf("--");
      } 
      printf("\\");
      for (int k = ( 2 * n - x + 5); k > 2; k--){
        if ( k % 2 == 0 && x == 0) {
          printf("^");
        }
        else if ( k % 2 == 1 && x == 0) {
          printf("~");
        }
        else if (k % 2 == 0 && x == 1) {
          printf("~");
        }
        else if (k % 2 == 1 && x == 1) {
          printf("^");
        }
      }
      printf("\n");
    }
    for (int k =( 2 * n + 4); k > 2 ; k--){
      printf(" ");
    }   
    printf("|");
    for (int j = 0 ; j < (5+ 2 * (m - NUM_STEPS)); j++) {
      printf("==");
    }
    printf("|");
    printf("\n");

  }
}
void rs_bottom () {
  /*line1*/
  printf("   /  ");
  for ( int j = 0; j < (5+ 4 * NUM_STEPS); j++) {
    printf(" ");
  }
  printf(" \\  ");  
  printf("\n");
  
  /*line2*/
  printf("  /  ");
  for ( int j = 0; j <(7+ 4 * NUM_STEPS) ; j++) {
    printf("=");
  }
  printf("  \\");   
  printf("\n");

  /* line3 */
  printf(" /  / ");
  for ( int j = 1; j <(6+ 4 * NUM_STEPS) ; j++) {
    printf("\"");
  }
  printf(" \\  \\ ");  
  printf("\n");

  /* line4 */
  printf("|  | ");
  for ( int j = 0; j <(7+ 4 * NUM_STEPS) ; j++) {
    printf("\"");
  }
  printf(" |  |");  
  printf("\n");

  /*line5 */
  printf(" \\  \\ ");
  for ( int j = 1; j < (6+ 4 * NUM_STEPS); j++) {
    printf("\"");
  }
  printf(" /  / ");  
  printf("\n");
  
  /*line6 */
  printf("  \\  ");
  for ( int j = 0; j <(7+ 4 * NUM_STEPS); j++) {
    printf("=");
  }
  printf("  /");   
  printf("\n");
  
  /*line7 */
  printf("   \\  ");
  for ( int j = 1; j < (6+ 4 * NUM_STEPS); j++) {
    printf("_");
  }
  printf(" /  ");  
  printf("\n");
}
void main(void) {
  rs_top ();
  rs_center_block ();
  rs_steps ();
  rs_bottom();
}
