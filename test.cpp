/**
Parikshit Bhetwal
Dennis Lim 
PE 5
This is the test file for 
programming exercise five. 
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

// Tests the Factorial() function 
TEST_CASE ("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
}

// Tests the Rectangle() constructor 
TEST_CASE("Rectangle class constructor", "[rectangle-constructor]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 2, 
		.y = 2
	};
	Rectangle r1(p1, p2); 
	REQUIRE((r1.get_p1().x == 1 && r1.get_p1().y == 1 
			 && r1.get_p2().x == 2 && r1.get_p2().y == 2)); 
}

// Tests the GetWidth() method 
TEST_CASE("Rectangle get width", "[rectangle-width]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 2
	};
	Rectangle r1(p1, p2); 
	REQUIRE(r1.GetWidth() == p2.x - p1.x); 

}

// Tests the GetHeight() method 
TEST_CASE("Rectangle get height", "[rectangle-height]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 3
	};
	Rectangle r1(p1, p2); 
	REQUIRE(r1.GetHeight() == p2.y - p1.y); 
}
