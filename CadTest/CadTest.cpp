#include <iostream>
#include <vector>
#include <memory>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <omp.h>
#include "src/Curve.h"
#include "src/Circle.h"
#include "src/Ellipse.h"
#include "src/Helix.h"

#define THREAD_NUM 4 

int main()
{
	std::vector<std::shared_ptr<Curve>> curvesVec;
	std::vector<std::shared_ptr<Circle>> circlesVec;
	int totalSum = 0;
	const int objectsAmount = 100;
	srand(time(NULL));

	for (int i = 0; i < objectsAmount; i++)
	{
		int x = rand() % 3;
		double param1 = rand() % 10000 / 100.0;
		double param2 = rand() % 10000 / 100.0;
		double param3 = rand() % 100 / 100.0;

		if (x == 0)
		{
			curvesVec.emplace_back(std::make_shared<Circle>(param1));
		}
		else if (x == 1)
		{
			curvesVec.emplace_back(std::make_shared<Ellipse>(param1, param2));
		}
		else
		{
			curvesVec.emplace_back(std::make_shared<Helix>(param1, param3));
		}
	}

	for (auto& curve : curvesVec)
	{
		Vector3 point = curve->Get3DPoint(M_PI / 4.0);
		Vector3 derivative = curve->GetFirstDerivative(M_PI / 4.0);

		std::cout << "Type: " << typeid(*curve.get()).name() << std::endl;

		std::cout << "3DPoint: x:" << point.X()
			<< ", y:" << point.Y()
			<< ", z:" << point.Z()
			<< std::endl;

		std::cout<< "Derivative: x:" << derivative.X()
			<< ", y:" << derivative.Y() 
			<< ", z:" << derivative.Z()
			<< std::endl;
	std::cout<<std ::endl;
	}

	for (auto& curve : curvesVec)
	{
		auto circle = std::dynamic_pointer_cast<Circle>(curve);
		if (circle)
			circlesVec.emplace_back(circle);
	}

	std::sort(circlesVec.begin(), circlesVec.end(),
		[](auto& c1, auto& c2) {return c1->GetRadius() < c2->GetRadius(); });

	//One Thread
	for (auto& circle : circlesVec)
	{
		totalSum += circle->GetRadius();
	}

	std::cout << "Total sum of radii: " << totalSum << std::endl;
	totalSum = 0;

	//Multiple Threads
#pragma omp parallel num_threads(THREAD_NUM)
#pragma omp for reduction (+:totalSum) 
	for (auto i = 0; i < circlesVec.size(); i++)
	{
		totalSum += circlesVec[i]->GetRadius();
	}

	std::cout << "Total sum of radii (OpenMP): " << totalSum << std::endl;
	std::cout << "Type something to exit..." << std::endl;
	std::cin >> totalSum;
}

