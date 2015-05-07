#pragma once

#include "core.h"

class Vector2D
{
public:
	Vector2D(double x, double y) : x(x), y(y) {}
	Vector2D(const Vector2D& v) { (*this) = v; }
	Vector2D() {}
	virtual ~Vector2D() {}

	double x;
	double y;

	double lenght() { return sqrt(this->x * this->x + this->y * this->y); }

	Vector2D normalize() {
		double val = (1 / this->lenght());
		return Vector2D( this->x * val, this->y * val);
	}

	Vector2D& operator+=(const Vector2D& v2) {
		this->x += v2.x;
		this->y += v2.y;

		return *this;
	}


	Vector2D& operator-=(const Vector2D& v2) {
		this->x -= v2.x;
		this->y -= v2.y;

		return *this;
	}

	Vector2D& operator*=(double scalar) {
		this->x *= scalar;
		this->y *= scalar;

		return *this;
	}

	Vector2D& operator/=(double scalar) {
		if (scalar != 0) {
			this->x /= scalar;
			this->y /= scalar;

			return *this;
		}
		else {
			throw std::overflow_error("Divide by zero exception");
		}
	}
};

inline Vector2D operator+(Vector2D first, const Vector2D& v) {
	return first += v;
}

inline Vector2D operator-(Vector2D first, const Vector2D& v) {
	return first -= v;
}

inline Vector2D operator*(Vector2D first, double scalar) {
	return first *= scalar;
}

inline Vector2D operator/(Vector2D first, double scalar) {
	if (scalar != 0) {
		return first /= scalar;
	}
	else {
		throw std::overflow_error("Divide by zero exception");
	}
}