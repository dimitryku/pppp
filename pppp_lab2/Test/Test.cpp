#include "pch.h"
#include "CppUnitTest.h"
#include"../pppp_lab2/solve.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(NoOneSolution)
		{
			std::string expected = "0";
			std::string actual = solve(0, 0, 0, 0, 5, 1);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InfinitySolutions)
		{
			std::string expected = "1 -5.000000 1.000000";
			std::string actual = solve(5, 1, 0, 0, 1, 0);
			Assert::AreEqual(expected, actual);
		}
		

		TEST_METHOD(SingleSolution)
		{
			std::string expected = "2 3.000000 2.000000";
			std::string actual = solve(1, 5, 2, 7, 13, 20);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InfinityYsolutions)
		{
			std::string expected = "3 6.000000";
			std::string actual = solve(1, 0, 4, 0, 6, 24);
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(InfinityXsolutions)
		{
			std::string expected = "4 7.000000";
			std::string actual = solve(0, 1, 0, 3, 7, 21);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SolutionIsAnyNums)
		{
			std::string expected = "5";
			std::string actual = solve(0, 0, 0, 0, 0, 0);
			Assert::AreEqual(expected, actual);
		}

	};
}
