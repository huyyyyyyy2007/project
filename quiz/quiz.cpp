#include<iostream>
#include<cstdlib>
using namespace std;



int main(){
    string questions[] = {"1. How old are you: ",
                          "2. What is 1 + 1 ",
                          "3. When did Messi win the World Cup ",
                          "4. When did Ronaldo win the last Champions league "};
    string options[][4] = {{"A. 18", " B. 19", " C. 21", " D. 23"},
                          {"A. 2", " B. 3", " C. 4", " D. 5"},
                          {"A. 2022", " B. 2018", " C. 2021", " D. 2014"},
                          {"A. 2023", " B. 2019", " C. 2018", " D. 2020"}};  
    
double size = sizeof(questions) / sizeof(questions[0]);
char choice;
char answers[] ={'a', 'a', 'a', 'c'};
int score;
for  (int i = 0; i < size; i ++){
    cout << "***************" << endl;
    cout << questions[i] << endl;
    cout << "***************" << endl;
    for (int j = 0 ; j < sizeof(options[0]) / sizeof(options[0][0]); j++){
        cout << options[i][j] << endl;
    }
    cout << "Enter your answer here: ";
    cin >> choice;
    if (choice == answers[i]){
        cout << "CORRECT" << endl;
        score ++;
    }
    else {
        cout << "WRONG" << endl;
        cout << "The answer is: " << answers[i] << endl;

    }
    }
cout << "*************" << endl;
cout << "THE SCORE IS: " << score << endl;
cout << "*************" << endl; 
cout << "THE AVERAGE:  " << (score/size) * 100 ;
return 0;
}