#include<windows.h>

#include <GL/glut.h>

#include <stdlib.h>
#include<math.h>
#define PI 3.1416

float c1xp=0.0,c1yp=0.0,c1zp=0.0;
float c2xp=0.0,c2yp=0.0,c2zp=0.0;
float p1xp=0.0,p1yp=0.0,p1zp=0.0;
float p1sxp=0.0,p1syp=0.0,p1szp=0.0;
float x=1.0;
float rxp=0.0,ryp=0.0,rzp=0.0;
float r=0.0;

float ttx = 0.0;

float width=-940,width2=600,width3=2000;
static float hospitalcorrection=170;
static float cc=-30;
static float ccor=35;
static float pcor=-25;
static float pcor1=40;
static float home3cc=700;
static float home4cc=450;
static float home4ccup=10;
float k=.1,w=.1,A=3.5,phi=0,timee=0.0;
float wave_ordinate(float k,float w,float A,float phi,float x)
{
    timee++;
    return A * sin( (k*x) - (w*timee) + phi);
}
void waveSea()
{
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
    glTranslatef(0.0,450.0,0.0);
    glBegin(GL_LINE_STRIP);
    for(float x = 0 ; x < 902 ; x+=0.6)
    {
        float y = wave_ordinate(k,w,A,phi,x);
        for (int xx = 250; xx<450; xx+=1)
        {
            glColor3f(135.0f/255,206.0f/255,250.0f/255);
            glVertex2d(x,y-xx);
            glColor3f(0.2,0.3,0.8);
            glVertex2d(x,y+1-xx);
        }
    }
    glEnd();
    glPopMatrix();
}


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}

void Sky()
{
        glPushMatrix();
        glColor3ub(181, 228, 247);
        glBegin(GL_QUADS);
        glVertex2i(0,684);
        glVertex2i(902,684);
        glVertex2i(902,0);
        glVertex2i(0,0);
        glEnd();
        glPopMatrix();

        glutPostRedisplay();
}

void Sun()
{
    glColor3ub(247, 212, 37);
    drawCircle(110.0f,605.0f,40.0f);
    glutPostRedisplay();
}

void Home2()
{
    //building body
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 103);
    glVertex2i(5+150,257);
    glColor3ub(250, 57, 118);
    glVertex2i(5+150,450);
    glColor3ub(240, 126, 65);
    glVertex2i(137+150,450);
    glColor3ub(247, 87, 0);
    glVertex2i(137+150,257);
    glEnd();
    glPopMatrix();

    //building door
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52+150,257);
    glVertex2i(87+150,257);
    glVertex2i(87+150,290);
    glVertex2i(52+150,290);
    glEnd();
    glPopMatrix();

    //building window top single
    glPushMatrix();
    glColor3ub(232,232,232);
    glBegin(GL_QUADS);
    glVertex2i(25+150,400);
    glVertex2i(25+150,440);
    glVertex2i(265,440);
    glVertex2i(265,400);
    glEnd();
    glPopMatrix();

    //building window middle left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+150,350);
    glVertex2i(25+150,380);
    glVertex2i(50+150,380);
    glVertex2i(50+150,350);
    glEnd();
    glPopMatrix();

    //building window middle right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+150,350);
    glVertex2i(90+150,380);
    glVertex2i(115+150,380);
    glVertex2i(115+150,350);
    glEnd();
    glPopMatrix();

    //building window bottom left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+150,310);
    glVertex2i(25+150,340);
    glVertex2i(50+150,340);
    glVertex2i(50+150,310);
    glEnd();
    glPopMatrix();

    //building window bottom right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+150,310);
    glVertex2i(90+150,340);
    glVertex2i(115+150,340);
    glVertex2i(115+150,310);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

