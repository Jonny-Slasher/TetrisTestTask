
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
	//Посторение и отрисовка Фигур тетромино и поля 
	void PrintBoard();//отобразить игровое поле
	bool CreateTetromino();//создать тетрамино
	void PrintTetramino(const Tetromino*);//отобразить тетрамино
	void PrintNextTetromino();//печать следующего тетрамино
	void ClearTempTetr();//удалить предыдущее тетрамино
	void FixOnField();//фиксация тетрамино на поле
	void ShowScore();//показ очков
	//проверки
	bool DownIsClear();//чисто ли внизу
	bool LeftIsClear();//чисто ли слева
	bool RightIsClear();//чисто ли справа
	bool CanRotateTetromino();//возможен ли поворот
	bool ClearLine();//очистка линии

};
