// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include <ctime>
#include<tchar.h>
TestApp::TestApp() : BaseApp(bcgrX + 7, bcgrY), real_time(0), temp_tetromino(0), step_time(1)
{

	srand(time(0));
	next_tetromino = rand() % 7;
	CreateTetromino();

}

void TestApp::KeyPressed(int btnCode)
{
	if (btnCode == 72) //up
	{
	}
	else if (btnCode == 80) {//down

		while (DownIsClear())
			tetromino->y++;
		real_time = step_time;
	}

	else if (btnCode == 75) //left
	{
		if (LeftIsClear())
			tetromino->x--;
	}
	else if (btnCode == 77) //right
	{
		if (RightIsClear())
			tetromino->x++;
	}
	else if (btnCode == 32)//space
	{
		ClearTempTetr();
		if (CanRotateTetromino()) {
			tetromino->RotateTetromino();
			temp_tetromino = tetromino->CopyTetromino();
		}

	}

	if (tetromino->x < 0)
		tetromino->x = 0;
	else if (tetromino->x + tetromino->GetSizeX() > bcgrX - 1)
		tetromino->x = bcgrX - tetromino->GetSizeX();

}

void TestApp::UpdateF(float deltaTime)
{

	ClearTempTetr();
	ClearLine();
	real_time += deltaTime;
	if (real_time > step_time) {
		real_time = 0;


		if (DownIsClear()) {

			tetromino->y++;
		}
		else {
			FixOnField();
			if (!CreateTetromino()) {
				cout << " Game is over \nYour score is: " << score << endl;
				exit(0);
			}
		}
	}
	temp_tetromino = tetromino->CopyTetromino();
	PrintTetramino(tetromino);
	PrintBoard();
	PrintNextTetromino();
	ShowScore();
}

void TestApp::PrintBoard()
{
	for (int x = 0; x <= bcgrX; x++)

		SetChar(x, 0, '_');
	for (int x = 0; x <= bcgrX; x++)
		SetChar(x, Y_SIZE, '=');
	for (int y = 1; y <= Y_SIZE; y++)
	{
		SetChar(0, y, '|');
		SetChar(bcgrX, y, '|');
	}


}



bool TestApp::CreateTetromino()
{
	int rand_tetromino = next_tetromino;
	next_tetromino = rand() % 7;
	int side = rand() % 4;
	switch (rand_tetromino) {
	case 0:
		tetromino = new TetrominoO(7, 1);
		break;
	case 1:

		tetromino = new TetrominoI(7, 1, true);
		break;
	case 2:
		tetromino = new TetrominoL(7, 1, side);
		break;
	case 3:
		tetromino = new TetrominoJ(7, 1, side);
		break;
	case 4:
		tetromino = new TetrominoZ(7, 1, side);
		break;
	case 5:
		tetromino = new TetrominoS(7, 1, side);
		break;
	case 6:
		tetromino = new TetrominoT(7, 1, side);
		break;
	default:
		break;
	}



	for (int x = 0; x < tetromino->GetSizeX(); x++) {
		for (int y = 0; y < tetromino->GetSizeY(); y++) {
			if (GetChar(tetromino->x + x, tetromino->y + y) != ' ') {
				return false;
			}
		}
	}
	temp_tetromino = tetromino->CopyTetromino();
	return true;
}

void TestApp::PrintTetramino(const Tetromino* tetromino)
{
	for (int x = 0; x < tetromino->GetSizeX(); x++) {
		for (int y = 0; y < tetromino->GetSizeY(); y++) {
			if (tetromino->arr[x][y] != ' ') {
				SetChar(x + tetromino->x, y + tetromino->y, tetromino->arr[x][y]);
			}
		}
	}
}

