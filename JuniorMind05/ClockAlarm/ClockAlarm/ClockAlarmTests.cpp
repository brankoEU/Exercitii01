#include "stdafx.h"
#include "CppUnitTest.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ClockAlarm
{		
	enum class WeekDays : int
	{
		Monday = 0x1,
		Tuesday = 0x2,
		Wednesday = 0x4,
		Thursday = 0x8,
		Friday = 0x10,
		Saturday = 0x20,
		Sunday = 0x40
	};

	WeekDays operator |(WeekDays lhs, WeekDays rhs)
	{
		return static_cast<WeekDays> (
			static_cast<underlying_type<WeekDays>::type>(lhs) |
			static_cast<underlying_type<WeekDays>::type>(rhs)
			);
	}

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

		TEST_METHOD(TestDaysMWF)
		{
			const WeekDays Days = WeekDays::Monday | WeekDays::Wednesday | WeekDays::Friday;
			Assert::IsTrue(AlarmRinger(6, Days));
		}
		
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