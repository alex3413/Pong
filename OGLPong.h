#pragma once
#pragma comment(lib, ws2_32.lib)
#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <winsock2.h>
void keyboardf(unsigned char, int,int);
void keyboardUpf(unsigned char, int,int);
void draw();
void Timer (int);
void mainSocket(int);

class reflection{
	public:
		float red, green, blue;
		float x,y;
		float vy;
		float size;
		bool up,down,hold;
	reflection(float ,float ,float);
	reflection();
	
	void draw(float ,float ,float );
	void draw();
	
	void move();
	void care();
};

class game{
	public:
	int orthoWid; // ������� ������������ �����
	int orthoHeid;
	
	int winWid; // ������ ����
	int winHeid;
	
	int winXPos; // ������� ����
	int winYPos;
	
	float fieldSizeX; // ������� �������� ����
	float fieldSizeY;
	
	int delay; //��������� ��� ������
	
	float pThickness;// ������� ���������
	float ballSize; // ������ ������
	float borderT; // ������� ����� ����
	float mLineT; // ������� ����� ����������
	int scoreL; // ���������� ����� �������
	int scoreR;
	float textPosX; 
	float textPosY;
	float ballSpeedX; // �������� ������ �� �
	float pSpeedY; // �������� ��������
	
	game(){
	orthoWid = 700; // ������� ������������ �����
	orthoHeid = 700;
	
	winWid = 700; // ������ ����
	winHeid = 700;
	
	winXPos = 100; // ������� ����
	winYPos = 100;
	
	fieldSizeX = 600; // ������� �������� ����
	fieldSizeY = 400;
	
	delay = 1; //��������� ��� ������
	
	pThickness = 10;// ������� ���������
	ballSize = 5; // ������ ������
	borderT = 10; // ������� ����� ����
	mLineT = 5; // ������� ����� ����������
	scoreL = 0; // ���������� ����� �������
	scoreR = 0;
	textPosX = 0; 
	textPosY = fieldSizeY+10;
	ballSpeedX = 0.5; // �������� ������ �� �
	pSpeedY = 1; // �������� ��������
	}
	void start_settings();
	void win();
	void keyControl();
	void keyReset();
	void drawField();
	void drawScore();
};
class Ball{
	public:
		float r,g,b;
		float x;
		float y;
		float vx;
		float vy;
	void move();
	void reflection();
	void draw();
};

extern game settings;
extern Ball ball ;
extern reflection leftP;
extern reflection rightP;










