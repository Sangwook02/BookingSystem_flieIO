#include "Menu.h"
#include "BookFlight.h"
#include "FlightAccount.h"
#include "BookRestaurant.h"
#include "BookStudyCafe.h"
#include <fstream>
#include <iostream>
using namespace std;



Menu::Menu() {
	this->flightSize = 0;
	user = new FlightAccount[1000]; // 수정 필요

	this->restaurantSize = 0;
	ruser = new RestaurantAccount[1000]; // 수정 필요

	this->studyCafeSize = 0;
	suser = new StudyCafeAccount[1000];
}
Menu::~Menu() {
	delete[] user;
	delete[] ruser;
	delete[] suser;
}
void Menu::printFlight(string a, int n) {
	if (n == 0) {
		if (a.substr(0, 2) == "GP") {
			cout << "김포에서 출발하여 ";
		}
		else if (a.substr(0, 2) == "CJ") {
			cout << "제주에서 출발하여 ";
		}
		else if (a.substr(0, 2) == "KH") {
			cout << "김해에서 출발하여 ";
		}
		else if (a.substr(0, 2) == "GJ") {
			cout << "광주에서 출발하여 ";
		}
		else {
			cout << "대구에서 출발하여 ";
		}

		if (a.substr(2, 2) == "GP") {
			cout << "김포로 향하는 05월 ";
		}
		else if (a.substr(2, 2) == "CJ") {
			cout << "제주로 향하는 05월 ";
		}
		else if (a.substr(2, 2) == "KH") {
			cout << "김해로 향하는 05월 ";
		}
		else if (a.substr(2, 2) == "GJ") {
			cout << "광주로 향하는 05월 ";
		}
		else {
			cout << "대구로 향하는 05월 ";
		}
		cout << a.substr(6, 2) << "일 " << a.substr(8, 2) << "시 비행기입니다.\n\n";
	}
}
void Menu::printRestaurant(string a, int n) {
	if (n == 0) {
		cout << a[0] - 31 << "일 ";
		if (a[1] == 49) {
			cout << "12시에 " << a[3] << "번 자리 예약되어 있습니다." << endl;
		}
		else if (a[1] == 50) {
			cout << "13시에 " << a[3] << "번 자리 예약되어 있습니다." << endl;
		}
		else if (a[1] == 51) {
			cout << "18시에 " << a[3] << "번 자리 예약되어 있습니다." << endl;
		}
		else if (a[1] == 52) {
			cout << "19시에 " << a[3] << "번 자리 예약되어 있습니다." << endl;
		}
	}
	
}

