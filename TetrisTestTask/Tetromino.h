#pragma once

class Tetromino
{
protected:

	int size_x;
	int size_y;

public:

	int x;
	int y;
	char** arr;

	//������������
	Tetromino(int, int, int, int);
	Tetromino(int, int);

	//����������
	virtual ~Tetromino();

	//����������� �������
	virtual Tetromino* CopyTetromino() = 0;

	//������� �������
	virtual void RotateTetromino() = 0;

	//��������� ������ ��� ������� �������
	void InitArray();

	//������� ������� �������
	void ClearArray();

	//������� �������� �������
	int GetSizeX() const { return size_x; }
	int GetSizeY() const { return size_y; }

};

//��������� - �������
class TetrominoO : public Tetromino {
public:
	TetrominoO(int, int);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
};

//��������� - ������� I
class TetrominoI : public Tetromino {
public:
	TetrominoI(int, int, bool = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	bool tet_side;
};

//��������� - L
class TetrominoL : public Tetromino {
public:
	TetrominoL(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//��������� - J
class TetrominoJ : public Tetromino {
public:
	TetrominoJ(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//��������� - Z
class TetrominoZ : public Tetromino {
public:
	TetrominoZ(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//��������� - S
class TetrominoS : public Tetromino {
public:
	TetrominoS(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//��������� - T
class TetrominoT : public Tetromino {
public:
	TetrominoT(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};