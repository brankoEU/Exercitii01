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

		TEST_METHOD(ConvertToRomanTest3)
		{
			Assert::AreEqual("III", ConvertToRoman(3).c_str());
		}

		string ConvertToRoman(int number)
		{
			string romanNr;
			const string romanNumbers[] = { "I" , "V" };
			if (number % 10 > 2) romanNr = romanNumbers[0] + romanNumbers[0] + romanNumbers[0];
			else if (number % 10 > 1) romanNr = romanNumbers[0] + romanNumbers[0];
			else romanNr = romanNumbers[0];

			return romanNr;
		}

	};
}