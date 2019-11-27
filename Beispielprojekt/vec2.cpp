/*
  Author: Fib
  File: Vector2.cpp
  Date: January 21, 2011
  Class: Vector2
  Description: Class definitions that represents a math vector in two dimensional space.
*/

#include "stdafx.h"
#include "vec2.h"

// ****************************************************************
// * Constructor.  Initializes both components to zero.
// ****************************************************************
Vector2::Vector2()
{
	X = 0;
	Y = 0;
}

// ****************************************************************
// * Constructor.  Initializes both components to value.
// ****************************************************************
Vector2::Vector2(double value)
{
	X = value;
	Y = value;
}

// ****************************************************************
// * Constructor.  Initializes the X component to value1,
// * the Y component to value2
// ****************************************************************
Vector2::Vector2(double value1, double value2)
{
	X = value1;
	Y = value2;
}

// ****************************************************************
// * Overloads the addition operator so that two vectors can
// * be added together.
// *
// * Returns: The sum of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator+ (Vector2 param)
{
	Vector2 temp;

	temp.X = X + param.X;
	temp.Y = Y + param.Y;

	return temp;
}

// ****************************************************************
// * Overloads the subtraction operator so that two vectors can
// * be subtracted.
// *
// * Returns: The difference of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator- (Vector2 param)
{
	Vector2 temp;

	temp.X = X - param.X;
	temp.Y = Y - param.Y;

	return temp;
}

// ****************************************************************
// * Overloads the multiplication operator so that both components
// * of a vector can be multiplied by a float.
// *
// * Returns: The product of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator* (double param)
{
	Vector2 temp;

	temp.X = X * param;
	temp.Y = Y * param;

	return temp;
}

// ****************************************************************
// * Overloads the multiplication operator so that two vectors can
// * be multiplied.
// *
// * Returns: The product of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator* (Vector2 param)
{
	Vector2 temp;

	temp.X = X * param.X;
	temp.Y = Y * param.Y;

	return temp;
}

// ****************************************************************
// * Overloads the division operator so that both components
// * of a vector can be divided by a float.
// *
// * Returns: The quotient of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator/ (double param)
{
	Vector2 temp;

	temp.X = X / param;
	temp.Y = Y / param;

	return temp;
}

// ****************************************************************
// * Overloads the division operator so that two vectors can
// * be divided.
// *
// * Returns: The quotient of the current instance and param.
// ****************************************************************
Vector2 Vector2::operator/ (Vector2 param)
{
	Vector2 temp;

	temp.X = X / param.X;
	temp.Y = Y / param.Y;

	return temp;
}

// ****************************************************************
// * Overloads the equals operator so that two vectors can be
// * compared for equality.
// *
// * Returns: True if the current instance is equal to param.
// ****************************************************************
bool Vector2::operator== (Vector2 param)
{
	if (param.X == X && param.Y == Y)
		return true;
	else
		return false;
}

bool Vector2::operator!= (Vector2 param)
{
	if (param.X != X || param.Y != Y)
		return true;
	else
		return false;
}

// ****************************************************************
// * Adds two vectors.
// *
// * Returns: The sum of value1 and value2.
// ****************************************************************
Vector2 Vector2::Add(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	temp.X = value1.X + value2.X;
	temp.Y = value1.Y + value2.Y;

	return temp;
}

// ****************************************************************
// * Subtracts two vectors.
// *
// * Returns: The difference of value1 and value2.
// ****************************************************************
Vector2 Vector2::Subtract(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	temp.X = value1.X - value2.X;
	temp.Y = value1.Y - value2.Y;

	return temp;
}

// ****************************************************************
// * Multiplies a vector and a float value.
// *
// * Returns: The product of value and scaleFactor.
// ****************************************************************
Vector2 Vector2::Multiply(Vector2 value, double scaleFactor)
{
	Vector2 temp;

	temp.X *= scaleFactor;
	temp.Y *= scaleFactor;

	return temp;
}

