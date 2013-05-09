/*
 * set_test.cpp
 *
 *  Created on: 2013-5-8
 *      Author: slieer
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include<vector>
#include<set>

using namespace std;

static string randArray[30] = {
		"programming", //declare a array that contain the 30 words
		"pop quiz", "assignment", "reference drive", "visual art",
		"visual studio", "web development", "digital entertainment system",
		"photoshop", "maya", "lighting", "internet", "computer", "laptop",
		"practical", "lecture", "lab group", "tutorial", "block m", "array",
		"pointers", "inspiration", "creativity", "variables", "potential",
		"imagination", "production", "instincts", "entrepreneurial", "effects" };

static void checkInput(char useInput, string str); // declare the function first
static int score = 5; //declare the variable and the first value is 5
static set<char> inside; //declare the vector to save the character which is correct
static set<char> outside; //declare the vector to save the character which is not correct

static void outputLetter() //this function is used to print the variable which is saved in the vector
{
	set<char>::iterator pos1;
	cout << "Characters used: ";
	for (pos1 = inside.begin(); pos1 != inside.end(); pos1++) //for loop
		cout << *pos1 << " ";
	set<char>::iterator pos2;
	cout << endl;
	cout << "Characters not used: ";
	for (pos2 = outside.begin(); pos2 != outside.end(); pos2++) //for loop
		cout << *pos2 << " ";
	cout << endl;
}

static void getRand() //this function is used to catch a letter randomization
{
	int k; //declare the variable
	char input;
	srand((unsigned) time(NULL)); //to make the seed equal time of system

	k = rand() % 30; //just get first 30 numbers
	cout << "Please guess this word ." << endl;
	cout << "You can enter a letter in one time." << endl;
	for (int i = 0; i < randArray[k].length(); i++) //it means how many character the letter have , then output how many "_".
			{

		cout << "_";
		cout << " ";

	}
	cout << randArray[k] << endl;
	while (score != 0) { // i declare a variable which is used to jude the whether the game is over
		cout << "Your input:";
		cin >> input;

///////////////////////////////////////////
////////////////////////////////////////////
		while (1) {
			if (inside.find(input) != inside.end()) {
				cout << "You have inputed the characte:" << input << endl;
				cout << "Please input a character:";
				cin >> input;
			} else
				break;
		}
///////////////////////////////////////////
////////////////////////////////////////////

		checkInput(input, randArray[k]);
	}

}

static void checkInput(char userInput, string str) //the function is used to check the character whether is correct
		{
	for (unsigned int i = 0; i < str.length(); i++) {
		if (userInput == str[i]) {
			cout << "Right!" << endl;
			inside.insert(userInput); //save data in the inside vector
			outputLetter();
			return;
		}

	}
	cout << "Wrong!" << endl;
	outside.insert(userInput); //save data in the outside vector
	outputLetter();
	score--; //if the player enter a wrong character , the score will get decrease , i get the first value is 5
	if (score == 0) {
		cout << "Sorry ,Game Over!" << endl;
	} else
		cout << "You only have " << score << " chance to guess the word."
				<< endl;
}

void set_main_() //the main function
{
	getRand();
	system("pause");
}

