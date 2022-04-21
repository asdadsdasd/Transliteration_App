#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationApp/Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLibrary
{
	TEST_CLASS(TestLibrary)
	{
	public:
		
		TEST_METHOD(_translitMin)
		{
			string eng = "q";
			vector<string> exp_string{ "ку" };

			vector<string> returnString = translit(eng);
			if (exp_string == returnString)
			{
				Assert::AreEqual(1, 1);
			}
			else
			{
				Assert::AreEqual(1, 2);
			}
		}

		TEST_METHOD(_translitMedium)
		{
			string eng = "qqqqq";
			vector<string> exp_string{ "кукукукуку" };

			vector<string> returnString = translit(eng);
			if (exp_string == returnString)
			{
				Assert::AreEqual(1, 1);
			}
			else
			{
				Assert::AreEqual(1, 2);
			}
		}

		TEST_METHOD(_translitMax)
		{
			string eng = "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
			vector<string> exp_string{ "кукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукукуку" };

			vector<string> returnString = translit(eng);
			if (exp_string == returnString)
			{
				Assert::AreEqual(1, 1);
			}
			else
			{
				Assert::AreEqual(1, 2);
			}
		}

		TEST_METHOD(_multipleTranslit)
		{
			string eng = "ezhik";
			vector<string> exp_string{ "езхик", "ежик" };

			vector<string> returnString = translit(eng);
			if (exp_string == returnString)
			{
				Assert::AreEqual(1, 1);
			}
			else
			{
				Assert::AreEqual(1, 2);
			}
		}

		TEST_METHOD(_multipleTranslitqwe)
		{
			string eng = "yozhik";
			vector<string> exp_string{ "йозхик", "йозхик", "ёзхик", "ёжик" };

			vector<string> returnString = translit(eng);
			if (exp_string == returnString)
			{
				Assert::AreEqual(1, 1);
			}
			else
			{
				Assert::AreEqual(1, 2);
			}
		}
	};
}
