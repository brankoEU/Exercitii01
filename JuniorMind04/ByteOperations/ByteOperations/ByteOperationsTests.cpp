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

		TEST_METHOD(UseAndOperator)
		{
			Assert::AreEqual(ToBinary(5 && 3), And(ToBinary(5), ToBinary(3)));
		}
		
		vector<char> ToBinary(int number)
		{
			vector<char> bin;
			while (number > 0)
			{
				bin.push_back(number % 2);
				number /= 2;
			}
			return Reverse(bin);
		}

		vector<char> Reverse(std::vector<char> bin)
		{
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

		vector<char> And(vector<char> bin1, vector<char> bin2)
		{
			vector<char> bin;
			if (bin1.size() != bin2.size())
			{
				for (int i = 1; i < max(bin1.size(), bin2.size()); i++)
				{
					if (bin1.size() < bin2.size()) bin1.insert(bin1.begin(), 0);
					else bin2.insert(bin2.begin(), 0);
				}
			}
			for (int i = 1; i < bin1.size(); i++)
			{
				if (bin1[i] == 1 && bin2[i] == 1) { bin.push_back(1); }
				else { bin.push_back(0); }
			}

			return RemoveBeginingZero(bin);
		}

	};
}