#pragma once
#include <string>

enum class Color{
	White,
	Green,
	Blue,
	Violet,
	Yellow,
	Red,
};

class Cell {
	public:
		Cell();
		Cell(std::string value, Color color);
		void setValue(std::string myText);
		void setColor(const std::string& myColor);
		void setColorC(const Color& myColor);
		std::string getValue();
		std::string getColor();
		Color getColorC();
		int toInt();
		double toDouble();
		void reset();
	private:
		std::string value;
		Color color;

};
