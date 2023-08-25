#include "Helix.h"

Helix::Helix(double _radius, double _step)
{
	SetRadius(_radius);
	SetStep(_step);
}

void Helix::SetRadius(double _radius)
{
	assert(_radius >= 0 && "Radius must be positive");
}

void Helix::SetStep(double _step)
{
	step = _step;
}

Vector3 Helix::Get3DPoint(const double& _t) const
{
	return Vector3(radius * std::cos(_t), radius * std::sin(_t), step*_t);
}

Vector3 Helix::GetFirstDerivative(const double& _t) const
{
	return Vector3(-radius*std::sin(_t), radius*std::cos(_t),step);
}
