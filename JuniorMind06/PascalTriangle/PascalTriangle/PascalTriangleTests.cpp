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

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual({ 1,11,55,165,330,462,462,330,165,55,11,1 }, GenerateRow(11));
		}

		vector<int> GetNextRow(vector<int> row, int i, vector<int> nextRow = {})
		{
			i == 0 || i == row.size() ? nextRow.emplace_back(1) : nextRow.emplace_back(row[i - 1] + row[i]);
			return i==0 ? nextRow : GetNextRow(row, i-1, nextRow);
		}

		vector<int> GenerateRow(int rowNr, vector<int> prev = {})
		{
			return rowNr < 0 ? prev : GenerateRow(rowNr-1, GetNextRow(prev, prev.size()));
		}

	};
}