void Home4()
{
    //footpath
    glPushMatrix();
    glColor3ub(168, 142, 133);
    glBegin(GL_QUADS);
    glVertex2i(449+170,257+10);
    glVertex2i(5+700,257+10);
    glVertex2i(5+700,257);
    glVertex2i(449+170,257);
    glEnd();
    glPopMatrix();
    //building body
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 103);
    glVertex2i(5+150+home4cc,257+home4ccup);
    glColor3ub(184, 6, 6);
    glVertex2i(5+150+home4cc,450+home4ccup);
    glColor3ub(224, 104, 67);
    glVertex2i(137+150+home4cc,450+home4ccup);
    glColor3ub(227, 53, 0);
    glVertex2i(137+150+home4cc,257+home4ccup);
    glEnd();
    glPopMatrix();

    //building door
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52+150+home4cc,257+home4ccup);
    glVertex2i(87+150+home4cc,257+home4ccup);
    glVertex2i(87+150+home4cc,290+home4ccup);
    glVertex2i(52+150+home4cc,290+home4ccup);
    glEnd();
    glPopMatrix();

    //building window top single
    glPushMatrix();
    glColor3ub(232,232,232);
    glBegin(GL_QUADS);
    glVertex2i(25+150+home4cc,400+home4ccup);
    glVertex2i(25+150+home4cc,440+home4ccup);
    glVertex2i(265+home4cc,440+home4ccup);
    glVertex2i(265+home4cc,400+home4ccup);
    glEnd();
    glPopMatrix();

    //building window middle left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+150+home4cc,350+home4ccup);
    glVertex2i(25+150+home4cc,380+home4ccup);
    glVertex2i(50+150+home4cc,380+home4ccup);
    glVertex2i(50+150+home4cc,350+home4ccup);
    glEnd();
    glPopMatrix();

    //building window middle right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+150+home4cc,350+home4ccup);
    glVertex2i(90+150+home4cc,380+home4ccup);
    glVertex2i(115+150+home4cc,380+home4ccup);
    glVertex2i(115+150+home4cc,350+home4ccup);
    glEnd();
    glPopMatrix();

    //building window bottom left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+150+home4cc,310+home4ccup);
    glVertex2i(25+150+home4cc,340+home4ccup);
    glVertex2i(50+150+home4cc,340+home4ccup);
    glVertex2i(50+150+home4cc,310+home4ccup);
    glEnd();
    glPopMatrix();

    //building window bottom right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+150+home4cc,310+home4ccup);
    glVertex2i(90+150+home4cc,340+home4ccup);
    glVertex2i(115+150+home4cc,340+home4ccup);
    glVertex2i(115+150+home4cc,310+home4ccup);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

void Home1()
{
    //building body
    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(5,257);
    glVertex2i(5,398);
    glVertex2i(137,398);
    glVertex2i(137,257);
    glEnd();
    glPopMatrix();

    //building door
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52,257);
    glVertex2i(87,257);
    glVertex2i(87,290);
    glVertex2i(52,290);
    glEnd();
    glPopMatrix();

    //building window top left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25,350);
    glVertex2i(25,380);
    glVertex2i(50,380);
    glVertex2i(50,350);
    glEnd();
    glPopMatrix();

    //building window top right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90,350);
    glVertex2i(90,380);
    glVertex2i(115,380);
    glVertex2i(115,350);
    glEnd();
    glPopMatrix();

    //building window bottom left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25,310);
    glVertex2i(25,340);
    glVertex2i(50,340);
    glVertex2i(50,310);
    glEnd();
    glPopMatrix();

    //building window bottom right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90,310);
    glVertex2i(90,340);
    glVertex2i(115,340);
    glVertex2i(115,310);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

void Home3()
{
    //building body
    glPushMatrix();
    glColor3ub(227, 54, 149);
    glBegin(GL_QUADS);
    glVertex2i(5+home3cc,257);  //home4cc=700
    glVertex2i(5+home3cc,398);
    glVertex2i(137+home3cc,398);
    glVertex2i(137+home3cc,257);
    glEnd();
    glPopMatrix();

    //building door
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52+home3cc,257);
    glVertex2i(87+home3cc,257);
    glVertex2i(87+home3cc,290);
    glVertex2i(52+home3cc,290);
    glEnd();
    glPopMatrix();

    //building window top left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+home3cc,350);
    glVertex2i(25+home3cc,380);
    glVertex2i(50+home3cc,380);
    glVertex2i(50+home3cc,350);
    glEnd();
    glPopMatrix();

    //building window top right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+home3cc,350);
    glVertex2i(90+home3cc,380);
    glVertex2i(115+home3cc,380);
    glVertex2i(115+home3cc,350);
    glEnd();
    glPopMatrix();

    //building window bottom left
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(25+home3cc,310);
    glVertex2i(25+home3cc,340);
    glVertex2i(50+home3cc,340);
    glVertex2i(50+home3cc,310);
    glEnd();
    glPopMatrix();

    //building window bottom right
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(90+home3cc,310);
    glVertex2i(90+home3cc,340);
    glVertex2i(115+home3cc,340);
    glVertex2i(115+home3cc,310);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

