#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#ifdef _WIN32
#include <conio.h>
#endif
#include "./Res/lib/BsGraph.h"
#include "./Res/images.c"

std::string pressed = "null";

void ammo_func(){pressed = "AMMO";}
void hlth_func(){pressed = "HEALTH";}
void armo_func(){pressed = "ARMOR";}
void invt_func(){pressed = "INVENTORY";}
 
Bs_cmd_graph *screen = new Bs_cmd_graph(70,22,2588); 
Bs_cmd_button *button1 = new Bs_cmd_button(1,18,1,32);
Bs_cmd_button *button2 = new Bs_cmd_button(16,18,2,34);
Bs_cmd_button *button3 = new Bs_cmd_button(32,18,3,36);
Bs_cmd_button *button4 = new Bs_cmd_button(48,18,4,33);
Bs_mouse_pointer *mouse = new Bs_mouse_pointer(35,11,97);
 int main(){
  	float px = 25; float py = 25; float pa = 270;
 	char c;
 	//char key = ' ';
 	while(1){
 	screen->Bs_cmd_clear();
 	 screen->Bs_draw_text(1,1,"3D ASCII ENGINE BY: CHOCOBONIS (c) 2020");
 	 
 	//screen->Bs_draw_line(0,12,69,12,32);  // draw floor
 	std::cout<<"BUTTON PRESSED TEST: "<<pressed<<std::endl;
 	// square in middle of screen	 
 	
 	 draw_wall(*screen, px, py, pa, 5,5,15,5, 31);
 	 draw_wall(*screen, px, py, pa, 5,5,5,15, 32);
 	 draw_wall(*screen, px, py, pa, 5,15,15,15, 33);
 	 draw_wall(*screen, px, py, pa, 15,15,15,5, 34);
 	 
 	 draw_wall(*screen, px, py, pa, 30, 5,40,5, 31);
 	 draw_wall(*screen, px, py, pa, 30, 5,30,15, 32);
 	 draw_wall(*screen, px, py, pa, 30,15,40,15, 33);
 	 draw_wall(*screen, px, py, pa, 40,15,40,5, 34);
 	
 	 
 	 screen->Bs_draw_line(0, 0,69, 0,35);
 	 screen->Bs_draw_line(0,21,69,21,35);
 	 screen->Bs_draw_line( 0,0, 0,69,35);
 	 screen->Bs_draw_line(69,0,69,69,35);
 	 
 	 screen->Bs_draw_imgA(weapon,39,8);
 	
 	 screen->Bs_draw_line(1,17,69,17,34);
 	 
 	 button1->Bs_draw_button(*screen, "[   AMMO    ]");
 	 button1->Bs_add_id();
 	 button2->Bs_draw_button(*screen, "[   HEALTH    ]");
 	 button2->Bs_add_id();
 	 button3->Bs_draw_button(*screen, "[   ARMOR    ]");
 	 button3->Bs_add_id();
 	 button4->Bs_draw_button(*screen, "[    INVENTORY    ]");
 	 button4->Bs_add_id();
 	 
 	 display_direction(*screen,1,2,pa);
 	 mouse->Bs_mouse_draw(*screen);
 	 //std::cout<<"facing "<<pa<<std::endl;
 	screen->Bs_cmd_draw();
 	#ifdef linux
 	   system ("/bin/stty raw");
    	   key=getchar();
 	   system ("/bin/stty cooked");
 	#endif
 	#ifdef _WIN32
 	 key = _getch();
 	#endif 
 	   usleep(300);
 	 button1->onClick(mouse->x,mouse->y,ammo_func);
 	 button2->onClick(mouse->x,mouse->y,hlth_func);
 	 button3->onClick(mouse->x,mouse->y,armo_func);
 	 button4->onClick(mouse->x,mouse->y,invt_func);
 	 mouse->Bs_mouse_controller();
 	 switch(key){
 	  case 'w':px = px + cos((3.14159*pa)/180);py = py + sin((pa*3.14159)/180);break;
 	  case 'd':if(pa > 350){pa = 0;}else{pa+=10;}break;
 	  case 's':px = px - cos((3.14159*pa)/180);py = py - sin((pa*3.14159)/180);break;
 	  case 'a':if(pa < 0){pa = 350;}else{pa-=10;}break;
 	  case 'x':px = px + cos((3.14159*(pa+90))/180);py = py + sin(((pa+90)*3.14159)/180);break;
 	  case 'z':px = px - cos((3.14159*(pa+90))/180);py = py - sin(((pa+90)*3.14159)/180);break;
 	  case 'r':px = 25; py = 25; pa = 270; break;
 	  case '.':return 0;break;
 	 }
 	}
 	
 return 0;
 } 
