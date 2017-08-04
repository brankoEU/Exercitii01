#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <iostream>

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

		string LetterCombinationForExcelColums(int number)
		{
			const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string columnName = "";

			while (number % 26 > 0)
			{
				columnName = alphabet[number % 26 - 1] + columnName;
				number = number / 26;
			}
			
			return columnName;
		}

	};
}