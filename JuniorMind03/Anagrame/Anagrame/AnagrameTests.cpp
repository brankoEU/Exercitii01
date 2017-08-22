#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Anagrame
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDuplicates)
		{
			Assert::AreEqual(2, CheckDuplicates("aac", 'a'));
		}

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(2, CalculateAnagrams("ab"));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(6, CalculateAnagrams("abc"));
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(3, CalculateAnagrams("aac"));
		}



		int CalculateAnagrams(string text)
		{
			int repetitions = 0;
			for (int i = 0; i < text.length(); i++)
			{
				if(CheckDuplicates(text, text[i])>1)
				repetitions += CheckDuplicates(text, text[i]);
			}
			return repetitions;
			//return CalculateFactorial(text.length())/CalculateFactorial(repetitions);
		}

		int CheckDuplicates(string text, char charToCheck)
		{
			return count(begin(text), end(text), charToCheck);
		}

		int CalculateFactorial(int n)
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