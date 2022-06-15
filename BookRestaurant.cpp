#include "BookRestaurant.h"
#include <cstring>

int BookRestaurant::take(int n, string id) {
	int part = time;
	part += 4 * date;
	if (t[part][n].Status() == true) {
		t[part][n].setStatus();
		cout << "예약이 완료 되었습니다.\n\n";
		dataRestaurantID.push_back(id);
		dataRestaurantTime.push_back(part);
		dataRestaurantTable.push_back(n);
		return 1;
	}
	else {
		cout << "이미 선점된 테이블입니다.\n다른 테이블을 선택해주세요.\n";
		return 0;
	}
}

BookRestaurant::BookRestaurant() {
	this->date = 0;
	this->time = 0;
	for (int i = 0; i < 29; i++) {

		t[i][0].setTable("0", 4);
		t[i][1].setTable("1", 4);
		t[i][2].setTable("2", 4);
		t[i][3].setTable("3", 4);
		t[i][4].setTable("4", 6);
		t[i][5].setTable("5", 6);
		t[i][6].setTable("6", 4);
		t[i][7].setTable("7", 4);
		t[i][8].setTable("8", 6);
	}
}
void BookRestaurant::cancel(string id) {
	for (int i = 0; i < dataRestaurantID.size(); i++) {
		if (dataRestaurantID[i] == id) {
			dataRestaurantID[i] = "";
			dataRestaurantTime[i] = -1;
			dataRestaurantTable[i] = -1;

		}
	}
	cout << "예약이 모두 취소되었습니다.\n\n";
}
int BookRestaurant::Book(string id) {
	setDate();
	setTime();
	int part = 1 + time;
	part += (4 * date);
	cout << "-----번호를 골라주세요-----\n0~3번 테이블은 4인석, 4~5번 테이블은 6인석입니다.\n우측의 테이블들은 예약이 불가능한 WALK-IN 테이블입니다.\n\n";

	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";
	cout << "\t" << "|" << "  "<< t[part][0].able() << " " << "|" << "\t" << "|" << "  " << t[part][1].able() << " " << "|" << "\t\t" << "|" << "    " << "|" << "\n";
	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";

	cout << "\n";

	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";
	cout << "\t" << "|" << "  " << t[part][2].able() << " " << "|" << "\t" << "|" << "  " << t[part][3].able() << " " << "|" << "\t\t" << "|" << "    " << "|" << "\n";
	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";

	cout << "\n";

	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";
	cout << "\t" << "|" << "    " << "|" << "\t" << "|" << "    " << "|" << "\t\t" << "|" << "    " << "|" << "\n";;
	cout << "\t" << "|" << "  " << t[part][4].able() << " " << "|" << "\t" << "|" << "  " << t[part][5].able() << " " << "|" << "\t\t" << "|" << "    " << "|" << "\n";
	cout << "\t" << "|" << "    " << "|" << "\t" << "|" << "    " << "|" << "\t\t" << "|" << "    " << "|" << "\n";
	cout << "\t" << "ㅡㅡㅡ" << "\t" << "ㅡㅡㅡ" << "\t\t" << "ㅡㅡㅡ" << "\n";

	int tmp,b = 0;
	string input;
	while (b == 0) {
		cout << ">> ";
		cin >> input;
		cout << "\n";
		if (input.length() == 1) {
			if (input[0] == 48) {
				tmp = 0;
				b = take(tmp, id);
				continue;
			}
			else if (input[0] == 49) {
				tmp = 1;
				b = take(tmp, id);
				continue;
			}
			else if (input[0] == 50) {
				tmp = 2;
				b = take(tmp, id);
				continue;
			}
			else if (input[0] == 51) {
				tmp = 3;
				b = take(tmp, id);
				continue;
			}
			else if (input[0] == 52) {
				tmp = 4;
				b = take(tmp, id);
				continue;
			}
			else if (input[0] == 53) {
				tmp = 5;
				b = take(tmp, id);
				continue;
			}
			else {
				cout << "잘못된 입력입니다. 다시 입력해 주세요.\n";
			}
		}
		else {
			cout << "잘못된 입력입니다. 다시 입력해 주세요.\n";
		}
	}


	//예약가능한 자리 보여주고 확정받기.

	//예약 후에
	cout << "\n로그아웃:1 계속 예약하기:2 >> ";

	while (1) {
		cin >> input;
		cout << "\n";
		if (input.length() == 1 && input[0] == 49) {
			return 1;
		}
		else if (input.length() == 1 && input[0] == 50) {
			return 0;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
}
int BookRestaurant::getFour_q_size() {
	return four_q.size();
}
int BookRestaurant::getSix_q_size() {
	return six_q.size();
}
int BookRestaurant::WalkIn(string id) {
	cout << "인원 수를 입력해주세요\n최대 14명까지 이용 가능합니다.\n\n>>";
	string num;
	cin >> num;
	int number = 0, tmp;
	int size = (int)num.size();
	for (int i = 0; i < num.size(); i++) {
		tmp = num[i] - '0';
		size -= 1;
		number += tmp * pow(10, size);
	}
	//int num에 전체 인원 수 입력 받는 과정.
	if (number <= 4 && number > 0) {
		four_q.push(id);
		if (getFour_q_size() < 3) {
			cout << "4인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "4인 테이블의 현재 내 앞 대기팀은 " << getFour_q_size() - 2 << "팀입니다.\n\n";
		}
	}
	else if(number >= 5 && number <= 6) {
		six_q.push(id);
		if (getSix_q_size() < 1) {
			cout << "6인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "6인 테이블의 현재 내 앞 대기팀은 " << getSix_q_size() - 1 << "팀입니다.\n\n";
		}
	}
	else if (number >= 7 && number <= 8) {
		four_q.push(id);
		if (getFour_q_size() < 3) {
			cout << "4인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "4인 테이블의 현재 내 앞 대기팀은 " << getFour_q_size() - 2 << "팀입니다.\n\n";
		}
		four_q.push(id);
	}
	else if (number >= 9 && number <= 10) {
		four_q.push(id);
		if (getFour_q_size() < 3) {
			cout << "4인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "4인 테이블의 현재 내 앞 대기팀은 " << getFour_q_size() - 2 << "팀입니다.\n\n";
		}
		six_q.push(id);
		if (getSix_q_size() < 1) {
			cout << "6인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "6인 테이블의 현재 내 앞 대기팀은 " << getSix_q_size() - 1 << "팀입니다.\n\n";
		}
	}
	else if (number >= 11 && number <= 14) {
		four_q.push(id);
		if (getFour_q_size() < 3) {
			cout << "4인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "4인 테이블의 현재 내 앞 대기팀은 " << getFour_q_size() - 2 << "팀입니다.\n\n";
		}
		four_q.push(id);
		six_q.push(id);
		if (getSix_q_size() < 1) {
			cout << "6인 테이블의 현재 내 앞 대기팀은 0팀입니다.\n\n";
		}
		else {
			cout << "6인 테이블의 현재 내 앞 대기팀은 " << getSix_q_size() - 1 << "팀입니다.\n\n";
		}
	}
	else {
		cout << "예약 가능한 인원 수가 아닙니다.\n\n";
	}
	
	while (1)
	{
		cout << "\n로그아웃:1 계속 예약하기:2 >> ";
		string input;
		cin >> input;

		if (input.length() == 1 && input[0] == 49) {
			return 1;
		}
		else if (input.length() == 1 && input[0] == 50) {
			return 0;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
	
}

void BookRestaurant::setTime() {
	cout << "시간을 골라주세요.\n\n<런치>\n12시:1 13시:2\n\n<디너>\n18시:3 19시:4\n>> ";
	string input;
	cin >> input;

	if (input.length() == 1) {
		if (input[0] == 49) {
			cout << "런치 12시를 선택했습니다.\n\n";
			this->time = 1;
		}
		else if (input[0] == 50) {
			cout << "런치 13시를 선택했습니다.\n\n";
			this->time = 2;
		}
		else if (input[0] == 51) {
			cout << "디너 18시를 선택했습니다.\n\n";
			this->time = 3;
		}
		else if (input[0] == 52) {
			cout << "디너 19시를 선택했습니다.\n\n";
			this->time = 4;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
	else {
		cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
	}
}

void BookRestaurant::setDate() {
	string input;
	int tmp;
	cout << "\n오늘은 05월 16일입니다. 17일부터 23일까지 에약이 가능합니다.\n방문 날짜를 입력하세요(예: 05 19) >> ";
	while(1) {
		cin.ignore();
		getline(cin, input);

		if (input.length() == 5) {
			if (input[2] == ' ') {
				int number = 0;
				tmp = input[3] - '0';
				number += tmp * 10;
				number += input[4] - '0';

				this->date = number -17;
				cout << date;
				cout << "\n";
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