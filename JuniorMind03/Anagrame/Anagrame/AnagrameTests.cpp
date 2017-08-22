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

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(1, CalculateAnagrams("aaaaa"));
		}

		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(6, CalculateAnagrams("aabb"));
		}

		TEST_METHOD(TestMethod6)
		{
			Assert::AreEqual(60, CalculateAnagrams("aaabbc"));
		}

		int CalculateAnagrams(string text)
		{
			int repetitions = 1;
			string charsChecked = "";
			for (int i = 'a'; i <= 'z'; i++)
			{
				if (CheckDuplicates(text, i) > 1 && CheckDuplicates(charsChecked, i) < 1)
				{
					charsChecked += i;
					repetitions *= CalculateFactorial(CheckDuplicates(text, i));
				}
			}
			return CalculateFactorial(text.length())/repetitions;
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