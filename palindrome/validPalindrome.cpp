#include<iostream>
#include<cctype>
#include<cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
        while(left < right && !isalnum(s[left])){ // 2 cái while này dùng để lọc kí tự đăc biệt.
            // isalnum là nói nếu đây là chữ số
            left ++;
        }
        
        while(left < right && !isalnum(s[right])){
            right --;
        }

        if(tolower(s[left]) != tolower(s[right])){
            // tolower là đưa chữ về dạng thường
            return false;
        }
        left++;
        right--;
       
    }
    
  return true;
    }
};

int main(){
     Solution solution;
     string s ="tab a cat";
     cout << solution.isPalindrome( s);
}