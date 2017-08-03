#include "stdafx.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LotoChances
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ChanceOf1From10Test)
		{
			Assert::AreEqual(0.1, CalculateLotoChance(1, 10));
		}

		TEST_METHOD(ChanceOf3From10Test)
		{
			Assert::AreEqual(0.00833333, CalculateLotoChance(3, 10),0.00000001);
		}

		TEST_METHOD(ChanceOf6From49Test)
		{
			Assert::AreEqual(0.00000007151123842018516, CalculateLotoChance(6, 49));
		}

		double CalculateLotoChance(int numbers, int loto)
		{
			
			return 1 / CalculateCombinations(loto, numbers);
		}

		double CalculateCombinations(int n, int k)
		{
			return CalculateFactorial(n) / (CalculateFactorial(k)*CalculateFactorial(n - k));
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