#ifndef PUZZLE_H
#define PUZZlE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Puzzle {
	public:
		//Puzzle();
		Puzzle(string);
		void display();
	private:
		vector< vector<T> > sudoku;
};

template <typename T>
//Puzzle<T>::Puzzle(){
Puzzle<T>::Puzzle(string filename){
	ifstream myFile;
	myFile.open(filename.c_str());
	string tempString;
	vector<T> tempVec;
	int tempInt = 0;

	for (int i = 0; i<9; i++){
		getline(myFile, tempString);
		for (int j = 0; j<9; j++){
			tempInt = (tempString[j] - 48);
			tempVec.push_back(tempInt);
		}
		sudoku.push_back(tempVec);
		for (int h = 0; h<9; h++){
			tempVec.pop_back();
		}
	}
	myFile.close();
}

template <typename T>
void Puzzle<T>::display(){
	for (int i = 0; i<9; i++){	
		for (int k = 0; k<9; k++){
			cout << sudoku[i][k];
		}
		cout << endl;
	}
}

#endif //!PUZZLE_H
