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
			Alarm alarm(WeekDays::Monday, 6);
			Assert::IsTrue(AlarmRinger(6, WeekDays::Monday, alarm));
		}
		
		enum class WeekDays
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
			return day == alarm.day && hour == alarm.hour;
		}

	};
}