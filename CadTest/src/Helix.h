#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
	Helix() = default;
	Helix(double _radius, double _step);
	void SetRadius(double _radius);
	void SetStep(double _step);
	Vector3 Get3DPoint(const double& _t) const override;
	Vector3 GetFirstDerivative(const double& _t) const override;

private:
	double radius = 1.0;
	double step = 1.0;
};

