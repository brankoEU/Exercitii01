#include "stdafx.h"
#include "CppUnitTest.h"
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			inline wstring ToString(const vector<char>& t) { return accumulate(t.begin(), t.end(), wstring(L""), [](wstring result, char item) -> wstring { return result + L" " + to_wstring(item); }); }
		}
	}
}

namespace ByteOperations
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConvertIntoBaseTwo)
		{
			Assert::AreEqual({ 1, 0, 1, 0 }, ConvertToBaseTwo(10));
		}

		TEST_METHOD(UseNotOperator)
		{
			Assert::AreEqual({ 0, 1, 0, 1 }, NotOperation(10));
		}
		
		vector<char> ConvertToBaseTwo(int number)
		{
			vector<char> bin;
			while (number > 0)
			{
				bin.push_back(number % 2);
				number /= 2;
			}
			reverse(bin.begin(), bin.end());
			return bin;
		}

		vector<char> NotOperation(int number)
		{
			vector<char> bite = ConvertToBaseTwo(number);
			for (int i = 0; i < bite.size(); i++)
			{
				bite[i] = bite[i] == 0 ? 1 : 0;
			}
			return bite;
		}

	};
}