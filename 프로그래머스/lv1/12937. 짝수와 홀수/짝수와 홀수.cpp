#include <iostream>
using namespace std;

string solution(int n){
    if(n % 2 == 0){
        return "Even";
    }
    else {
        return "Odd";
    }
}

/*
return num & 1 ? "Odd" : "Even";
*/