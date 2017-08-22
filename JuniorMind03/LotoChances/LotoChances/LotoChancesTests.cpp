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
			Assert::AreEqual(0.1, CalculateLotoChance(1, 1, 10));
		}

		TEST_METHOD(ChanceOf3From10Test)
		{
			Assert::AreEqual(0.00833333, CalculateLotoChance(3, 3, 10),0.00000001);
		}

		TEST_METHOD(ChanceOf6From49Test)
		{
			Assert::AreEqual(0.00000007151123842018516, CalculateLotoChance(6, 6, 49));
		}

		TEST_METHOD(ChanceOf5From40Test)
		{
			Assert::AreEqual(0.00000151973, CalculateLotoChance(5, 5, 40),0.00000001);
		}

		TEST_METHOD(ChanceOf5From49Test)
		{
			Assert::AreEqual(0.00001844989, CalculateLotoChance(5, 6, 49), 0.00000001);
		}

		TEST_METHOD(ChanceOf4From49Test)
		{
			Assert::AreEqual(0.00096861681, CalculateLotoChance(4, 6, 49), 0.00000001);
		}

		double CalculateLotoChance(int winNumbers, int extractedNumbers, int totalNumbers)
		{
			
			return 1 / CalculateProbability(winNumbers ,totalNumbers, extractedNumbers);
		}

		double CalculateProbability(int m, int n, int k)
		{
			return CalculateCombinations(n, k) / (CalculateCombinations(k, m)*CalculateCombinations(n - k, k - m));
		}

		double CalculateCombinations(int n, int k)
		{
			return CalculateFactorial(n) / (CalculateFactorial(k)*CalculateFactorial(n - k));
		}

		double CalculateFactorial(int n)
		{
			double fact = 1;
			for (int i = 1; i <= n; i++)
			{
				fact *= i;
			}

			return fact;
		}

	};
}