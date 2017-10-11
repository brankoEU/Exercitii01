#include "stdafx.h"
#include "CppUnitTest.h"
#include <random>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{		
	TEST_CLASS(PasswordTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("", GeneratePassword(4).c_str());
		}

		

		string GeneratePassword(int passlenght)
		{
			string ambiguous = "{}[]()/\\'\"`~,;:.<>";
			string symbols = "!@#$%^&*-_+=|?";
			string numbers = "1234567890";
			string lowercase = "abcdefghijklmnopqrstuvwxyz";
			string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string similar = "iIl10oO";
			string password = "";

			static random_device rd;
			static mt19937 generator(rd());
			uniform_int_distribution<int> asciiChar(33, 126);

			while (password.size() < passlenght)
			{
				password += char(asciiChar(generator));
				
			}

			return password;
		}

	};
}