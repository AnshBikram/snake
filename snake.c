#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

void main() {
	int gd=DETECT, gm, x=15, z, i, j, m, n, choice, k=40, score=0;
	char c='d',d='r',pd='r',tmp;
	randomize();

	while(1) {
		printf("1: To Play Snake\n2: Option\n3: To Exit");
		scanf("%d",&choice);

		switch(choice) {
			case 1:
				initgraph(&gd,&gm,"c:\\tc\\bgi");
				m=random(getmaxx()-194)+103;
				n=random(getmaxy()-194)+103;
				i=getmaxx()/2;
				j=getmaxy()/2;
				setcolor(RED);

				while(1) {
					clrscr();
					gotoxy(20,0);
					printf("Enter Q to Quit to Menu\nEnter W,A,S,D to move the SNAKE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Your Score: %d",score);
					circle(m,n,2);
					{
						if(d=='u'&&(m==i||m==i+1||m==i-1||m==i+2||m==i-2||m==i+3||m==i-3)&&n==j-x) {
							m=random(getmaxx()-194)+103;
							n=random(getmaxy()-194)+103;
							x=x+5;
							if(k==5) score=score+30; else if(k==10) score=score+20; else score=score+10;
						} else if(d=='d'&&(m==i||m==i+1||m==i-1||m==i+2||m==i-2||m==i+3||m==i-3)&&n==j+x){
							m=random(getmaxx()-194)+103;
							n=random(getmaxy()-194)+103;
							x=x+5;
							if(k==5) score=score+30; else if(k==10) score=score+20; else score=score+10;
						} else if(d=='r'&&m==i+x&&(n==j||n==j+1||n==j-1||n==j+2||n==j-2||n==j+3||n==j-3)){
							m=random(getmaxx()-194)+103;
							n=random(getmaxy()-194)+103;
							x=x+5;
							if(k==5) score=score+30; else if(k==10) score=score+20; else score=score+10;
						} else if(d=='l'&&m==i-x&&(n==j||n==j+1||n==j-1||n==j+2||n==j-2||n==j+3||n==j-3)){
							m=random(getmaxx()-194)+103;
							n=random(getmaxy()-194)+103;
							x=x+5;
							if(k==5) score=score+30; else if(k==10) score=score+20; else score=score+10;
						} 
					}
					rectangle(100,100,getmaxx()-100,getmaxy()-100);
					if(kbhit()) {
						c=getch();
						if(c=='q') break;
						else if(c=='w') d='u';
						else if(c=='s') d='d';
						else if(c=='a') d='l';
						else if(c=='d') d='r';
					}
					if(d=='u'&&pd!='d'){
						tmp=pd;
						pd='u';
						if(tmp=='r') {i=i+x;j=j+x; }
						else if(tmp=='l') {i=i-x;j=j+x;}
						for(z=x;z>=0;z--)
							putpixel(i,j-z,RED);
						j=j-1;
					}
					else if(d=='d'&&pd!='u'){
						tmp=pd;
						pd='d';
						if(tmp=='r') {i=i+x;j=j-x; }
						else if(tmp=='l') {i=i-x;j=j-x;}
						for(z=x;z>=0;z--)
							putpixel(i,j+z,RED);
						j=j+1;
					}
					else if(d=='l'&&pd!='r'){
						tmp=pd;
						pd='l';
						if(tmp=='u') {i=i+x;j=j-x; }
						else if(tmp=='d') {i=i+x;j=j+x;}
						for(z=x;z>=0;z--)
							putpixel(i-z,j,RED);
						i--;
					}
					else if(d=='r'&&pd!='l'){
						tmp=pd;
						pd='r';
						if(tmp=='u') {i=i-x;j=j-x; }
						else if(tmp=='d') {i=i-x;j=j+x;}
						for(z=x;z>=0;z--)
							putpixel(i+z,j,RED);
						i++;
					}
					else if(d=='d'&&pd=='u'){
						for(z=x;z>=0;z--)
							putpixel(i,j-z,RED);
						j=j-1;
					}
					else if(d=='u'&&pd=='d'){
						for(z=x;z>=0;z--)
							putpixel(i,j+z,RED);
						j=j+1;
					}
					else if(d=='l'&&pd=='r'){
						for(z=x;z>=0;z--)
							putpixel(i+z,j,RED);
						i++;
					}
					else if(d=='r'&&pd=='l'){
						for(z=x;z>=0;z--)
							putpixel(i-z,j,RED);
						i--;
					}
					else continue;
					delay(k);
				}
				closegraph();
				break;
			case 2: 
				clrscr();
				printf("Level\n1: Level 1\n2: Level 2\n3: Level 3\n");
				int l;
				scanf("%d",&l);
				if(l==1) k=20;
				if(l==2) k=10;
				if(l==3) k=5; clrscr();
				break;
			case 3: clrscr (); exit(1);
			default: printf("Invalid Choice");
		}
	}
}