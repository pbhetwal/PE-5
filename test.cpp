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
// NOTE: second require does not pass 
TEST_CASE("Rectangle class constructor", "[rectangle-constructor]") {
	Point p1 = {
		.x = 0, 
		.y = 0
	}; 

	Point p2 = {
		.x = 2, 
		.y = 2
	};

	Rectangle r1(p1, p2);  
	Rectangle r2(p2, p1); 

	REQUIRE((r1.get_p1().x == 0 && r1.get_p1().y == 0
			 && r1.get_p2().x == 2 && r1.get_p2().y == 2));

	
	REQUIRE((r2.get_p1().x == 0 && r2.get_p1().y == 0
			 && r2.get_p2().x == 2 && r2.get_p2().y == 2));
}

// Tests the GetWidth() method 
// NOTE: require doesn't pass
TEST_CASE("Rectangle get width", "[rectangle-width]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = -30000, 
		.y = 10000
	};

	Rectangle r1(p1, p2); 
	REQUIRE(r1.GetWidth() == 30001); 
}

// Tests the GetHeight() method 
// NOTE: require doesn't pass 
TEST_CASE("Rectangle get height", "[rectangle-height]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = -3, 
		.y = -100
	};

	Rectangle r1(p1, p2); 
	REQUIRE(r1.GetHeight() == 101); 
}

// Tests the Overlaps() method 
// NOTE: second require originally doesn't pass 
TEST_CASE("Rectangle overlaps", "[rectangle-overlaps]") {
	Point p1 = {
		.x = 1, 
		.y = 1
	}; 

	Point p2 = {
		.x = 200, 
		.y = 200
	};

	Point p3 = {
		.x = 3000, 
		.y = 3000
	}; 

	Point p4 = {
		.x = -3, 
		.y = -3
	};

	Point p5 = {
		.x = -1, 
		.y = -1
	};

	Point p6 = {
		.x = 0, 
		.y = 0
	};

	Rectangle r1(p2, p3); 
	Rectangle r2(p1, p3); 
	Rectangle r3(p1, p4); 
	Rectangle r4(p6, p1);
	Rectangle r5(p5, p6);

	REQUIRE(r1.Overlaps(r2) == true); 
	REQUIRE(r2.Overlaps(r1) == true); 
	REQUIRE(r1.Overlaps(r3) == false); 
	REQUIRE(r3.Overlaps(r1) == false);
	REQUIRE(r5.Overlaps(r4) == true); 
}

// Tests the CalculateArea() method 
// NOTE: the require originally fails 
TEST_CASE("Rectangle calculate area", "[rectangle-calculatearea]") {
	Point p1 = {
		.x = 1, 
		.y = 2
	}; 

	Point p2 = {
		.x = -3, 
		.y = 4
	};

	Rectangle r1(p1, p2); 
	// We could use: REQUIRE(r1.CalculateArea() == r1.GetWidth() * r1.GetHeight())
	// but that would rely on other methods, we only want to test this method 
	REQUIRE(r1.CalculateArea() == 8); 
}

// Test the area
TEST_CASE("Rec calculate area", "[rec-calculatearea]"){
	Point p1 = {
		.x = 3,
		.y = 3
	};

	Point p2 = {
		.x = 8,
		.y = 8
	};

	Rectangle r(p1, p2); 
	REQUIRE(r.CalculateArea() == 25); 
}

// Tests the Expand() method
// NOTE: the requires originally fail 
TEST_CASE("Rectangle expand", "[rectangle-expand]") {
	Point p1 = {
		.x = 2, 
		.y = 2
	}; 

	Point p2 = {
		.x = 0, 
		.y = 0
	};

	Rectangle r1(p1, p2); 
	r1.Expand(); 

	// Moves the upper right coordinate up one and to the right one
	// p1 is bottom left
	REQUIRE((r1.get_p2().x == 3 && r1.get_p2().y == 3));
	// Moves the bottom left coordinate down one and to the left one
	// p2 is upper right 
	REQUIRE((r1.get_p1().x == -1 && r1.get_p1().y == -1)); 

	// expanding the rectangle again, and same logic above should happen
	r1.Expand();
	REQUIRE((r1.get_p2().x == 4 && r1.get_p2().y == 4));
	REQUIRE((r1.get_p1().x == -2 && r1.get_p1().y == -2)); 

}



// Tests the Shrink() method 
// NOTE: the requires originally fail
TEST_CASE("Rectangle shrink", "[rectangle-shrink]") {
	Point p1 = {
		.x = 2, 
		.y = 2
	}; 

	Point p2 = {
		.x = 0, 
		.y = 0
	};

	Rectangle r1(p1, p2); 
	r1.Shrink(); 

	// Moves the bottom left coordinate up one and to the right one
	// p1 is bottom left
	REQUIRE((r1.get_p1().x == 1 && r1.get_p1().y == 1));
	// Moves the upper right coordinate down one and to the left one
	// p2 is upper right 
	REQUIRE((r1.get_p2().x == 1 && r1.get_p2().y == 1));
}