void MetroRailPillar()
{
    for(int i=0;i<8*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(213,214,212);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158+pcor);
        glVertex2i(66+i,158+pcor);
        glVertex2i(66+i,165+pcor);
        glVertex2i(34+i,165+pcor);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(213,214,212);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160+pcor);
        glVertex2i(63+i,160+pcor);
        glVertex2i(63+i,167+pcor);
        glVertex2i(37+i,167+pcor);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(213,214,212);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162+pcor);
        glVertex2i(60+i,162+pcor);
        glVertex2i(60+i,211+pcor+pcor1);
        glVertex2i(40+i,211+pcor+pcor1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(213,214,212);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206+pcor+pcor1);
        glVertex2i(63+i,206+pcor+pcor1);
        glVertex2i(63+i,214+pcor+pcor1);
        glVertex2i(38+i,214+pcor+pcor1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(213,214,212);
        glBegin(GL_QUADS);
        glVertex2i(45+i,211+pcor+pcor1);
        glVertex2i(55+i,211+pcor+pcor1);
        glVertex2i(55+i,220+pcor+pcor1);
        glVertex2i(45+i,220+pcor+pcor1);
        glEnd();
        glPopMatrix();
    }
}

void MetroRailGutter()
{
    glPushMatrix();
    glColor3ub(213,214,212);
    glPopMatrix();
    glBegin(GL_QUADS);
    glVertex2i(60-3,198+24);
    glVertex2i(175-17,198+24);
    glVertex2i(184-17,220+24);
    glVertex2i(51-3,220+24);
    glEnd();
    glPushMatrix();
    glColor3ub(213,214,212);
    glPopMatrix();
    glBegin(GL_QUADS);
    glVertex2i(60-3+460,198+24);
    glVertex2i(175-17+460,198+24);
    glVertex2i(184-17+460,220+24);
    glVertex2i(51-3+460,220+24);
    glEnd();
}

void HospitalMidWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}

