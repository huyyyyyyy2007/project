#include <iostream>
#include <vector>
#include<cstdlib>
#include <algorithm>
using namespace std;
 
void drawboard(char *spaces){ // có thể viết (char spaces[])
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[0] << "  |  "<< spaces[1] << "  | "<< spaces[2] << "    " << endl;
    cout << " ____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[3] << "  |  "<< spaces[4] << "  |  "<< spaces[5] << "    " << endl;
    cout << " ____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[6] << "  |  "<< spaces[7] << "  |  "<< spaces[8] << "   " << endl;
    cout << "     |     |     " << endl;

}
void playermove(char *spaces, char player){
    int number;
    while(true){ //while(true) là luôn luôn chạy như kiểu do while.
        cout << "Enter a spot you want to place the marker (1->9): " ;
        cin >> number ;
        number = number -1;
        if (spaces[number] == ' '){
            spaces[number] = player;
            break; // nếu đã đúng rồi thì không cần chạy nữa, break luôn.
        }
        else if(spaces[number] != ' '){
            cout << "Invalid option, please enter again: "<< endl;
        }
        else if(number < 0 || number > 8){
            cout << "Invalid option, please enter again: "<< endl;
        }
    }
}
void computermove(char *spaces, char computer){
    srand(time(0));
    int number;
    while(true){ // auto chạy;
        number = rand() % 8;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkwinner(char *spaces, char player, char computer){
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true; // return true để báo hiệu đã tìm ra người chiến thắng và gửi tín hiệu đến hàm trong main.
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;} 
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;}
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;}
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;}
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;} 
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;}
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "YOU WIN" :  cout << "YOU LOSE";
        return true;}
        
    else{
        return false;
    }
    
}
bool checkTie(char *spaces){
    for (int i = 0; i <9; i++){ // cho chạy i rồi thế vào array nếu còn chỗ thì false, hết chỗ thì true -> hoà.
        if (spaces[i] == ' '){
            return false;
        }
    }
    return true;
}
int main() {
   char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
   char player = 'X';
   char computer = 'O';
   bool running = true; // (Flag) dùng như một công tắc trong các trò chơi liên quan đến loop.

   drawboard(spaces);

   while(running){
    playermove(spaces, player);
    drawboard(spaces);
    if (checkwinner(spaces, player, computer)){
        running = false;
        break;
    }
    if (checkTie(spaces)){
        cout << "It's a tie!";
        break;
    }
    computermove(spaces, computer);
    drawboard(spaces);
    if (checkwinner(spaces, player, computer)){
        running = false;
        break;
    }
    if (checkTie(spaces)){
        cout << "It's a Tie!";
        break;
    }
    
   }
    return 0;
}