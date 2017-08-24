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

		TEST_METHOD(TestFunctionRemoveZeros)
		{
			Assert::AreEqual({ 1, 1 }, RemoveBeginingZero({ 0, 0, 1, 1 }));
		}

		TEST_METHOD(UseAndOperator)
		{
			Assert::AreEqual(ToBinary(5 && 3), Operations(ToBinary(5), ToBinary(3), "And"));
		}

		TEST_METHOD(TestFunctionGetAt)
		{
			Assert::AreEqual(1, GetAt({ 1, 1 }, 0));
		}

		TEST_METHOD(UseOrOperator)
		{
			Assert::AreEqual(ToBinary(5 | 3), Operations(ToBinary(5), ToBinary(3), "Or"));
		}

		TEST_METHOD(UseXorOperator)
		{
			Assert::AreEqual(ToBinary(5 ^ 3), Operations(ToBinary(5), ToBinary(3), "Xor"));
		}

		TEST_METHOD(ShiftLeftOperator)
		{
			Assert::AreEqual(ToBinary(8), ShiftLeft(ToBinary(1), 3));
			Assert::AreEqual(ToBinary(20), ShiftLeft(ToBinary(5), 2));
		}

		TEST_METHOD(ShiftRightOperator)
		{
			Assert::AreEqual(ToBinary(1), ShiftRight(ToBinary(8), 3));
			Assert::AreEqual(ToBinary(12), ShiftRight(ToBinary(50), 2));
		}
		
		vector<char> ToBinary(int number)
		{
			vector<char> bin;
			while (number > 0)
			{
				bin.insert(bin.begin(), number % 2);
				number /= 2;
			}
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

		int GetAt(vector<char> vector, int position)
		{
			return position <= (vector.size() - 1) ? vector[(vector.size() - 1) - position] : 0;
		}

		vector<char> Operations(vector<char> bin1, vector<char> bin2, string operation)
		{
			vector<char> bin;
			for (int i = 0; i < max(bin1.size(), bin2.size()); i++)
			{
				if(operation == "And") bin.insert(bin.begin(), GetAt(bin1, i) && GetAt(bin2, i) == 1 ? 1 : 0);
				if(operation == "Or") bin.insert(bin.begin(), GetAt(bin1, i) || GetAt(bin2, i) == 1 ? 1 : 0);
				if(operation == "Xor") bin.insert(bin.begin(), GetAt(bin1, i) == GetAt(bin2, i) ? 0 : 1);
			}
			return RemoveBeginingZero(bin);
		}

		vector<char> ShiftLeft(vector<char> bin, int positions)
		{
			for (int i = 0; i < positions; i++) bin.push_back(0);
			return bin;
		}

		vector<char> ShiftRight(vector<char> bin, int positions)
		{
			for (int i = 0; i < positions; i++) bin.pop_back();
			return bin;
		}

	};
}