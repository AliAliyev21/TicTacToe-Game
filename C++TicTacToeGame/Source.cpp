#include<iostream>
#include<Windows.h>
using namespace std;


void SetColor(int fg, int bg) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, fg | (bg << 4));

}
const int s = 3;
int game[s][s] = {};

bool GetPlayerWin1() {
	int diaqonal = 0;
	int diaqonal2 = 0;
	for (size_t i = 0; i < s; i++) {
		int sumRow = 0;
		int sumCol = 0;
		for (size_t k = 0; k < s; k++) {
			if (game[i][k] == 1) {
				sumRow += 1;
			}
			if (game[k][i] == 1) {
				sumCol += 1;
			}
			if (game[i][k] == 1 && i == k) {
				++diaqonal;
			}
			if (game[i][k] == 1 && (i + k) == (s - 1)) {
				++diaqonal2;
			}
		}
		if (sumRow >= s || sumCol >= s) {
			return true;
		}
	}
	for (size_t i = 0; i < s; i++) {
		int sumCol = 0;
		for (size_t k = 0; k < s; k++) {
			if (game[k][i] == 1) {
				sumCol += 1;
			}
		}
		if (sumCol >= s) {
			return true;
		}
	}
	if (diaqonal >= s || diaqonal2 >= s) {
		return true;
	}
	return false;
}

bool GetPlayerWin2() {
	int diaqonal = 0;
	int diaqonal2 = 0;
	for (size_t i = 0; i < s; i++) {
		int sumRow = 0;
		int sumCol = 0;
		for (size_t k = 0; k < s; k++) {
			if (game[i][k] == 2) {
				sumRow += 1;
			}
			if (game[k][i] == 2) {
				sumCol += 1;
			}
			if (game[i][k] == 2 && i == k) {
				++diaqonal;
			}
			if (game[i][k] == 2 && (i + k) == (s - 1)) {
				++diaqonal2;
			}
		}
		if (sumRow >= s || sumCol >= s) {
			return true;
		}
	}
	for (size_t i = 0; i < s; i++) {
		int sumCol = 0;
		for (size_t k = 0; k < s; k++) {
			if (game[k][i] == 2) {
				sumCol += 1;
			}
		}
		if (sumCol >= s) {
			return true;
		}
	}
	if (diaqonal >= s || diaqonal2 >= s) {
		return true;
	}
	return false;
}


void Show() {
	cout << " ---------------" << endl;
	int counter = 1;
	for (size_t i = 0; i < s; i++)
	{
		cout << "|  ";
		for (size_t k = 0; k < s; k++)
		{
			if (game[i][k] == 0) {
				cout << counter << "   ";
			}
			else if (game[i][k] == 1) {
				SetColor(9, 0);
				cout << "X" << "   ";
				SetColor(7, 0);
			}
			else if (game[i][k] == 2) {
				SetColor(2, 0);
				cout << "O" << "   ";
				SetColor(7, 0);
			}
			++counter;
		}cout << "|  "; cout << endl << endl;
	}
	cout << " ---------------" << endl;
}

bool isFirst = true;
void Update() {
	int number = 0;
	do
	{
		isFirst ? cout << "Player 1 turn " : cout << "Player 2 turn";
		cout << "Enter Number : " << endl;
		cin >> number;
		if (game[0][number - 1] != 0) {
			SetColor(4, 0);
			cout << "WRONG" << endl;
			SetColor(7, 0);
			continue;
		}
		if (isFirst) {
			game[0][number - 1] = 1;
		}
		else {
			game[0][number - 1] = 2;
		}
		break;
	} while (true);
	isFirst = !isFirst;
}

void Winner() {
	cout << "\a";
	Sleep(300);
	cout << "\a";
	Sleep(300);
}

void main() {
	while (true)
	{
		bool result1 = GetPlayerWin1();
		bool result2 = GetPlayerWin2();
		if (result1) {
			cout << "PLAYER 1 WINNER" << endl;
			system("color 9");
			Winner();
			break;
		}
		else if (result2) {
			cout << "PLAYER 2 WINNER" << endl;
			system("color 2");
			Winner();
			break;
		}
		Show();
		Update();
		Sleep(1000);
		system("cls");
	}
}