void Hospital()
{
    glPushMatrix();
    glColor3ub(111, 148, 89);
    glBegin(GL_QUADS);
    glVertex2i(151+hospitalcorrection,257);
    glVertex2i(181+hospitalcorrection,257);
    glVertex2i(181+hospitalcorrection,400);
    glVertex2i(151+hospitalcorrection,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(111, 148, 89);
    glBegin(GL_QUADS);
    glVertex2i(449+hospitalcorrection,257);
    glVertex2i(449+hospitalcorrection,400);
    glVertex2i(420+hospitalcorrection,400);
    glVertex2i(420+hospitalcorrection,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(111, 148, 89);
    glBegin(GL_QUADS);
    glVertex2i(181+hospitalcorrection,381);
    glVertex2i(420+hospitalcorrection,381);
    glVertex2i(420+hospitalcorrection,400);
    glVertex2i(181+hospitalcorrection,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,27,9);
    glBegin(GL_QUADS);
    glVertex2i(181+hospitalcorrection,258);
    glVertex2i(420+hospitalcorrection,258);
    glVertex2i(420+hospitalcorrection,381);
    glVertex2i(181+hospitalcorrection,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286+hospitalcorrection,257);
    glVertex2i(318+hospitalcorrection,257);
    glVertex2i(318+hospitalcorrection,298);
    glVertex2i(286+hospitalcorrection,298);
    glEnd();
    glPopMatrix();

    //window top row
    for(int hospitalwindowcorrection=50;hospitalwindowcorrection<6*38;hospitalwindowcorrection+=38)
    {
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(330+hospitalwindowcorrection,340);
        glVertex2i(330+hospitalwindowcorrection+22,340);
        glVertex2i(330+hospitalwindowcorrection+22,360);
        glVertex2i(330+hospitalwindowcorrection,360);
        glEnd();
        glPopMatrix();
    }

    //window bottom row
    for(int hospitalwindowcorrection=50;hospitalwindowcorrection<6*38;hospitalwindowcorrection+=38)
    {
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(330+hospitalwindowcorrection,305);
        glVertex2i(330+hospitalwindowcorrection+22,305);
        glVertex2i(330+hospitalwindowcorrection+22,325);
        glVertex2i(330+hospitalwindowcorrection,325);
        glEnd();
        glPopMatrix();
    }

    glutPostRedisplay();
}

void Khamba()
{
    for(int i=0;i<=8*100;i+=100)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(201, 201, 195);
        glVertex2i(15+i,190+20);
        glColor3ub(247, 247, 242);
        glVertex2i(25+i,190+20);
        glColor3ub(138, 138, 135);
        glVertex2i(25+i,285+20);
        glColor3ub(173, 173, 163);
        glVertex2i(15+i,285+20);
        glEnd();
        glPopMatrix();
    }
}

void Cables()
{


    for(int akash=25,cnt=1;cnt<=9;akash+=100,cnt++)
    {
        int x1=akash,y1=285+20,y2=180,x3=akash+100-10,y3=285+20;
        int x2=(x1+x3)/2;
        glBegin(GL_LINE_STRIP);
        for( float i = 0 ; i < 1 ; i += 0.01 )
        {
            float tempx=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
            float tempy=(1-i)*(1-i)*y1+3*(1-i)*i*y2+i*i*y3;

            // cout<<x<<" "<<y<<endl;
            glColor3f(0.0f,0.0f,0.0f);
            glVertex3f( tempx, tempy,0 );
        }

        glEnd();
    }
}

void Road()
{
    //road
    glPushMatrix();
    glColor3ub(102, 101, 101);
    glBegin(GL_QUADS);
    glVertex2i(0,200);
    glVertex2i(902,200);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    //road side footpath up
    glPushMatrix();
    glColor3ub(168, 142, 133);
    glBegin(GL_QUADS);
    glVertex2i(0,257);
    glVertex2i(902,257);
    glVertex2i(902,200);
    glVertex2i(0,200);
    glEnd();
    glPopMatrix();

    //road side footpath bottom
    glPushMatrix();
    glColor3ub(168, 142, 133);
    glBegin(GL_QUADS);
    glVertex2i(0,47);
    glVertex2i(902,47);
    glVertex2i(902,0);
    glVertex2i(0,0);
    glEnd();
    glPopMatrix();

    //road divider
    for(int i=0;i<=60*14;i+=60)
    {
        glPushMatrix();
        glColor3ub(179, 178, 177);
        glBegin(GL_QUADS);
        if(i!=360){
        glVertex2i(0+i,110);
        glVertex2i(45+i,110);
        glVertex2i(45+i,120);
        glVertex2i(0+i,120);}
        glEnd();
        glPopMatrix();
    }
}

void RoadCrack()
{
    //divider broken1
    for(int ap=0;ap<=60*14;ap+=60){
        if(ap!=120&&ap!=480&&ap!=720){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3ub(179, 178, 177);
    glVertex2i(45+ap,110);
    glVertex2i(45+ap,120);
    glVertex2i(51+ap,113);
    glEnd();}}
    //brick1
    glBegin(GL_TRIANGLES);
    glColor3ub(227, 98, 54);
    glVertex2i(656,185);
    glColor3ub(206, 209, 214);
    glVertex2i(640,185);
    glColor3ub(206, 209, 214);
    glVertex2i(640,193);
    //brick2
    glBegin(GL_TRIANGLES);
    glColor3ub(227, 98, 54);
    glVertex2i(656+120,185);
    glColor3ub(206, 209, 214);
    glVertex2i(640+120,185);
    glColor3ub(206, 209, 214);
    glVertex2i(640+120,193);
    //brick down
    for(int i=0;i<=80*14;i+=80){
        if(i!=240&&i!=540&&i!=720&&i!=360&&i!=480){
    glBegin(GL_TRIANGLES);
    glColor3ub(227, 98, 54);
    glVertex2i(666+120-i,185-90);
    glColor3ub(206, 209, 214);
    glVertex2i(640+120-i,175-90);
    glColor3ub(206, 209, 214);
    glVertex2i(637+120-i,193-90);}}
//    glColor3ub(102, 101, 101);
//    glVertex2i(656,193);
    glEnd();
}

void Rain()
{


    if( ttx < 50){
        ttx += 0.1;
    }
    if(ttx >= 50){
        waveSea();
    }
    glPushMatrix();
    glTranslatef(c1xp,(-1)*p1yp,0);
    glColor3ub(103,155,176);
    for(int j=0;j<20*160;j+=20)
    {
        for(int i=0;i<20*160;i+=20)
        {
            glBegin(GL_LINES);
            glVertex2f(0+i+j,0+i);
            glVertex2f(-5.5+i+j,10+i);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(0+i-j,0+i);
            glVertex2f(-5.5+i-j,10+i);
            glEnd();
        }
    }
    glPopMatrix();
}

void Car1()
{
    glPushMatrix();
    glColor3ub(184,184,33);
    glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-500,112+ccor);
    glVertex2i(414-500,112+ccor);
    glVertex2i(414-500,174+ccor);
    glVertex2i(311-500,174+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(184,184,33);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-500,162+ccor);
    glVertex2i(445-500,162+ccor);
    glVertex2i(473-500,134+ccor);
    glVertex2i(473-500,112+ccor);
    glVertex2i(414-500,112+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,89,89);
    glBegin(GL_QUADS);
    glVertex2i(417-500+88,158+ccor);
    glVertex2i(444-500+60,158+ccor);
    glVertex2i(444-500+60,139+ccor);
    glVertex2i(417-500+88,139+ccor);
    glEnd();
    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-500,158+ccor);
    glVertex2i(444-500,158+ccor);
    glVertex2i(463-500,139+ccor);
    glVertex2i(463-500,134+ccor);
    glVertex2i(417-500,134+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix(); //headlight top
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-500,128+ccor);
    glVertex2i(472-500,128+ccor);
    glVertex2i(472-500,123+ccor);
    glVertex2i(464-500,123+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix(); //headlight down
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-500,118+ccor);
    glVertex2i(472-500,118+ccor);
    glVertex2i(472-500,113+ccor);
    glVertex2i(464-500,113+ccor);
    glEnd();
    //glPopMatrix();


    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(342-500,116+ccor,15);


    //drawCircle(342-500,110,15);
    //drawCircle(342-500,110,15);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(434-500,116+ccor,15);


    //drawCircle(434-500,110,15);
    //drawCircle(434-500,110,15);
    glPopMatrix();
}

