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

	WeekDays operator &(WeekDays lhs, WeekDays rhs)
	{
		return static_cast<WeekDays> (
			static_cast<underlying_type<WeekDays>::type>(lhs) &
			static_cast<underlying_type<WeekDays>::type>(rhs)
			);
	}


	TEST_CLASS(ClockAlarmTests)
	{
	public:

		TEST_METHOD(TestWeekDays)
		{
			Alarm AlarmWeek(WeekDays::Monday | WeekDays::Tuesday | WeekDays::Wednesday | WeekDays::Thursday | WeekDays::Friday, 6);
			Assert::IsTrue(AlarmRinger(6, WeekDays::Monday, AlarmWeek));
		}

		TEST_METHOD(TestWeekEndDays)
		{
			Alarm AlarmWeekEnd(WeekDays::Saturday | WeekDays::Sunday, 8);
			Assert::IsTrue(AlarmRinger(8, WeekDays::Sunday, AlarmWeekEnd));
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

		bool AlarmRinger(int hour, WeekDays day, Alarm alarm)
		{
			return ((day & alarm.day) == day) && (hour == alarm.hour);
		}
	};
}