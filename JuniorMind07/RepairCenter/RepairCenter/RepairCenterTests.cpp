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

namespace RepairCenter
{		
	enum class Priority { Low, Medium, High };

	TEST_CLASS(SortingTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual({ 4,6,8,1,2,5,7,3,9,10 }, SortOrders());
		}

		struct Order
		{
			int ordNo;
			string ordName;
			Priority ordPriority;
			Order(int ordNo, string ordName, Priority ordPriority)
			{
				this->ordNo = ordNo;
				this->ordName = ordName;
				this->ordPriority = ordPriority;
			}

		};

		vector<Order> data_base = { { 1,"Brakes Change",Priority::Medium } ,{ 2,"Drivetrain Check",Priority::Medium } ,{ 3,"Oil Change",Priority::Low } ,{ 4,"Transmission Trouble",Priority::High } ,{ 5,"Suspension Problems",Priority::Medium } ,{ 6,"Replacing Exhaust",Priority::High } ,{ 7,"Replacing Catalytic Converter",Priority::Medium } ,{ 8,"Check ABS Wheels Sensors",Priority::High } ,{ 9,"Change Tires",Priority::Low } ,{ 10,"Removing Aftermarket Alarm",Priority::Low } };

		void shellSort(vector<Order> &db, int n)
		{
			for (int gap = n / 2; gap > 0; gap /= 2)
			{
				for (int i = gap; i < n; i += 1)
				{
					Order temp =  db[i];
					int j;
					for (j = i; j >= gap && CompareElements(db[j - gap], temp); j -= gap)
						db[j] = db[j - gap];

					db[j] = temp;
				}
			}
		}

		bool CompareElements(Order ord1, Order ord2)
		{
			if (ord1.ordPriority == ord2.ordPriority)
				return ord1.ordNo > ord2.ordNo;
			return ord1.ordPriority < ord2.ordPriority;
		}

		vector<int> SortOrders()
		{
			vector<int> result;
			shellSort(data_base,data_base.size());
			for (int i = 0; i < data_base.size(); i++)
				result.emplace_back(data_base[i].ordNo);
			return result;
		}

	};
}