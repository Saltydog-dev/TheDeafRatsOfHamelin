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


int countDeafRats(const std::string& town)
{
	int reponse = 0; 

	std::string piedPiper = town;
	int longueur = piedPiper.length(); 
	
	int compteur = 0; 
	std::string indice = "";

	int position = 0; 

	while (compteur < longueur)
	{
		
		indice = piedPiper[compteur];

		if (indice == "P")
		{
			position = compteur; 
			compteur = longueur - 1;
		}
			
		compteur++; 
	}

	// After the pied piper 
	for (int i = position; i < piedPiper.size(); i++)
	{
		std::string ratHead = "";
		std::string ratTail = ""; 
		std::string beforeRat = ""; 
		
		ratHead = piedPiper[i];
		ratTail = piedPiper[i + 1];
		

		if (ratHead == "~" && ratTail == "O")
		{
			beforeRat = piedPiper[i - 1];
			if (beforeRat == "~" or beforeRat == " " or beforeRat == "P" or beforeRat == "O")
				reponse++; 
		}
			
	}

	// Before the pied piper 
	for (int i = position; i != position; i--)
	{
		std::string ratHead = "";
		std::string ratTail = "";
		std::string beforeRat = "";

		ratHead = piedPiper[i];
		ratTail = piedPiper[i + 1];


		if (ratHead == "~" && ratTail == "O")
		{
			beforeRat = piedPiper[i - 1];
			if (beforeRat == "~" or beforeRat == " ")
				reponse++;
		}
	}



	return reponse;
}







int main()
{
	
	std::string test = "P O~ O~ ~O O~"; // 1 deaf rat 
	std::string test_1 = "~O~O~O~OP~O~OO~"; // 2 deaf rats
	std::string test_2 = "P  O~O~O~  ~O  O~O~O~  O~O~O~O~O~O~~OO~O~O~~OO~O~O~O~O~O~O~O~O~O~O~O~O~~OO~O~"; // 4 deaf rats 

	//std::cout << countDeafRats(test) << std::endl; 
	std::cout << countDeafRats(test_1) << std::endl;
	//std::cout << countDeafRats(test_2) << std::endl; 


	return 0; 
}