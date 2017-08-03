#include "stdafx.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LotoChances
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CalculateFactorialTest)
		{
			Assert::AreEqual(6.0, CalculateFactorial(3));
		}

		TEST_METHOD(ChanceOfOneFromTenTest)
		{
			Assert::AreEqual(10.0, CalculateLotoChance(1, 10));
		}

		TEST_METHOD(ChanceOf3From10Test)
		{
			Assert::AreEqual(120.0, CalculateLotoChance(3, 10));
		}

		double CalculateLotoChance(int numbers, int loto)
		{
			double chance = CalculateFactorial(loto) / (CalculateFactorial(numbers)*CalculateFactorial(loto - numbers));
			return chance;
		}

		double CalculateFactorial(int n)
		{
			int fact = 1;
			for (int i = 1; i <= n; i++)
			{
				fact *= i;
			}

			return fact;
		}

	};
}