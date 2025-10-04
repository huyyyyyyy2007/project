#include<iostream>
#include<cstdlib>
using namespace std;

char choice(){
    char result ;
    
    do {
        cout << "****************" << endl;
        cout << "Chọn Tài hoặc xỉu: "<< endl;
        cout << "****************"<< endl;
        cout << "'t' cho Tài"<< endl;
        cout << "'x' cho Xỉu"<<endl;
        cout << "Nhập lựa chọn của bạn tại đây: ";
        cin >> ws >> result;
    }
    while(result != 't' && result != 'x');
    return result;
}

void showresult(char result){
    switch(result){
        case 't': cout << "Tài" << endl;
                break;
        case 'x': cout << "Xỉu" << endl;
                break;
    }
}

double nhacai(){
     int sum = 0;
     int dice1 = rand() % 6 + 1;
     int dice2 = rand() % 6  + 1;
     int dice3 = rand() % 6 + 1;
     sum = dice1 + dice2 + dice3;
     if(sum < 11){
        cout << sum << "=>" << "Xỉu" << endl;
     }
     else {
        cout << sum << "=>" << "Tài" << endl;
     }
    return sum;
}

void showwinner(char playing, char casino){
       switch(playing){
        case 't': if(casino < 11){
                    cout << "Bạn đã thua";
        }
                  else{
                    cout << "Bạn đã thắng";
                  }
                  break;
        case 'x': if(casino >=11){
                    cout << "Bạn đã thua";
        }
                  else{
                    cout << "Bạn đã while";
                  }
        }
        }
       


int main(){
    int opt = 1;
    while (opt) {
        char playing;
        char casino;
        double ketqua;
        double winner;
        playing = choice();
        cout << "Lựa chọn của bạn là: " ;
        showresult(playing)  ;
        cout << "Kết quả là: ";
        ketqua = nhacai();
        showwinner(playing, casino);
        cout << "\nBạn muốn chơi lại không? (1: có, 0: không) \n";
        cin >> opt;
    }
    return 0;
}