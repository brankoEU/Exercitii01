#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ClockAlarm
{		
	TEST_CLASS(ClockAlarmTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(true, AlarmRinger(6, Monday, { Monday | 6 }));
		}
		
		enum WeekDays
		{
			Monday,
			Tuesday,
			Wednesday,
			Thursday,
			Friday,
			Saturday,
			Sunday
		};
		
		struct Alarm
		{
			WeekDays day;
			int hour;
			Alarm(WeekDays day, int hour)
			{
				this->day = day;
				this->hour = hour;
			}
		};

		bool AlarmRinger(int hour, WeekDays day, Alarm alarm)
		{
			return false;
		}

	};
}