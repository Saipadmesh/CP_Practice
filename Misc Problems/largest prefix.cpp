#include <iostream>
#include <vector>
#include <string>

using namespace std;

string checkPrefix(vector<string>& words){
    for(int i=0;i<words[0].size();i++){
        char c = words[0].at(i);
        for(int j=1;j<words.size();j++){
            if(i == words[j].size() || c != words[j].at(i)){
                return words[0].substr(0,i);
            }
        }
        
    }
    return words[0];
    
}

int main()
{
    vector<string> words {"flet","flee","fleetcode"};
    string prefix = checkPrefix(words);
    cout<<prefix;
    
}