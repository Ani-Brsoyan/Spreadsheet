#pragma once
#include "cell.h"

class Spreadsheet
{
	public:
		Spreadsheet(int r, int c);
		int getRow();
		int getCol();
		void setCellAt(int r, int c);
		Cell getCellAt(int r, int c);
		void addRowAt(int index);
		void removeRowAt(int index);
		void swapRows(int r1, int r2);
		void addColAt(int index);
		void removeColAt(int index);
		void swapCols(int c1, int c2);
		~Spreadsheet();
	private:
		Cell** CellAr;
		int row;
		int col;
};
