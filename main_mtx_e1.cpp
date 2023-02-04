#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#ifdef _WIN32
#include <conio.h>
#endif
#include "./Res/lib/BsGraph.h"
#include "./Res/shape_pyramid.c"

Bs_cmd_graph *screen = new Bs_cmd_graph(100,32,35); 

int main(){
Bs_initialize_mtrx();
Bs_translatef_shp(0,0,12);
//Bs_rotatef_shp(0,90,0);
 while(true){
  screen->Bs_cmd_clear();
  
  Bs_transform_shp(&piramid_shp);
  Bs_set_projection(&piramid_shp,13);
  Bs_draw_3dshp(piramid_shp, *screen, 35, 11);
 
 
  screen->Bs_draw_line(0, 0,99, 0,35);
  screen->Bs_draw_line(0,31,99,31,35);
  screen->Bs_draw_line( 0,0, 0,99,35);
  screen->Bs_draw_line(99,0,99,99,35);
 
  screen->Bs_draw_text(1,1,"3D ASCII ENGINE BY: CHOCOBONIS (c) 2020");

  screen->Bs_cmd_draw();
  
  #ifdef linux
   system ("/bin/stty raw");
   key=getchar();
   system ("/bin/stty cooked");
  #endif
  #ifdef _WIN32
   key = _getch();
  #endif 
  
  switch(key){
   case '.':return 1;break; // abort key is always .
   case 's':Bs_translatef_shp(0,0,2);break;
   case 'd':Bs_translatef_shp(2,0,0);break;
   case 'w':Bs_translatef_shp(0,0,-2);break;
   case 'a':Bs_translatef_shp(-2,0,0);break;
   
   case 'e':Bs_translatef_shp(0,2,0);break;
   case 'q':Bs_translatef_shp(0,-2,0);break;
   
   case 'i':Bs_rotatef_shp(0,1,0);break;
   case 'k':Bs_rotatef_shp(0,1,0);break;
   case 'j':Bs_rotatef_shp(15,0,0);break;
   case 'l':Bs_rotatef_shp(-15,0,0);break;
   
  }
 }
 return 0;
}
