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

	//конструкторы
	Tetromino(int, int, int, int);
	Tetromino(int, int);

	//деструктор
	virtual ~Tetromino();

	//копирование фигурки
	virtual Tetromino* CopyTetromino() = 0;

	//поворот фигурки
	virtual void RotateTetromino() = 0;

	//выделение памяти под матрицу фигурки
	void InitArray();

	//очистка матрицы фигурки
	void ClearArray();

	//геттеры размеров фигурки
	int GetSizeX() const { return size_x; }
	int GetSizeY() const { return size_y; }

};

//тетромино - квадрат
class TetrominoO : public Tetromino {
public:
	TetrominoO(int, int);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
};

//тетромино - палочка I
class TetrominoI : public Tetromino {
public:
	TetrominoI(int, int, bool = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	bool tet_side;
};

//тетромино - L
class TetrominoL : public Tetromino {
public:
	TetrominoL(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//тетромино - J
class TetrominoJ : public Tetromino {
public:
	TetrominoJ(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//тетромино - Z
class TetrominoZ : public Tetromino {
public:
	TetrominoZ(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//тетромино - S
class TetrominoS : public Tetromino {
public:
	TetrominoS(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};

//тетромино - T
class TetrominoT : public Tetromino {
public:
	TetrominoT(int, int, int = 0);
	virtual Tetromino* CopyTetromino();
	virtual void RotateTetromino();
	int tet_side;
};