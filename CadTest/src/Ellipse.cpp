#include "Ellipse.h"

Ellipse::Ellipse(double _xRadius, double _yRadius)
{
	SetRadii(_xRadius, _yRadius);
}

void Ellipse::SetRadii(double _xRadius, double _yRadius)
{
	assert((_xRadius >= 0 && _yRadius>=0) && "Radius must be positive");
	xRadius = _xRadius;
	yRadius = _yRadius;
}

Vector3 Ellipse::Get3DPoint(const double& _t) const
{
	return Vector3(std::cos(_t) * xRadius, std::sin(_t) * yRadius, 0);
}

Vector3 Ellipse::GetFirstDerivative(const double& _t) const
{
	return Vector3(-std::sin(_t)*xRadius, std::cos(_t)*yRadius,0);
}
