 
//small respond stage 1  the 'y' etc ...'z' !it doesn't write 'z'!!

#include <allegro.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
BITMAP *buffer;
BITMAP *buffer_title;
char squares_1[][17]={"mmsssmssssmsssmm",
		      "mmsssmmmmmmsssmm",
		      "ssssssssssssssss",
		      "ssssszzzzzzsssss",
		      "ssssszzzzzzsssss",
		      "bbbbbbbbbbbbbbbb"};
char squares_2[11][6][17]={"mmsssmssssmsssmm",
			  "mmsssmmmmmmsssmm",
			  "ssssssssssssssss",
			  "ssssszzzzzzsssss",
			  "ssssszzzzzzsssss",
			  "bbbbbbbbbbbbbbbb",


			"bbsssmssssmsssbb",
			"mmsssmmmmmmsssmm",
			"mmmmmmmmmmmmmmmm",
			"ssssszzzzzzsssss",
			"ssssszzzzzzsssss",
			"bbbbbbzzzzbbbbbb",

			"mmsssmssssmsssmm",
			"mmsssmmmmmmsssmm",
			"bsbsbsbsbsbsbsbs",
			"ssssszzmzzzsssss",
			"ssssszmmmzzsssss",
			"ssssssssssssssss",


			"bbbbbmmmmmbbbbbb",
			"bbbbbbmmmbbbbbbb",
			"ssbbbbbmbbbbbsss",
			"ssssbbbbbbbsssss",
			"ssssszbbbzzsssss",
			  "bbbbbbbbbbbbbbbb",

			  "zzzbbmzzzmbbbzzz",
			  "bbbbbbmzmbbbbbbb",
			  "ssbbbbbmbbbbbsss",
			  "zsssbbbbbbbssssz",
			  "zzssszbbbzzssszz",
			  "zzzsssssssssbzzz",

			  "bbbbbmmmmmbbbbbb",
			  "bbbbbbmmmbbbbbbb",
			  "ssbbbbbzzbbbbsss",
			  "ssssbzzzzzzsssss",
			  "sssszzzzzzzzssss",
			  "bbbzzzzzzzzzzbbb",

			  "bzzzzzzzzzzzzzzz",
			  "bbzzzzzzzzzzzzzz",
			  "ssbzzzzzzzzzzzzz",
			  "sssbzzzzzzzzzzzz",
			  "ssssbzzzzzzzzzzz",
			  "sssssbbbbbbbbbbb",

			  "bbbbbmmmmmbbbbbb",
			  "bbbbbbmmmbbbbbbb",
			  "ssbbbbbmbbbbbsss",
			  "ssssbbbbbbbsssss",
			  "ssssszbbbzzsssss",
			  "bbbbbbbbbbbbbbbb",

			  "bbbbbmmmmmbbbbbb",
			  "bbbbbbmmmbbbbbbb",
			  "ssbbbbbmbbbbbsss",
			  "ssssbbbbbbbsssss",
			  "ssssszbbbzzsssss",
			  "bbbbbbbbbbbbbbbb",

			  "bbbbbmmmmmbbbbbb",
			  "bbbbbbmmmbbbbbbb",
			  "ssbbbbbmbbbbbsss",
			  "ssssbbbbbbbsssss",
			  "ssssszbbbzzsssss",
			  "bbbbbbbbbbbbbbbb",

			  "bbbbbmmmmmbbbbbb",
			  "bbbbbbmmmbbbbbbb",
			"ssbbbbbmbbbbbsss",
			  "ssssbbbbbbbsssss",
			  "ssssszbbbzzsssss",
			  "bbbbbbbbbbbbbbbb"


};

char array_lives_3[][11]={"zzbbbbbzzz",
			"zbzzzzzbzz",
			"zzzzzzzzbz",
			"zzzzzzbbzz",
			"zzzzbbbzzz",
			"zzzzzzbbzz",
			"zzzzzzzzbz",
			"zbzzzzzzzb",
			"zzbbzzzzbz",
			"zzzbbbbbzz"};

char array_lives_2[][11]={"zzzbbbzzzz",
			  "zbbzzzbbzz",
			  "bzzzzzzzbz",
			  "zzzzzzzbzz",
			  "zzzzzzbzzz",
			  "zzzzzbzzzz",
			  "zzzzbzzzzz",
			  "zzzbzzzzzz",
			  "zbbzzzzzbb",
			  "bbbbbbbbzz"};
char array_lives_1[][11]={"zzzzzbbzzz",
			  "zzzzbzbzzz",
			  "zzzbzzbzzz",
			  "zzzzzzbzzz",
			  "zzzzzzbzzz",
			  "zzzzzzbzzz",
			  "zzzzzzbzzz",
			  "zzzzzzbzzz",
			  "zzzzzzbzzz",
			  "zzzbbbbbbz"};
