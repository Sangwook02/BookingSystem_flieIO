#include "Account.h"

int Account::getNumberOfBook() {
	return numberOfBooking;
}
string Account::getCurrentUser() {
	return currentUserID;
}

void Account::setCurrentUser(string id) {
	this->currentUserID = id;
}

Account::Account() {
	this->name = "";
	this->numberOfBooking = 0;
}
void Account::addNumberOfBook() {
	numberOfBooking++;
}
void Account::subNumberOfBook() {
	numberOfBooking--;
}
void Account::setUser(int n) { //회원가입
	cout << "이름을 입력하십시오: ";
	string name;
	cin >> name;
	this->name = name;
	
	int cntAlpha = 0,cntNumber = 0;
	
	string id;
	while (1) {
		cout << "아이디를 입력하십시오(영문 소문자와 숫자 포함 최소 9자 이상 공백 포함 불가): ";
		cin >> id;
		if (id.size() >= 9) {
			for (int i = 0; i < id.size(); i++) {
				if (isalpha(id[i]) == 2) {
					cntAlpha++;
				}
				else if (id[i] > 47 && id[i] < 58) {
					cntNumber++;
				}
			}
			if (cntAlpha + cntNumber > 8) {
				break;
			}
			else {
				cout << "잘못된 입력입니다.\n다시 ";
			}
		}
		else {
			cout << "\n잘못된 입력입니다.\n다시 ";
		}
	}
	this->id = id;
	//데이터베이스에 중복되는 아이디  있는지 확인 하는 코드 삽입 필요.
	//요구 사항 준수했는지 확인 필요
	string pw;
	while (1) {
		cout << "비밀번호를 입력하십시오(영문 소문자와 숫자 포함 최소 9자 이상 공백 포함 불가): ";
		cin >> pw;

		if (pw.size() >= 9) {
			for (int i = 0; i < pw.size(); i++) {
				if (isalpha(pw[i]) == 2) {
					cntAlpha++;
				}
				else if (pw[i] > 47 && pw[i] < 58) {
					cntNumber++;
				}
			}
			if (cntAlpha + cntNumber > 8) {
				break;
			}
			else {
				cout << "잘못된 입력입니다.\n다시 ";
			}
		}
		else {
			cout << "\n잘못된 입력입니다.\n다시 ";
		}
	}
	//요구 사항 준수했는지 확인 필요
	ofstream fout("c:\\Users\\chosw\\Desktop\\file_io.txt", ios::app);
	if (!fout) {
		cout << "failed to open file";
	}
	if (n == 1) {
		flight.insert(make_pair(id, pw));
	}
	else if (n == 2) {
		rest.insert(make_pair(id, pw));
	}

	fout <<"aa\t" << n << "\t"  << id << "\t" << pw << "\t" << name << endl;
	fout.close();
	cout << "\n\n회원가입이 완료되었습니다.\n";
}
string Account::getID() {
	return this->id;
}

string Account::getName() {
	return this->name;
}
void Account::show() { //제출 전 삭제
	string id;
	cin >> id;
	cout << flight[id];
}

int Account::login(int n) {
	char input[50];
	cout << "아이디를 입력하세요>> ";
	string id;
	cin >> id;
	
	if (n == 1 || n == 2) {
		if (find(id, n)) {
			cout << "\n---로그인 성공---\n\n";
			setCurrentUser(id);
			return 1;
		}
		else {
			cout << "\n---로그인 실패---\n\n";
			return 0;
		}
	}
}


bool Account::find(string id, int n) {
	int c;
	char tmp_1[100];
	string pw;

	ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt");
	if (!fin) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	while ((c = fin.get()) != EOF) {
		fin.getline(tmp_1,100);
		string tmp(tmp_1);
		int idx = tmp.find("\t", 4);
		if (tmp.substr(0, 2) == "a\t"&& tmp.substr(2,2) == "1\t" && tmp.substr(4, idx - 4) == id) {
			
			cout << "비밀번호를 입력하세요>> ";
			cin >> pw;
			int idx_1 = tmp.find("\t", idx + 1);
			idx_1 -= 1;
			
			if (tmp.substr(idx + 1, idx_1 - idx) == pw) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (tmp.substr(0, 2) == "a\t" && tmp.substr(2, 2) == "2\t" && tmp.substr(4, idx - 4) == id) {

			cout << "비밀번호를 입력하세요>> ";
			cin >> pw;
			int idx_1 = tmp.find("\t", idx + 1);
			idx_1 -= 1;
			if (tmp.substr(idx + 1, idx_1 - idx) == pw) {
				return true;
			}
			else {
				return false;
			}
		}

	}
	return false;
}