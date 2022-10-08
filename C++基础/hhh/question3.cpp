
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num;
    string s[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"};
    string s1[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s2[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    while(cin>>num && num != -1){
        if(num < 10){
            cout<<s1[num];
        }
        else if(num > 10 && num < 20){
            cout<<s2[num % 10];
        }
        else{
            if(num % 10 == 0 && num != 0){
                cout<<s[num / 10];
            }
            else{
                cout<<s[num / 10]<<"-"<<s1[num % 10];
            }
        }
        cout<<endl;
    }
    return 0;
}