char array_lives_0[][11]={"zzzzbbbzzz",
			  "zzbbzzzbzz",
			  "zbbzzzzzbz",
			  "bbzzzzzzbb",
			  "bzzzzzzzzb",
			  "bzzzzzzzzb",
			  "bzzzzzzzbz",
			  "zbbzzzzbbz",
			  "zzbbzzbbzz",
			  "zzzbbbbzzz"};

char arkanos[][71]={"zzz.zzzzzzzz...zzzzzzzzzzzzzzzzzzz.zzzzzz..zzzzzz.zzzz...zzzzzzz.....z",
		    "zz.zz.zzzz.zzzzz.zz.zzzz.zzzzzzzz.z.zzzzz.z.zzzzz.z.z.zzz.zzzz.zzzzzz.",
		    "zz.zz.zzzz.zzzzz.zz.zzz.zzzzzzzz.zzz.zzzz.zz.zzzz.z.zzzzzz.zzz.zzzzzzz",
		    "z.zzzz.zzz.zzzzz.zz.z.zzzzzzzzz.zzzzz.zzz.zzz.zzz.z.zzzzzzz.zz.zzzzzzz",
		    ".zzzzz.zzz.zzzz.zzz..zzzzzzzzz.zzzzzzz.zz.zzzz.zz.z.zzzzzzz.zzz...zzzz",
		    "........zz......zzz..zzzzzzzzz........z.z.zzzz.zz.z.zzzzzzz.zzzzzz..zz",
		    ".zzzzzzz.z.z.zzzzzz.z.zzzzzzzz.zzzzzzzz.z.zzzzz.z.z.zzzzzzz.zzzzzzzz.z",
		    ".zzzzzzz.z.zz.zzzzz.zz.zzzzzzz.zzzzzzzz.z.zzzzz.z.zz.zzzzzz.zzzzzzzzz.",
		    ".zzzzzzz.z.zzz.zzzz.zzz.zzzzzz.zzzzzzzz.z.zzzzzz..zzz.zzz..zz.zzzzzzz.",
		    ".zzzzzzz.z.zzzz.zzz.zzzz.zzzzz.zzzzzzzz.z.zzzzzzz.zzzz...zzzzzz......z"};


int number_hits[][17]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

class ball
{


public:

  int dead;
  int x,y,direction;
  void print_ball();
  ball();
  
};


class shot
{
protected:
  int x[10];//we reserve enough memory for ten bullets at the same time... more than enough
  int y[10];
  int  number_bullets;  
  int index_bullet;
  
  
  void new_shot();
public:
  shot()
  {
    number_bullets=0;index_bullet=0;
    for(int i=0;i<10;i++)
      {
	x[i]=1000;
	y[i]=0;
      }
  }

  void shoot(bool);
  void compareWithBricks();
  

};
//int shot::number_bullets=0;
class proyectile:public shot
{
public:
  void figure_bullet(int n){circlefill(buffer,x[n],y[n],5,makecol(0,255,0));}
};


ball::ball()
{
 
  srand(time(NULL));
  int r=rand() % 100;
  if(r>50)
    {
      direction=1;
      x=50+rand() % 300;
    }
  else 
    {
      direction=4;
      x=400+ rand() % 400;
    }
  
  y=400;
  dead=0;
}
class stick
{

  bool going_up;
public:
  int x,y,bouncing; 
  stick(){x=350;y=460;bouncing=0;going_up=true;}
  void print_stick();

};

class bricks
{
protected:
 
  char type;
  int hits;

public:
  int x,y; 
  int stage;//from 10 to 0 if 'b'; from 20 to 11 if 'm';  from 30 to 21 if 's';
  int fire_stage;
  void coordenates_bricks();//set the coordenates in pixels of every brick  CONSTRUCTOR
  virtual  void respond()=0;//how the brick responds when hit.
  void restore_to_first(int);
  bool check_zeros();

};

class BetterBricks:public bricks
{
public:

};

class big:public bricks
{
public:
  void respond();
};
class small:public bricks
{
  int y_effect;
  int y_aux;
  
public:
  small(){y_effect=0;}
  void respond();
};

class medium:public bricks
{
  int x_effect,y_effect;
public:
  void respond();

};
class zero:public bricks
{

public:
  void respond(){};

};
class screens
{

public:
  static int number_screen;
  void print_squares();

};
int screens::number_screen=0;

class writes
{
  int room;

public:
  
virtual  void infor_screen()=0;
};

class lives:public writes
{


public:
  int n_lives;
  void infor_screen();
  lives(){n_lives=3;}
};

class ark:public writes
{//presentation screen
  bool going_away;
  bool gone;
  int color;
  int x1,x2;
public:
  ark(){going_away=false;gone=false;x1=-450;x2=550;color=255;}
  void infor_screen();

};
class room:public writes
{
 
public:
 int n_room;
  room(){n_room=0;}
  void infor_screen(){};
};


