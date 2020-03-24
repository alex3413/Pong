
#include "OGLPong.h"

void reflection::draw(){
	glColor3f(1,1,1);
	glVertex2f(x+settings.pThickness,y+size/2);
	glVertex2f(x+settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y+size/2);
	
}
void reflection::move(){
	y +=vy;
	if(y < -settings.fieldSizeY + size/2){
		y = -settings.fieldSizeY + size/2;
		vy = 0;
	}
	if(y > settings.fieldSizeY - size/2){
		y = settings.fieldSizeY - size/2;
		vy = 0;
	}
}
void reflection::care(){
	if(hold){
		ball.vx = 0;
		if(x < 0)
			ball.x = x + 2*settings.pThickness;
		if(x > 0)
			ball.x = x - 2*settings.pThickness;
		ball.vy=vy;
		ball.y = y;
	}
}
