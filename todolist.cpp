#include<iostream>
using namespace std;

struct Task{ // vector bao gồm giá trị và trạng thái thì dùng thêm struct;
    string description; // giá trị
    bool isdone; // trạng thái
};

void showMenu() {
    cout << "\n--- TO-DO LIST ---" << endl;
    cout << "1. Them cong viec" << endl;
    cout << "2. Xem danh sach" << endl;
    cout << "3. Hoan thanh cong viec" << endl;
    cout << "4. Xoa cong viec" << endl;
    cout << "5. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

int main(){
    vector<Task> list;
    int choice;
    while (true){
    showMenu();
    cin >> choice;
    cin.ignore();
    if (choice == 1){
        cout << "Nhập nội dung công việc: ";
        string desc;
        getline(cin, desc);
        list.push_back({desc, false});
    }
    else if (choice == 2){
        for (int i = 0; i < list.size(); i++){
            cout << i + 1 <<". [" << (list[i].isdone ? "x" : " ") << "]" << list[i].description << endl;
        }
    }
    else if (choice == 3){
        cout << "Nhập thứ tự công việc mà bạn muốn hoàn thành: ";
        int id;
        cin >> id;
        if (id > 0 && id <= list.size()){
            list[id-1].isdone = true;
        }
    }
    else if (choice == 4){
        int id;
        cout << "Nhập thứ tự công việc bạn muốn xoá: ";
        cin >> id;
        if (id > 0 && id <= list.size()){
            list.erase(list.begin() + id -1);
        }
    }
    else {
        break;
    }
}
    return 0;
}