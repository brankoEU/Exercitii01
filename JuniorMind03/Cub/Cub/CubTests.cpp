#include "stdafx.h"
#include "CppUnitTest.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Cub
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FirstCube)
		{
			Assert::AreEqual(192, CalculateCube(1));
		}

		TEST_METHOD(SecondCube)
		{
			Assert::AreEqual(442, CalculateCube(2));
		}

		TEST_METHOD(ThirdCube)
		{
			Assert::AreEqual(692, CalculateCube(3));
		}
		
		TEST_METHOD(ForthCube)
		{
			Assert::AreEqual(942, CalculateCube(4));
		}

		int CalculateCube(int k) 
		{
			int count = 0;
			int number = 1;
			while (count < k)
			{
				number++;
				if ((int)pow(number, 3) % 1000 == 888) count++;
			}
			return number;
		}
	};
}