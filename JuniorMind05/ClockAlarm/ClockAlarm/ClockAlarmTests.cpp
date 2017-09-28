#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ClockAlarm
{		
	TEST_CLASS(ClockAlarmTests)
	{
	public:
		
		TEST_METHOD(TestMonday)
		{
			Assert::IsTrue(AlarmRinger(6, WeekDays::Monday));
		}

		TEST_METHOD(TestWeek)
		{
			Assert::IsTrue(AlarmRinger(6, WeekDays::Friday));
			Assert::IsFalse(AlarmRinger(8, WeekDays::Wednesday));
		}

		TEST_METHOD(TestWeekEnd)
		{
			Assert::IsTrue(AlarmRinger(8, WeekDays::Sunday));
			Assert::IsFalse(AlarmRinger(6, WeekDays::Sunday));
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

		int AlarmSetup(WeekDays day)
		{
			bool weekEnd = false;
			switch (day)
			{
			case WeekDays::Saturday: weekEnd = true;
			case WeekDays::Sunday: weekEnd = true;
			}
			return weekEnd ? 8 : 6;
		}

		bool AlarmRinger(int hour, WeekDays day)
		{
			Alarm alarm(day, AlarmSetup(day));
			return day == alarm.day && hour == alarm.hour;
		}

	};
}