ball balloon;
stick my_stick;
screens main_screen;
big b_bricks[6][17];
small s_bricks[6][17];
medium m_bricks[6][17];
zero z_bricks[6][17];

lives print_lives;
ark titles;

bool game;
writes * print_live_base;
writes * print_title;
room number_room;
shot *shooter;
proyectile bullet;

void coord_stick();
void coord_ball();
void check_hit_brick();
void check_hit_stick();
void coord_brick();
int main()
{
  allegro_init();
  install_timer();
  install_keyboard();

  //  if(install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL ))return 0;
 set_volume(255, 255);

  set_color_depth(16);
  set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,1200,600,0,0);
  
  buffer=create_bitmap(800,500);//On this buffer we will put the ball, squares and stick
  buffer_title=create_bitmap(800,200);
  clear_to_color(buffer,makecol(255,0,255));
  clear_to_color(buffer_title,makecol(255,0,255));

  MIDI * hh;
  hh=load_midi("/home/pepe/Video_Game_Themes_-_Final_Fantasy_7.mid");
  play_midi(hh,false);
  

  print_live_base=&print_lives; 
  print_title=&titles;

  shooter=&bullet;

  //bricks *coordenates;
    BetterBricks *coordenates;
  coordenates->coordenates_bricks();
   main_screen.print_squares();
   game=false;

    //Variables you will need
COLOR_MAP transtable;
PALETTE pal;
//After you have set your screen up
get_palette(pal);
create_light_table(&transtable, pal, 10, 10, 60, NULL);
//Then you can use any one of the blenders that you might want.
set_screen_blender(0, 0, 0, 255);
//Now you can draw a transparent sprite
//draw_trans_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y);
   


   while(!key[KEY_ESC] && print_lives.n_lives>-1)
    {
      if((key[KEY_RIGHT] || key[KEY_LEFT]) && game==false)
	{
	  game=true;
	 balloon. dead=100;
	}
      clear_bitmap(buffer);
      //   clear_bitmap(buffer_title);
      clear_to_color(buffer_title,makecol(255,0,255));
      coord_stick();
     
      coord_brick();
      if(game)
	{
	  coord_ball();
	  check_hit_brick();
	  check_hit_stick();
	  shooter->shoot(false);
	  shooter->compareWithBricks();
	  if(key[KEY_UP])shooter->shoot(true);
	  
	}
      print_title->infor_screen();
      print_live_base->infor_screen();

      //      if(print_lives.n_lives<0)balloon.dead=300;


            if(print_lives.n_lives<0)
	      // if(balloon.dead==150)
	{
	  sleep(1);
	  balloon.dead=300;
	 
	  number_room.n_room=0;
	  coordenates->restore_to_first(0);
	  print_lives.n_lives=3;
	
	  
	}


      if(coordenates->check_zeros())//next screen (stage)
	{
	  sleep(1);
	  balloon.y=400;
	  number_room.n_room++;
	  balloon.dead=300;
	  coordenates->restore_to_first(number_room.n_room);
	  if(print_lives.n_lives<3)	  print_lives.n_lives+=2;
	  if(print_lives.n_lives>3)print_lives.n_lives=3;
	}
      //      draw_trans_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y);
            draw_trans_sprite(buffer,buffer_title,0,200);
      draw_sprite(screen,buffer,200,50);


    }

  allegro_exit();
  
  return 0;
}
END_OF_MAIN()
void coord_stick()
{
  my_stick.print_stick();




}
void coord_ball()
{

balloon.print_ball();

}

void check_hit_brick()
{


  for(int y=0;y<6;y++)
    {

      for(int x=0;x<16;x++)
	{

	  if(squares_1[y][x]=='b') b_bricks[y][x].respond();
	  else if(squares_1[y][x]=='s')s_bricks[y][x].respond();
	  else if(squares_1[y][x]=='m')m_bricks[y][x].respond();
	  else if(squares_1[y][x]=='z')z_bricks[y][x].respond();

	}



    }

  if(balloon.x>790)
    {
      switch(balloon.direction)
	{
	case 1:
	  balloon.direction=4;
	  break;
	case 2:
	  balloon.direction=3;
	  break;
	}

    }
  if(balloon.x<10)
    {
      switch(balloon.direction)
	{
	case 3:
	  balloon.direction=2;
	  break;
	case 4:
	  balloon.direction=1;
	  break;

	}

    }

  if(balloon.y<10)
    {
      switch(balloon.direction)
	{
	case 1:
	  balloon.direction=2;
	  break;
	case 4:
	  balloon.direction=3;
	  break;
	}
    }

  if(balloon.y>480)
    {
      usleep(100000);
      print_lives.n_lives--;
      balloon.y=480;
      switch(balloon.direction)
	{
	case 2:
	  balloon.direction=1;
	  break;
	case 3:
	  balloon.direction=4;
	  break;



	}



    }

}

