#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <MyroC.h>
/*
Citations: 
For the outline to sort: http://www.cs.grinnell.edu/~klingeti/courses/s2017/csc161/homeworks/05-image-suite.html
Limited help from PM, Titus, and Julia Fay.
 */
int grayColorVal(Pixel pix) {
  int gray_color = (0.30 * pix.R) + (0.59 * pix.G) + (0.11 * pix.B);
  return gray_color;
}
Picture *  circleSelect(Picture* pic, int radius, int x_coord, int y_coord){
  int left_circ = x_coord - radius;
  int right_circ = x_coord + radius;
  int top_circ = y_coord - radius;
  int bottom_circ = y_coord + radius;
  int gray_color;
  //iterate through only to pixels that could potentially be in the circle
  for (int row = top_circ; row < bottom_circ; row++){
    for (int col = left_circ; col < right_circ; col++) {
      // if the pixel is within the circle, color it grey.
      if ((pow((col- x_coord),2) + pow((row - y_coord),2)) <= pow(radius,2)){
        gray_color = (0.30 * pic->pix_array[row][col].R) + (0.59 *pic->pix_array[row][col].G) + (0.11 * pic->pix_array[row][col].B);
        pic->pix_array[row][col].R = gray_color;
        pic->pix_array[row][col].G = gray_color;
        pic->pix_array[row][col].B = gray_color;
      }//end if
    }// for col
    if(row == (bottom_circ - 1)){
      return pic;
    }//end if
  }//for row
}

int middleGray(Picture* pic){
  int gray_values[255] = {0};
  int median_element = (int)((pic->height * pic->width)/2 + 0.5);
  printf("Median element is : %d\n", median_element);
  for (int row = 0; row < pic->height; row++){
    for(int col = 0; col < pic->width; col++){
      gray_values[grayColorVal(pic->pix_array[row][col])] += 1;
    } // for col
  } // for row
  for(int i = 0; i < 255; i++) {
    median_element -= gray_values[i];
    if (median_element <= 0) {
      return i;
    } //end if
  } // for i
}

Picture * tornEdges(Picture* pic){
  int med_gray_val = middleGray(pic);
  for (int row = 0; row < pic->height; row++){

    for(int col = 0; col < pic->width; col++){

      if(grayColorVal(pic->pix_array[row][col]) <= med_gray_val){
        pic->pix_array[row][col].R = 255;
        pic->pix_array[row][col].G = 255;
        pic->pix_array[row][col].B = 255;
      } //end if
      else{
        pic->pix_array[row][col].R = 0;
        pic->pix_array[row][col].G = 0;
        pic->pix_array[row][col].B = 0;
      }//for else
    }//for col
    if(row == (pic->height - 1)){
      return pic;
    }//end if
  }//for row
}

/*
This filter is intened to mimic the Instagram filter called "Toaster". It does this by estimating the equations (based on a selection of points) that alter the red, green, and blue values. For the red and green values, this equation could be estimated using one function in the square root family. The blue value, however, required two functions to accurately model. Instead of changing all of the RGB values by a fixed amount, they follow functions.
*/
Picture * ourToasterFilter(Picture* pic){
  int r_val;
  int g_val;
  int b_val;
  for (int row = 0; row < pic->height; row++){
    for(int col = 0; col < pic->width; col++){
      r_val = pic->pix_array[row][col].R;
      g_val = pic->pix_array[row][col].G;
      b_val = pic->pix_array[row][col].B;
      
      pic->pix_array[row][col].R = (int)( 8 * pow(r_val, 0.5) + 110);
      g_val = pic->pix_array[row][col].G = (int)(15* pow (g_val, 0.5));
      if(b_val <= 80) {
        pic->pix_array[row][col].B = (int)(pow((b_val/10), 0.5) + 50);
      }//end if
      else {
        pic->pix_array[row][col].B = (int)(10 * pow (b_val, 0.5) + 50);
      }//end else
    }//for col
    if(row == (pic->height - 1)){
      return pic;
    }//end if
  }//for row
}
int main(void){
  rConnect("/dev/rfcomm0");

  Picture image1 = rLoadPicture("bumble-bee.jpeg");
  Picture image2 = rLoadPicture("stars.jpeg");
  Picture image3 = rLoadPicture("soccer-goal.jpg");

  /*
  rSavePicture(circleSelect(&image1, 50, 100, 75), "gray-circle-1.jpg");
  rSavePicture(tornEdges(&image2), "torn-edges.jpg");
  rSavePicture(ourToasterFilter(&image3), "toaster-filter.jpg");
  */
  
  rDisplayPicture(&image1, 5, "original-bee");
  rDisplayPicture(circleSelect(&image1, 50, 100, 75), 5, "gray-circle-1");

  rDisplayPicture(&image2, 5, "original-star");
  rDisplayPicture(tornEdges(&image2), 5, "torn-edges");

  rDisplayPicture(&image3, 5, "original-goal");
  rDisplayPicture(ourToasterFilter(&image3), 5, "toaster-filter");
  
  
  rDisconnect();
  return 0;
}
