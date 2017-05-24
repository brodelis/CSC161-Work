# 161.01-project-05
CSC 161 (Spring 2017, Section 01) Project 5: Image Suite
by Elise Brod  	brodelis@grinnell.edu
   Aditi Munshi munshiad@grinnell.edu

Description of outToasterFilter:
This filter is intened to mimic the Instagram filter called "Toaster". It does this by estimating the equations (based on a selection of points) that alter the red, green, and blue values. For the red and green values, this equation could be estimated using one function in the square root family. The blue value, however, required two functions to accurately model. Instead of changing all of the RGB values by a fixed amount, they follow functions.

   -- The red values of the image are modified by the function 8 * r_val^(1/2) + 110
   -- The green values of the image are modified by the function 15 *g_val^(1/2).
   -- If the blue value of the current pixel is less than or equal to 80, then it is modified by the function (b_val/10)^(1/2) + 50.
   -- If the blue value of the current pixel is greater than 80, then it is modified by the function 10 * b_val ^ (1/2) + 50.

Citations:

For the outline to sort:
http://www.cs.grinnell.edu/~klingeti/courses/s2017/csc161/homeworks/05-image-suite.html

Limited help from PM, Titus, and Julia Fay.

soccer-goal.jpg from
http://www.forzagoal.com/forza-pro-soccer-goals/forza-goal-post-12-x-6.html

bumble-bee.jpeg from
https://libraries.io/github/weebygames/jimp

star.jpeg from http://www.bergoiata.org/fe/space6/25.htm

Filter inspiration from http://www.instructables.com/id/How-to-make-Instagram-Filters-in-Photoshop/
