#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Anagrame
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(2.0, CalculateAnagrams("ab"));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(6.0, CalculateAnagrams("abc"));
		}

		double CalculateAnagrams(string text)
		{
			return CalculateFactorial(text.length())/CalculateFactorial(text.length()-2);
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