void check_hit_stick()
{

  //  if(balloon.y>460-10 && balloon.y<460-6 && (balloon.x>my_stick.x-10 && balloon.x<(my_stick.x+110)))
  if(balloon.y>my_stick.y-10 && balloon.y<my_stick.y && (balloon.x>my_stick.x-10 && balloon.x<(my_stick.x+110)))
    {
      my_stick.bouncing=4;
      switch(balloon.direction)
	{
	case 2:
	  balloon.direction=1;

	  break;
	case 3:
	  balloon.direction=4;

	  break;


	}


    }






}

void screens::print_squares()
{

  //  int x=0,y=0;//these are the index of the array
  char square;
  int coord_x=120;//320-200
  int coord_y=80-40;//130-50

  for(int x=180;x<1020;x+=20)
    {
      rectfill(screen,x,29,x+20,49,makecol(150,0,0));
      circlefill(screen,x+10,39,10,makecol(200,0,0));
    }
  for(int x=180;x<1020;x+=20)
    {
      rectfill(screen,x,550,x+20,551+20,makecol(150,0,0));
      circlefill(screen,x+10,551+10,10,makecol(200,0,0));

    }  

for(int y=50;y<550;y+=20)
    {
      rectfill(screen,1000,y,1000+20,y+20,makecol(150,0,0));
      circlefill(screen,1010,y+10,10,makecol(200,0,0));
    }
  for(int y=50;y<550;y+=20)
    {
      rectfill(screen,180,y,180+20,y+20,makecol(150,0,0));
      circlefill(screen,180+10,y+10,10,makecol(200,0,0));
    }
  for(int y=0;y<6;y++)
    {

      coord_x=120;
      coord_y+=40;

      for(int x=0;x<16;x++)
	{
	
	  switch(squares_1[y][x])
	    {
	    case 's':
	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(255,0,0));
	      rectfill(buffer,coord_x+5,coord_y+5,coord_x+38-5,coord_y+38-5,makecol(220,0,0));
	      coord_x+=40;
	      break;
	    case 'b':
	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,200,0));
	      rectfill(buffer,coord_x+5,coord_y+5,coord_x+38-5,coord_y+38-5,makecol(0,160,0));
	      coord_x+=40;
	      break;
	    case 'z':
	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,0,0));
	      coord_x+=40;
	      break;
	    case 'm':
	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,100,0));
	      rectfill(buffer,coord_x+5,coord_y+5,coord_x+38-5,coord_y+38-5,makecol(0,80,0));
	      coord_x+=40;
	      break;
	    }
	}
    }
}
void stick::print_stick()
{
  if(key[KEY_RIGHT])  my_stick.x+=7;
  if(key[KEY_LEFT]) my_stick.x-=7;

  if(my_stick.bouncing)
    {
      switch(my_stick.bouncing)
	{
	case 4:
	  my_stick.y+=4;
	  break;
	case 3:
	my_stick.y+=5;
	break;
	case 2:
	  my_stick.y+=4;
	  break;

	case 1:
	  my_stick.y+=3;
	  break;


	}

      my_stick.bouncing--;
    }
  else
    {
      if(my_stick.going_up)
	{
	  my_stick.y--;
	  if(my_stick.y<400)going_up=false;
	    
	}
      else{

	my_stick.y++;
	if(my_stick.y>460)going_up=true;


      }
      //      my_stick.y=460;
     

      
    }
  


      rectfill(buffer,my_stick.x-10,my_stick.y,my_stick.x+100,my_stick.y+20,0);
      rectfill(buffer,my_stick.x,my_stick.y,my_stick.x+80,my_stick.y+20,makecol(0,0,250));
      rectfill(buffer,my_stick.x+5,my_stick.y+5,my_stick.x+80-5,my_stick.y+20-5,makecol(0,0,210));
      //rectfill(buffer,350,460,430,480,makecol(255,0,0));


 
}
void ball::print_ball()
{
  srand(time(NULL));
  int r=rand() %100;
  circlefill(buffer,balloon.x,balloon.y,10,0);
  int speed=4;
  if(r>40 && balloon.y<200)speed=7;
  if(balloon.dead)
    {
      speed=1;
      balloon.dead--;

    }

  switch(direction)
    {
    case 1:
      balloon.x+=speed;
      balloon.y-=speed;
      break;

    case 2:
      balloon.x+=speed;
      balloon.y+=speed;
      break;

    case 3:
      balloon.x-=speed;
      balloon.y+=speed;
      break;

    case 4:
      balloon.x-=speed;
      balloon.y-=speed;
      break;

    }
  circlefill(buffer,balloon.x,balloon.y,10,makecol(0,240,0));
  circlefill(buffer,balloon.x,balloon.y,8,makecol(0,180,0));

}

