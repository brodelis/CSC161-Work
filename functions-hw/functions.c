#include <stdio.h>
void slash (int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j<i + 1; j++) {
        printf(" ");
    }
    printf("\\*\\");
    printf("\n");
  }
}
void num_square(int n, int m) {
  int a [ m - n + 1 ];
  int i,j,k,w;
  for (i = n; i < m +1; i++) {
    a[i-n] = i;
  }
  for (k = 0; k < m - n + 1; k ++) {
    for (j = 0; j < m - n + 1; j++) {
      int index = (k + j) % (m - n + 1);
      printf("%d", a[index]) ;
    }
    printf("\n");
  }
}

int calculate_whole (int amount, int denom) {
  return (amount/denom);
}
int calculate_remainder(int amount, int denom) {
  return (amount%denom);
}
void make_change(int amount){
  int i = amount;
  printf("Change for %d is: \n", i);
  printf("dollars  = %d\n", calculate_whole(i, 100));
  i = calculate_remainder(i, 100);
  printf("quarters = %d\n", calculate_whole(i, 25));
  i = calculate_remainder(i, 25);  
  printf("dimes    = %d\n", calculate_whole(i, 10));
  i = calculate_remainder(i, 10);
  printf("nickels  = %d\n", calculate_whole(i, 5));  
  printf("cents    = %d\n", calculate_remainder(amount,5));
}
int main (void) {
  slash(3);
  slash(5);
  num_square(4, 9);
  num_square(3, 7);
  make_change(157);
  make_change(141);
  return 0;
}
