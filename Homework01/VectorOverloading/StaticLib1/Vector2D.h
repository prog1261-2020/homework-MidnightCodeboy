//
#pragma once
#include <string>

class Vector2D {
public:
	Vector2D(int x, int y);

	double length() const;

	bool operator==(const Vector2D& rhs) const;
	bool operator!=(const Vector2D& rhs) const;
	std::string toString() const;

private:
	int _x;
	int _y;
};