#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Ciclometru
{		
	TEST_CLASS(CyclometerTests)
	{
	public:
		
		TEST_METHOD(TotalDistance)
		{
			vector<Cyclometer> data_base = { { "Ionut",26,{ 2,2,3,1,3 } } ,{ "Alex",20,{ 3,1,3,4,2 } } ,{ "Marius",30,{ 1,2,1,4,1 } } };
			Assert::AreEqual(2562.24, CalculateTotalDistance(data_base), 0.000000000001);
		}

		TEST_METHOD(TestDistancePerCyclist)
		{
			Assert::AreEqual(898.04, DistancePerCyclist(26, { 2,2,3,1,3 }));
		}

		struct Cyclometer
		{
			string name;
			double diameter;
			vector<double> records;
			Cyclometer(string name, double diameter, vector<double> records)
			{
				this->name = name;
				this->diameter = diameter;
				this->records = records;
			}
		};

		double Circumference(double diameter)
		{
			return diameter * 3.14;
		}

		double DistancePerCyclist(double diameter, vector<double> rotations)
		{
			double distance = 0;
			for (int i = 0; i < rotations.size(); i++)
			{
				distance += Circumference(diameter)*rotations[i];
			}
			return distance;
		}

		double CalculateTotalDistance(vector<Cyclometer> data)
		{
			double totalDistance = 0;
			for (int i = 0; i < data.size(); i++)
			{
				totalDistance += DistancePerCyclist(data[i].diameter, data[i].records);
			}
			return totalDistance;
		}

	};
}