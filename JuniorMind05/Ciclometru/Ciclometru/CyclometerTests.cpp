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

		TEST_METHOD(BestAverageSpeed)
		{
			vector<Cyclometer> data_base = { { "Ionut",26,{ 2,2,3,1,3 } } ,{ "Alex",20,{ 3,1,3,4,2 } } ,{ "Marius",30,{ 1,2,1,4,1 } } };
			Assert::AreEqual("Ionut", BestAverageSpeedPerCyclist(data_base).c_str());
		}

		TEST_METHOD(CyclistBestSpeed)
		{
			vector<Cyclometer> data_base = { { "Ionut",26,{ 2,2,3,1,3 } } ,{ "Alex",20,{ 3,1,3,4,2 } } ,{ "Marius",30,{ 1,2,1,4,1 } } };
			Result result = CyclistBestSpeed(data_base);
			Assert::AreEqual("Marius", result.name.c_str());
			Assert::AreEqual(4, result.second);
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

		struct Result
		{
			string name;
			int second;
		};

		double Circumference(double diameter)
		{
			return diameter * 3.14;
		}

		double SpeedPerSecond(double diameter, double rotations)
		{
			return Circumference(diameter)*rotations;
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

		string BestAverageSpeedPerCyclist(vector<Cyclometer> data)
		{
			double speed = 0;
			string bestAverage;
			for (int i = 0; i < data.size(); i++)
			{
				if ((DistancePerCyclist(data[i].diameter, data[i].records) / data[i].records.size()) > speed)
				{
					speed = DistancePerCyclist(data[i].diameter, data[i].records) / data[i].records.size();
					bestAverage = data[i].name;
				}
			}
			return bestAverage;
		}

		int GetMaxRotationPos(vector<double> rotations)
		{
			double maxRotations = rotations[0];
			int position;
			for (int i = 1; i < rotations.size(); i++)
			{
				if (rotations[i] > maxRotations) 
				{
					maxRotations = rotations[i];
					position = i+1;
				}
			}
			return position;
		}

		Result CyclistBestSpeed(vector<Cyclometer> data)
		{
			double bestSpeed = 0;
		    Result result;
			for (int i = 0; i < data.size(); i++)
			{
				if (bestSpeed < SpeedPerSecond(data[i].diameter, data[i].records[GetMaxRotationPos(data[i].records) - 1]))
				{
					bestSpeed = SpeedPerSecond(data[i].diameter, data[i].records[GetMaxRotationPos(data[i].records) - 1]);
					result.name = data[i].name;
					result.second = GetMaxRotationPos(data[i].records);
				}
			}
			
			return result;
		}

	};
}