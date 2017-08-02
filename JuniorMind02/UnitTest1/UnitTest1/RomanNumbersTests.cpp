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
		
		TEST_METHOD(ConvertToRomanTestOne)
		{
			Assert::AreEqual("I", ConvertToRoman(1).c_str());
		}

		string ConvertToRoman(int number)
		{
			const string romanNumber[] = { "I" };
			return romanNumber[number-1];
		}

	};
}