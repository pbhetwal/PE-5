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

// Tests the Overlaps() method 
TEST_CASE("Rectangle overlaps", "[rectangle-overlaps]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 1
	};

	Point p3 = {
		.x = 2, 
		.y = 2
	}; 

	Point p4 = {
		.x = 3, 
		.y = 3
	};

	Rectangle r1(p1, p2); 
	Rectangle r2(p1, p2); 
	Rectangle r3(p3, p4); 
	REQUIRE(r1.Overlaps(r2) == true); 
	REQUIRE(r1.Overlaps(r3) == false);
}

// Tests the CalculateArea() method 
TEST_CASE("Rectangle calculate area", "[rectangle-calculatearea]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 3
	};
	Rectangle r1(p1, p2); 
	// We could use: REQUIRE(r1.CalculateArea() == r1.GetWidth() * r1.GetHeight())
	// but that would rely on other methods, we only want to test this method 
	REQUIRE(r1.CalculateArea() == (p2.x - p1.x) * (p2.y - p1.y)); 
}

// Tests the Expand() method
TEST_CASE("Rectangle expand", "[rectangle-expand]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 3
	};

	Rectangle r1(p1, p2); 
	r1.Expand(); 

	// Moves the bottom left coordinate down one and to the left one
	// p1 is bottom left
	REQUIRE((r1.get_p1().x == p1.x-1 && r1.get_p1().y == p1.y-1));
	// Moves the upper right coordinate up one and to the right one
	// p2 is upper right 
	REQUIRE((r1.get_p2().x == p2.x+1 && r1.get_p2().y == p2.y+1)); 
}


// Tests the Shrink() method 
TEST_CASE("Rectangle shrink", "[rectangle-shrink]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 3, 
		.y = 3
	};

	Rectangle r1(p1, p2); 
	r1.Shrink(); 

	// Moves the bottom left coordinate up one and to the right one
	// p1 is bottom left
	REQUIRE((r1.get_p1().x == p1.x+1 && r1.get_p1().y == p1.y+1));
	// Moves the upper right coordinate down one and to the left one
	// p2 is upper right 
	REQUIRE((r1.get_p2().x == p2.x-1 && r1.get_p2().y == p2.y-1)); 
}