void Menu::printStudy(string a, int n) {
	if (n == 0) {
		cout << a[0] - 31 << "일 ";

		int tmp = 0;
		tmp += (a[2]-48);
		tmp *= 10;
		tmp += (a[3]-48);
		cout << tmp << "시에 예약되어 있습니다." << endl;
	}

}
void Menu::getMenu() {
	string selectMenu;
	BookFlight*p = new BookFlight();
	BookRestaurant*q = new BookRestaurant();
	BookStudyCafe*r = new BookStudyCafe();

	while (1) {
		cout << "원하는 서비스를 선택하세요\n";
		cout << "\n비행기 예약:1 식당 예약:2 독서실 예약:3 종료:4 >> ";
		std::cin >> selectMenu;
		int selected;

		if (selectMenu[0] == 49) {
			ofstream fout("c:\\Users\\chosw\\Desktop\\file_io.txt");
			if (!fout) {
				cout << "failed to open file";
			}
			while (1) {
				selected = user->Menu();
				if (selected == 0) { //회원가입
					user[flightSize].setUser(1);
					this->flightSize += 1;

				}
				else if (selected == 1) {//로그인
					int i = user->login(1);
					string Current = user->getCurrentUser();
					if (i == 1) {
						int tmp = 0;
						while (tmp != 1) {
							cout << "예매:1 예약 정보 조회:2 예약 취소:3 내 정보 조회:4 로그아웃:5 >> ";
							string input;

							cin >> input;
							if (input.length() == 1 && input[0] == 49) {
								tmp = p->Book(Current);
								for (int u = 0; u < flightSize; u++) {
									if (user[u].getID() == Current) {
										user[u].addMileage();
										user[u].getNumberOfBook();
							
										break;
									}
								}
							}
							else if (input.length() == 1 && input[0] == 50) {//조회
								int c, chk_1 = 0;
								char tmp_1[100],tmp_2[100];
								ifstream fini("C:\\Users\\chosw\\Desktop\\file_io.txt");
								if (!fini) {
									cout << "파일 열기 오류" << endl;
								}
								vector<string> lst;
								while ((c = fini.get()) != EOF) {
									fini.getline(tmp_1, 100);
									string tmp(tmp_1);
									int idx = tmp.find("\t", 4);
									if (tmp.substr(0, 4) == "d\t1\t"&& tmp.substr(4, idx - 4) == Current) {
										lst.push_back(tmp.substr(idx + 1, 10));
									}

								}
								fini.close();
								ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt");
								while ((c = fin.get()) != EOF) {
									fin.getline(tmp_1, 100);
									string tmp(tmp_1);
									int idx = tmp.find("\t", 4);

									if (tmp.substr(0, 4) == "b\t1\t" && tmp.substr(4, idx - 4) == Current) {
										string codeFlight = tmp.substr(idx + 1, 10);
										
										for (int chk = 0; chk < lst.size(); chk++) {
											if (codeFlight == lst[chk]) {
												chk_1 = 1;
												break;
											}
										}
										printFlight(codeFlight, chk_1);
										
									}
								}

								fin.close();

								cout << "\n";
							}
							else if (input.length() == 1 && input[0] == 51) {//삭제
								p->cancel(Current);
								for (int u = 0; u < flightSize; u++) {
									if (user[u].getID() == Current) {
										user[u].subNumberOfBook();
										user[u].subMileage();
										break;
									}
								}
							}
							else if (input.length() == 1 && input[0] == 52) {
								for (int u = 0; u < flightSize; u++) {
									if (user[u].getID() == Current) {
										cout << "회원님의 마일리지는 "<< user[u].showMileage()<< "km입니다.\n";
										cout << "회원님의 예약 횟수는 " << user[u].getNumberOfBook() << "입니다.\n\n";
										break;
									}
								}
							}
							else if (input.length() == 1 && input[0] == 53) {
								break;
							}
							else {
								cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
							}
						}
					}
					else if (i == 0) {
						cout << "비행기 예약 종료:1 로그인 재시도:2 >> ";
						string input;
						cin >> input;
						if (input.length() == 1 && input[0] == 49) {
							break;
						}
						else if (input.length() == 1 && input[0] == 50) {
							continue;
						}
						else {
							cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
						}
					}
				}
				else if (selected == 2) {
					break;
				}
			}
		}
		else if (selectMenu[0] == 50) {
			while (1) {
				selected = ruser->Menu();
				if (selected == 0) {
					ruser[restaurantSize].setUser(2);
					this->restaurantSize += 1;
				}
				else if (selected == 1) {//로그인
					int i = ruser->login(2);
					if (i == 1) {
						int tmp = 0;
						
						while (tmp != 1) {
							string Current = ruser->getCurrentUser();
							cout << "예약/WALK IN:1 예약 정보 조회:2 예약 취소:3 내 정보:4>> ";
							string input;
							cin >> input;


							if (input.length() == 1 && input[0] == 49) {
								cout << "7세 이하의 미취학 아동이 있습니까? (y/n) >> ";
								cin >> input;
								if (input == "y") {
									cout << "저희 식당을 이용할 수 없습니다.\n죄송합니다.";
									break;
								}
								else if (input == "n") {
									while (tmp != 1) {
										cout << "예약 또는 Walk-in 중에 하나를 선택해주세요\n" << "예약:1 Walk-in:2 >> ";
										cin >> input;

										if (input.length() == 1 && input[0] == 49) {
											tmp = q->Book(Current);
										}
										else if (input.length() == 1 && input[0] == 50) {
											tmp = q->WalkIn(Current);

										}
										else {
											cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
										}
									}
								}
								else {
									cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
								}
							}
							else if (input.length() == 1 && input[0] == 50) {//조회
								int c, chk_1 = 0;
								char tmp_1[100], tmp_2[100];
								ifstream fini("C:\\Users\\chosw\\Desktop\\file_io.txt");
								if (!fini) {
									cout << "파일 열기 오류" << endl;
								}
								vector<string> lst;
								while ((c = fini.get()) != EOF) {
									fini.getline(tmp_1, 100);
									string tmp(tmp_1);
									int idx = tmp.find("\t", 4);
									
									if (tmp.substr(0, 4) == "d\t2\t" && tmp.substr(4, idx - 4) == Current) {
										chk_1 = 1;
										break;
									}

								}
								fini.close();
								ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt");
								while ((c = fin.get()) != EOF) {
									fin.getline(tmp_1, 100);
									string tmp(tmp_1);
									int idx = tmp.find("\t", 4);

									if (tmp.substr(0, 4) == "b\t2\t" && tmp.substr(4, idx - 4) == Current) {
										string codeBook = tmp.substr(idx + 1, 4);
										printRestaurant(codeBook, chk_1);

									}
								}
								fin.close();
								cout << "\n";
							}
							else if (input.length() == 1 && input[0] == 51) {
								q->cancel(Current);
							}
							else if (input.length() == 1 && input[0] == 52) {
								for (int u = 0; u < restaurantSize; u++) {
									if (ruser[u].getID() == Current) {
										cout << "회원님의 예약 횟수는 " << ruser[u].getNumberOfBook() << "입니다.\n\n";
										break;
									}
								}
							}
							else {
								cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
							}


							
						}

					}
					else if (i == 0) {
						cout << "식당 예약 종료:1 로그인 재시도:2 >> ";
						string input;

						cin >> input;
						if (input.length() == 1 && input[0] == 49) {
							break;
						}
						else if (input.length() == 1 && input[0] == 50) {
							continue;
						}
						else {
							cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
						}
					}
				}
				else if (selected == 2) {
					break;
				}
			}
		}
		else if (selectMenu[0] == 51) { //독서실
			while (1) {
				selected = suser->Menu();
				if (selected == 0) {
					suser[studyCafeSize].set();
					this->studyCafeSize += 1;
				}
				else if (selected == 1) {//로그인
					int i = suser->login();
					int tmp = 0;
					if (i == 1) {
						//예약
						int now;
						int current;
						string c;
						while (tmp == 0) {
							cout << "\n예약:1 예약 조회:2 예약 취소:3 내 정보 조회:4 >> ";
							now = suser->getCurrentUserSex();
							c = suser->getCurrentUser();
							string input;
							cin >> input;

							if (input.length() == 1 && input[0] == 49) {
								tmp = r->Book(now,c);
								for (int u = 0; u < studyCafeSize; u++) {
									if (suser[u].getID() == stoi(c)) {
										suser[u].addNumberOfBook();
										break;
									}
								}

							}


							else if (input.length() == 1 && input[0] == 50) {//조회
								int k, chk_1 = 0;
								char tmp_1[100], tmp_2[100];
								ifstream fini("C:\\Users\\chosw\\Desktop\\file_io.txt");
								if (!fini) {
									cout << "파일 열기 오류" << endl;
								}
								vector<string> lst;
								while ((k = fini.get()) != EOF) {
									fini.getline(tmp_1, 100);
									string tmp(tmp_1);
									int idx = tmp.find("\t", 4);

									if (tmp.substr(0, 4) == "d\t3\t" && tmp.substr(4, c.size()) == c) {
										chk_1 = 1;
										break;
									}

								}
								fini.close();
								ifstream fin("C:\\Users\\chosw\\Desktop\\file_io.txt");
								while ((k = fin.get()) != EOF) {
									fin.getline(tmp_1, 100);
									string tmp(tmp_1);
									if (tmp.substr(0, 4) == "b\t3\t" && tmp.substr(4, c.size()) == c) {
										string codeBook = tmp.substr(5+c.size(), 4);
										printStudy(codeBook, chk_1);

									}
								}
								fin.close();
								
								cout << "\n";
							}
							else if (input.length() == 1 && input[0] == 51) {//취소
								r->cancel(c);
							}

							else if (input.length() == 1 && input[0] == 52) {
								for (int u = 0; u < studyCafeSize; u++) {
									if (suser[u].getID() == stoi(c)) {
										cout << "회원님의 예약 횟수는 " << suser[u].getNumberOfBook() << "회 입니다.\n\n";
										tmp = 1;
										break;
									}
								}
							}
							else {
								cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
							}
							
						}
						
					}
					else if (i == 0) {
						cout << "독서실 예약 종료:1 로그인 재시도:2 >> ";
						string input;

						cin >> input;
						if (input.length() == 1 && input[0] == 49) {
							break;
						}
						else if (input.length() == 1 && input[0] == 50) {
							continue;
						}
						else {
							cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
						}
					}
				}
				else if (selected == 2) {
					break;
				}
			}
		}
		else if (selectMenu[0] == 52) {
			cout << "\n프로그램을 종료합니다.\n이용해주셔서 감사합니다.\n\n";
			break;
		}
		else {
			cout << "\n옳지 않은 입력입니다.\n다시 입력해주세요.\n\n";
		}

	}
	
}



