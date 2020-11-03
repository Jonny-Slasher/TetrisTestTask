#include "Tetromino.h"


Tetromino::Tetromino(int c_x, int c_y, int sz_x, int sz_y) :size_x(sz_x), size_y(sz_y), arr(0)
{
	this->x = c_x;
	this->y = c_y;
	InitArray();
}

Tetromino::Tetromino(int c_x, int c_y) :size_x(0), size_y(0), arr(0)
{
	this->x = c_x;
	this->y = c_y;

}

Tetromino::~Tetromino()
{
}



void Tetromino::RotateTetromino()
{

	if (arr == 0) {
		return;
	}

	//������������� ��������� �������
	char** temp_arr;
	temp_arr = new char* [size_x];
	for (int i = 0; i < size_x; i++) {
		temp_arr[i] = new char[size_y];
	}
	//����������� ������� ��� �� ���������
	for (int x = 0; x < size_x; x++) {
		for (int y = 0; y < size_y; y++) {
			temp_arr[x][y] = arr[x][y];
		}
	}
	//������� ������������ �������
	ClearArray();
	//������ ������� �������� size_x � size_y

	int temp = size_x;
	size_x = size_y;
	size_y = temp;
	//
	InitArray();
	//������� ������� � ������ � � ������
	for (int x = 0; x < size_x; x++) {
		for (int y = 0; y < size_y; y++) {
			arr[x][y] = temp_arr[y][size_x - x - 1];
		}
	}
	for (int i = 0; i < size_y; i++) {
		delete[] temp_arr[i];
	}
	delete[] temp_arr;
}

//������������ ��������� ������ ��� �������
void Tetromino::InitArray()
{
	arr = new char* [size_x];
	for (int i = 0; i < size_x; i++) {
		arr[i] = new char[size_y];
	}
	for (int x = 0; x < size_x; x++) {
		for (int y = 0; y < size_y; y++) {
			arr[x][y] = ' ';
		}
	}
}

//�������� �������
void Tetromino::ClearArray()
{
	for (int i = 0; i < size_x; i++)
		delete[] arr[i];
	delete[] arr;
}

//��������� ����������� � �������  ��������� ���������
TetrominoO::TetrominoO(int x, int y) :Tetromino(x, y, 2, 2)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j] = 'O';
		}
	}

}


Tetromino* TetrominoO::CopyTetromino()
{
	TetrominoO* temp = new TetrominoO(this->x, this->y);
	return temp;
}

void TetrominoO::RotateTetromino()
{
}


//��������� ����������� � �������  ��������� I
TetrominoI::TetrominoI(int x, int y, bool side) : Tetromino(x, y, 1, 4), tet_side(0)
{
	for (int x = 0; x < 1; x++) {
		for (int y = 0; y < 4; y++) {
			arr[x][y] = 'O';
		}
	}
	if (side != tet_side)
		RotateTetromino();
}

Tetromino* TetrominoI::CopyTetromino()
{
	TetrominoI* temp = new TetrominoI(this->x, this->y, tet_side);
	return temp;
}

void TetrominoI::RotateTetromino()
{
	Tetromino::RotateTetromino();
	tet_side = !tet_side;
}


//��������� ����������� � �������  ��������� L
TetrominoL::TetrominoL(int x, int y, int side) :Tetromino(x, y, 2, 3), tet_side(0)
{
	arr[0][0] = 'O';
	arr[0][1] = 'O';
	arr[0][2] = 'O';
	arr[1][2] = 'O';
	while (tet_side < side)
		RotateTetromino();
}

Tetromino* TetrominoL::CopyTetromino()
{
	return new TetrominoL(this->x, this->y, tet_side);
}

void TetrominoL::RotateTetromino()
{

	Tetromino::RotateTetromino();
	if (++tet_side > 3)
		tet_side = 0;
}

//��������� ����������� � �������  ��������� J
TetrominoJ::TetrominoJ(int x, int y, int side) :Tetromino(x, y, 2, 3), tet_side(0)
{
	arr[1][0] = 'O';
	arr[1][1] = 'O';
	arr[1][2] = 'O';
	arr[0][2] = 'O';
	while (tet_side < side)
		RotateTetromino();

}

Tetromino* TetrominoJ::CopyTetromino()
{
	return new TetrominoJ(this->x, this->y, tet_side);
}

void TetrominoJ::RotateTetromino()
{
	Tetromino::RotateTetromino();
	if (++tet_side > 3)
		tet_side = 0;
}

//��������� ����������� � �������  ��������� Z
TetrominoZ::TetrominoZ(int x, int y, int side) :Tetromino(x, y, 3, 2), tet_side(0)
{
	arr[0][0] = 'O';
	arr[1][0] = 'O';
	arr[1][1] = 'O';
	arr[2][1] = 'O';
	while (tet_side < side)
		RotateTetromino();
}

Tetromino* TetrominoZ::CopyTetromino()
{
	return new TetrominoZ(this->x, this->y, tet_side);
}

void TetrominoZ::RotateTetromino()
{
	Tetromino::RotateTetromino();
	if (++tet_side > 3)
		tet_side = 0;
}

//��������� ����������� � �������  ��������� S
TetrominoS::TetrominoS(int x, int y, int side) :Tetromino(x, y, 3, 2), tet_side(0)
{
	arr[1][0] = 'O';
	arr[2][0] = 'O';
	arr[1][1] = 'O';
	arr[0][1] = 'O';
	while (tet_side < side)
		RotateTetromino();

}

Tetromino* TetrominoS::CopyTetromino()
{
	return new TetrominoS(this->x, this->y, tet_side);
}

void TetrominoS::RotateTetromino()
{
	Tetromino::RotateTetromino();
	if (++tet_side > 3)
		tet_side = 0;
}

//��������� ����������� � �������  ��������� T
TetrominoT::TetrominoT(int x, int y, int side) :Tetromino(x, y, 3, 2), tet_side(0)
{
	arr[1][1] = 'O';
	arr[0][0] = 'O';
	arr[1][0] = 'O';
	arr[2][0] = 'O';
	while (tet_side < side)
		RotateTetromino();
}

Tetromino* TetrominoT::CopyTetromino()
{
	return new TetrominoT(this->x, this->y, tet_side);
}

void TetrominoT::RotateTetromino()
{
	Tetromino::RotateTetromino();
	if (++tet_side > 3)
		tet_side = 0;
}

