#pragma once
#include <algorithm>

class Vector3D
{
private:

	float x; // Coordenada X del vector.
	float y; // Coordenada Y del vector.
	float z; // Coordenada Z del vector.

public:

	//------Constructoras y destructoras:

	// Constructora de Vector3D por defecto: pone todas las coordenadas a 0.
	Vector3D()
		: x(0), y(0), z(0)
	{};
	// Constructora de Vector3D con valores: asigna los valores dados a las coordenadas.
	Vector3D(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
	{};
	// Destructora de Vector3D .
	//~Vector3D();


	//------Getters y setters:

	// Devuelve la coordenada X.
	float getX() const { return x; }
	// Devuelve la coordenada Y.
	float getY() const { return y; }
	// Devuelve la coordenada Z.
	float getZ() const { return z; }
	// Settea la coordenada X.
	void setX(float _x) { x = _x; }
	// Settea la coordenada Y.
	void setY(float _y) { y = _y; }
	// Settea la coordenada Z.
	void setZ(float _z) { z = _z; }


	//------Sobrecarga de operadores:

	// Operador asignacion.
	Vector3D& operator=(const Vector3D& _vec)
	{
		x = _vec.x;
		y = _vec.y;
		z = _vec.z;

		return *this;
	}
	// Operador suma.
	Vector3D operator+(const Vector3D& _vec)
	{
		return Vector3D{ x + _vec.x, y + _vec.y, z + _vec.z };
	}
	// Operador resta.
	Vector3D operator-(const Vector3D& _vec)
	{
		return Vector3D{ x - _vec.x, y - _vec.y, z - _vec.z };
	}
	// Operador multiplicacion: poducto por escalar.
	Vector3D operator*(float scalar)
	{
		return multiplyByScalar(scalar);
	}
	// Operador multiplicacion: producto escalar.
	float operator*(const Vector3D& _vec)
	{
		return scalarMultiply(_vec);
	}


	//------Operaciones:

	// Devuelve el modulo del vector.
	float getModule() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	// Normaliza el vector dado en otro.
	Vector3D normalize() const
	{
		float mod = getModule();

		if (mod != 0)
		{
			return Vector3D{ x / mod, y / mod, z / mod };
		}
	}
	// Producto escalar de 2 vectores.
	float scalarMultiply(Vector3D _vec) const
	{
		return x * _vec.x + y * _vec.y + z * _vec.z;
	};
	// productor vectorial de 2 vectores.
	Vector3D vectorialMultiply(const Vector3D& _vec) const
	{
		return Vector3D{
			y * _vec.z - z * _vec.y,
			z * _vec.x - x * _vec.z,
			x * _vec.y - y * _vec.x };
	}
	// Producto por escalar de 1 vector.
	Vector3D multiplyByScalar(float scalar) const
	{
		return Vector3D{ x * scalar, y * scalar, z * scalar };
	};
};