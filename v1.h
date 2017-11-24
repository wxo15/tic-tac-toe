// tic-tac-toe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <vector>

using namespace std;
//using string;

int main()
{
	//Specification here
	cout << "Two player mode? (Y/N)" << endl;
	string r0;
	cin >> r0;

	cout << "May I start first? (Y/N)" << endl;
	string r1;
	cin >> r1;

	int m[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};

	int n;
	if (r1 == "Y") {
		n = 0;
	}
	else if (r1 != "N") {
		cout << "Invalid response - wtf man...";

		return 1;
	}
	else {
		cout << "Stingy much?" << endl;
		n = 1;
	}


	for (n; n < 11; n++)
	{
		system("CLS");

		for (int i = 0; i < 5; i++) {
			if (i % 2 == 1) {
				cout << string(5, '_') << endl;
			}
			else {
				for (int j = 0; j < 3; j++) {
					if (m[i / 2][j] == 0) {
						cout << 3 * (i / 2) + j + 1 << "|";
					}
					else if (m[i / 2][j] == 1) {
						cout << "X" << "|";
					}
					else {
						cout << "O" << "|";
					}
					if (j == 2) {
						cout << endl;
					}
				}

			}
		}

		//check if anyone won
		for (int i = 0; i < 3; i++) {
			int checkh = 0;
			int checkv = 0;
			int checkd1 = 0;
			int checkd2 = 0;
			for (int j = 0; j < 3; j++) {
				checkh += m[i][j];
				checkv += m[j][i];
				checkd1 += m[j][j];
				checkd2 += m[2 - j][j];
			}
			if (checkh == 3 || checkv == 3 || checkd1 == 3 || checkd2 == 3) {
				cout << "Game over! I won, you noob!" << endl;
				return 0;
			}
			else if (checkh == 12 || checkv == 12 || checkd1 == 12 || checkd2 == 12) {
				cout << "Wait, I lost?" << endl;
				return 0;
			}
		}
		//check if it is a draw
		for (int a = 1; a < 10; a++) {
			if (m[(a - 1) / 3][(a - 1) % 3] == 0) {
				goto NOTDRAW;
			}
		}
		cout << "Draw!" << endl;
		return 0;
	NOTDRAW:;

		//Two-player mode
		if (r0 == "Y"&&n % 2 == 1) {
			cout << "You are 0, like your chance of winning lol. Pick your position 1-9." << endl;
			int res;
			cin >> res;
			//User input
			while (res <= 0 || res > 9 || m[(res - 1) / 3][(res - 1) % 3] != 0) {
				cout << "Error - input invalid!" << endl;
				cin.clear();
				cin.ignore();
				cin >> res;
			}
			//User change of sign
			m[(res - 1) / 3][(res - 1) % 3] = 4;
		}

		if (r0 == "Y"&&n % 2 == 0) {
			cout << "You are 0, like your chance of winning lol. Pick your position 1-9." << endl;
			int res;
			cin >> res;
			//User input
			while (res <= 0 || res > 9 || m[(res - 1) / 3][(res - 1) % 3] != 0) {
				cout << "Error - input invalid!" << endl;
				cin.clear();
				cin.ignore();
				cin >> res;
			}
			//User change of sign
			m[(res - 1) / 3][(res - 1) % 3] = 1;
		}

		//Single-player mode
		if (r0 == "N"&&n % 2 == 1) {
			cout << "You are 0, like your chance of winning lol. Pick your position 1-9." << endl;
			int res;
			cin >> res;
			//User input
			while (res <= 0 || res > 9 || m[(res - 1) / 3][(res - 1) % 3] != 0) {
				cout << "Error - input invalid." << endl;
				cin.clear();
				cin.ignore();
				cin >> res;
			}
			//User change of sign
			m[(res - 1) / 3][(res - 1) % 3] = 4;
		}
		//Computer algorithm here
		if (r0 == "N"&&n % 2 == 0) {
			//one step to win
			for (int i = 0; i < 3; i++) {
				int checkh = 0;
				int checkv = 0;
				int checkd1 = 0;
				int checkd2 = 0;
				for (int j = 0; j < 3; j++) {
					checkh += m[i][j];
					checkv += m[j][i];
					checkd1 += m[j][j];
					checkd2 += m[2 - j][j];
				}
				if (checkh == 2) {
					for (int j = 0; j < 3; j++) {
						if (m[i][j] == 0) {
							m[i][j] = 1;
							goto END;
						};
					}
				}
				if (checkv == 2) {
					for (int j = 0; j < 3; j++) {
						if (m[j][i] == 0) {
							m[j][i] = 1;
							goto END;
						}
					}
				}
				if (checkd1 == 2) {
					for (int j = 0; j < 3; j++) {
						if (m[j][j] == 0) {
							m[j][j] = 1;
						}
					}
					goto END;
				}
				if (checkd2 == 2) {
					for (int j = 0; j < 3; j++) {
						if (m[2 - j][j] == 0) {
							m[2 - j][j] = 1;
						}
					}
					goto END;
				}

			}
			//one step to lose
			for (int i = 0; i < 3; i++) {
				int checkh = 0;
				int checkv = 0;
				int checkd1 = 0;
				int checkd2 = 0;
				for (int j = 0; j < 3; j++) {
					checkh += m[i][j];
					checkv += m[j][i];
					checkd1 += m[j][j];
					checkd2 += m[2 - j][j];
				}
				if (checkh == 8) {
					for (int j = 0; j < 3; j++) {
						if (m[i][j] == 0) {
							m[i][j] = 1;
							goto END;
						}
					}
				}
				if (checkv == 8) {
					for (int j = 0; j < 3; j++) {
						if (m[j][i] == 0) {
							m[j][i] = 1;
							goto END;
						}
					}
				}
				if (checkd1 == 8) {
					for (int j = 0; j < 3; j++) {
						if (m[j][j] == 0) {
							m[j][j] = 1;
							goto END;
						}
					}
				}
				if (checkd2 == 8) {
					for (int j = 0; j < 3; j++) {
						if (m[2 - j][j] == 0) {
							m[2 - j][j] = 1;
							goto END;
						}
					}
				}
			}
			//(double fork)
			int a[3][3] =
			{
				{ 4,0,0 },
				{ 0,1,0 },
				{ 0,0,4 },
			};
			int b[3][3] =
			{
				{ 0,0,4 },
				{ 0,1,0 },
				{ 4,0,0 },
			};
			for (int c = 0; c < 9; c++) {
				if (m[c / 3][c % 3] != a[c / 3][c % 3]) {
					goto SKIP1;
				}
			}
			m[0][1] = 1;
			goto END;
		SKIP1:;
			for (int c = 0; c < 9; c++) {
				if (m[c / 3][c % 3] != b[c / 3][c % 3]) {
					goto SKIP2;
				}
			}
			m[0][1] = 1;
			goto END;
		SKIP2:;


			//creating a fork
			//edge (2, 4, 6, 8)
			for (int a = 1; a < 5; a++) {
				a = 2 * a;
				int fcheckh = 0;
				int fcheckv = 0;
				for (int i = 0; i < 3; i++) {
					fcheckh += m[(a - 1) / 3][i];
					fcheckv += m[i][(a - 1) % 3];
				}
				if (fcheckh == 1 && fcheckv == 1 && m[(a - 1) / 3][(a - 1) % 3] == 0) {
					m[(a - 1) / 3][(a - 1) % 3] = 1;
					goto END;
				}
			}
			//corner+centre (1, 3, 5, 7, 9)
			for (int a = 1; a < 6; a++) {
				a = (2 * a) - 1;
				int fcheckh = 0;
				int fcheckv = 0;
				int fcheckd1 = 0;
				int fcheckd2 = 0;
				for (int i = 0; i < 3; i++) {
					fcheckh += m[(a - 1) / 3][i];
					fcheckv += m[i][(a - 1) % 3];
					if (a == 1 || a == 5 || a == 9) {
						fcheckd1 += m[i][i];
					}
					else if (a == 3 || a == 5 || a == 7) {
						fcheckd2 += m[i][2 - i];
					}
				}
				if (((fcheckh == 1 && fcheckv == 1) || (fcheckh == 1 && fcheckd1 == 1) || (fcheckh == 1 && fcheckd2 == 1) || (fcheckv == 1 && fcheckd1 == 1) || (fcheckv == 1 && fcheckd2 == 1) || (fcheckd1 == 1 && fcheckd2 == 1))
					&& m[(a - 1) / 3][(a - 1) % 3] == 0) {
					m[(a - 1) / 3][(a - 1) % 3] = 1;
					goto END;
				}
			}
			//preventing a fork
			//edge (2, 4, 6, 8)
			for (int a = 1; a < 5; a++) {
				a = 2 * a;
				int fcheckh = 0;
				int fcheckv = 0;
				for (int i = 0; i < 3; i++) {
					fcheckh += m[(a - 1) / 3][i];
					fcheckv += m[i][(a - 1) % 3];
				}
				if (fcheckh == 4 && fcheckv == 4 && m[(a - 1) / 3][(a - 1) % 3] == 0) {
					m[(a - 1) / 3][(a - 1) % 3] = 1;
					goto END;
				}
			}
			//corner+centre (1, 3, 5, 7, 9)
			for (int a = 1; a < 6; a++) {
				a = (2 * a) - 1;
				int fcheckh = 0;
				int fcheckv = 0;
				int fcheckd1 = 0;
				int fcheckd2 = 0;
				for (int i = 0; i < 3; i++) {
					fcheckh += m[(a - 1) / 3][i];
					fcheckv += m[i][(a - 1) % 3];
					if (a == 1 || a == 5 || a == 9) {
						fcheckd1 += m[i][i];
					}
					else if (a == 3 || a == 5 || a == 7) {
						fcheckd2 += m[i][2 - i];
					}
				}
				if (((fcheckh == 4 && fcheckv == 4) || (fcheckh == 4 && fcheckd1 == 4) || (fcheckh == 4 && fcheckd2 == 4) || (fcheckv == 4 && fcheckd1 == 4) || (fcheckv == 4 && fcheckd2 == 4) || (fcheckd1 == 4 && fcheckd2 == 4))
					&& m[(a - 1) / 3][(a - 1) % 3] == 0) {
					m[(a - 1) / 3][(a - 1) % 3] = 1;
					goto END;
				}
			}
			//playing centre
			if (m[1][1] == 0) {
				m[1][1] = 1;
				goto END;
			}
			//playing opposite corner
			if (m[0][0] == 0 && m[2][2] == 4) {
					m[0][0] = 1;
					goto END;
				}
			if (m[0][0] == 4 && m[2][2] == 0) {
					m[2][2] = 1;
					goto END;
				}
			if (m[0][2] == 0 && m[2][0] == 4) {
					m[0][2] = 1;
					goto END;
				}
			if (m[0][2] == 4 && m[2][0] == 0) {
					m[2][0] = 1;
					goto END;
				}
			//playing corner
			if (m[0][0] == 0) {
				m[0][0] = 1;
				goto END;
			}
			if (m[0][2] == 0) {
				m[0][2] = 1;
				goto END;
			}
			if (m[2][0] == 0) {
				m[2][0] = 1;
				goto END;
			}
			if (m[2][2] == 0) {
				m[2][2] = 1;
				goto END;
			}
			//playing edge
			if (m[0][1] == 0) {
				m[0][1] = 1;
				goto END;
			}
			if (m[1][0] == 0) {
				m[1][0] = 1;
				goto END;
			}
			if (m[1][2] == 0) {
				m[1][2] = 1;
				goto END;
			}
			if (m[2][1] == 0) {
				m[2][1] = 1;
				goto END;
			}


			END:;
			}



		}

	}
