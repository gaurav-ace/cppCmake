#include "../include/main.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
//********* word guessing ***********

// need to have a set of words to choose from

std::vector<std::string> words = {
"test", "taste", "book", "code", "program", "last"
};


//need a random function to pick a random word from "words"
std::string pickWord(std::vector<std::string> &words){

int limit = words.size()-1;

//std::cout << "\t\t random picked index is " << rand()%limit << "\n";

return words[std::rand() % limit]; // this rand() % limit return a random number in the range of 0 to limit 
}


int main()
{
	srand(time(0));
	std::cout << "\n\t\t********* word guessing ************\n\n";

	std::cout << pickWord(words) << "\n";
	return 0;
}
