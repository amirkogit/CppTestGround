// PowerBall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>

namespace RandomNumbers {

	//Select five numbers from 1 to 69 for the white balls; then select one number from 1 to 26 for the red Powerball.

	int run()
	{
		std::random_device rd{};
		auto mtgen = std::mt19937{ rd() };
		auto ud_white_ball = std::uniform_int_distribution<>{ 1,69 };

		// select five numbers for white balls
		std::cout << "Five numbers for white ball: ";

		for (auto i = 0; i < 5; ++i) {
			auto number = ud_white_ball(mtgen);
			std::cout << number << " ";
		}

		std::cout << "\n";

		auto ud_power_ball = std::uniform_int_distribution<>{ 1,26 };

		std::cout << "Powerball number: " << ud_power_ball(mtgen) << "\n";

		return 0;
	}

} // end namespace
int main()
{
    std::cout << "Powerball number generator!\n"; 

	const int TRIALS = 100;

	for (int i = 0; i < TRIALS; ++i) {
		std::cout << "<---------> TRIAL ---------> [" << i << "]\n";
		RandomNumbers::run();
		std::cout << "\n";
	}

	std::random_device rd{};
	auto mtgen = std::mt19937{ rd() };
	auto ud_luck_rd_selector = std::uniform_int_distribution<>{ 1,TRIALS };

	std::cout << "========== LUCKY RANDOM SELECTOR ============ : " << ud_luck_rd_selector(mtgen);
	std::cout << "\n";


	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
