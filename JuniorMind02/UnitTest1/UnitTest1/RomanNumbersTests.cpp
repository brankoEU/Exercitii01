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
		
		TEST_METHOD(ConvertToRomanTestFor1)
		{
			Assert::AreEqual("I", ConvertToRoman(1).c_str());
		}

		TEST_METHOD(ConvertToRomanTestFor2)
		{
			Assert::AreEqual("II", ConvertToRoman(2).c_str());
		}

		TEST_METHOD(ConvertToRomanTestFor7)
		{
			Assert::AreEqual("VII", ConvertToRoman(7).c_str());
		}

		string ConvertToRoman(int number)
		{
			const string smallRomanNumbers[] = { "I" , "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
			
			if (number % 10 > 0) return smallRomanNumbers[number - 1];
		}

	};
}