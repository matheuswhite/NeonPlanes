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

	Vector2D rotatedVector(double angle) {
		Vector2D col1 = Vector2D(cos(angle), -sin(angle));
		Vector2D col2 = Vector2D(sin(angle), cos(angle));

		return Vector2D(this->innerProduct(col1), this->innerProduct(col2));
	}

	Vector2D projection(Vector2D second) {
		double val = (this->lenght() * this->cos_between(second));
		return Vector2D(second.normalize().x * val, second.normalize().y * val);
	}

	double projectionLenght(Vector2D second) {
		return this->cos_between(second) * this->lenght();
	}

	double lenght() { return sqrt(this->x * this->x + this->y * this->y); }

	Vector2D normalize() {
		double val = (1 / this->lenght());
		return Vector2D( this->x * val, this->y * val);
	}

	double innerProduct(const Vector2D& second) {
		return (this->x * second.x) + (this->y * second.y);
	}

	double cos_between(Vector2D second) {
		return cos(this->angle(second));
	}

	double angle(Vector2D second) {
		double l = this->lenght() * second.lenght();
		return acos( this->innerProduct(second)/ l);
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