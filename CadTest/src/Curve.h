#pragma once
#include <cassert>
#include <cmath>

//TODO: constructor with reference?
//TODO: code format
//TODO: check Helix code
struct Vector3
{
public:
	Vector3() = default;
	Vector3(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }
	double X() const;
	double Y() const;
	double Z() const;
private:
	double x = 0;
	double y = 0;
	double z = 0;
};

class Curve
{
public:
	Curve() = default;
	virtual Vector3 Get3DPoint(const double& t) const = 0;
	virtual Vector3 GetFirstDerivative(const double& t) const = 0;
	virtual ~Curve() = default;
};

