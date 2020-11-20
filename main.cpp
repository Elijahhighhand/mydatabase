#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{
	float width,height;
	int w=600,h=400,p=0;
	width = 600;
	height = 400;
	initgraph(w,h);

	float ball_x,ball_y,ball_vy,radius,g;
	radius=15;
	ball_x=width/4;
	ball_y=height/2;
	ball_vy=0;
	g = 0.2;

	float rx,ry,rw,rh,vx,rx1,ry1,rw1,rh1;
	rh=100;rh1=0;
	rw=20;rw1=20;
	rx=width*3/4;rx1=width*3/4;
	ry=height+rh;ry1=height;
	vx=-3;

	int score = 0;
	int i=1;
	while (1)
	{
		if (kbhit())
		{
			char input=_getch();
			if (input==' ' && ball_y-radius-40>=0)
			{
				ball_vy=-6;
			}
		}
		ball_vy=ball_vy+g;
		ball_y=ball_y+ball_vy;
		if(ball_y>=height-radius)
		{
			ball_y=0;
			ball_y=height-radius;
		}

		if ((rx<=ball_x+radius) && (rx+rw>=ball_x-radius) && (height-rh<=ball_y+radius))
		{	
			if(p<score){
				p=score;}
			score = 0;
			Sleep(100);
			i=0;
		}
		if((rx1<=ball_x+radius) && (rx1+rw1>=ball_x-radius) && (height-rh-90>=ball_y+radius))
		{
			if(p<score){
				p=score;}
			score = 0;
			Sleep(100);
			i=0;
		}
		
		if(rx+rw>=600)
		{
			i=1;
		}
		rx=rx+vx;rx1=rx1+vx;
		if(rx<=0)
		{
			rx=width;
			rh=rand() % int(height/4)+height/4;
			vx=rand()/float(RAND_MAX) *4 - 7;
			score+=i;
		}
		if(rx1<=0)
		{
			rx1=width;
			rh1=0;
			vx=rand()/float(RAND_MAX) *3 - 5;
		}


		cleardevice();
		fillrectangle(rx1,rh1,rx1+rw1,height-rh-110);
		fillrectangle(rx,height-rh,rx+rw,height);
		fillcircle(ball_x,ball_y,radius);

		TCHAR s[20];
		_stprintf(s, _T("%d"),score);
		settextstyle(40,0, _T("宋体"));
		outtextxy(50,30,s);

		Sleep(10);
	}

	_getch();
	return 0;
}        