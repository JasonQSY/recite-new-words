#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class NewWord{
public:
	string English;
	string Chinese;
};

vector<NewWord> WordList;
const int WordNumber = 97;

void inputtxt();
void printWordList();

int main()
{
	uniform_int_distribution<int> u(1, WordNumber);//must be a constant number
	default_random_engine e(time(0));
	string input;
	NewWord ThisWord;
	int score = 0;

	//initialize
	inputtxt();
	
	cout << "The program will print the Chinese meaning of a random new word." << endl
		<< "You need enter the English word." << endl
		<< "Please enter 0 to quit the simple game." << endl;
	for (int i = 0; i < 20; i++){
		ThisWord = WordList[u(e)];
		cout << "You current score is " << score << "." << endl;
		cout << "Chinese:" << ThisWord.Chinese << endl;
		cout << "English:";
		cin >> input;
		if (input == "0"){
			cout << "Game Over." << endl;
			break;
		}
		else if (input == ThisWord.English){
			cout << "Good job!" << endl;
			score++;
		}
		else{
			cout << "Wrong answer. You fail." << endl;
			cout << "The correct answer is " << ThisWord.English << "." << endl;
		}
	}
	cout << "Your final score is " << score << "." << endl;
	getchar();
	getchar();
	return 0;
}
void inputtxt(){
	ifstream input("words.txt");
	string line, word;
	int number, lineno;
	NewWord NewWord;

	lineno = 0;
	while (getline(input, line)){
		//cout << line << endl;
		stringstream record(line);
		number = 0;
		while (record >> word){
			if (number == 0){
				NewWord.English = word;
			}
			else if (number == 2){
				NewWord.Chinese = word;
			}
			number++;
		}
		WordList.push_back(NewWord);
		lineno++;
	}
}
void printWordList(){
	for (int i = 0; i < WordNumber; i++){
		cout << WordList[i].English << " " << WordList[i].Chinese << endl;
	}
}