#include <stdio.h>
#include <MyroC.h>

int main(void){
  rConnect("/dev/rfcomm0");

    Picture kitten = rLoadPicture("home/munshiad/Desktop/boosted-kitten.jpg");
    printf("height: %d\n width:%d\n", kitten.height, kitten.width);
    rDisplayPicture(&kitten, 5, "Picture 1");
  
    /* rConnect("/dev/rfcomm0");
  Picture kitten = rTakePicture();
  // Picture kitten1 = circleSelect(&kitten, 100, 200, 150);
  // Picture kitten2 = tornEdges(&kitten);
  rDisplayPicture(&kitten, 5, "Kitten1");
  //void rDisplayPicture(&kitten2, 5, "Kitten2");
  */
  rDisconnect();
  return 0;
}