// ****************************************************************
// * Multiplies two vectors.
// *
// * Returns: The product of value1 and value2.
// ****************************************************************
Vector2 Vector2::Multiply(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	temp.X = value1.X * value2.X;
	temp.Y = value1.Y * value2.Y;

	return temp;
}

// ****************************************************************
// * Divides a vector and a float value.
// *
// * Returns: The quotient of value and scaleFactor.
// ****************************************************************
Vector2 Vector2::Divide(Vector2 value, double scaleFactor)
{
	Vector2 temp;

	temp.X /= scaleFactor;
	temp.Y /= scaleFactor;

	return temp;
}

// ****************************************************************
// * Divides two vectors.
// *
// * Returns: The quotient of value1 and value2.
// ****************************************************************
Vector2 Vector2::Divide(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	temp.X = value1.X / value2.X;
	temp.Y = value1.Y / value2.Y;

	return temp;
}

// ****************************************************************
// * Compares the current instance and another Vector2 for equality.
// *
// * Returns: True if the current instance is equal to other.
// ****************************************************************
bool Vector2::Equals(Vector2 other)
{
	if (other.X == X && other.Y == Y)
		return true;
	else
		return false;
}

// ****************************************************************
// * Calculates the dot product of two vectors.
// *
// * Returns: A float that represents the dot product of
// *          value1 and value2.
// ****************************************************************
double Vector2::Dot(Vector2 value1, Vector2 value2)
{
	double temp;

	temp = (value1.X * value2.X) + (value1.Y * value2.Y);

	return temp;
}

// ****************************************************************
// * Scales the current instance by a factor.
// *
// * Returns: Nothing.
// ****************************************************************
void Vector2::Scale(double scaleFactor)
{
	X *= scaleFactor;
	Y *= scaleFactor;
}

// ****************************************************************
// * Normalizes the current instance.  To normalize means to set
// * each component to a value that's between 0 and 1.
// *
// * Returns: Nothing.
// ****************************************************************
void Vector2::Normalize()
{
	X /= Length();
	Y /= Length();
}

// ****************************************************************
// * Creates a vector with all of its components set to zero.
// *
// * Returns: A vector with all of its components set to zero.
// ****************************************************************
Vector2 Vector2::Zero()
{
	Vector2 temp;

	temp.X = 0;
	temp.Y = 0;

	return temp;
}

// ****************************************************************
// * Creates a vector with all of its components set to one.
// *
// * Returns: A vector with all of its components set to one.
// ****************************************************************
Vector2 Vector2::One()
{
	Vector2 temp;

	temp.X = 1;
	temp.Y = 1;

	return temp;
}

// ****************************************************************
// * Returns a vector that contains the lowest value from each
// * matching pair of components.
// *
// * Returns: A minimized vector.
// ****************************************************************
Vector2 Vector2::Min(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	if (value1.X <= value2.X)
		temp.X = value1.X;
	else
		temp.X = value2.X;

	if (value1.Y <= value2.Y)
		temp.Y = value1.Y;
	else
		temp.Y = value2.Y;

	return temp;
}

// ****************************************************************
// * Returns a vector that contains the highest value from each
// * matching pair of components.
// *
// * Returns: A maximized vector.
// ****************************************************************
Vector2 Vector2::Max(Vector2 value1, Vector2 value2)
{
	Vector2 temp;

	if (value1.X >= value2.X)
		temp.X = value1.X;
	else
		temp.X = value2.X;

	if (value1.Y >= value2.Y)
		temp.Y = value1.Y;
	else
		temp.Y = value2.Y;

	return temp;
}

// ****************************************************************
// * Restricts a vector to be within a specified range.
// *
// * Returns: The restricted vector.
// ****************************************************************
Vector2 Vector2::Clamp(Vector2 value, Vector2 min, Vector2 max)
{
	Vector2 temp;

	if (value.X > max.X)
		temp.X = max.X;

	if (value.X < min.X)
		temp.X = min.X;

	if (value.Y > max.Y)
		temp.Y = max.Y;

	if (value.Y < min.Y)
		temp.Y = min.Y;

	if (value.X < max.X && value.X > min.X)
		temp.X = value.X;

	if (value.Y < max.Y && value.Y > min.Y)
		temp.Y = value.Y;

	return temp;
}

