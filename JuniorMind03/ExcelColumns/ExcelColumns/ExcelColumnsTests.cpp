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

		string LetterCombinationForExcelColums(int number)
		{
			char alphabet[1][26] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
			return alphabet[3];
		}

	};
}