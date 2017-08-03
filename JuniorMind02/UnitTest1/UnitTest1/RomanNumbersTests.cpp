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

		TEST_METHOD(ConvertToRomanTestFor30)
		{
			Assert::AreEqual("XXX", ConvertToRoman(30).c_str());
		}

		TEST_METHOD(ConvertToRomanTestFor70)
		{
			Assert::AreEqual("LXX", ConvertToRoman(70).c_str());
		}

		TEST_METHOD(ConvertToRomanTestFor74)
		{
			Assert::AreEqual("LXXIV", ConvertToRoman(74).c_str());
		}

		TEST_METHOD(ConvertToRomanTestFor48)
		{
			Assert::AreEqual("XLVIII", ConvertToRoman(48).c_str());
		}

		string ConvertToRoman(int number)
		{
			string romanNr;
			const string smallRomanNumbers[] = { "I" , "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
			const string bigRomanNumbers[] = { "X" , "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" , "C" };
			if (number / 10 > 0) romanNr += bigRomanNumbers[number / 10 - 1];
			if (number % 10 > 0) romanNr += smallRomanNumbers[number % 10 - 1];
			return romanNr;
		}

	};
}