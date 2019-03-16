#include<iostream>
#include<string>
#include <fstream>
using namespace std;

int main(){
    int n;
    ifstream fin("input_string");

    fin >> n;
    fin.get();
    string str;
    while(n--){
        getline(fin, str); 
        cout << str << endl;
    }
    fin.close();
    return 0;
}