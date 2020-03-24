#include <iostream>
#include "OGLPong.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Hide(){
  HWND Hide;
  AllocConsole(); 
  Hide = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Hide,0);
}
game settings;
Ball ball ;
reflection leftP;
reflection rightP;
int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition (settings.winXPos,settings.winYPos);
	glutInitWindowSize(settings.winWid, settings.winHeid);
	glutCreateWindow("Ping_POng");
	glutDisplayFunc(draw);
	glutTimerFunc(settings.delay, Timer, 0);
	glutKeyboardFunc(keyboardf);
	glutKeyboardUpFunc(keyboardUpf);
	glClearColor(0,0,0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-settings.orthoWid, settings.orthoWid, -settings.orthoHeid, settings.orthoHeid);
	Hide();
	glutMainLoop();
	
	return 0;
}
