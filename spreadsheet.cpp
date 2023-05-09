#include "spreadsheet.h"
#include <iostream>

Spreadsheet::Spreadsheet(int r, int c)
	:row(r)
	,col(c){
		CellAr = new Cell*[r];
		for(int i = 0; i < r; i++){
			CellAr[i] = new Cell[c];
		}
}

int Spreadsheet::getRow(){
	return row;
}

int Spreadsheet::getCol(){
	return col;
}

void Spreadsheet::setCellAt(int r, int c){
	if(r >= row || c >= col){
		std::cout << "There is not a cell with these coordinates\n";
	}else{
		std::cout << "Enter the cell containment\n";
		std::string str;
		std::cin.ignore();//BE CAREFUL
		std::getline(std::cin, str);
		CellAr[r][c].setValue(str);
	//	std::cout << CellAr[r][c].getValue() << std::endl;
		std::cout << "Enter cell color (first letter uppercase)\n";
		std::string myColor;
		std::cin >> myColor;
		CellAr[r][c].setColor(myColor);
	//	std::cout << CellAr[r][c].getColor() << std::endl;
	}	
}

Cell Spreadsheet::getCellAt(int r, int c){
	return CellAr[r][c];
}

void Spreadsheet::addRowAt(int index){
	if(index > row){
		return;
	}
	row += 1;
	Cell** mat = new Cell*[row];
	for(int i = 0; i < row; i++){
		if(i == index){
			mat[i] = new Cell[col];
		}else{
			mat[i] = CellAr[i];
		}
	}
	delete[] CellAr;
	CellAr = mat;
}

void Spreadsheet::removeRowAt(int index){
	if(index >= row){
		return;
	}
	Cell* tmp = CellAr[index];
	for(int i = index; i < row - 1; i++){
		CellAr[i] = CellAr[i + 1];
	}
	CellAr[row - 1] = tmp;
	delete[] CellAr[row - 1];
	row -= 1;
}

void Spreadsheet::swapRows(int r1, int r2){
	if(r1 >= row || r2 >= row){
		return;
	}
	Cell* tmp = CellAr[r1];
	CellAr[r1] = CellAr[r2];
	CellAr[r2] = tmp;
}

void Spreadsheet::addColAt(int index){
	if(index > col){
		return;
	}
	col = col + 1;
	Cell* tmp;
	for(int i = 0; i < row; i++){
		tmp = new Cell[col];
		int j = 0;
		for(int j_tmp = 0; j_tmp < col; j_tmp++){
			if(j_tmp != index){
				tmp[j_tmp].setColorC(CellAr[i][j].getColorC());
				tmp[j_tmp].setValue(CellAr[i][j].getValue());
				j++;
			}
		}
		delete[] CellAr[i];
		CellAr[i] = tmp;
	}
}

void Spreadsheet::removeColAt(int index){
	if(index >= col){
		return;
	}
	for(int i = 0; i < row; i++){
		for(int j = index; j < col - 1; j++){
			CellAr[i][j].setColorC(CellAr[i][j + 1].getColorC());
			CellAr[i][j].setValue(CellAr[i][j + 1].getValue());
		}
	}
	col = col - 1;
}

void Spreadsheet::swapCols(int c1, int c2){
	if(c1 >= col || c2 >= col){
		return;
	}
	Color c_tmp;
	std::string s_tmp;
	for(int i = 0; i < row; i++){
		c_tmp = CellAr[i][c1].getColorC();
		CellAr[i][c1].setColorC(CellAr[i][c2].getColorC());
		CellAr[i][c2].setColorC(c_tmp);
		s_tmp = CellAr[i][c1].getValue();
		CellAr[i][c1].setValue(CellAr[i][c2].getValue());
		CellAr[i][c2].setValue(s_tmp);	
	}
	
}

Spreadsheet::~Spreadsheet(){
	for(int i = 0; i < row; i++){
		delete[] CellAr[i];
	}
	delete[] CellAr;
}
