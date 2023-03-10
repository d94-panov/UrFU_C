#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
 class Point{
   public:
     int X,Y, Cvet;
     Point(int XN, int YN, int Color);
     virtual void  Show();
     virtual void  Hide();
     void Locat (int *XL,int *YL);
     void Fly (int Cost);
 };
 class Krug: public Point{
   public:
     int Radius;
     Krug(int XN, int YN, int R, int Color);
     virtual void  Show();
     virtual void  Hide();
 };
 class Ring: public Krug{
    public:
     int Width;
     Ring(int XN, int YN, int R, int Color, int Wid);
     virtual void  Show();
 };

 Point::Point(int XN, int YN, int Color)
 {
   X= XN; Y= YN; Cvet= Color;
 }
 void Point::Show(){}
 void Point::Hide(){}
 void Point::Locat(int *XL,int *YL)
 {
    *XL= X; *YL= Y;
 }
 void Point::Fly(int Cost)
 {
    int XX, YY;
    Show();
    randomize();
    do{
       Locat(&XX,&YY);
       do XX = XX + (int)((random(2)-0.5)*Cost); //{ЇҐаҐ¬ҐйҐ­ЁҐ1 }
       while ((XX < 0) && (XX > getmaxx()));
       do YY = YY + (int)((random(2)-0.5)*Cost);//  { ЇҐаҐ¬ҐйҐ­ЁҐ2}
       while ((YY < 0) && (YY > getmaxy()));
       Hide();
       X = XX; Y = YY;
       Show(); delay (300);//   { ¬Ґ«мЄ ­ЁҐ ЄагЈ®ў }
     }while (!kbhit());
     getch();
 }
 Krug::Krug(int XN, int YN, int R, int Color): Point(XN, YN, Color)
 {
   Radius = R;
   Show();
 }
 void Krug::Show()
 {
   setcolor (Cvet);
   setfillstyle (1, Cvet);
   pieslice (X, Y, 0, 320, Radius);
 }
 void Krug::Hide()
 {
   setcolor (getbkcolor());
   setfillstyle (1,getbkcolor());
   pieslice (X, Y, 0, 320, Radius);
 }
 Ring::Ring(int XN, int YN, int R, int Color, int Wid):Krug(XN, YN, R, Color)
 {
   Width = Wid;
 }
 void Ring::Show()
 {
   Krug::Show();
   setfillstyle (10, getbkcolor());
   pieslice (X, Y, 90 , 320, Radius - Width);
 }

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\bc31\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
     printf("Graphics error: %s\n", grapherrormsg(errorcode));
     printf("Press any key to halt:");
     getch();
     exit(1);             /* return with error code */
   }

//   Krug TestKrug();
//   Ring TestRing();
   setbkcolor (80);
    Krug TestKrug(150, 40, 50, 1);
    Ring TestRing(450, 80, 90, 50, 10);
    TestKrug.Fly (100);
    TestRing.Fly (60);
    TestKrug. Fly (60);
    getch();
    TestKrug.Hide();
    TestRing.Hide();
    getch();
}
