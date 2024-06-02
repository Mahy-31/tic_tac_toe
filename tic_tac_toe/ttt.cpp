#include <iostream>
#include <vector>
using namespace std;

char box[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
char symbol = 'X';

void square() {
	cout << "    |" << "    |" << endl;
	cout << "  " << box[0][0] << " |" << " " << box[0][1] << "  |" << " " << box[0][2] << endl;
	cout << "____|" << "____|" << "____" << endl;
	cout << "    |" << "    |" << endl;
	cout << "  " << box[1][0] << " |" << " " << box[1][1] << "  |" << " " << box[1][2] << endl;
	cout << "____|" << "____|" << "____" << endl;
	cout << "    |" << "    |" << endl;
	cout << "  " << box[2][0] << " |" << " " << box[2][1] << "  |" << " " << box[2][2] << endl;
	cout << "    |" << "    |" << endl;
}

void common() {
	if (choice == 1 && box[0][0] == '1') {
		box[0][0] = symbol;
	}
	else if (choice == 2 && box[0][1] == '2') {
		box[0][1] = symbol;
	}
	else if (choice == 3 && box[0][2] == '3') {
		box[0][2] = symbol;
	}
	else if (choice == 4 && box[1][0] == '4') {
		box[1][0] = symbol;
	}
	else if (choice == 5 && box[1][1] == '5') {
		box[1][1] = symbol;
	}
	else if (choice == 6 && box[1][2] == '6') {
		box[1][2] = symbol;
	}
	else if (choice == 7 && box[2][0] == '7') {
		box[2][0] = symbol;
	}
	else if (choice == 8 && box[2][1] == '8') {
		box[2][1] = symbol;
	}
	else if (choice == 9 && box[2][2] == '9') {
		box[2][2] = symbol;
	}
	else {
		cout << "invalid choice" << endl;
	}


}

bool forx() {
	symbol = 'X';
	for (int i = 0; i < 3; i++) {
		if (box[0][i] == box[1][i] && box[1][i] == box[2][i] || box[i][0] == box[i][1] && box[i][1] == box[i][2]) {
			return true;
		}
	}
	if (box[0][0] == box[1][1] && box[1][1] == box[2][2] || box[0][2] == box[1][1] && box[1][1] == box[2][0]) {
		return true;
	}
	return false;
}

bool foro() {
	symbol = 'O';
	for (int i = 0; i < 3; i++) {
		if (box[0][i] == box[1][i] && box[1][i] == box[2][i] || box[i][0] == box[i][1] && box[i][1] == box[i][2]) {
			return true;
		}
	}
	if (box[0][0] == box[1][1] && box[1][1] == box[2][2] || box[0][2] == box[1][1] && box[1][1] == box[2][0]) {
		return true;
	}
	return false;
}

bool checkdraw() {
	if (box[0][0] != '1' && box[1][0] != '2' && box[2][0] != '3' && box[1][0] != '4' && box[1][1] != '5' && box[1][2] != '6' && box[2][0] != '7' && box[2][1] != '8' && box[2][2] != '9') {
		return true;
	}
	return false;
}

int main() {
	cout << "TIC TAC TOE GAME!!" << endl;

	cout << "Player 1 (X) and player 2 (O)" << endl;

	square();

	while (!forx() && !foro() && !checkdraw()) {
		cout << "player 1 enter the digit:" << endl;
		cin >> choice;
		symbol = 'X';
		common();
		square();
		forx();
		if (forx() == true) {
			cout << "congrats!! player 1 won" << endl;
		}
		else if (checkdraw() == true) {
			cout << "draw" << endl;
		}
		else {
			if (!forx() && !foro()) {
				cout << "player 2 enter the digit:" << endl;
				cin >> choice;
				symbol = 'O';
				common();
				square();
				foro();
				if (foro() == true) {
					cout << "congrats!! player 2 won" << endl;
				}
			}
		}

	}
	return 0;
}
