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
			Assert::AreEqual({ 0 }, Not(ToBinary(3)));
		}

		TEST_METHOD(TestFunctionRemoveZeros)
		{
			Assert::AreEqual({ 1, 1 }, RemoveBeginingZero({ 0, 0, 1, 1 }));
			Assert::AreEqual({ 0 }, RemoveBeginingZero({ 0, 0, 0, 0 }));
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

		TEST_METHOD(LessThanOperator)
		{
			Assert::AreEqual(false, LessThan(ToBinary(8), ToBinary(8)));
			Assert::AreEqual(true, LessThan(ToBinary(7), ToBinary(8)));
		}

		TEST_METHOD(GraterThanOperator)
		{
			Assert::AreEqual(true, GraterThan(ToBinary(9), ToBinary(8)));
			Assert::AreEqual(false, GraterThan(ToBinary(8), ToBinary(8)));
		}

		TEST_METHOD(EqualOperator)
		{
			Assert::AreEqual(false, Equal(ToBinary(9), ToBinary(8)));
			Assert::AreEqual(true, Equal(ToBinary(8), ToBinary(8)));
			Assert::AreEqual(false, Equal(ToBinary(7), ToBinary(8)));
		}

		TEST_METHOD(NotEqualOperator)
		{
			Assert::AreEqual(true, NotEqual(ToBinary(9), ToBinary(8)));
			Assert::AreEqual(false, NotEqual(ToBinary(8), ToBinary(8)));
		}

		TEST_METHOD(TestSumFunction)
		{
			Assert::AreEqual(ToBinary(9), Sum(ToBinary(5), ToBinary(4)));
			Assert::AreEqual(ToBinary(8), Sum(ToBinary(3), ToBinary(5)));
		}

		TEST_METHOD(TestDifferenceFunction)
		{
			Assert::AreEqual(ToBinary(2), Difference(ToBinary(3), ToBinary(5)));
			Assert::AreEqual(ToBinary(3), Difference(ToBinary(5), ToBinary(2)));
			Assert::AreEqual(ToBinary(3), Difference(ToBinary(8), ToBinary(5)));
		}

		TEST_METHOD(TestMultiplyFunction)
		{
			Assert::AreEqual(ToBinary(15), Multiply(ToBinary(3), ToBinary(5)));
			Assert::AreEqual(ToBinary(21), Multiply(ToBinary(7), ToBinary(3)));
			Assert::AreEqual(ToBinary(32), Multiply(ToBinary(4), ToBinary(8)));
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
			while (bin[0] == 0 && bin.size() > 1)
			{
				bin.erase(bin.begin());
			}
			return bin;
		}

		int GetAt(vector<char> vector, int position)
		{
			return position <= (vector.size() - 1) ? vector[vector.size() - position - 1] : 0;
		}

		vector<char> Operations(vector<char> bin1, vector<char> bin2, string operation)
		{
			vector<char> bin;
			for (int i = 0; i < max(bin1.size(), bin2.size()); i++)
			{
				bin.insert(bin.begin(), ChooseOperation(GetAt(bin1, i), GetAt(bin2, i), operation));
			}
			return RemoveBeginingZero(bin);
		}

		char ChooseOperation(char first, char second, string operation)
		{
			if (operation == "And") return first && second == 1 ? 1 : 0;
			if (operation == "Or")  return first || second == 1 ? 1 : 0;
		    return first == second ? 0 : 1;
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

		bool LessThan(vector<char> bin1, vector<char> bin2)
		{
			for (int i = max(bin1.size(), bin2.size()); i >= 0; i--)
			{
				if (GetAt(bin1, i) < GetAt(bin2, i)) return true;
			}
			return false;
		}

		bool GraterThan(vector<char> bin1, vector<char> bin2)
		{
			return LessThan(bin2, bin1);
		}

		bool Equal(vector<char> bin1, vector<char> bin2)
		{
			return !LessThan(bin1, bin2) && !LessThan(bin2, bin1);
		}

		bool NotEqual(vector<char> bin1, vector<char> bin2)
		{
			return !Equal(bin1, bin2);
		}

		vector<char> Sum(vector<char> bin1, vector<char> bin2)
		{
			int carry = 0;
			vector<char> bin;
			for (int i = 0; i <= max(bin1.size(), bin2.size()); i++)
			{
				bin.insert(bin.begin(), (GetAt(bin1, i) + GetAt(bin2, i) + carry) % 2);
				carry = (GetAt(bin1, i) + GetAt(bin2, i) + carry) / 2;
			}
			return RemoveBeginingZero(bin);
		}

		vector<char> Difference(vector<char> bin1, vector<char> bin2)
		{
			vector<char> bin = Sum(bin1, Sum(Not(bin2), ToBinary(1)));
			if (bin.size() > min(bin1.size(), bin2.size())) bin.erase(bin.begin());
			return RemoveBeginingZero(bin);
		}

		vector<char> Multiply(vector<char> bin1, vector<char> bin2)
		{
			vector<char> bin = { 0 };
			for (int i = 0; i < bin2.size(); i++)
			{
				if (GetAt(bin2, i) == 1)
				{
					bin = Sum(bin, bin1);
					bin1.push_back(0);
				}
			    else bin1.push_back(0);
			}
			return bin;
		}

	};
}