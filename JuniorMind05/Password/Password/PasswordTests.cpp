#include "stdafx.h"
#include "CppUnitTest.h"
#include <random>
#include <algorithm>
#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{		
	TEST_CLASS(PasswordTest)
	{
	public:
		
		TEST_METHOD(VerifyUpperCase)
		{
			string password = GeneratePassword({ 7,2,2,1,true,true });
			PasswordOptions options;
			Assert::AreEqual(2, VerifyPassword(password, options.restricted.uppercase));
		}

		TEST_METHOD(VerifySymbols)
		{
			string password = GeneratePassword({ 7,2,2,1,true,true });
			PasswordOptions options;
			Assert::AreEqual(1, VerifyPassword(password, options.restricted.symbols));
		}
		
		struct PasswordOptions
		{
			int passLenght;
			int uppercase;
			int numbers;
			int symbols;
			bool excludeAmbiguius;
			bool excludeSimilar;

			struct Restrictions
			{
				string ambiguous = "{}[]()/\\'\"`~,;:.<>";
				string symbols = "!@#$%^&*-_+=|?";
				string numbers = "1234567890";
				string lowercase = "abcdefghijklmnopqrstuvwxyz";
				string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string similar = "iIl10oO";
			}restricted;

			int GetLowerCaseLenght()
			{
				return passLenght - numbers - symbols - uppercase;
			}

		};

		string GeneratePassword(PasswordOptions options)
		{
			string password = "";
			int countUpper = 0, countSymbols = 0, countNumbers = 0, countLower = 0;

			static random_device rd;
			static mt19937 generator(rd());
			uniform_int_distribution<int> rndNo(33, 126);

			while (password.size() < options.passLenght)
			{
				char nextChar = char(rndNo(generator));
				if (CheckChar(options.restricted.ambiguous, nextChar) && !options.excludeAmbiguius) { password += nextChar; }
				if (CheckChar(options.restricted.similar, nextChar) && !options.excludeSimilar) { password += nextChar; }
				if (CheckChar(options.restricted.symbols, nextChar) && countSymbols < options.symbols) { countSymbols++; password += nextChar; }
				if (CheckChar(options.restricted.uppercase, nextChar) && countUpper < options.uppercase) { countUpper++; password += nextChar; }
				if (CheckChar(options.restricted.numbers, nextChar) && countNumbers < options.numbers) { countNumbers++; password += nextChar; }
				if (CheckChar(options.restricted.lowercase, nextChar) && countLower < options.GetLowerCaseLenght()) { countLower++; password += nextChar; }
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

		int VerifyPassword(string password, string str)
		{
			int count = 0;
			for each (char c in password)
			{
				for (int i = 0; i < str.size(); i++)
				{
					if (str[i] == c) { count++; }
				}
			}
			return count;
		}

	};
}