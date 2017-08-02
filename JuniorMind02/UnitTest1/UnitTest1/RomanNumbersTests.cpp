#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RomanNumbers
{		
	TEST_CLASS(RomanNumbersTests)
	{
	public:
		
		TEST_METHOD(ConvertToRomanTest1)
		{
			Assert::AreEqual("I", ConvertToRoman(1).c_str());
		}

		TEST_METHOD(ConvertToRomanTest2)
		{
			Assert::AreEqual("II", ConvertToRoman(2).c_str());
		}

		string ConvertToRoman(int number)
		{
			const string romanNumbers[] = { "I" , "V" };
			if (number % 10 > 1) return romanNumbers[0] + romanNumbers[0];
			else return romanNumbers[0];
		}

	};
}