void big::respond()
{
  int r;
  if((balloon.x>x-10 && balloon.x<x+38+10) && (balloon.y>y-10 && balloon.y<y+38+10) )
    {


      switch(balloon.direction)
	{

	case 1:
	  if(balloon.y<y+44){
	    balloon.direction=4;
	    if((rand() % 100)>90)balloon.direction=3;
	    balloon.x-=4;}
	  else {
	    balloon.direction=2;
	    if(rand() %100 >80)balloon.direction=3;
	    balloon.y+=4;}
	  break;
	case 2:
	  if(balloon.y>y-5){
	    balloon.direction=3;
	    if(rand() % 100 >90)balloon.direction=4;
	    balloon.x-=4;}
	  else {
	    balloon.direction=1;
	    if(rand() % 100>90)balloon.direction=4;
	    balloon.y-=4;}
	  break;
	case 3:
	  if(balloon.y>y-5){
	    balloon.direction=2;
	    if(rand() % 100 >90)balloon.direction=1;
	    balloon.x+=4;}
	  else {
	    balloon.direction=4;
	    if(rand() % 100 > 90)balloon.direction=1;
	    balloon.y-=4;}
	  break;
	case 4:
	  if(balloon.y<y+38+6){
	    balloon.direction=1;
	    if(rand() % 100 > 90)balloon.direction=2;
	    balloon.x+=4;}
	  else {
	    balloon.direction=3;
	    if(rand()%100 > 90)balloon.direction=2;
	    balloon.y+=4;}
	  break;

	}

      hits++;

      stage=10;//from 10 to 0
   
    };
  
if(stage)
    {
      switch(stage)
	{
	
	case 10:
	  rectfill(buffer,x,y,x+38,y+38,makecol(255,255,255));
	  break;
	
	case 9:
	  rectfill(buffer,x-2,y-2,x+44,y+44,makecol(255,255,255));
	  break;
	
	case 8:
	  rectfill(buffer,x-4,y-4,x+48,y+48,makecol(255,255,255));
	  break;
	case 4:
	case 7:
	  rectfill(buffer,x-6,y-6,x+52,y+52,makecol(255,255,255));

	  break;
	case 5:
	case 6:
	  rectfill(buffer,x-8,y-8,x+56,y+56,makecol(255,255,255));
	  break;
	case 3:
	  rectfill(buffer,x,y,x+38,y+38,makecol(0,200,0));
	  rectfill(buffer,x+5,y+5,x+38-5,y+38-5,makecol(0,160,0));
	  rectfill(buffer,x+9,y+9,x+38-9,y+38-9,makecol(150,150,150));
	  break;

	case 2:
	  rectfill(buffer,x,y,x+38,y+38,makecol(0,200,0));
	  rectfill(buffer,x+5,y+5,x+38-5,y+38-5,makecol(0,160,0));
	  rectfill(buffer,x+11,y+11,x+38-11,y+38-11,makecol(100,100,100));
	  break;
	case 1:
	  rectfill(buffer,x,y,x+38,y+38,makecol(0,200,0));
	  rectfill(buffer,x+5,y+5,x+38-5,y+38-5,makecol(0,160,0));
	  rectfill(buffer,x+13,y+13,x+38-13,y+38-13,makecol(70,70,70));
    if(hits>=3)
	{
	  type='z';
	  squares_1[(y-80)/40][(x-120)/40]='z';
	};

	  break;

	}

      stage--;
    }




}

