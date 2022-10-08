
#include<iostream>
using namespace std;
int main(){
    int day1, month1, year1;
    int day2, month2, year2;
    int allDay = 0;
    cin>>day1>>month1>>year1;
    cin>>day2>>month2>>year2;
    if(year1 > year2){
        swap(year1, year2);
        swap(month1, month2);
        swap(day1, day2);
    }
    if(year1 == year2 && month1 > month2){
        swap(month1, month2);
        swap(day1, day2);
    }
    if(year1 == year2 && month1== month2 && day1 > day2){
        swap(day1, day2);
    }
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year1 == year2){
        if(month1 == month2){
            if(day1 == day2){
                allDay = 0;
            } else if(day1 < day2){
                allDay = day2 - day1;
            } else if(day1 > day2){
                allDay = day1 - day2;
            }
        } else if(month1 < month2){
            allDay += month[month1] - day1;
            for(int i = month1 + 1; i < month2; i++){
                allDay += month[i];
            }
            allDay += day2;
        }
    }else if(year1 < year2){
        allDay += month[month1] - day1;
        for(int i = month1 + 1; i <= 12; i++){
            allDay += month[i];
        }
        for(int i = year1 + 1; i < year2; i++){
            if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
                allDay += 365;
            }else {
                allDay += 366;
            }
        }
        for(int i = 1; i < month2; i++){
            allDay += month[i];
        }
        allDay += day2;
    }
    cout<<allDay + 1<<endl;
    return 0;
}
