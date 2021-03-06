#include "stdafx.h"
#include "Vector3D.h"

Vector3D::Vector3D() : _x(0.f), _y(0.f), _z(0.f), _length(0.f), _data()
{
}

Vector3D::Vector3D(const Vector3D& rhs) : _x(rhs._x), _y(rhs._y), _z(rhs._z), _data()
{
}

Vector3D::~Vector3D()
{
}

// Division (for dividing my contribution count in one of the vertex normal calculation classes)
void Vector3D::DivideByInt(int value)
{
	this->_x /= value;
	this->_y /= value;
	this->_z /= value;
}

Vector3D::Vector3D(float32 x, float32 y, float32 z) : _x(x),_y(y),_z(z),_length(0.f), _data()
{
}

const float& Vector3D::GetX() const
{
	return this->_x;
}

const float& Vector3D::GetZ() const
{
	return this->_z;
}

const float& Vector3D::GetY() const
{
	return this->_y;
}

const Vector3D Vector3D::operator+(const Vector3D &other)
{
	Vector3D _temp;

	_temp = Vector3D(this->_x + other._x,
					 this->_y + other._y,
					 this->_z + other._z);

	return _temp;
}

const Vector3D Vector3D::operator+(const int32& other)
{

}

// Cross product creation
Vector3D Vector3D::CrossProduct(const Vector3D &other)
{
	Vector3D Sum(this->_y * other._z - other._y * this->_z,
				 this->_z * other._x - other._z * this->_x,
				 this->_x * other._y - other._x * this->_y); // X Co-Ordinate

	return Sum;
}

const float& Vector3D::GetLength() const
{
	return _length;
}

float Vector3D::DotProduct(const Vector3D &other)
{
	return (this->_x * other._x) + (this->_y * other._y) + (this->_z * other._z);
}

const Vector3D Vector3D::operator-(const Vector3D &other)
{
	Vector3D _temp;

	_temp = Vector3D(this->_x - other._x,
					 this->_y - other._y,
					 this->_z - other._z);

	return _temp;

}

const Vector3D Vector3D::operator/(const Vector3D& other)
{
	return Vector3D(this->_x / other._x, this->_y / other._y, this->_z / other._z);
}

const Vector3D Vector3D::operator/(const int32& other)
{

}

// Return magnitude of the shape -- otherwise considered as the length
float32 Vector3D::Magnitude()
{	
	return sqrtf(
		(this->_x * this->_x) +
		(this->_y * this->_y) + 
		(this->_z * this->_z));
}

Vector3D Vector3D::Normalise()
{
	Vector3D Sum(
		this->_x / this->Magnitude(),
		this->_y / this->Magnitude(),
		this->_z / this->Magnitude());

	return Sum;
}

void Vector3D::SetX(float x)
{
	this->_x = x;
}

void Vector3D::SetY(float y)
{
	this->_y = y;
}

void Vector3D::SetZ(float z)
{
	this->_z = z;
}

// Based on the substraction of VERTEX
//void Vector3D::SubstractVertices(Vertex other_one, Vertex other_two)
//{
//	this->_x = other_one.GetX() - other_two.GetX();
//	this->_y = other_one.GetY() - other_two.GetY();
//	this->_z = other_one.GetZ() - other_two.GetZ();
//}

//Vector3D& Vector3D::operator= (const Vector3D &other)
//{
//	this->_x = other._x;
//	this->_y = other._y;
//	this->_z = other._z;
//
//	return *this;
//}