void small::respond()
{



 if((balloon.x>x-10 && balloon.x<x+38+10) && (balloon.y>y-10 && balloon.y<y+38+10) )
    {


       switch(balloon.direction)
	{

	case 1:
	  if(balloon.y<y+44){
	    balloon.direction=4;
	    balloon.x-=4;}
	  else {
	    balloon.direction=2;
	    balloon.y+=4;}
	  break;
	case 2:
	  if(balloon.y>y-5){
	    balloon.direction=3;
	    balloon.x-=4;}
	  else {
	    balloon.direction=1;
	    balloon.y-=4;}
	  break;
	case 3:
	  if(balloon.y>y-5){
	    balloon.direction=2;
	    balloon.x+=4;}
	  else {
	    balloon.direction=4;
	    balloon.y-=4;}
	  break;
	case 4:
	  if(balloon.y<y+38+6){
	    balloon.direction=1;
	    balloon.x+=4;}
	  else {
	    balloon.direction=3;
	    balloon.y+=4;}
	  break;

	}

      hits++;

      stage=10;//from 10 to 0
   
    };
  
if(stage)
    {
      switch(stage)
	{
	
	case 10:
	  rectfill(buffer,x,y,x+4,y+4,makecol(255,255,255));
	  rectfill(buffer,x+34,y,x+38,y+4,makecol(255,255,255));
	  rectfill(buffer,x,y+34,x+4,y+38,makecol(255,255,255));
	  rectfill(buffer,x+34,y+34,x+38,y+38,makecol(255,255,255));
	  break;
	
	case 9:
	  rectfill(buffer,x-4,y-4,x,y,makecol(255,255,255));
	  rectfill(buffer,x+38,y-4,x+42,y,makecol(255,255,255));
	  rectfill(buffer,x-4,y+38,x,y+42,makecol(255,255,255));
	  rectfill(buffer,x+38,y+38,x+42,y+42,makecol(255,255,255));
	  break;
	
	case 8:
	  rectfill(buffer,x-8,y-8,x-4,y-4,makecol(255,255,255));
	  rectfill(buffer,x+42,y-8,x+46,y-4,makecol(255,255,255));
	  rectfill(buffer,x-8,y+42,x-4,y+46,makecol(255,255,255));
	  rectfill(buffer,x+42,y+42,x+46,y+46,makecol(255,255,255));
	  break;

	case 7:
	  rectfill(buffer,x-12,y-12,x-8,y-8,makecol(255,255,255));
	  rectfill(buffer,x+46,y-12,x+50,y-8,makecol(255,255,255));
	  rectfill(buffer,x-12,y+46,x-4,y+50,makecol(255,255,255));
	  rectfill(buffer,x+46,y+46,x+50,y+50,makecol(255,255,255));


	  break;

	case 6:
	  rectfill(buffer,x-16,y-16,x-12,y-12,makecol(255,255,255));
	  rectfill(buffer,x+50,y-16,x+54,y-12,makecol(255,255,255));
	  rectfill(buffer,x-16,y+50,x-12,y+54,makecol(255,255,255));
	  rectfill(buffer,x+50,y+50,x+54,y+54,makecol(255,255,255));
	  break;
	case 5:
	  rectfill(buffer,x-20,y-20,x-16,y-16,makecol(255,255,255));
	  rectfill(buffer,x+54,y-20,x+60,y-16,makecol(255,255,255));
	  //rectfill(buffer,x-20,y+54,x+24,y+60,makecol(255,255,255));
	  rectfill(buffer,x+54,y+54,x+60,y+60,makecol(255,255,255));

	  break;
	case 4:
	  rectfill(buffer,x-24,y-24,x-16,y-16,makecol(255,255,255));
	  rectfill(buffer,x+60,y-24,x+64,y-20,makecol(255,255,255));
	  rectfill(buffer,x-24,y+60,x-20,y+56,makecol(255,255,255));
	  rectfill(buffer,x+60,y+60,x+64,y+64,makecol(255,255,255));

	  break;

	case 2:
	case 3:
	  rectfill(buffer,x-28,y-28,x-24,y-24,makecol(255,255,255));
	  rectfill(buffer,x+64,y-28,x+68,y-24,makecol(255,255,255));
	  //	  rectfill(buffer,x-28,y+64,x+24,y+68,makecol(255,255,255));
	  rectfill(buffer,x+64,y+64,x+68,y+68,makecol(255,255,255));
	  break;

	case 1:
	  if(hits)
	    {
	      if(!y_effect)
		{
		  y_effect=80;
		  y_aux=y;
		  stage=2;		 
		}
	      else 
		{
		  //  y_effect--;
		  y--;
		  stage=2; //afterwards it rises
		 
		}

	     
	      //if(y_effect==1)
	        if(y<-40)
		{
		  y_effect=0;
		  y=y_aux;
		  stage=1;
		  squares_1[(y-80)/40][(x-120)/40]='z';
		  type='z';
		}
	      
	    }
	 
	  
	  break;
	  
	}

            stage--;
    }






}
void medium::respond()
{
if((balloon.x>=x-5 && balloon.x<=x+44) && (balloon.y>y-10 && balloon.y<y+38+13) )
    {

 switch(balloon.direction)
	{

	case 1:
	  if(balloon.y<y+44){
	    balloon.direction=4;
	    balloon.x-=4;}
	  else {
	    balloon.direction=2;
	    balloon.y+=4;}
	  break;
	case 2:
	  if(balloon.y>y-5){
	    balloon.direction=3;
	    balloon.x-=4;}
	  else {
	    balloon.direction=1;
	    balloon.y-=4;}
	  break;
	case 3:
	  if(balloon.y>y-5){
	    balloon.direction=2;
	    balloon.x+=4;}
	  else {
	    balloon.direction=4;
	    balloon.y-=4;}
	  break;
	case 4:
	  if(balloon.y<y+38+6){
	    balloon.direction=1;
	    balloon.x+=4;}
	  else {
	    balloon.direction=3;
	    balloon.y+=4;}
	  break;

	}


    
      hits++;

      stage=10;//from 10 to 0
    };
  
if(stage)
    {
      switch(stage)
	{
	
	case 10:
	  x_effect=x;
	  y_effect=y;
	  y-=2;
	  break;
	
	case 9:
	  y+=2;
	  break;
	
	case 8:
	  y+=2;
	  break;

	case 7:
	  y-=2;

	  break;

	case 6:
	  x+=2;
	  break;

	case 5:
	  x-=2;
	  break;
	
	case 4:
	  x-=2;
	  break;
	case 3:
	  x+=2;
	  break;

	case 2:
	  x+=2;
	  break;
	case 1:
	  x=x_effect;
	  y=y_effect;

      if(hits>=2)
	{
	  type='z';
	  squares_1[(y-80)/40][(x-120)/40]='z';
	};

	  break;

	}

      stage--;
    }




}
void bricks::coordenates_bricks()
{

 

  for(int index_y=0;index_y<6;index_y++)
    {

      for(int index_x=0;index_x<16;index_x++)
	{
	  switch(squares_1[index_y][index_x])
	    {
	    case 's':
	      s_bricks[index_y][index_x].x=120+index_x*40;
	      s_bricks[index_y][index_x].y=80+index_y*40;
	      s_bricks[index_y][index_x].type='s';
	      s_bricks[index_y][index_x].stage=0;
	      s_bricks[index_y][index_x].hits=0;
	      break;

	    case 'b':
	      b_bricks[index_y][index_x].x=120+index_x*40;
	      b_bricks[index_y][index_x].y=80+index_y*40;
	      b_bricks[index_y][index_x].type='b';
	      b_bricks[index_y][index_x].hits=0;
	      b_bricks[index_y][index_x].stage=0;

		break;

	    case 'm':
	      m_bricks[index_y][index_x].x=120+index_x*40;
	      m_bricks[index_y][index_x].y=80+index_y*40;
	      m_bricks[index_y][index_x].type='m';
	      m_bricks[index_y][index_x].hits=0;
	      m_bricks[index_y][index_x].stage=0;
	      break;
	    case 'z':
	      z_bricks[index_y][index_x].x=120+index_x*40;
	      z_bricks[index_y][index_x].y=80+index_y*40;
	      z_bricks[index_y][index_x].type='z';
	      z_bricks[index_y][index_x].hits=0;
	      z_bricks[index_y][index_x].stage=0;
	      break;


	    }
	  //here i could store the type of each one reading it from the array squares[][17]={...
	  //and I could store the number of hits too.
	}

    }



}

