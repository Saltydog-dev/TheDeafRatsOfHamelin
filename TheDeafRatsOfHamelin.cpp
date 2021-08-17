/**
* \file TheDeafRatsOfHamelin.cpp
* \author Stéphane Voulanger 
* \brief The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.
*        But some of the rats are deaf and are going the wrong way!
*        How many deaf rats are there?
* 
*        P = The Pied Piper
*        O~ = Rat going left
*        ~O = Rat going right
*        
*        ex1 ~O~O~O~O P has 0 deaf rats
*        ex2 P O~ O~ ~O O~ has 1 deaf rat
*        ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
* \version 0.1
* \date 2021-08-11
* \source https://www.codewars.com/kata/598106cb34e205e074000031/train/cpp
* \copyright Copyright (c) 2021
*/

#include <iostream>
#include <vector>

int countDeafRats(const std::string& town)
{
	int answer = 0;
	std::string newTown = town; 

	int townLength = newTown.length(); 
	int counter = 0; 
	std::string rats = "";
	std::string piedPiper = "";

	// Delete the space 
	while (counter < townLength)
	{
		rats = newTown[counter];
		if (rats != " ")
			piedPiper += rats;
		counter++; 
	}

	int piedPiperLength = piedPiper.length(); 
	counter = 0; 

	// Find the position of the " P "
	std::string indice = "";
	int position = 0;

	while (counter < piedPiperLength)
	{
		indice = piedPiper[counter];
		if (indice == "P")
		{
			position = counter;
			counter = piedPiperLength - 1;
		}
		counter++;
	}

	int positionP = position; 

	// After the pied piper 
	std::vector<std::string> myRats; 
	position += 1; 

	for (size_t i = position; i < piedPiper.size(); i+=2)
	{
		rats = piedPiper[i];
		rats += piedPiper[i + 1];
		myRats.push_back(rats);
		rats = ""; 
	}

	// Find the right rats 
	for (auto it = myRats.begin(); it != myRats.end(); ++it)
	{
		if (*it == "~O")
			answer++; 
	}

	myRats.clear();
	
	if (positionP != 0)
	{
		// Before the pied piper 
		for (size_t i = 0; i != positionP; i+=2)
		{
			rats = piedPiper[i];
			rats += piedPiper[i + 1];
			myRats.push_back(rats);
			rats = "";
		}

		// Find the left rats 
		for (auto it = myRats.begin(); it != myRats.end(); ++it)
		{
			if (*it == "O~")
				answer++;
		}
	};

	return answer;
}


// Algorithm Test 
int main()
{
	std::string test_0 = "P O~ O~ O~ O~"; // 0 deaf rat
	std::string test_1 = "P O~ O~ ~O O~"; // 1 deaf rat 
	std::string test_2 = "~O~O~O~OP~O~OO~"; // 2 deaf rats
	std::string test_3 = "~OO~~O~OP~O~OO~"; // 3 deaf rats 
	std::string test_4 = "P  O~O~O~  ~O  O~O~O~  O~O~O~O~O~O~~OO~O~O~~OO~O~O~O~O~O~O~O~O~O~O~O~O~~OO~O~"; // 4 deaf rats 
	
	
	std::cout << countDeafRats(test_0) << std::endl; 
	std::cout << countDeafRats(test_1) << std::endl; 
	std::cout << countDeafRats(test_2) << std::endl; 
	std::cout << countDeafRats(test_3) << std::endl; 
	std::cout << countDeafRats(test_4) << std::endl; 

	return 0; 
}