#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    vector <int> words;
    string word;
    while(getline(ss,word,' ')){
        words.push_back(stoi(word));
    }
    
    sort(words.begin(),words.end());
    answer = answer + to_string(words[0]) + " " + to_string(words[words.size()-1]);
    
    return answer;
}