void TestApp::PrintNextTetromino()
{
	for (int y = 1; y < 7; y++)
		for (int x = X_SIZE - 6; x < X_SIZE; x++)
			SetChar(x, y, ' ');
	Tetromino* next = 0;
	switch (next_tetromino)
	{
	case 0:
		next = new TetrominoO(X_SIZE - 4, 2);
		break;
	case 1:
		next = new TetrominoI(X_SIZE - 5, 3, true);
		break;
	case 2:
		next = new TetrominoL(X_SIZE - 5, 2, 2);
		break;
	case 3:
		next = new TetrominoJ(X_SIZE - 5, 2, 2);
		break;
	case 4:
		next = new TetrominoZ(X_SIZE - 5, 2, 2);
		break;
	case 5:
		next = new TetrominoS(X_SIZE - 5, 2, 2);
	case 6:
		next = new TetrominoT(X_SIZE - 5, 2, 2);
	default:
		return;
		break;
	}
	PrintTetramino(next);
}

void TestApp::ClearTempTetr()
{

	for (int x = 0; x < temp_tetromino->GetSizeX(); x++) {
		for (int y = 0; y < temp_tetromino->GetSizeY(); y++) {
			if (temp_tetromino->arr[x][y] != ' ') {
				SetChar(x + temp_tetromino->x, y + temp_tetromino->y, ' ');
			}
		}
	}
}

void TestApp::FixOnField()
{
	ClearTempTetr();
	for (int x = 0; x < tetromino->GetSizeX(); x++)
		for (int y = 0; y < tetromino->GetSizeY(); y++)
			if (tetromino->arr[x][y] != ' ')
				SetChar(x + tetromino->x, y + tetromino->y, 'O');
	delete tetromino;
	delete temp_tetromino;
}

void TestApp::ShowScore()
{
	for (int i = 0; i < 6; i++)
		SetChar(X_SIZE - 6 + i, 6, *(L"Score:" + i));
	string scr = to_string(score);
	for (int i = 0; i < scr.length(); i++)
		SetChar(X_SIZE - 3 + i, 7, scr[i]);

}

bool TestApp::DownIsClear()
{
	if (tetromino->y + tetromino->GetSizeY() > Y_SIZE)
		return false;
	for (int x = 0; x < tetromino->GetSizeX(); x++)
		for (int y = tetromino->GetSizeY() - 1; y >= 0; y--)
			if (tetromino->arr[x][y] != ' ')
			{
				if (GetChar(tetromino->x + x, tetromino->y + y + 1) != ' ')
					return false;
				else
					break;
			}
	return true;
}

bool TestApp::LeftIsClear()
{
	for (int y = 0; y < tetromino->GetSizeY(); y++)
		for (int x = 0; x < tetromino->GetSizeX(); x++)
			if (tetromino->arr[x][y] != ' ')
			{
				if (GetChar(tetromino->x + x - 1, tetromino->y + y) != ' ')
					return false;
				else
					break;
			}
	return true;
}

bool TestApp::RightIsClear()
{
	for (int y = 0; y < tetromino->GetSizeY(); y++)
		for (int x = tetromino->GetSizeX() - 1; x >= 0; x--)
			if (tetromino->arr[x][y] != ' ')
			{
				if (GetChar(tetromino->x + x + 1, tetromino->y + y) == 'O')
					return false;
				else
					break;
			}
	return true;
}

bool TestApp::CanRotateTetromino()
{
	Tetromino* temp = tetromino->CopyTetromino();
	temp->RotateTetromino();
	for (int y = 0; y < temp->GetSizeY(); y++)
		for (int x = 0; x < temp->GetSizeX(); x++)
			if (temp->arr[x][y] != ' ' && GetChar(temp->x + x, temp->y + y) == 'O')
				return false;
	return true;
}

bool TestApp::ClearLine()
{
	bool flag;
	for (int y = Y_SIZE - 1; y > 0; y--)
	{
		flag = true;
		for (int x = 1; x < bcgrX; x++)
			if (GetChar(x, y) == ' ')
			{
				flag = false;
				break;
			}
		if (!flag)
			continue;

		for (int x = 1; x < bcgrX; x++)
			SetChar(x, y, ' ');

		for (int i = y; i > 1; i--)
			for (int x = 0; x < bcgrX; x++)
				SetChar(x, i, GetChar(x, i - 1));

		score++;
		return true;
	}
	return false;
}




