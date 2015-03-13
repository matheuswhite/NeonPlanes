#pragma once

#include "core.h"

class Vector2D
{
public:
	Vector2D(float x, float y) : x(x), y(y) {}
	Vector2D(const Vector2D& v) { (*this) = v; }
	virtual ~Vector2D() {}

	float x;
	float y;

	float lenght() { return sqrt(this->x * this->x + this->y * this->y); }

	void normalize() {
		float l = this->lenght();
		if (l > 0) {
			(*this) *= 1 / l;
		}
	}

	Vector2D operator+(const Vector2D& v) {
		return Vector2D(this->x + v.x, this->y + v.y);
	}

	Vector2D& operator+=(const Vector2D& v2) {
		this->x += v2.x;
		this->y += v2.y;

		return *this;
	}

	Vector2D operator-(const Vector2D& v) {
		return Vector2D(this->x - v.x, this->y - v.y);
	}

	Vector2D& operator-=(const Vector2D& v2) {
		this->x -= v2.x;
		this->y -= v2.y;

		return *this;
	}

	Vector2D operator*(float scalar) {
		return Vector2D(this->x * scalar, this->y * scalar);
	}

	Vector2D& operator*=(float scalar) {
		this->x *= scalar;
		this->y *= scalar;

		return *this;
	}

	Vector2D operator/(float scalar) {
		if (scalar != 0) {
			return Vector2D(this->x/scalar, this->y/scalar);
		}
		else {
			throw std::overflow_error("Divide by zero exception");
		}
	}

	Vector2D& operator/=(float scalar) {
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