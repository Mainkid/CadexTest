#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	Ellipse() = default;
	Ellipse(double _xRadius, double _yRadius);
	void SetRadii(double _xRadius, double _yRadius);
	Vector3 Get3DPoint(const double& _t) const override;
	Vector3 GetFirstDerivative(const double& _t) const override;

private:
	double xRadius = 1.0;
	double yRadius = 1.0;
};

