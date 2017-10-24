#include "stdafx.h"
#include "CppUnitTest.h"
#include <numeric>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			inline wstring ToString(const vector<int>& t) { return accumulate(t.begin(), t.end(), wstring(L""), [](wstring result, int item) -> wstring { return result + L" " + to_wstring(item); }); }
		}
	}
}

namespace SortLotoExtraction
{		
	TEST_CLASS(SortNumbers)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual({ 1,5,14,21,42,49 }, Sort({ 42,14,1,5,49,1 }));
		}

		vector<int> Sort(vector<int> list)
		{
			return list;
		}

	};
}