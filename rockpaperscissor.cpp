#include<iostream>
#include<cstdlib>
using namespace std;

char getplayer(){
    char choice;
    char r = 'r';
    char s = 's';
    char p = 'p';
    do {
        cout << "****************" << endl;
        cout << "Rock - Paper - Scissor" << endl;
        cout << "****************" << endl;
        cout << " 'r' for rock" << endl;
        cout << " 'p' for paper" << endl;
        cout << " 's' for scissor" << endl;
        cout << "Type your choice here: " , cin >> choice;

    }
    while( choice != r && choice != p && choice != s);
    return choice;
}

char getrobot(){
    
    int num = rand() % 3 + 1;
    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 'r';
}

void showchoice(char choice){
    switch(choice){
        case 'r' : cout << "Rock" << endl;
              break;
        case 'p' : cout << "Paper" << endl;
              break;
        case 's' : cout << "Scissor" << endl;
              break;
    }
}

void choosewinner(char player, char robot){
    switch(player){
        case 'r' : if ( robot == 'r'){
                   cout << "Its a tie";
                }
                else if ( robot == 's'){
                    cout << "You win";
                }
                else {
                    cout << "You lose";
                }
                break;

      case 'p' : if ( robot == 'p'){
                   cout << "Its a tie";
                }
                else if ( robot == 'r' ){
                    cout << "You win";
                }
                else {
                    cout << "You lose";
                }
                break;

        case 's' : if ( robot == 's'){
                   cout << "Its a tie";
                }
                else if ( robot == 'p'){
                    cout << "You win";
                }
                else {
                    cout << "You lose";
                }
                break;
   }
}
int main (){ 
    srand(time(0));
    char player;
    char robot;
    player = getplayer();
    cout << "Your choice is: " ;
    showchoice(player);
    robot = getrobot();
    cout << "Robot'choice is: " ;
    showchoice(robot);
    choosewinner(player, robot);

    return 0;
}