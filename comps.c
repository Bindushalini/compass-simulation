#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 550
GLint m;
GLfloat red=1.0,green=1.0,blue=1.0;
void drawtext(float x,float y,char *s)
{
  int i;
  glRasterPos2f(x,y);
  for(i=0;s[i]!='\0';i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
 
}
void draw_pixel(GLint cx,GLint cy)
{
  glColor3f(0.8,1.0,0.8);
//glColor3f(1.0,1.0,1.0);
  glBegin(GL_POINTS);
     glVertex2i(cx,cy);
   glEnd();
 }
 void plotpixels(GLint h,GLint k,GLint x,GLint y)
 {
   draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
        draw_pixel(y+h,-x+k);
            draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r){
GLint d=1-r,x=0,y=r;
while(y>x)
{
 plotpixels(h,k,x,y);
 if(d<0)
   d+=2*x+3;
 else
   {
     d+=2*(x-y)+5;
     --y;
    }
    ++x;
 }
 plotpixels(h,k,x,y);
}
void reshape(int nw,int nh)
{ glViewport(0,0,nw,nh);
  glClearColor(red,green,blue,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,(GLdouble)nw,0.0,(GLdouble)nh);
glutPostRedisplay();
  }
void line()
{
// needleARROW
  glColor3f(1.0,0.0,0.0);
  glLineWidth(5.0);
 glBegin(GL_LINES);
   glVertex3f(400.0,250.0,0.0);
   glVertex3f(500.0,250.0,0.0);
   glEnd();
     glBegin(GL_POINTS);
      glColor3f(1.0,1.0,0.0);
      glPointSize(5.0);
      glVertex3f(500.0,250.0,0.0);
glutSwapBuffers();
 glEnd();
}
void display(void)
 {  int i;
	glClearColor(red,green,blue,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
 //circle
  for(i=0;i<105;i++)
   {
       glColor3f(1.0,0.0,1.0);
	circle_draw(400,250,i);
   }
//nut
glColor3f(0.0,0.0,1.0);
glBegin(GL_POINTS);
 glPointSize(10.0);
 glVertex2f(399,250);
glEnd();

//dir text
  glColor3f(0.0,1.0,0.0);
   drawtext(498,245,"N");
	drawtext(450,310,"NW");
	drawtext(315,310,"SW");
	drawtext(450,170,"NE");
	drawtext(315,170,"SE");
       drawtext(390,140,"E");
       drawtext(288,245,"S");
	drawtext(388,348,"W");


if(m==1)
{
line();
}
   glFlush();
glutSwapBuffers();
 }
void line2(float x1,float y1,float nx1,float ny1){
 glColor3f(1.0,0.0,0.0);
  glLineWidth(5.0);
 glBegin(GL_LINES);
   glVertex3f(x1,y1,0.0);
   glVertex3f(nx1,ny1,0.0);
     glBegin(GL_POINTS);
      glColor3f(1.0,1.0,0.0);
      glPointSize(5.0);
      glVertex3f(nx1,ny1,0.0);  
glutSwapBuffers();
glEnd();
}


void rotateneed(int theta,float xx,float yy,float x2,float y2)
{
float nx1,ny1;
 float t=(3.14*theta)/180;
nx1=xx+((x2-xx)*cos(t)-(y2-yy)*sin(t));
ny1=yy+((x2-xx)*sin(t)+(y2-yy)*cos(t));
m=0;
display();
line2(xx,yy,nx1,ny1);
}

void translate1(GLint option)    /*to translate the compass increments*/
{m=1; int j;
switch(option){

case 1: for(j=1;j<=4;j++){
		glTranslatef(50.0,50.0,0.0);
		display();
          sleep(1);}
	for(j=1;j<=4;j++){
 		glTranslatef(-50.0,-50.0,0.0);
  		display();
    		sleep(1);}
       	sleep(1);
        for(j=1;j<=4;j++){
		glTranslatef(-50.0,50.0,0.0);
		display();
		sleep(1);}
	for(j=1;j<=4;j++){
 		glTranslatef(50.0,-50.0,0.0);
  		display();
		sleep(1);}
    break;
	
case 2: for(j=1;j<=4;j++){
		glTranslatef(-50.0,-50.0,0.0);
		display();
		sleep(1);}
	for(j=1;j<=4;j++){
 		glTranslatef(50.0,50.0,0.0);
  		display();
		sleep(1);}
       	sleep(1);
        for(j=1;j<=4;j++){
		glTranslatef(50.0,-50.0,0.0);
		display();
		sleep(1);
		}
	for(j=1;j<=4;j++){
 		glTranslatef(-50.0,50.0,0.0);
  		display();
		sleep(1);}
}
glutPostRedisplay();
}
void scale(GLint option)
{
switch(option){

case 1:
	glScalef(1.4,1.0,0.0);
	display();
        break;
case 2:
 	glScalef(0.8,1.0,0.0);
  	display();
         break;
}
glutPostRedisplay();
 }
void colorsm(GLint opt)
{
 	switch(opt){
 	case 1: 
		red=1.0; green=1.0; blue=0.0;
	        break;
     	case 2:
		red=1.0; green=0.0; blue=1.0;
	        break;
	case 3: 
		red=0.0; green=1.0; blue=1.0;
	        break;
}
glutPostRedisplay();
}
void keys(unsigned char key,int x,int y)
{  
        if(key=='w')
            rotateneed(90,400.0,250.0,500.0,250.0);
        if(key=='s')
           rotateneed(180,400.0,250.0,500.0,250.0);
	if(key=='e')
           rotateneed(270,400.0,250.0,500.0,250.0);
	if(key=='n')
           rotateneed(360,400.0,250.0,500.0,250.0);
        if(key=='k')
	   rotateneed(45,400.0,250.0,500.0,250.0);
	if(key=='l')
	   rotateneed(135,400.0,250.0,500.0,250.0);
	if(key=='m')
	   rotateneed(225,400.0,250.0,500.0,250.0);
	if(key=='o')
	   rotateneed(315,400.0,250.0,500.0,250.0);
}
void main_menu(GLint option)
{
switch(option)
{
 case 3: exit(0); 
	 break;
}
glutSwapBuffers();
glutPostRedisplay();

}
 void main(int argc,char** argv)
{   m=1;
   GLint submenu,sm1,sm2;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
        glutKeyboardFunc(keys);

submenu=glutCreateMenu(translate1);
       glutAddMenuEntry("move up",1);
       glutAddMenuEntry("move down",2);
 sm1=glutCreateMenu(colorsm);
        glutAddMenuEntry("yellow",1);
	glutAddMenuEntry("magenta",2);
	glutAddMenuEntry("cyan",3);
sm2=glutCreateMenu(scale);
       glutAddMenuEntry("zoom in",1);
       glutAddMenuEntry("zoom out",2);
glutCreateMenu(main_menu);
     glutAddSubMenu("translation",submenu);
     glutAddSubMenu("change bg color",sm1);
     glutAddSubMenu("scaling",sm2);
     glutAddMenuEntry("stop",3);

glutAttachMenu (GLUT_RIGHT_BUTTON);
   
glutMainLoop();
}


