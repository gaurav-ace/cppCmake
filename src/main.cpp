#include "../include/main.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
//********* word guessing ***********

// need to have a set of words to choose from

#define MAX_ATTEMPTS 10
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
	srand(time(0)); // time(0) gives the time in seconds since the Unix epoch,
			// srand() gives the random function a new seed, a starting point 
			// (usually random numbers are calculated by taking the previous number 
			// (or the seed) and then do many operations on that number to generate the next).
                        // if srand() not used, rand() function considers srand(1) and genenrate same set of numbers every tim    
	std::cout << "\n\t\t********* word guessing ************\n\n";

//	std::cout << pickWord(words) << "\n";

	std::string word = pickWord(words);
//	std::cout << "Word to be guessed (showing for testing purpose) : " << word <<"\n";

        int len = word.length(), attempts_lost = 0, guessedLen = 0;
	std::string userGuess = "";
	bool isValid = true;

	for(int i = 0; i < len; i++)
	{
		userGuess += "_";	
 	}
	
		
	std::cout << "\t\t The word contains "<< len << " letters\n";
	
	do{
	
		std::cout << "\t\t" << userGuess << "\n\n";
	
		//now we will ask user to input the letters one by one, if it matches the random word's letter
		// we will print matched
		char letter;
   		std::cout << "\t\tPlease guess the letter : ";
		std::cin >> letter;
		
	
//		std::cout << "\nguessed letter is : " << letter << "\n";
	
		// match from letters of random word
		size_t pos = word.find(letter); 

		if(pos != std::string::npos)
		{
			//std::cout << "remaining word : " << word << " matched pos : " << pos << "\n";
			std::cout << "\t\tGreat!!\n";
			if(userGuess[pos] == '_')
			{	
				guessedLen++;
				userGuess[pos] = letter; // add letter at pos in userGuess
				word[pos] = '*'; // replace letter at pos from word to some special char
			}
//			 std::cout << "remaining word : " << word << " matched pos : " << pos << "\n";
			if(guessedLen == len)
			{
				std::cout << "\t\tCongrats, you have guessed the word : \'" << userGuess << "\' correctly!!!\n";
				isValid = false;
			}
		} 
		else
		{
			std::cout << "sorry, wrong guess!!\n";
				
			attempts_lost++;	
			std::cout << "attempts left = " << MAX_ATTEMPTS - attempts_lost << "\n";
			if(attempts_lost == MAX_ATTEMPTS)
				isValid = false;
		}
	}while(isValid);
	
	

	return 0;
}
