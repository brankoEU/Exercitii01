#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <numeric>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			inline wstring ToString(const vector<int>& t) { return accumulate(t.begin(), t.end(), wstring(L""), [](wstring result, int item) -> wstring { return result + L" " + to_wstring(item); }); }
		}
	}
}

namespace PascalTriangle
{		
	TEST_CLASS(PascalTriangleTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual({ 1 , 1 }, GenerateRow(1));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual({ 1,3,3,1 }, GenerateRow(3));
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual({ 1,5,10,10,5,1 }, GenerateRow(5));
		}

		int GeneratePascal(int row, int col)
		{
			if (col == 0 || col == row) return 1;
			return GeneratePascal(row - 1, col - 1) + GeneratePascal(row - 1, col);
		}

		vector<int> GenerateRow(int row)
		{
			vector<int> rez;
			for (int i = 0; i <= row; i++)
			{
				rez.emplace_back(GeneratePascal(row, i));
			}
			return rez;
		}

	};
}