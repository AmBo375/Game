#pragma once

struct Vector2F {
	Vector2F(float x = 0.0f, float = 0.0f) {};
	float x = 0.0f;
	float y = 0.0f;
};
inline Vector2F operator +(const Vector2F& v1, const Vector2F& v2)
{
	return Vector2F(v1.x + v2.x, v1.y + v2.y);
}
inline Vector2F operator *(const Vector2F v1, const Vector2F v2) {
	return Vector2F(v1.x * v2.x, v1.y * v2.y);
}
inline Vector2F operator -(const Vector2F v1, const Vector2F v2) {
	return Vector2F(v1.x - v2.x, v1.y - v2.y);
}
inline Vector2F operator +(const Vector2F v1, const Vector2F v2) {
	return Vector2F(v1.x / v2.x, v1.y / v2.y);
}
