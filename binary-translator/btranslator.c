#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <sys/stat.h> 

// The following three functions print arrays, to be used after the arrays are populated.
void printHexArray (char arr[2])
{
  printf("[");
  for(int i = 0; i < 2; i++) {

    printf("%c ", arr[i]);
  }
  printf("]\n");
}

void printBinArray (char arr[8])
{
  printf("[");
  for(int i = 0; i < 8; i++) {
    printf("%c ", arr[i]);
  }
  printf("]\n");
}
void printPermArray (char arr[9])
{
  printf("[");
  for(int i = 0; i < 9; i++) {
    printf("%c ", arr[i]);
  }
  printf("]\n");
}
// This power function was taken from stack overflow, by user ephemient. This made more sense to me than using doubles and changing back to integers, since we never want doubles. http://stackoverflow.com/questions/213042/how-do-you-do-exponentiation-in-c
int power(int base, unsigned int exp)
{
  int i, result = 1;
  for (i = 0; i < exp; i++)
    {
      result *= base;
    }
  return result;
}
// Binary Translator functions
unsigned char  binaryStringToValue(char digits [8])
{
  unsigned char ret = 0;
  
  for (int i = 0; i < 8; i++)
    {
      if (digits[i] == '1')
        {
          ret += power(2, (7 - i));
        }
    }
  return ret;
}

void writeValueAsBinaryString(unsigned char val, char digits[8])
{
  for (int i = 0; i < 8; i++)
    {
      if (val > (power(2, 7 - i) - 1))
        {
          digits[i] = '1';
          val -= power(2, 7 - i);
        }
      else
        {
          digits[i] = '0';
        }
    }
}

// Hex translator functions

// Note: hexStringToValue assumes that you are using lowercase letters. For example, in order to get 160 you need to write a0.
unsigned char hexStringToValue(char digits[2])
{
  unsigned char ret = 0;
  
  for (int i = 0; i < 2; i++)
    {
      // This checks to see if digits[i] is a number.
      if (digits[i] > 47 && digits[i] < 58)
        {
          ret += (digits[i]- '0') * power(16, (1 - i));
        }
      // This case is for when digits[i] is a lowercase letter
      else
        {
          ret+= (digits[i] - 87) * power(16, (1 - i));
        }
    }
  return ret; 
}


void writeValueAsHexString(unsigned char val, char digits[2])
{
  for (int i = 0; i < 2; i++)
    {
      //if the char is going to be a letter
      if (val >= 160 - (150 * i))
        {
          // then make the ith element a letter, and subtract the net value of that letter from val.
          digits[i] = ((val % 160)/(power(16, (1 - i))))%10 + 'a';
          val -= (digits[i] - 87) * power(16, (1 - i));
        }
      //if the char is going to be a number
      else
        {
          //then make the ith element a number, and subtract the net value of that number from val.
          digits[i] = ((val % 160)/(power(16, (1 - i))))%10 + '0';
          val -= (digits[i] - '0') * power(16, (1 - i));
        }
    }
}
void writePermissionString(int perms, char str[9])
{
  //This statement is here in case you give a number larger than 511. This way you will only use the last 9 digits.
  int val = perms & 511;
  for(int i = 0; i < 9; i++)
    {
      //This checks to see if each element should be a letter.
      if(val >= power(2, (8-i)))
        {
          //Which letter should it be? Depends on it's position.
          if(i % 3 == 0)
            {
              str[i] = 'r';
            }
          else if(i % 3 == 1)
            {
              str[i] = 'w';
            }
          else if (i % 3 == 2)
            {
              str[i] = 'x';
            }
          val -= power(2, (8-i));
        }
      // If it isn't a letter, it should be a - 
      else
        {
          str[i] = '-';
        }
    }
}
int generatePermissionBits(char str[9])
{
  // This is a retaining value, being added to based on str.
  int ret = 0;
  for (int i = 0; i < 9; i++)
    {
      // If str[i] is a letter, add to ret.
      if (str[i] == 'r' || str[i] =='w' || str[i] =='x')
        {
          ret += power(2, (8-i));
        }
    }
  return ret;
}
void main (void)
{
  char* bin1 = "01000011";
  char* bin2 = "11011011";
  char* bin3 = "00000011";

  int val1 = 10;
  int val2 = 116;
  int val3 = 37;
  
  char* hex1 = "af";
  char* hex2 = "b8";
  char* hex3 = "3c";

  int hval1 = 200;
  int hval2 = 35;
  int hval3 = 107;
  
  char* perm1 = "rwxr-xr-x";
  char* perm2 = "-w-rw--w-";
  char* perm3 = "r-x--x--x";
  
  int perms1 = 0755;
  int perms2 = 0664;
  int perms3 = 13;
      
  char binEmpty[8];
  char hexEmpty[2];
  char permEmpty[9];
  
  //Binary Tests
  printf("\n\n\n BINARY TESTS\n");
   
  printf("Testing binaryStringToValue\n");
  printf("Converting %s to decimal: %u \n", bin1, binaryStringToValue(bin1));
  printf("Converting %s to decimal: %u \n", bin2, binaryStringToValue(bin2));
  printf("Converting %s to decimal: %u \n", bin3, binaryStringToValue(bin3));

  printf("First test of writeValueAsBinaryString\n"); 
  writeValueAsBinaryString(val1, binEmpty);
  printBinArray(binEmpty);

  printf("Second test of writeValueAsBinaryString\n"); 
  writeValueAsBinaryString(val2, binEmpty);
  printBinArray(binEmpty);
 
  printf("Third test of writeValueAsBinaryString\n"); 
  writeValueAsBinaryString(val3, binEmpty);
  printBinArray(binEmpty);

  

  // Hex Tests
  printf("\n\n\n HEX TESTS\n");
  
  printf("Testing hexStringToValue\n");
  printf("Converting %s to decimal: %u \n", hex1, hexStringToValue(hex1));
  printf("Converting %s to decimal: %u \n", hex2, hexStringToValue(hex2));
  printf("Converting %s to decimal: %u \n", hex3, hexStringToValue(hex3));


  printf("First test of writeValueAsHexString\n"); 
  writeValueAsHexString(hval1, hexEmpty);
  printHexArray(hexEmpty);

  printf("Second test of writeValueAsHexString\n"); 
  writeValueAsHexString(hval2, hexEmpty);
  printHexArray(hexEmpty);
 
  printf("Third test of writeValueAsHexString\n"); 
  writeValueAsHexString(hval3, hexEmpty);
  printHexArray(hexEmpty);


 
  //Permission String Tests
  printf("\n\n\n PERMISSION STRING TESTS\n");
  
  printf("First test of writePermissionString\n");
  writePermissionString(perms1, permEmpty);
  printPermArray(permEmpty);
  
  printf("Second test of writePermissionString\n");
  writePermissionString(perms2, permEmpty);
  printPermArray(permEmpty);

  printf("Third test of writePermissionString\n"); 
  writePermissionString(perms3, permEmpty);
  printPermArray(permEmpty);  

  printf("Testing generatePermissionBits\n");
  printf("Calculating permission bits for %s. The corresponding integer is %d \n", perm1, generatePermissionBits(perm1));
  printf("Calculating permission bits for %s. The corresponding integer is %d \n", perm2, generatePermissionBits(perm2));
  printf("Calculating permission bits for %s. The corresponding integer is %d \n", perm3, generatePermissionBits(perm3));

}