void Car2()
{
    glPushMatrix();
    glTranslatef(c2xp,c2yp,c2zp);
    glColor3ub(147, 149, 150);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(459+500,154-70);
    glVertex2i(466+500,160-70);
    glVertex2i(491+500,160-70);
    glVertex2i(510+500,179-70);
    glVertex2i(568+500,179-70);
    glVertex2i(579+500,162-70);
    glVertex2i(579+500,141-70);
    glVertex2i(459+500,141-70);
    glEnd();
    //glPopMatrix();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(503+500,169-70);
    glVertex2i(512+500,177-70);
    glVertex2i(525+500,177-70);
    glVertex2i(521+500,163-70);
    glVertex2i(503+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(526+500,163-70);
    glVertex2i(530+500,177-70);
    glVertex2i(565+500,177-70);
    glVertex2i(565+500,163-70);
    glEnd();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(474+500,142-70,10);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(551+500,142-70,10);

    glPopMatrix();
}

void Car3()
{
    glPushMatrix();
    glColor3ub(42, 145, 235);
    glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-150+cc,112+ccor);
    glVertex2i(414-150+cc,112+ccor);
    glVertex2i(414-150+cc,174+ccor);
    glVertex2i(311-150+cc,174+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(42, 145, 235);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-150+cc,162+ccor);
    glVertex2i(445-150+cc,162+ccor);
    glVertex2i(473-150+cc,134+ccor);
    glVertex2i(473-150+cc,112+ccor);
    glVertex2i(414-150+cc,112+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,89,89);
    glBegin(GL_QUADS);
    glVertex2i(417-150-88+cc,158+ccor);
    glVertex2i(444-150-60+cc,158+ccor);
    glVertex2i(444-150-60+cc,134+ccor);
    glVertex2i(417-150-88+cc,134+ccor);
    glEnd();
    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-150+cc,158+ccor);
    glVertex2i(444-150+cc,158+ccor);
    glVertex2i(463-150+cc,139+ccor);
    glVertex2i(463-150+cc,134+ccor);
    glVertex2i(417-150+cc,134+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix(); //headlight top
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-150+cc,128+ccor);
    glVertex2i(472-150+cc,128+ccor);
    glVertex2i(472-150+cc,123+ccor);
    glVertex2i(464-150+cc,123+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix(); //headlight down
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-150+cc,118+ccor);
    glVertex2i(472-150+cc,118+ccor);
    glVertex2i(472-150+cc,113+ccor);
    glVertex2i(464-150+cc,113+ccor);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(342-150+cc,116+ccor,15);


    //drawCircle(342-500,110,15);
    //drawCircle(342-500,110,15);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(434-150+cc,116+ccor,15);


    //drawCircle(434-500,110,15);
    //drawCircle(434-500,110,15);


    glPopMatrix();
}

