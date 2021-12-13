#include <graphics.h>
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

const int ANCHO=700, ALTO=700;

int _A,_B;

void init0 ();
void bat(int,int);
void batBottom(int,int);

struct origin{
	int x;
	int y;
};

int main(){
	init0();
	while (true){
		if(GetAsyncKeyState(0x58)){
			for(int i=0;i<50;i++){
				_A=i*7;
				_B=i*3;
				bat(_A,_B);
				batBottom(_A,_B);
				cleardevice();
				readimagefile("descarga.jpg",200,200,500,500);
			}
		}
	}
	system("pause");
	closegraph();
	return 0;
}

void bat(int a,int b){
	int x,y,f,fa,fb,fc,c;
	int na=a*-1;
	int nb=b*-1;
	int a1=a/7;
	int b1=b/3;
	struct origin newOrigin = {ANCHO/2,ALTO/2};
	for(int i=na;i<(na/3);i++){
		x=i;
		y=b*sqrt(1-(pow(x,2)/pow(a,2)));
		putpixel(newOrigin.x+x,newOrigin.y-y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y-y,WHITE);
		f=y;
		c=i;
	}
	for(int j=c;j<(na/7);j++){
		x=j;
		y=-1*(((b1*2)*sqrt(1-pow(x+((a1*3)/2),2)/pow(a1,2)))-f);
		putpixel(newOrigin.x+x,newOrigin.y-y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y-y,WHITE);
		fa=y;
		c=j;
	}
	for(int k=c;k<(-a1*4/5);k++){
		x=k;
		y=-1*((x+b1-tan(6.137))/tan(6.137)-fa);
		putpixel(newOrigin.x+x,newOrigin.y-fa-y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y-fa-y,WHITE);
		fb=y;
		c=k;
	}
	line(newOrigin.x+x,newOrigin.y-1.5*fb,newOrigin.x-(a1/2),newOrigin.y-(b1*2.25));
	line(newOrigin.x-x,newOrigin.y-1.5*fb,newOrigin.x+(a1/2),newOrigin.y-(b1*2.25));
	for(int l=c;l<(-a1*1/2);l++){
		x=l;
	}
	line(newOrigin.x+x,newOrigin.y-(b1*2.25),newOrigin.x-x,newOrigin.y-(b1*2.25));
}

void batBottom(int a,int b){
	int x,y,f,fa,fb,fc,c;
	int na=a*-1;
	int nb=b*-1;
	int a1=a/7;
	int b1=b/3;
	struct origin newOrigin = {ANCHO/2,ALTO/2};
	for(int i=na;i<(-a1*4);i++){
		x=i;
		y=b*sqrt(1-(pow(x,2)/pow(a,2)));
		putpixel(newOrigin.x+x,newOrigin.y+y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y+y,WHITE);
		f=y;
		c=i;
	}
	for(int j=c;j<(-a1*2);j++){
		x=j;
		y=-1*(((b1*1)*sqrt(1-pow(x+b,2)/pow(a1,2)))-f);
		putpixel(newOrigin.x+x,newOrigin.y+y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y+y,WHITE);
		fa=y;
		c=j;
	}
	for(int k=c;k<0;k++){
		x=k;
		y=-1*(((b1*1)*sqrt(1-pow(x+(b/3),2)/pow(a1,2)))-f);
		putpixel(newOrigin.x+x,newOrigin.y+y,WHITE);
		putpixel(newOrigin.x-x,newOrigin.y+y,WHITE);
		fa=y;
		c=k;
	}
}

void init0(){
	initwindow( ANCHO, ALTO, "GUINXU_Math" );
	readimagefile("descarga.jpg",200,200,500,500);
}
