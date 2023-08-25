#include "Circle.h"


Circle::Circle(const double _radius)
{
	SetRadius(_radius);
}

void Circle::SetRadius(const double _radius)
{
	assert(_radius >= 0 && "Radius must be positive");
	radius = _radius;
}

double Circle::GetRadius() const
{
	return radius;
}

Vector3 Circle::Get3DPoint(const double& _t) const
{
	return Vector3(std::cos(_t) * radius, std::sin(_t) * radius,0);
}

Vector3 Circle::GetFirstDerivative(const double& _t) const
{
	return Vector3(-std::sin(_t)*radius, std::cos(_t)*radius,0);
}
