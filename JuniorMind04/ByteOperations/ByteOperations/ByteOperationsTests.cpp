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
			Assert::AreEqual(ToBinary(9), Sum(ToBinary(5), ToBinary(4), 2));
			Assert::AreEqual(ToBinary(8), Sum(ToBinary(3), ToBinary(5), 2));
		}

		TEST_METHOD(TestDifferenceFunction)
		{
			Assert::AreEqual({ 0 }, Difference(ToBinary(5), ToBinary(5), 2));
			Assert::AreEqual(ToBinary(3), Difference(ToBinary(5), ToBinary(2), 2));
			Assert::AreEqual(ToBinary(12), Difference(ToBinary(16), ToBinary(4), 2));
		}

		TEST_METHOD(TestMultiplyFunction)
		{
			Assert::AreEqual(ToBinary(15), Multiply(ToBinary(3), ToBinary(5), 2));
			Assert::AreEqual(ToBinary(21), Multiply(ToBinary(7), ToBinary(3), 2));
			Assert::AreEqual(ToBinary(32), Multiply(ToBinary(4), ToBinary(8), 2));
		}
		TEST_METHOD(TestDivisionFunction)
		{
			Assert::AreEqual(ToBinary(5), Division(ToBinary(25), ToBinary(5), 2));
			Assert::AreEqual(ToBinary(3), Division(ToBinary(15), ToBinary(5), 2));
			Assert::AreEqual(ToBinary(4), Division(ToBinary(16), ToBinary(4), 2));
		}

		TEST_METHOD(LessThanAnyBase)
		{
			Assert::AreEqual(false, LessThan(ToAnyBase(8, 5), ToAnyBase(8, 5)));
			Assert::AreEqual(true, LessThan(ToAnyBase(7, 5), ToAnyBase(8, 5)));
		}

		TEST_METHOD(GraterThanAnyBase)
		{
			Assert::AreEqual(true, GraterThan(ToAnyBase(9, 8), ToAnyBase(8, 8)));
			Assert::AreEqual(false, GraterThan(ToAnyBase(8, 7), ToAnyBase(8, 7)));
		}

		TEST_METHOD(EqualAnyBase)
		{
			Assert::AreEqual(false, Equal(ToAnyBase(21, 3), ToAnyBase(17, 3)));
			Assert::AreEqual(true, Equal(ToAnyBase(22, 11), ToAnyBase(22, 11)));
			Assert::AreEqual(false, Equal(ToAnyBase(31, 21), ToAnyBase(33, 21)));
		}

		TEST_METHOD(NotEqualAnyBase)
		{
			Assert::AreEqual(true, NotEqual(ToAnyBase(25, 17), ToAnyBase(31, 17)));
			Assert::AreEqual(false, NotEqual(ToAnyBase(17, 15), ToAnyBase(17, 15)));
		}

		TEST_METHOD(AnyBaseSum)
		{
			Assert::AreEqual(ToAnyBase(9, 6), Sum(ToAnyBase(5, 6), ToAnyBase(4, 6), 6));
			Assert::AreEqual(ToAnyBase(8, 3), Sum(ToAnyBase(3, 3), ToAnyBase(5, 3), 3));
		}

		TEST_METHOD(AnyBaseDifference)
		{
			Assert::AreEqual({ 0 }, Difference(ToAnyBase(5, 4), ToAnyBase(5, 4), 4));
			Assert::AreEqual(ToAnyBase(3, 6), Difference(ToAnyBase(5, 6), ToAnyBase(2, 6), 6));
			Assert::AreEqual(ToAnyBase(12, 5), Difference(ToAnyBase(16, 5), ToAnyBase(4, 5), 5));
		}

		TEST_METHOD(AnyBaseMultiply)
		{
			Assert::AreEqual(ToAnyBase(15, 3), Multiply(ToAnyBase(3, 3), ToAnyBase(5, 3), 3));
			Assert::AreEqual(ToAnyBase(21, 3), Multiply(ToAnyBase(7, 3), ToAnyBase(3, 3), 3));
			Assert::AreEqual(ToAnyBase(32, 4), Multiply(ToAnyBase(4, 4), ToAnyBase(8, 4), 4));
		}
		TEST_METHOD(AnyBaseDivision)
		{
			Assert::AreEqual(ToAnyBase(5, 4), Division(ToAnyBase(25, 4), ToAnyBase(5, 4), 4));
			Assert::AreEqual(ToAnyBase(3, 3), Division(ToAnyBase(15, 3), ToAnyBase(5, 3), 3));
			Assert::AreEqual(ToAnyBase(4, 4), Division(ToAnyBase(16, 4), ToAnyBase(4, 4), 4));
		}

		TEST_METHOD(TestComplements)
		{
			Assert::AreEqual({ 6, 7, 8 }, ComplemetsByBase({ 3, 2, 1 }, 10));
		}
		
		vector<char> ToBinary(int number)
		{
			return ToAnyBase(number, 2);
		}
		
		vector<char> ToAnyBase(int number, int base)
		{
			vector<char> bin;
			while (number > 0)
			{
				bin.insert(bin.begin(), number % base);
				number /= base;
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

		vector<char> Sum(vector<char> bin1, vector<char> bin2, int base)
		{
			int carry = 0;
			vector<char> bin;
			for (int i = 0; i <= max(bin1.size(), bin2.size()); i++)
			{
				bin.insert(bin.begin(), (GetAt(bin1, i) + GetAt(bin2, i) + carry) % base);
				carry = (GetAt(bin1, i) + GetAt(bin2, i) + carry) / base;
			}
			return RemoveBeginingZero(bin);
		}

		vector<char> Difference(vector<char> bin1, vector<char> bin2, int base)
		{
			if ((bin1.size() - bin2.size()) != 0)
			{
				for (int i = 0; i <= (bin1.size() - bin2.size()); i++) 
					bin2.insert(bin2.begin(), 0);
			}
			vector<char> bin = Sum(bin1, Sum(ComplemetsByBase(bin2, base), ToAnyBase(1, base), base), base);
			if (bin.size() > min(bin1.size(), bin2.size())) bin.erase(bin.begin());
			return RemoveBeginingZero(bin);
		}

		vector<char> Multiply(vector<char> bin1, vector<char> bin2, int base)
		{
			vector<char> bin = { 0 };
			do
			{
				bin = Sum(bin, bin1, base);
				bin2 = Difference(bin2, ToAnyBase(1, base), base);
			} while (NotEqual(bin2, { 0 }));
			return bin;
		}

		vector<char> Division(vector<char> bin1, vector<char> bin2, int base)
		{
			int div = 0;
			while (NotEqual(bin1, {0}))
			{
				bin1 = Difference(bin1, bin2, base);
				div++;
			}
			return ToAnyBase(div, base);
		}

		vector<char> ComplemetsByBase(vector<char> bin, int base)
		{
			for (int i = 0; i < bin.size(); i++)
			{
				bin[i] = base - 1 - bin[i];
			}
			return RemoveBeginingZero(bin);
		}

	};
}