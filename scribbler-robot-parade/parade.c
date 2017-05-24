#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MyroC.h>
#include <stdbool.h>
#include <string.h>
#include "parade.h"



//main controls the parade
int main(int argc, char **argv){
  printf("argc: %d\n", argc);
  bool log = false;
  FILE *log_file;
   FILE *script_file;
  if(argc == 4 &&
     strcmp(argv[1], "-log") == 0){
    log = true;
    log_file = fopen(argv[2], "w");
        if (script_file == NULL){
      printf("Next time, try a valid .txt file.\n");
        }//end if
  }//end if
  else if (argc != 2 && argc != 4 ){
    printf("parade needs a <scriptfile> argument.\n");
    return 1;
  }//end else
  if(argc == 2){
    script_file = fopen(argv[1], "r");
    if (script_file == NULL){
      printf("Next time, try a valid .txt file.\n");
      return 1;
    }//end if
  }//end if
  else {
    script_file = fopen(argv[3], "r");
        if (script_file == NULL){
      printf("Next time, try a valid .txt file.\n");
    }
  }

  rConnect("/dev/rfcomm0");
  printf("Press enter to start getting in line (moving forward).\n");
  wait_for_key_press();
  printf("Press enter to stop moving forward\n");
  moving_forward();
  wait_for_key_press();
  rHardStop();

  if(log){
    perform_and_log_file(script_file, log_file);
  }else{
    perform_file(script_file);
  }                    
  rDisconnect();
  
  if(log == true){
    fclose(log_file);
  }
  fclose(script_file);
  return 0;
}

