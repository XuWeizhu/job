#include<iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("sort");
    int length = 0;
    int tmp;
    fin >> length;
    fin.get();
    
    vector<int> str_random, str_sorted;
    for(int i = 0;i<length;++i){
        fin >> tmp;
        str_random.push_back(tmp);
    }
    fin.get();
    for(int i = 0;i<length;++i){
        fin >> tmp;
        str_sorted.push_back(tmp);
    }

    


    fin.close();
    return 0;
}