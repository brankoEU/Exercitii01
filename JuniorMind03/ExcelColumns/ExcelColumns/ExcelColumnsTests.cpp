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

		TEST_METHOD(ColumnWithBGNLeters)
		{
			Assert::AreEqual("BGN", LetterCombinationForExcelColums(1548).c_str());
		}

		TEST_METHOD(ColumnWithFourLeters)
		{
			Assert::AreEqual("DXVY", LetterCombinationForExcelColums(87125).c_str());
		}

		TEST_METHOD(ColumnAZ)
		{
			Assert::AreEqual("AZ", LetterCombinationForExcelColums(52).c_str());
		}

		TEST_METHOD(ColumnBA)
		{
			Assert::AreEqual("BA", LetterCombinationForExcelColums(53).c_str());
		}

		TEST_METHOD(ColumnBZ)
		{
			Assert::AreEqual("BZ", LetterCombinationForExcelColums(78).c_str());
		}

		string LetterCombinationForExcelColums(int number)
		{
			string columnName = "";

			while (number > 0)
			{
				if (number % 26 == 0)
				{ 
					columnName = char(64+26) + columnName;
					number--;
				}
				else
				{ 
					columnName = char(64 + number % 26) + columnName;
				}
				number /= 26;
			}
			
			return columnName;
		}

	};
}