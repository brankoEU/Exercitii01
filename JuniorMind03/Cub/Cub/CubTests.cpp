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