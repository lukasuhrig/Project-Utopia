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
	double X, Y;

	Vector2();
	Vector2(double);
	Vector2(double, double);
	~Vector2() {};

	Vector2 operator + (Vector2);
	Vector2 operator - (Vector2);
	Vector2 operator * (double);
	Vector2 operator * (Vector2);
	Vector2 operator / (double);
	Vector2 operator / (Vector2);
	bool operator == (Vector2);
	bool operator != (Vector2);

	static Vector2 Add(Vector2, Vector2);
	static Vector2 Subtract(Vector2, Vector2);
	static Vector2 Multiply(Vector2, double);
	static Vector2 Multiply(Vector2, Vector2);
	static Vector2 Divide(Vector2, double);
	static Vector2 Divide(Vector2, Vector2);
	bool Equals(Vector2);

	static double Dot(Vector2, Vector2);
	void Scale(double);

	void Normalize();

	static Vector2 Zero();
	static Vector2 One();

	static Vector2 Min(Vector2, Vector2);
	static Vector2 Max(Vector2, Vector2);
	static Vector2 Clamp(Vector2, Vector2, Vector2);

	static Vector2 Lerp(Vector2, Vector2, double);

	void Rotate(double);
	static Vector2 Rotate(Vector2, double);
	void RotateAboutTarget(Vector2, double);
	static Vector2 RotateAboutTarget(Vector2, Vector2, double);

	double Length();
	double LengthSquared();

	void Negate();

	std::string ToString();

};