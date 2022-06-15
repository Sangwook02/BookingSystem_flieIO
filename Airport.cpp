#include "Airport.h"

Airport::Airport() {
	this->code = "";
}
Airport::Airport(string code) {
	this->code = code;
}
string Airport::getCode() {
	return this->code;
}
int Airport::take(int a, int b, int c) {
	ofstream fout("c:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	f[a][b][c].showLeftSeat();
	string input;
	cout << "예산을 입력하세요. >> ";
	cin >> input;
	int number = 0, tmp;
	int size = (int)input.size();
	for (int i = 0; i < input.size(); i++) {
		tmp = input[i] - '0';
		size -= 1;
		number += tmp * pow(10, size);
	}
	

	if (number >= 150000) {
		cout << "비즈니스석을 추천합니다.\n";
	}
	else if (number >= 80000) {
		cout << "이코노미석을 추천합니다.\n";
	}
	else {
		cout << "예산이 부족합니다.\n";
	}

	int pick;
	while (1) {
		cout << "예약할 좌석의 번호를 입력해주세요. >> ";
		cin >> pick;
		if (f[a][b][c].getStatus(pick) == 0) {
			f[a][b][c].setStatus(pick);
			fout << "\t" << pick << endl;
			fout.close();
			return 1;
		}
		else {
			cout << "이미 선점된 좌석입니다.\n다른 좌석을 선택해주세요.\n";
			return 0;
		}
	}
}

int Airport::cancel(int a, int b, int c) {
	f[a][b][c].showSeat();
	int pick;
	while (1) {
		f[a][b][c].showLeftSeat();
		cout << "취소할 좌석의 번호를 입력해주세요. >> ";
		cin >> pick;
		if (f[a][b][c].getStatus(pick) == 1) {
			
			f[a][b][c].setStatus(pick);
			return 1;
		}
		else {
			cout << "잘못된 입력입니다.\n다른 좌석을 선택해주세요.\n";
		}
	}

}