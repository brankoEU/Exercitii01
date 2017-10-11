#include "stdafx.h"
#include "CppUnitTest.h"
#include <random>
#include <algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{		
	TEST_CLASS(PasswordTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("", GeneratePassword(7).c_str());
		}

		

		string GeneratePassword(int passlenght)
		{
			string ambiguous = "{}[]()/\\'\"`~,;:.<>";
			string symbols = "!@#$%^&*-_+=|?";
			string numbers = "1234567890";
			string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string similar = "iIl10oO";
			string password = "";
			int countUpper = 0, countSymbols = 0, countNumbers = 0;

			static random_device rd;
			static mt19937 generator(rd());
			uniform_int_distribution<int> asciiChar(33, 126);

			while (password.size() < passlenght)
			{
				char nextChar = char(asciiChar(generator));
				if (!CheckChar(ambiguous, nextChar) && !CheckChar(similar, nextChar)) { password += nextChar; }
				if (CheckChar(symbols, nextChar)) { countSymbols++; }
				if (CheckChar(uppercase, nextChar)) { countUpper++; }
				if (CheckChar(numbers, nextChar)) { countNumbers++; }
			}

			return password;
		}

		bool CheckChar(string str, char toCheck)
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (toCheck == str[i]) return true;
			}
			return false;
		}

	};
}