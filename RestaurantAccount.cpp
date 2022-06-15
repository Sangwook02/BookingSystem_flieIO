#include "RestaurantAccount.h"

RestaurantAccount::RestaurantAccount() {
	this->age = 0;
}

int RestaurantAccount::Menu() {
	cout << "\n********홍익 식당에 오신 것을 환영합니다********\n";
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