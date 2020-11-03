
#pragma once

#include "BaseApp.h"
#include"Tetromino.h"
#define bcgrX 16
#define bcgrY 20
class TestApp : public BaseApp
{
	typedef BaseApp Parent;

private:
	float real_time;
	float step_time;
public:
	int next_tetromino;
	Tetromino* tetromino;
	Tetromino* temp_tetromino;
	int score = 0;
	TestApp();
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
	//���������� � ��������� ����� ��������� � ���� 
	void PrintBoard();//���������� ������� ����
	bool CreateTetromino();//������� ���������
	void PrintTetramino(const Tetromino*);//���������� ���������
	void PrintNextTetromino();//������ ���������� ���������
	void ClearTempTetr();//������� ���������� ���������
	void FixOnField();//�������� ��������� �� ����
	void ShowScore();//����� �����
	//��������
	bool DownIsClear();//����� �� �����
	bool LeftIsClear();//����� �� �����
	bool RightIsClear();//����� �� ������
	bool CanRotateTetromino();//�������� �� �������
	bool ClearLine();//������� �����

};
