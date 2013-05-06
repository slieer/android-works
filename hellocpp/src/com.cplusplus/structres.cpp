/*
 * structres.cpp
 *
 *  Created on: 2013-5-5
 *      Author: Administrator
 */

// example about structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define N_MOVIES 3

struct movies_t {
	string title;
	int year;
} mine, yours, films[N_MOVIES];

static void printmovie(movies_t movie);
static int main_1_test();
static int main_2_test();
static int main_3_test();

void structres(){
	main_1_test();
	main_2_test();
	main_3_test();
}

static int main_1_test() {
	string mystr;

	mine.title = "2001 A Space Odyssey";
	mine.year = 1968;

	cout << "Enter title: ";
	getline(cin, yours.title);
	cout << "Enter year: ";
	getline(cin, mystr);
	stringstream(mystr) >> yours.year;

	cout << "My favorite movie is:\n ";
	printmovie(mine);
	cout << "And yours is:\n ";
	printmovie(yours);
	return 0;
}

static int main_2_test() {
	string mystr;
	int n;

	for (n = 0; n < N_MOVIES; n++) {
		cout << "Enter title: ";
		getline(cin, films[n].title);
		cout << "Enter year: ";
		getline(cin, mystr);
		stringstream(mystr) >> films[n].year;
	}

	cout << "\nYou have entered these movies:\n";
	for (n = 0; n < N_MOVIES; n++)
		printmovie(films[n]);
	return 0;
}

static int main_3_test ()
{
  string mystr;

  movies_t amovie;
  movies_t * pmovie;
  pmovie = &amovie;

  cout << "Enter title: ";
  getline (cin, pmovie->title);
  cout << "Enter year: ";
  getline (cin, mystr);
  (stringstream) mystr >> pmovie->year;

  cout << "\nYou have entered:\n";
  cout << pmovie->title;
  cout << " (" << pmovie->year << ")\n";

  return 0;
}

static void printmovie(movies_t movie) {
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}

