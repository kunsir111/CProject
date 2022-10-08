
#include<iostream>
#include<cmath>
using namespace std;



int main(){
    int seed, num; //
    bool flag = false;
    cout<<"Enter an integer as a random number seed:";
    cin>>seed;
    srand(seed);
    num = rand() % 22659 + 2022;
    cout<<"The random number is "<<num<<endl;
    cout<<num<<" factors:";
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            cout<<i<<" ";
            flag = true;
        }
    }
    if(!flag){
        cout<<"no factor";
    }
    cout<<endl;
    return 0;
}
