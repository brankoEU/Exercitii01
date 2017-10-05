#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include "cyclometer.h"

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

		struct Result
		{
			string name;
			int second;
		};

		double CalculateTotalDistance(vector<Cyclometer> data)
		{
			double totalDistance = 0;
			for (int i = 0; i < data.size(); i++)
			{
				totalDistance += data[i].GetTotalDistance();
			}
			return totalDistance;
		}

		string BestAverageSpeedPerCyclist(vector<Cyclometer> data)
		{
			double speed = 0;
			string bestAverage;
			for (int i = 0; i < data.size(); i++)
			{
				if (data[i].GetAverageSpeed() > speed)
				{
					speed = data[i].GetAverageSpeed();
					bestAverage = data[i].name;
				}
			}
			return bestAverage;
		}

		Result CyclistBestSpeed(vector<Cyclometer> data)
		{
			double bestSpeed = 0;
		    Result result;
			for (int i = 0; i < data.size(); i++)
			{
				if (bestSpeed < data[i].SpeedPerSecond())
				{
					bestSpeed = data[i].SpeedPerSecond();
					result.name = data[i].name;
					result.second = data[i].GetMaxRotationPos();
				}
			}
			return result;
		}
	};
}