void coord_brick()
{
  int coord_x,coord_y=40;

  for(int index_y=0;index_y<6;index_y++)
    {
      coord_x=120;
      coord_y+=40;

      for(int index_x=0;index_x<16;index_x++)
	{
	  switch(squares_1[index_y][index_x])
	    {

	    case 'b':
	      if(!b_bricks[index_y][index_x].stage)//respond does the effect , not here
		{
		  rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,200,0));
		  rectfill(buffer,coord_x+5,coord_y+5,coord_x+38-5,coord_y+38-5,makecol(0,160,0));
		}
	      coord_x+=40;
	      break;
	    case 's':
	      rectfill(buffer,coord_x,s_bricks[index_y][index_x].y,coord_x+38,s_bricks[index_y][index_x].y+38,makecol(255,0,0));
	        rectfill(buffer,coord_x+5,s_bricks[index_y][index_x].y+5,coord_x+38-5,s_bricks[index_y][index_x].y+38-5,makecol(220,0,0));
	      coord_x+=40;

	      break;
	    case 'm':
	      //	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,100,0));
	      //rectfill(buffer,coord_x+5,coord_y+5,coord_x+38-5,coord_y+38-5,makecol(0,80,0));
	      rectfill(buffer,m_bricks[index_y][index_x].x,m_bricks[index_y][index_x].y,(m_bricks[index_y][index_x].x)+38,(m_bricks[index_y][index_x].y)+38,makecol(0,100,0));
	      rectfill(buffer,(m_bricks[index_y][index_x].x)+5,(m_bricks[index_y][index_x].y)+5,(m_bricks[index_y][index_x].x)+38-5,(m_bricks[index_y][index_x].y)+38-5,makecol(0,80,0));
	      coord_x+=40;
	      break;
	    case 'z':
	      rectfill(buffer,coord_x,coord_y,coord_x+38,coord_y+38,makecol(0,0,0));
	      coord_x+=40;
	      break;
	    }
	}
    }
}

void lives::infor_screen()
{
  int x=20;
  int y=400;
  char value;
  int index_x=0;
  for(int index_y=0;index_y<10;index_y++)
    {

      while(1)
	{
	  if(n_lives==3)value=array_lives_3[index_y][index_x++];
	  else if(n_lives==2)value=array_lives_2[index_y][index_x++];
	  else if(n_lives==1)value=array_lives_1[index_y][index_x++];
	  else if(!n_lives)value=array_lives_0[index_y][index_x++];
	  if(!value)break;
	    
	  
	  if(value=='b') rectfill(buffer,x,y,x+8,y+8,makecol(150,0,0));
	  x+=10;

	}
      
      y+=10;
      x=20;
      index_x=0;

    }

}