// ****************************************************************
// * Performs a linear interpolation between two vectors.
// *
// * Returns: The linear interpolation of the two vectors.
// ****************************************************************
Vector2 Vector2::Lerp(Vector2 value1, Vector2 value2, double amount)
{
	Vector2 temp;

	if (amount > 1)
		amount = 1;

	if (amount < 0)
		amount = 0;

	temp.X = value1.X + (value2.X - value1.X) * amount;
	temp.Y = value1.Y + (value2.Y - value1.Y) * amount;

	return temp;

}

// ****************************************************************
// * Calculates the position of the current instance that is
// * rotated about the origin, by an angle in radians.
// *
// * Note: In 2D screen space, the origin (0, 0) is always the top
// * left most pixel of the screen.
// *
// * Returns: Nothing.
// ****************************************************************
void Vector2::Rotate(double angle)
{
	Vector2 temp(X, Y);
	angle = (2 * PI) - angle;

	temp.X = (X * cos(angle)) + (Y * -sin(angle));
	temp.Y = (X * sin(angle)) + (Y * cos(angle));

	X = temp.X;
	Y = temp.Y;
}

// ****************************************************************
// * Calculates the position of a vector that is rotated about
// * the origin, by an angle in radians.
// *
// * Note: In 2D screen space, the origin (0, 0) is always the top
// * left most pixel of the screen.
// *
// * Returns: The rotated vector.
// ****************************************************************
Vector2 Vector2::Rotate(Vector2 value, double angle)
{
	Vector2 temp;
	angle = (2 * PI) - angle;

	temp.X = (value.X * cos(angle)) + (value.Y * -sin(angle));
	temp.Y = (value.X * sin(angle)) + (value.Y * cos(angle));

	return temp;
}

// ****************************************************************
// * Calculates the position of the current instance that is
// * rotated about a target vector, by an angle in radians.
// *
// * Returns: Nothing.
// ****************************************************************
void Vector2::RotateAboutTarget(Vector2 target, double angle)
{
	Vector2 temp;

	temp.X = X - target.X;
	temp.Y = Y - target.Y;
	temp = Rotate(temp, angle);

	X = target.X + temp.X;
	Y = target.Y + temp.Y;
}

// ****************************************************************
// * Calculates the position of a vector that is rotated about a
// * target vector, by an angle in radians.
// *
// * Returns: The rotated vector.
// ****************************************************************
Vector2 Vector2::RotateAboutTarget(Vector2 source, Vector2 target, double angle)
{
	Vector2 temp;

	temp = source - target;
	temp = Rotate(temp, angle);

	return target + temp;
}

// ****************************************************************
// * Calculates the length, or the magnitude, of the current instance.
// *
// * Returns: The length of the vector.
// ****************************************************************
double Vector2::Length()
{
	return sqrt((X * X) + (Y * Y));
}

// ****************************************************************
// * Calculates the length to the power of two of the current
// * instance.
// *
// * Returns: The length to the power of two of the vector.
// ****************************************************************
double Vector2::LengthSquared()
{
	double temp;

	temp = sqrt((X * X) + (Y * Y));

	return temp * temp;
}

// ****************************************************************
// * Multiplies each component in the current instance by
// * negative one.
// *
// * Returns: Nothing.
// ****************************************************************
void Vector2::Negate()
{
	X *= (-1);
	Y *= (-1);
}

// ****************************************************************
// * Returns a string representation of the current instance.
// *
// * Returns: The string that represents the vector.
// ****************************************************************
std::string Vector2::ToString()
{
	std::stringstream ss(std::stringstream::in | std::stringstream::out);

	ss << "(" << X << ", " << Y << ")";

	return ss.str();
}