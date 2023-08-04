#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
voiddisp(intn,float c[][3]){
floatmaxx,maxy;
inti;
maxx=getmaxx();
maxy=getmaxy();
maxx=maxx/2;
maxy=maxy/2;
i=0;
while(i<n-1){
line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
i++; }
i=n-1;
line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
setcolor(GREEN);
line(0,maxy,maxx*2,maxy);
line(maxx,0,maxx,maxy*2);
setcolor(WHITE);}
void mul(intn,float b[][3],float c[][3],float a[][3]){
inti,j,k;
for(i=0;i<n;i++)
for(j=0;j<3;j++)
a[i][j]=0;
for(i=0;i<n;i++)
for(j=0;j<3;j++)
for(k=0;k<3;k++) {
a[i][j]=a[i][j]+(c[i][k]*b[k][j]); }}
void translation(intn,float c[][3],float tx,floatty){
inti;
for(i=0;i<n;i++) {
c[i][0]=c[i][0]+tx;
c[i][1]=c[i][1]+ty; }}
void scaling(intn,float c[][3],float sx,floatsy){
float b[10][3],a[10][3];
inti,j;
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=sx;
b[1][1]=sy;
b[2][2]=1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
void rotation(intn,float c[][3],float ra){
inti=0,j;
float b[10][3],xp,yp,a[10][3];
xp=c[0][0];
yp=c[0][1];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=b[1][1]=cos(ra*3.14/180);
b[0][1]=sin(ra*3.14/180);
b[1][0]=-sin(ra*3.14/180);;
b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
b[2][2]=1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidrefthx(intn,float c[][3]){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=b[2][2]=1;
b[1][1]=-1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidrefthy(intn,float c[][3]){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[1][1]=b[2][2]=1;
b[0][0]=-1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidreforg(intn,float c[][3]){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=b[1][1]=-1;
b[2][2]=1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidrefthyx(intn,float c[][3]){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][1]=b[1][0]=b[2][2]=1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidrefthynegx(intn,float c[][3]){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][1]=b[1][0]=-1;
b[2][2]=1;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidshearx(intn,float c[][3],float shx){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=b[1][1]=b[2][2]=1;
b[1][0]=shx;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
voidsheary(intn,float c[][3],float shy){
inti=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=b[1][1]=b[2][2]=1;
b[0][1]=shy;
mul(n,b,c,a);
setcolor(RED);
disp(n,a);}
int main(){
inti,j,k,cho,n,gd=DETECT,gm;
float c[10][3],tx,ty,sx,sy,ra;
initgraph(&gd,&gm,” “);
cout<<“Enter no. of vertices”;
cin>>n;
for (i=0;i<n;i++) {
cout<<“Enter coordinates of vertex”,i+1;
cin>>c[i][0]>>c[i][1];
c[i][2]=1; }
do {
cleardevice();
cout<<“\n\t\t ——MENU——“;
cout<<“\n\t\t 1)Translation”;
cout<<“\n\t\t 2)Scaling”;
cout<<“\n\t\t 3)Rotation”;
cout<<“\n\t\t 4)Reflection”;
cout<<“\n\t\t 5)Shear”;
cout<<“\n\t\t 6)EXIT”;
cout<<“\n\t Enter your Choice”;
cin>>cho;
switch(cho) {
case 1:
cout<<“\n\t Enter translation factor for X and Y axis:\t”;
cin>>tx>>ty;
cleardevice();
setcolor(15);
disp(n,c);
translation(n,c,tx,ty);
setcolor(15);
disp(n,c);
getch();
break;
case 2:
cout<<“\n\t Enter scaling factor for X and Y axis:\t”;
cin>>sx>>sy;
cleardevice();
setcolor(15);
disp(n,c);
scaling(n,c,sx,sy);
getch();
break;
case 3:
cout<<“\n\t Enter rotation factor :\t”;
cin>>ra;
cleardevice();
disp(n,c);
rotation(n,c,ra);
getch();
break;
case 4:
intch;
do{
cleardevice();
cout<<“\n\t\t ——MENU——“;
cout<<“\n\t\t 1)Reflection about x axis”;
cout<<“\n\t\t 2)Reflection about x axis”;
cout<<“\n\t\t 3)Reflection about origin”;
cout<<“\n\t\t 4)Reflection about the line y=x”;
cout<<“\n\t\t 4)Reflection about the line y=-x”;
cout<<“\n\t Enter your Choice”;
cin>>ch;
switch(ch){
case 1:
cleardevice();
setcolor(15);
disp(n,c);
refthx(n,c);
getch();
break;
case 2:
cleardevice();
setcolor(15);
disp(n,c);
refthy(n,c);
getch();
break;
case 3:
cleardevice();
setcolor(15);
disp(n,c);
reforg(n,c);
getch();
break;
case 4:
cleardevice();
setcolor(15);
disp(n,c);
refthyx(n,c);
getch();
break;
case 5:
cleardevice();
setcolor(15);
disp(n,c);
refthynegx(n,c);
getch();
break;
default:
cout<<“\n\t Invalid Choice !!!”;
break; } }
while(cho!=5);
case 5:
int cha;
floatshx,shy;
do {
cleardevice();
cout<<“\n\t\t ——MENU——“;
cout<<“\n\t\t 1)X-shear”;
cout<<“\n\t\t 2)Y-shear”;
cout<<“\n\t Enter your Choice”;
cin>>cha;
switch(cha) {
case 1:
cout<<“\n\t Enter Shear factor: “;
cin>>shx;
cleardevice();
setcolor(15);
disp(n,c);
shearx(n,c,shx);
getch();
break;
case 2:
cout<<“\n\t Enter Shear factor: “;
cin>>shy;
cleardevice();
setcolor(15);
disp(n,c);
shearx(n,c,shy);
getch();
break;
default:
cout<<“\n\t Invalid Choice !!!”;
break; } }
while(cho!=2);
case 6:
exit(0);
break;
default:
cout<<“\n\t Invalid Choice !!!”;
break; } }
while(cho!=6);
getch();
closegraph();}
