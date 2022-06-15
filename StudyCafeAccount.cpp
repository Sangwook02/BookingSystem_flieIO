#include "StudyCafeAccount.h"

int StudyCafeAccount::userID = 0;
map<int, string> StudyCafeAccount::user;

int StudyCafeAccount::getID() {
	return id;
}
int StudyCafeAccount::getNumberOfBook() {
	return numberOfBooking;
}
void StudyCafeAccount::addNumberOfBook() {
	numberOfBooking++;
}
void StudyCafeAccount::subNumberOfBook() {
	numberOfBooking--;
}
int StudyCafeAccount::getSex() {
	return sex;
}
int StudyCafeAccount::Menu() {
	cout << "\n********홍익 독서실에 오신 것을 환영합니다********\n";
	cout << "\n메뉴를 선택하세요.\n회원가입:1 로그인:2 시작 페이지로 가기:3 >> ";
	string input;
	while (1) {
		cin >> input;
		cout << "\n--------------------------------------------------------------------\n"; //표준
		if (input.length() == 1 && input[0] == 49) {
			cout << "\n회원가입을 시작합니다.\n\n";
			return 0;
		}
		else if (input.length() == 1 && input[0] == 50) {
			cout << "\n로그인을 시작합니다.\n\n";
			return 1;
		}
		else if (input.length() == 1 && input[0] == 51) {
			return 2;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}
	}
}


void StudyCafeAccount::set() { //회원가입

	cout << "호수를 입력하십시오 >> ";
	string num;
	cin >> num;

	int number = 0, tmp;

	int size = (int)num.size();

	for (int i = 0; i < num.size(); i++) {
		tmp = num[i] - '0';
		size -= 1;
		number += tmp * pow(10, size);
	}
	this->roomNumber = number;
	this->id = userID;
	cout << "아이디는 " << userID << "입니다.\n";
	addUserID();
	string pw;
	while (1) {
		cout << "비밀번호를 입력하십시오(영문 소문자와 숫자 포함 최소 9자 이상 공백 포함 불가): ";
		
		cin >> pw;
		if (pw.size() >= 9) {
			break;
		}
		else {
			cout << "\n잘못된 입력입니다.\n다시 ";
		}
	}
	//요구 사항 준수했는지 확인 필요
	user.insert(make_pair(id, pw));
	ofstream fout("c:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	if (!fout) {
		cout << "failed to open file";
	}
	fout << "aa\t3\t" << id << "\t" << pw << "\t" << num << endl;
	fout.close();
	cout << "\n\n회원가입이 완료되었습니다.\n";
	
}
void StudyCafeAccount::addUserID() {
	this->userID += 1;
}

void StudyCafeAccount::addTime(int date, int hour) {
	time[date] += hour;
}

int StudyCafeAccount::getCurrentUser() {
	return currentUserID;
}
void StudyCafeAccount::setCurrentUserSex(int sex) {
	this->currentUserSex = sex;
}

int StudyCafeAccount::getCurrentUserSex() {
	return currentUserSex;
}

bool StudyCafeAccount::find(string id, int n) {
	int c;
	char tmp_1[100];
	string pw;

	ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt");
	if (!fin) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	while ((c = fin.get()) != EOF) {
		fin.getline(tmp_1, 100);
		string tmp(tmp_1);
		int idx = tmp.find("\t", 4);
		if (tmp.substr(0, 2) == "a\t" && tmp.substr(2, 2) == "3\t" && tmp.substr(4, idx - 4) == id) {

			cout << "비밀번호를 입력하세요>> ";
			cin >> pw;
			int idx_1 = tmp.find("\t", idx + 1);
			idx_1 -= 1;

			if (tmp.substr(idx + 1, idx_1 - idx) == pw) {
				fin.close();
				return true;
			}
			else {
				fin.close();
				return false;
			}
		}

	}
	fin.close();
	return false;
}
int StudyCafeAccount::login() {
	cout << "아이디를 입력하세요 >> ";
	string num;
	int i;

	cin >> num;

	int number = 0, tmp;

	if (find(num, 3)) {
		cout << "\n---로그인 성공---\n\n";
		this->currentUserID = id;
		//성별 입력
		while (1) {
			cout << "이용자의 성별을 입력해주세요.(남자:1 여자:2) >> ";
			cin >> num;
			number = 0;
			int size = (int)num.size();
			for (int i = 0; i < num.size(); i++) {
				tmp = num[i] - '0';
				size -= 1;
				number += tmp * pow(10, size);
			}
			if (number == 1) {
				this->sex = 1;
				setCurrentUserSex(1);
				break;
			}
			else if (number == 2) {
				this->sex = 2;
				setCurrentUserSex(2);
				break;
			}
			else {
				cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
			}
		}

		return 1;
	}
	else {
		cout << "\n---로그인 실패---\n\n";
		return 0;
	}
}