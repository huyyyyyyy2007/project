#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct character {
  string name;
  int damage;
  int health;
};

struct boss {
  string name;
  int damage;
  int health;
};

struct character1 {
  int name;
  int health;
  int damage;
};

int main() {
  vector<character> combat;
  vector<character1> combat1;
  vector<boss> fight;
  int choice;
  cout << "\n--- CHÀO MỪNG ĐẾN TRÒ CHƠI DRAGONBALL ---" << endl;
  cout << "1. Bắt đầu chơi 2 người" << endl;
  cout << "2. Bắt dầu chế độ đánh boss" << endl;
  cout << "3. Thoát trò chơi" << endl;
  cout << "---------------------" << endl;
  cout << "Chọn lựa chọn của bạn: ";
  cin >> choice;
  cin.ignore();
  if (choice == 1) {
    srand(time(0));
    string name1;
    int damage1;
    int health1;
    cout << "Vui lòng đặt tên cho nhân vật 1: ";
    getline(cin, name1);
    if (!name1.empty()) {
      cout << "Hãy nhập lượng sát thương cho nhân vật này: ";
      cin >> damage1;
      cin.ignore();
      cout << "Hãy nhập lượng máu cho nhân vật này: ";
      cin >> health1;
      cin.ignore();
      combat.push_back({name1, damage1, health1});
    } else {
      cout << "Vui lòng nhập tên cho vật. ";
    }
    string name2;
    int damage2;
    int health2;
    cout << "Vui lòng đặt tên cho nhân vật 2: ";
    getline(cin, name2);
    if (!name1.empty()) {
      cout << "Hãy nhập lượng sát thương cho nhân vật này: ";
      cin >> damage2;
      cin.ignore();
      cout << "Hãy nhập lượng máu cho nhân vật này: ";
      cin >> health2;
      cin.ignore();
      combat.push_back({name2, damage2, health2});
    } else {
      cout << "Vui lòng nhập tên cho vật. ";
    }
    while (combat[0].health > 0 && combat[1].health > 0) {
      int satthuong = rand() % combat[0].damage + 1; // random sát thương
      double stamina = 0;
      if (satthuong <= (20 * combat[0].damage / 100)) {
        stamina = stamina + 80;
      } else if (satthuong > (20 * combat[0].damage / 100) &&
                 satthuong <= (50 * combat[0].damage / 100)) {
        stamina = stamina + 40;
      } else if (satthuong > (50 * combat[0].damage / 100) &&
                 satthuong <= (80 * combat[0].damage / 100)) {
        stamina = stamina + 30;
      } else {
        stamina = stamina + 20;
      }
      int press;
      bool chose = false;
      while (!chose) {
        cout << "Hãy nhập số 1 để nhân vật 1 tấn công: ";
        cin >> press;
        cin.ignore();
        if (press == 1) {
          combat[1].health = combat[1].health - satthuong;
          cout << "-----" << combat[0].name << " tấn công " << combat[1].name
               << " với lượng sát thương " << satthuong << "-----" << endl;
          cout << "-----" << "Lượng Ki hiện tại của " << combat[0].name << ": "
               << stamina << "-----" << endl;
          cout << "-----" << combat[1].name << " còn " << combat[1].health
               << " máu " << "-----" << endl;
          chose = true;
        } else {
          cout << "Vui lòng nhập số 1 để tấn công. " << endl;
        }
      }
      if (combat[1].health < 0) {
        cout << "-----" << combat[1].name << " ĐÃ CHẾT  " << ", "
             << " CHIẾN THẮNG THUỘC VỀ " << combat[0].name << "-----" << endl;
        break;
      }
      if (stamina >= 100) {
        cout << combat[0].name << " ĐÃ TUNG RA CHIÊU CUỐI " << endl;
        cout << "CHIẾN THẮNG THUỘC VỀ: " << combat[0].name;
      }
      satthuong = rand() % combat[1].health + 1;
      double nangluong = 0;
      if (satthuong <= (20 * combat[1].damage / 100)) {
        nangluong = nangluong + 80;
      } else if (satthuong > (20 * combat[1].damage / 100) &&
                 satthuong <= (50 * combat[1].damage / 100)) {
        nangluong = nangluong + 40;
      } else if (satthuong > (50 * combat[1].damage / 100) &&
                 satthuong <= (80 * combat[1].damage / 100)) {
        nangluong = nangluong + 30;
      } else {
        nangluong = nangluong + 20;
      }
      bool dachon = false;
      while (!dachon) {
        cout << "Hãy nhập số 2 để nhân vật 2 tấn công: ";
        cin >> press;
        cin.ignore();
        if (press == 2) {
          combat[0].health = combat[0].health - satthuong;
          cout << "-----" << combat[1].name << " tấn công " << combat[0].name
               << " với lượng sát thương " << satthuong << "-----" << endl;
          cout << "-----" << "Lượng ki hiện tại của " << combat[1].name << ": "
               << nangluong << "------" << endl;
          cout << "-----" << combat[0].name << " còn lại " << combat[0].health
               << " máu " << "-----" << endl;
          dachon = true;
        } else {
          cout << "Vui lòng nhập số 2 để tấn công. " << endl;
        }
      }
      if (combat[0].health < 0) {
        cout << "-----" << combat[0].name << " ĐÃ CHẾT " << ", "
             << " CHIẾN THẮNG THUỘC VỀ " << combat[1].name << "-----" << endl;
        break;
      }
      if (nangluong >= 100) {
        cout << combat[1].name << " ĐÃ TUNG RA CHIÊU CUỐI " << endl;
        cout << "CHIẾN THẮNG THUỘC VỀ: " << combat[1].name;
      }
    }
  } else if (choice == 2) {
    int exp = 0;
    int choicee;
    int name3;
    cout << "Nhập tên cho nhân vật bạn: ";
    cin >> name3;

    do {
      cout << "Lựa chọn level boss dưới đây để đánh: " << endl;
      cout << "LEVEL 1: Khả Han phẫn nộ (yêu cầu 0 exp)" << endl;
      cout << "LEVEL 2: Ác nhân Xíu (yêu cầu 1 exp)" << endl;
      cout << "LEVEL 3: Quỷ vương Xíu Xiu (yêu cầu 2 exp)" << endl;
      cout << "LEVEL 4: Han quỷ nhân (yêu cầu 3 exp)" << endl;
      cout << "Nhập 4 để thoát" << endl;
      cout << "Nhập level bạn muốn chơi: ";
      cin >> choicee;

      if (choicee == 1) {
      }
    } while (choicee != 4);
  }
  return 0;
}
