#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ExcelColumns
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ColumnWithOneLeters)
		{
			Assert::AreEqual("C", LetterCombinationForExcelColums(3).c_str());
		}

		TEST_METHOD(ColumnWithTwoLeters)
		{
			Assert::AreEqual("AB", LetterCombinationForExcelColums(28).c_str());
		}

		TEST_METHOD(ColumnContainingLeterZ)
		{
			Assert::AreEqual("ACZ", LetterCombinationForExcelColums(754).c_str());
		}

		TEST_METHOD(ColumnWithBGNLeters)
		{
			Assert::AreEqual("BGN", LetterCombinationForExcelColums(1548).c_str());
		}

		TEST_METHOD(ColumnWithFourLeters)
		{
			Assert::AreEqual("DXVY", LetterCombinationForExcelColums(87125).c_str());
		}

		TEST_METHOD(ColumnAZZZ)
		{
			Assert::AreEqual("AZZZ", LetterCombinationForExcelColums(17576).c_str());
		}

		string LetterCombinationForExcelColums(int number)
		{
			const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string columnName = "";
			int strLength = alphabet.length();

			while (number > 0)
			{
				if (number % strLength == 0) { columnName = alphabet[strLength - 1] + columnName; }
				else
				{ columnName = alphabet[number % strLength - 1] + columnName; }
				number /= strLength;
			}
			
			return columnName;
		}

	};
}