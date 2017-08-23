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
			Assert::AreEqual({ 1, 0, 1, 0 }, ToBinary(10));
		}

		TEST_METHOD(UseNotOperator)
		{
			Assert::AreEqual({ 1, 0, 1 }, Not(ToBinary(10)));
		}

		TEST_METHOD(RemoveZeros)
		{
			Assert::AreEqual({ 1, 1 }, RemoveBeginingZero({ 0, 0, 1, 1 }));
		}
		
		vector<char> ToBinary(int number)
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

		vector<char> Not(vector<char> bin)
		{
			for (int i = 0; i < bin.size(); i++)
			{
				bin[i] = bin[i] == 0 ? 1 : 0;
			}
			return RemoveBeginingZero(bin);
		}

		vector<char> RemoveBeginingZero(vector<char> bin)
		{
			while (bin[0] == 0)
			{
				bin.erase(bin.begin());
			}
			
			return bin;
		}

	};
}