float cdxp1=0.0;
float cdxp2=0.0;
float cdxp3=0.0;

float cloudClxp = 0.0;

float cloudx = 0.0;
void Cloud()
{

    if(cloudx < 850 ){
        cloudx += 0.01;
    }else cloudx -= 1460;

    glutPostRedisplay();

    glPushMatrix();
    glTranslatef(cloudClxp+cloudx,0,0);
    glColor3ub(230,234,237);
    drawCircle(594.0f,586.0f,20.0f);
    drawCircle(572.0f,595.0f,28.0f);
    drawCircle(539.0f,595.0f,35.0f);
    drawCircle(513.0f,575.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudClxp+cloudx,0,0);
    drawCircle(393.0f,577.0f,20.0f);
    drawCircle(370.0f,585.0f,28.0f);
    drawCircle(339.0f,583.0f,35.0f);
    drawCircle(311.0f,565.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudClxp+cloudx,0,0);
    drawCircle(193.0f,607.0f,20.0f);
    drawCircle(170.0f,615.0f,28.0f);
    drawCircle(139.0f,613.0f,35.0f);
    drawCircle(111.0f,595.0f,20.0f);
    glPopMatrix();

    glutPostRedisplay();
}

void CarTranslate(int value)
{
    width+=1.0;
    width2-=1.0;
    //width3-=0.01;

    if(width<10093)
    {
        cdxp1+=0.09;
        cdxp2+=0.1;
        cdxp3+=0.0001; //CloudsT variable

        c1xp+=0.1;
        if(width>10091)
        {
            width=-940;
            c1xp=0.0;
        }
        if(width==1295)
        {
            cdxp1=0.0;
        }
    }
    if(width2>-1614)
    {
        c2xp-=0.5;
        p1xp-=0.001;
        p1yp+=0.6;
        if(width2==-1613)
        {
            width2=600;
            c2xp=0;

            p1xp=0;
            p1yp=0;
            p1sxp=0;
            p1syp=0;
            x=1.0;
            glutPostRedisplay();
        }
        if(width2<1200)
        {
            p1sxp+=0.001;
            p1syp+=0.001;
            glutPostRedisplay();
        }
    }

    glutTimerFunc(0,CarTranslate,25);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='b')
    {
        CarTranslate(0);
        glutPostRedisplay();
    }
    if(key=='e')
    {
        exit(0);
    }
}

void Raining()
{
    if(r==0)
    {
        r=1;
    }else
    {
        r=0;
    }
}

void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
        PlaySound("storm-thunder.wav", NULL, SND_FILENAME| SND_ASYNC);
        Raining();
        break;
    default:
        break;
    }
}

void myInit (void)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    Home1();
    Home2();
    Home4();
    Home3();
    //drawFilledCircle(300.0f,400.0f,40.0f);
    Hospital();

    //Hotel();
    //Door();

    //School();
    //SchoolDoor();
    //HouseFrontTree();
    Sun();
    Cloud();
    //BetweenRoadAndBuldings();


    Cables();
    Road();
    Khamba();
    RoadCrack();
    Car3();     //truck right
    Car1();     //truck left
    MetroRailPillar();
    MetroRailGutter();

    Car2();     //car below

    if(r==1)
    {

        //ttx=0.0;
        Rain();
        //Sleep(900);

    }
    glFlush ();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (902,684);
    glutInitWindowPosition (250, 30);
    glutCreateWindow ("Graphics Project 2D Dhaka City Road");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    myInit ();
    glutMainLoop();
}