void ark::infor_screen()
{
  if(!color)return ;
  int y=0;//0 in buffer_title
  int x1_each=x1;
  int x2_each=x2;
  int aux_mod;


      for(int ind_y=0;ind_y<10;ind_y++)
	{
	  
	  for(int ind_x=0;ind_x<70;ind_x++)
	    {
	      if(arkanos[ind_y][ind_x]=='.')
		{
		  if(!(ind_y % 2)) rectfill(buffer_title,x1_each,y,x1_each+8,y+8,makecol(color,color,color));
		  else rectfill(buffer_title,x2_each,y,x2_each+8,y+8,makecol(color,color,color));

		}
	      x1_each+=10;	      
	      x2_each+=10;
	    }
	 
	  y+=10;
	  x1_each=x1;
	  x2_each=x2;
	}
      if(x1<50)x1++;
  
      if(x2>50)x2--;
      if(game)color--;
}


void bricks::restore_to_first(int n_room)
{

  for(int index_y=0;index_y<6;index_y++)
    {

      for(int index_x=0;index_x<16;index_x++)
	{
	  squares_1[index_y][index_x]=squares_2[n_room][index_y][index_x];
	  switch(squares_1[index_y][index_x])
	    {
	    case 'b':
	      b_bricks[index_y][index_x].x=120+40*index_x;
	      b_bricks[index_y][index_x].y=80+40*index_y;
	      b_bricks[index_y][index_x].type='b';
	      b_bricks[index_y][index_x].stage=0;
	      break;
	    case 's':
	      s_bricks[index_y][index_x].x=120+40*index_x;
	      s_bricks[index_y][index_x].y=80+40*index_y;
	      s_bricks[index_y][index_x].type='s';
	      s_bricks[index_y][index_x].stage=0;
	      break;
	    case 'm':
	      m_bricks[index_y][index_x].x=120+40*index_x;
	      m_bricks[index_y][index_x].y=80+40*index_y;
	      m_bricks[index_y][index_x].type='m';
	      m_bricks[index_y][index_x].stage=0;
	      break;
	  }


	}
    }

}

bool bricks::check_zeros()
{
  int counter=0;
  char value;
  int index_x,index_y;
  for( index_y=0;index_y<6;index_y++)
    {
      for( index_x=0;index_x<16;index_x++)
	{
	  //if(value=squares_1[index_y][index_x]!='z')break;
	  value=squares_1[index_y][index_x];
	  if(value=='z')counter++;
	  if(counter>90) return true;
	}
      //      if(value!='z')break;
    }
  return false;
  //return (index_y==5 && index_x==15 && value=='z')? true:false;
}

void shot::shoot(bool a)//defect :  no new shoot
{  
  if(a) new_shot();
  for(int index=0;index<10;index++)
    {
    
      if(x[index]!=1000)
	{
	  y[index]-=15;
	  
	  circlefill(buffer,x[index],y[index],4,makecol(0,150,0));
	  if(y[index]<-10)x[index]=1000;
	}
      //      else number_bullets--;
  
    }
}
void shot::new_shot()
{
   key[KEY_UP]=0;
 
   if(x[index_bullet]==1000)
     {
       x[index_bullet]=my_stick.x+50;
       y[index_bullet]=my_stick.y-10;
       //	  number_bullets++;
       index_bullet++;
     }
	  if(index_bullet>9)index_bullet=0; 

}

void shot::compareWithBricks()
{
  int x_brick,y_brick;
  for(int index_y=0;index_y<6;index_y++)
    {


      for(int index_x=0;index_x<16;index_x++)
	{
	  //here we have to calculate the coordenates of the square..
	  //according to index_y and index_x
	  x_brick=120+index_x*40;//left corner
	  y_brick=(80+index_y*40)+40;//to get the square's base!
	  if(squares_1[index_y][index_x]!='z')
	    {

	      for(int index=0;index<10;index++)
		{
		  //here we go along the array of the ten bullets...
		  //comparing each to the same non-'z' square.
		  //if the bullet crashes into... we'll write 'z' in the aquares array
		  //fireStage = 10 or whatever ...x bullet=1000 !!!!.. this bullet will disappear
		  if(x[index]>x_brick && x[index]<x_brick+40 && y[index]<y_brick && y[index]>y_brick-40)
		    {//the bullet has hit the square
		      x[index]=1000;//the bullet disappear

		      squares_1[index_y][index_x]='z';


		    }


		}

	    }

	}


    }




}
