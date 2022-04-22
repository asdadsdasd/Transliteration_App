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
			setDecMap();
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
			setDecMap();
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
			setDecMap();
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


		TEST_METHOD(_multipleTranslitTwoVariants)
		{
			setDecMap();
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


		TEST_METHOD(_multipleTranslitFourVariants)
		{
			setDecMap();
			string eng = "yozhik";
			vector<string> exp_string{ "йозхик", "йожик", "ёзхик", "ёжик" };

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
