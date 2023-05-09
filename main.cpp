#include <iostream>
#include "spreadsheet.h"

int main() {
	Cell* c = new Cell();
	c->setValue("23.5");
	std::cout << c->getValue() << std::endl;
	std::cout << c->getColor() << std::endl;
//	c->reset();
//	std::cout << c->getValue() << std::endl;
	double num = 0;
 	try {
		num = c->toDouble();
		std::cout << ++num << std::endl;
	} catch (const char* msg) {
		std::cout << msg << std::endl;
	}
	int n = 3;
	int m = 3;
	while(n <= 0 || m <= 0){
		std::cout << "Enter valid parameters for spreadsheet\n";
		std::cin >> n >> m;
	}
	Spreadsheet s(n, m);
/*	s.setCellAt(0, 0);
	std::cout << std::endl;
	s.setCellAt(2, 0);
	int i = 0;
	int j = 0;
	Cell myCell = s.getCellAt(i, j);
	std::cout << myCell.getValue() << " " << myCell.getColor() << std::endl;
	s.addRowAt(3);
	std::cout << s.getRow() << std::endl;
	s.removeRowAt(0);
	std::cout << s.getRow() << std::endl;
	s.swapRows(0, 2);
	Cell myCell3 = s.getCellAt(0, 0);
	std::cout << myCell3.getValue() << std::endl;*/
	s.setCellAt(0, 0);
	std::cout << std::endl;
	s.setCellAt(0, 2);
	s.setCellAt(0, 1);
	s.swapCols(0, 2);
	Cell newCell = s.getCellAt(0, 1);
	std::cout << newCell.getValue() << " " << newCell.getColor() << std::endl;
	s.addColAt(1);
	Cell newCell2 = s.getCellAt(0, 1);
	std::cout << newCell2.getValue() << " " << newCell2.getColor() << std::endl;
	Cell newCell3 = s.getCellAt(0, 2);
	std::cout << newCell3.getValue() << " " << newCell3.getColor() << std::endl;
	std::cout << s.getCol() << std::endl;
	delete c;
	return 0;
}
