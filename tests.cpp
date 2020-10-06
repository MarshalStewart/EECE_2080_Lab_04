// tests.cpp
#include "Recursion.h"
#include <gtest/gtest.h>


		TEST(Factorial, Recursion1)
		{
			FactorialByRecursion calculator;

			int val = calculator.CalculateFactorial(3);

			ASSERT_EQ(6, val);
		}

		TEST(Factorial, Recursion2)
		{
			FactorialByRecursion calculator;

			int val = calculator.CalculateFactorial(10);

			ASSERT_EQ(3628800, val);

		}
		
		TEST(Factorial, Stack1)
		{
			FactorialByStack calculator;

			int val = calculator.CalculateFactorial(3);

			ASSERT_EQ(6, val);

		}

		TEST(Factorial, Stack2)
		{
			FactorialByStack calculator;

			int val = calculator.CalculateFactorial(10);

			ASSERT_EQ(3628800, val);


		}


		// Palindrome
		TEST(PalindromeRecursion, emptyString)
		{
			PalindromeRecursion pal("");
			std::string str = pal.getString();
			ASSERT_FALSE(pal.CheckIfPalindromeTest());
			ASSERT_FALSE(pal.CheckIfPalindrome(str));
		}

		TEST(PalindromeRecursion, simpleString)
		{
			PalindromeRecursion pal("kayak");
			std::string str = pal.getString();
			//ASSERT_TRUE(pal.CheckIfPalindromeTest());
			ASSERT_TRUE(pal.CheckIfPalindrome(str));
		}

		TEST(PalindromeRecursion, complicatedString)
		{
			PalindromeRecursion pal("xx420!!024xx");
			std::string str = pal.getString();
			//ASSERT_TRUE(pal.CheckIfPalindromeTest());
			ASSERT_TRUE(pal.CheckIfPalindrome(str));
		}

		TEST(PalindromeRecursion, negativeTest)
		{
			PalindromeRecursion pal("boop");
			std::string str = pal.getString();
			//ASSERT_FALSE(pal.CheckIfPalindromeTest());
			ASSERT_FALSE(pal.CheckIfPalindrome(str));
		}

		TEST(PalindromeStack, emptyString)
		{
			PalindromeStack pal("");
			std:stack<char> str = pal.getStack();
			ASSERT_FALSE(pal.CheckIfPalindrome());
		}

		TEST(PalindromeStack, simpleString)
		{
			PalindromeStack pal("racecar");
			std:stack<char> str = pal.getStack();
			ASSERT_TRUE(pal.CheckIfPalindrome());
		}

		TEST(PalindromeStack, complicatedString)
		{
			PalindromeStack pal("123$$321");
			std:stack<char> str = pal.getStack();
			ASSERT_TRUE(pal.CheckIfPalindrome());
		}

		TEST(PalindromeStack, negativeTest)
		{
			PalindromeStack pal("stack");
			std:stack<char> str = pal.getStack();
			ASSERT_FALSE(pal.CheckIfPalindrome());
		}


		TEST(Exception,UserDefinedExceptionTest1)
		{

			std::string status = CallSimpleExceptionMethod(1);
			ASSERT_EQ(std::string("I got Exception 1"), status);
			
		}

		TEST(Exception,UserDefinedExceptionTest2)
		{


				std::string status = CallSimpleExceptionMethod(2);
				ASSERT_EQ(std::string("I got Exception 2"), status);

		}

		TEST(Exception,UserDefinedExceptionTest3)
		{

			std::string status = CallSimpleExceptionMethod(3);
			ASSERT_EQ(std::string("I got Exception 3"), status);

		}

		TEST(Exception,UserDefinedExceptionTest4)
		{

			std::string status = CallSimpleExceptionMethod(4);
			ASSERT_EQ(std::string("I did not get an Exception"), status);

		}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
