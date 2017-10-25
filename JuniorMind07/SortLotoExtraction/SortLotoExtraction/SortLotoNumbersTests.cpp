#include "stdafx.h"
#include "CppUnitTest.h"
#include <numeric>
#include <vector>
#include "generator.h"

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
		
		TEST_METHOD(SelectionSort)
		{
			vector<int> list = { 42,14,21,5,49,1 };
			SelectionSort(list);
			Assert::AreEqual({ 1,5,14,21,42,49 }, list);
		}

		TEST_METHOD(QuickSort)
		{ 
			vector<int> list = { 42,14,21,5,49,1 };
			QuickSort(list, 0, list.size() - 1);
			Assert::AreEqual({ 1,5,14,21,42,49 }, list);
		}

		TEST_METHOD(InsersionSort)
		{
			vector<int> list = { 42,14,21,5,49,1 };
			InsersionSort(list, list.size()-1);
			Assert::AreEqual({ 1,5,14,21,42,49 }, list);
		}

		//SelectionSort
		void SelectionSort(vector<int> &list)
		{
			for (int i = 0; i < list.size()-1; i++)
			{
				int minPos = i;
				for (int j = i+1; j < list.size(); j++)
				{
					if (list[j] < list[minPos]) { minPos = j; }
				}
				if (minPos != i) { swap(list[i], list[minPos]); }
			}
		}

		//QuickSort .....
		void QuickSort(vector<int> &list, int low, int high)
		{
			if (low < high)
			{
				int pi = Partition(list, low, high);
				QuickSort(list, low, pi - 1);
				QuickSort(list, pi + 1, high);
			}
		}

		int Partition(vector<int> &list, int low, int high)
		{
			int pivot = list[high];
			int i = (low - 1);
			for (int j = low; j <= high - 1; j++)
			{
				if (list[j] <= pivot)
					{
						i++;
						swap(list[i], list[j]);
					}
				}
			swap(list[i + 1], list[high]);
			return (i + 1);
		}

		//InsertionSort .....
		void InsersionSort(vector<int> &list, int n)
		{
			if (n > 0)
			{
				InsersionSort(list, n - 1);
				int x = list[n];
				int j = n - 1;
				while (j >= 0 && list[j] > x)
				{
					list[j + 1] = list[j];
					j--;
				}
				list[j + 1] = x;
			}
		}

	};
}