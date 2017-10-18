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
			Assert::AreEqual({ 1 }, GeneratePascal(1));
		}

		vector<int> GeneratePascal(int line)
		{
			return {};
		}

	};
}