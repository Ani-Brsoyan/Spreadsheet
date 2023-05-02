#include "cell.h"
#include <iostream>

Cell::Cell() {
	this->value = " ";
	this->color = Color::White;
}

Cell::Cell(std::string value,Color color) {
	this->value = value;
	this->color = color;
}

void Cell::setValue(std::string myText) {
	this->value = myText;
}

std::string Cell::getValue() {
	return this->value;
}

//try to implement with std::map <string, int>
void Cell::setColor(const std::string& myColor) {
	if(myColor == "White"){
		this->color = Color::White;
	}else if(myColor == "Green"){
		this->color = Color::Green;
	}else if(myColor == "Blue"){
		this->color = Color::Blue;
	}else if(myColor == "Violet"){
		this->color = Color::Violet;
	}else if(myColor == "Yellow"){
		this->color = Color::Yellow;
	}else if(myColor == "Red"){
		this->color = Color::Red;
	}else {
		std::cout << "Invalid color: Your cell color is setted white\n";
		this->color = Color::White;
	}
}

void Cell::setColorC(const Color& myColor){
	this->color = myColor;
}

std::string Cell::getColor() {
	switch(static_cast<int>(this->color)){
		case 1:{
			return "Green";
			break;
		       }
		case 2:{
			return "Blue";
			break;
		       }
		case 3:{
			return "Violet";
			break;
		       }
		case 4:{
			return "Yellow";
			break;
		       }
		case 5:{
			return "Red";
			break;
		       }
		default:
			return "White";	
	}
}

Color Cell::getColorC(){
	return this->color;
}

int Cell::toInt() {
	int i = 0;
	std::string myString = this->value;
	while(myString[i] != '\0'){
		if(myString[i] < '0' || myString[i] > '9'){
			throw "Not an Int";
		}
		i++;
	}
	return std::stoi(myString);
}

double Cell::toDouble() {
	int i = 0;
	int point = 0;
	std::string myString = this->value;
	while (myString[i] != '\0'){
		if(myString[i] == '.'){
			point++;
			i++;
		}
		if(myString[i] < '0' || myString[i] > '9' || (point > 1)) {
			throw "Not a Double";
		}
		i++;
	}
	return std::stod(myString);

}

void Cell::reset() {
	this->value = " ";
	this->color = Color::White;
}
