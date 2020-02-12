/**
Parikshit Bhetwal
Dennis Lim 
PE 5
This is the implementation file for 
programming exercise five. 
*/

/**
    Bugs that we found in the original Rectangle.o file:

    Rectangle(Point p1, Point p2) - Doesn't check to 
    make sure p1 is passed in as bottom left 
    and p2 is passed in as top right. 
    
    GetWidth() - Doesn't give absolute value 
    of differences. 
    
    GetHeight()- Doesn't give absolute value 
    of differences. 
    
    Overlaps() - Doesn't report true if 
    overlapping method call is switched for two 
    overlapping objects. Ex) r1.OverLaps(r2)
    must equal r2.OverLaps(r1)
    
    CalculateArea() - Reports negative area with 
    points that have negative values. 
    
    Expand() - Due to mentioned constructor error, 
    doesn't expand correctly sometimes. 
    
    Shrink() - Due to mentioned constructor error, 
    doesn't shrink correctly sometimes. 
*/

#include "Rectangle.h"
#include <cstdlib>

/**
	Calculates factorial of number. 
	@param number The number to calculate for. 
	@return The caluclated factorial. 
*/
unsigned int Factorial( unsigned int number ) {
	// Call recursively until 1 
	if(number > 1) {
		return number * Factorial(number-1); 
	}
	return 1; 
}

/** 
	Constructor that takes two Points. 
	@param p1 The first point. 
	@param p2 The second point. 
*/ 
Rectangle::Rectangle(Point p1, Point p2) {
	if(p1.x < p2.x && p1.y < p2.y) {
		p1_ = p1;
		p2_ = p2; 
	}
	else{
		p1_ = p2; 
		p2_ = p1; 
	}
}

/** 
	Gets the width of this Rectangle. 
	@return abs(p2_.x - p1_.x) The width. 
*/ 
int Rectangle::GetWidth() {
	return abs(p2_.x - p1_.x); 
}

/**
	Gets the height of this Rectangle. 
	@return abs(p2_.y - p1_.y) The height. 
*/
int Rectangle::GetHeight() {
	return abs(p2_.y - p1_.y); 
}

/**
	Checks if two Rectangles overlap. 
	@param other The other rectangle. 
	@return true or false If they overlap. 
*/
bool Rectangle::Overlaps(Rectangle& other) {
	Point o_p1_ = other.get_p1();
	Point o_p2_ = other.get_p2();

	if(p1_.x == o_p1_.x && p1_.y == o_p1_.y) {
		return true; 
	}

	else if(p1_.x == o_p2_.x && p1_.y == o_p2_.y) {
		return true; 
	}

	else if(p2_.x == o_p1_.x && p2_.y == o_p1_.y) {
		return true; 
	}

	else if(p2_.x == o_p2_.x && p2_.y == o_p2_.y) {
		return true; 
	}
	return false; 
}

/**
	Returns the area of this Rectangle. 
	@return abs(GetWidth() * GetHeight()) 
			The area. 
*/
int Rectangle::CalculateArea() {
	return abs(GetWidth() * GetHeight()); 
}

/**
	Expands this Rectangle. 
*/
void Rectangle::Expand() {
	p1_.x--; 
	p1_.y--; 

	p2_.x++; 
	p2_.y++;
}

/**
	Shrinks this Rectangle.
*/
void Rectangle::Shrink() {
	p1_.x++; 
	p1_.y++; 

	p2_.x--; 
	p2_.y--;
}
