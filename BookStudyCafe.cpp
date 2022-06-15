#include "BookStudyCafe.h"

int BookStudyCafe::take(int part, int a, int b, int sex) {
	if (s[part][a][b].Status() == true) {
		s[part][a][b].setStatus(sex);
		dataStudyCafeSeat.push_back(15*a + b);
		dataStudyCafeTime.push_back(part);
		cout << "예약이 완료 되었습니다.\n\n";
		return 1;
	}
	else {
		cout << "이미 선점된 자리입니다.\n다른 자리를 선택해주세요.\n";
		return 0;
	}
}

void BookStudyCafe::cancel(string id) {
	int c;
	char tmp_1[100];
	ofstream fout("C:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	if (!fout || !fin) {
		cout << "파일 열기 오류" << endl;
	}
	while ((c = fin.get()) != EOF) {
		fin.getline(tmp_1, 100);
		string tmp(tmp_1);
		if (tmp.substr(0, 4) == "b\t3\t" && tmp.substr(4, id.size()) == id) {
			fout << "dd\t3\t" << id << endl;

		}
	}
	fout.close();

	fin.close();
	cout << "예약이 모두 취소되었습니다.\n\n";
}
int BookStudyCafe::getDate() {
	return date;
}
int BookStudyCafe::Book(int sex, string id) {
	int number = 0,tmp;
	string num;
	while (1) {
		cout << "이용자의 나이를 입력해주세요.(예: 17) >> ";
		cin >> num;
		number = 0;
		int size = (int)num.size();
		for (int i = 0; i < num.size(); i++) {
			tmp = num[i] - '0';
			size -= 1;
			number += tmp * pow(10, size);
		}
		if (number >= 14) {
			break;
		}
		else if (number < 14) {
			cout << "13세 이하는 독서실을 이용할 수 없습니다.\n죄송합니다.\n\n";
			return 1;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
	setDate();
	setTime();
	ofstream fout("c:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	//자리 선택
	for (int i = 0; i < 14; i++) {
		if (time[i] == 1) {
			//자리 보여주고 예약 받기
			cout << i+9 << "시 남은 좌석\n";
			for (int m = 0; m < 15; m++) {
				cout << "\t|";
				for (int n = 0; n < 15; n++) {
					if (s[14*date + i][m-1][n].getUserSex() == 0 || sex != s[14*date + i][m-1][n].getUserSex()) {
						if (s[14 * date + i][m + 1][n].getUserSex() == 0 || sex != s[14 * date + i][m + 1][n].getUserSex()) {
							if (s[14 * date + i][m][n-1].getUserSex() == 0 || sex != s[14 * date + i][m][n-1].getUserSex()) {
								if (s[14 * date + i][m][n+1].getUserSex() == 0 || sex != s[14 * date + i][m][n+1].getUserSex()) {
									s[14 * date + i][m][n].able();
								}
								else {
									cout << "   ";
								}
							}
							else {
								cout << "   ";
							}
						}
						else {
							cout << "   ";
						}
						
					}
					else {
						cout << "   ";
					}
					cout << "|";
				}
				cout << "\n\t-------------------------------------------------------------\n";
			}
			if (!fout) {
				cout << "failed to open file";
			}
			cout << id;
			fout << "bb\t3\t" << id << "\t" << getDate() << "\t" << i + 9 << "\t";


			int b = 0;
			while (b == 0) {
				cout << ">> ";
				cin >> num;
				fout << num<< endl;
				int number = 0, tmp;
				int size = (int)num.size();
				for (int j = 0; j < num.size(); j++) {
					tmp = num[j] - '0';
					size -= 1;
					number += tmp * pow(10, size);
				}
				if (number < 225 && number >= 0) {
					b = take(14 * date + i, (number / 15), (number % 15), sex);
					//dataStudyCafeID.push_back(id);
				}
				else {
					cout << "잘못된 입력입니다. 다시 입력해주세요.\n";
				}
			}
			
		}
	}
	fout.close();
	return 1;
}

BookStudyCafe::BookStudyCafe() {
	for (int i = 0; i < 98; i++) {
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				s[i][j][k].setSeat((15*j)+k);//
			}
		}
	}
}


void BookStudyCafe::setTime() {
	string input;
	int total = 0;

	cout << "오전 9시부터 오후 10시까지 예약이 가능합니다.(시작 시간 기준)\n이용하려 하는 총 시간을 입력해주세요\n최대 4시간까지 이용 가능합니다.";
	
	while (1) {
		cout << "\n>>";
		cin >> input;
		if (input.length() == 1) {
			if (input[0] == 49) {
				cout << "총 1시간 이용합니다.\n\n";
				total = 1;
				break;
			}
			else if (input[0] == 50) {
				cout << "총 2시간 이용합니다.\n\n";
				total = 2;
				break;
			}
			else if (input[0] == 51) {
				cout << "총 3시간 이용합니다.\n\n";
				total = 3;
				break;
			}
			else if (input[0] == 52) {
				cout << "총 4시간 이용합니다.\n\n";
				total = 4;
				break;
			}
			else {
				cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
			}
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
	string num;
	int k;
	cout << "이용하고자 하는 시간을 한 줄에 하나씩 입력해주세요.(시작 시간 기준, 24시간제)\n";
	for (int i = 1; i <= total; i++) {
		cout << ">> ";
		cin >> num;

		int number = 0, tmp;
		int size = (int)num.size();
		for (int j = 0; j < num.size(); j++) {
			tmp = num[j] - '0';
			size -= 1;
			number += (tmp * pow(10, size));
		}
		k = number-9;
		time[k] = 1;
	}

}

void BookStudyCafe::setDate() {
	string input;
	int tmp;
	cout << "\n오늘은 05월 16일입니다. 17일부터 23일까지 에약이 가능합니다.\n이용 날짜를 입력하세요(예: 05 19) ";
	while (1) {
		cout << ">> ";
		cin.ignore();
		getline(cin, input);

		if (input.length() == 5) {
			if (input[0] == '0' && input[1] == '5' && input[2] == ' ') {
				int number = 0;
				tmp = input[3] - '0';
				number += tmp * 10;
				number += input[4] - '0';
				if (number < 17) {
					cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
					continue;
				}
				this->date = number - 17;
				cout << "\n\n";
				break;
			}
			else {
				cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
			}
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
}