/*
  Author: Fib
  File: Vector2.h
  Date: January 21, 2011
  Class: Vector2
  Description: Class declarations that represents a math vector in two dimensional space.
*/

#pragma once

#include <cmath>   // Used for squart root, and trigonometry functions
#include <sstream> // Used to convert floats to strings
#include <string>  // Used to return a string in the ToString() function.

#define PI 3.14159

class Vector2
{

public:
	float X, Y;

	Vector2();
	Vector2(float);
	Vector2(float, float);
	~Vector2() {};

	Vector2 operator + (Vector2);
	Vector2 operator - (Vector2);
	Vector2 operator * (float);
	Vector2 operator * (Vector2);
	Vector2 operator / (float);
	Vector2 operator / (Vector2);
	bool operator == (Vector2);
	bool operator != (Vector2);

	static Vector2 Add(Vector2, Vector2);
	static Vector2 Subtract(Vector2, Vector2);
	static Vector2 Multiply(Vector2, float);
	static Vector2 Multiply(Vector2, Vector2);
	static Vector2 Divide(Vector2, float);
	static Vector2 Divide(Vector2, Vector2);
	bool Equals(Vector2);

	static float Dot(Vector2, Vector2);
	void Scale(float);

	void Normalize();

	static Vector2 Zero();
	static Vector2 One();

	static Vector2 Min(Vector2, Vector2);
	static Vector2 Max(Vector2, Vector2);
	static Vector2 Clamp(Vector2, Vector2, Vector2);

	static Vector2 Lerp(Vector2, Vector2, float);

	void Rotate(float);
	static Vector2 Rotate(Vector2, float);
	void RotateAboutTarget(Vector2, float);
	static Vector2 RotateAboutTarget(Vector2, Vector2, float);

	float Length();
	float LengthSquared();

	void Negate();

	std::string ToString();

};