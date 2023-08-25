#pragma once
#include "Curve.h"
#include <cstdint>

class Circle : public Curve
{
public:
	Circle() = default;
	Circle(const double _raduis);
	void SetRadius(const double _radius);
	double GetRadius() const;
	Vector3 Get3DPoint(const double& _t) const override;
	Vector3 GetFirstDerivative(const double& _t) const override;

private:
	double radius = 1;
};

