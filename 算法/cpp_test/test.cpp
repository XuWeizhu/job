#include<iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;

vector<int> sorted(vector<int> A);
void exch(int* a, int* b);
void merge(vector<int>* Ap, vector<int>* Auxp, int a, int b, int c);

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

    if(str_random.size()!=str_sorted.size()){
        cout<<" error"<<endl;
        return 0;
    }
    
    vector<int> out_array;
    out_array = sorted(str_random);
    if(out_array==str_sorted){
        cout<<"great!"<<endl;
        cout<<"\nanswer : "<<endl;
        for(int i = 0;i<str_sorted.size();++i){
            cout<<str_sorted[i]<<'\t';
        }
        cout<<"\nyour answer : "<<endl;
        for(int i = 0;i<out_array.size();++i){
            cout<<out_array[i]<<'\t';
        }
        cout<<endl;        

    }else{
        cout<<"error\n"<<endl;

        cout<<"input : "<<endl;
        for(int i = 0;i<str_random.size();++i){
            cout<<str_random[i]<<'\t';
        }        
        cout<<"\nanswer : "<<endl;
        for(int i = 0;i<str_sorted.size();++i){
            cout<<str_sorted[i]<<'\t';
        }
        cout<<"\nyour answer : "<<endl;
        for(int i = 0;i<out_array.size();++i){
            cout<<out_array[i]<<'\t';
        }
        cout<<endl;
        
    }
    return 0;
}

void exch(int* a, int* b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


//Here is your code

vector<int> sorted(vector<int> A){
    vector<int> Aux = A;
    int N = A.size();
    for(int strip = 1;strip<N;strip +=strip){
        for(int l1 = 0;l1<N-strip;l1 = l1+strip*2){
            merge(&A, &Aux, l1, l1+strip-1, min(l1+strip*2-1, N-1));
        }
    }
    return A;
}

void merge(vector<int>* Ap, vector<int>* Auxp, int a, int b, int c){
    int l1 = a;
    int m1 = b+1;

    for(int i = a;i<=c;++i){
        (*Auxp)[i] = (*Ap)[i];
    }

    for(int k = a;k<=c;++k){
        if(l1>b) (*Ap)[k] = (*Auxp)[m1++];
        else if(m1>c) (*Ap)[k] = (*Auxp)[l1++];
        else if((*Auxp)[l1] < (*Auxp)[m1]) (*Ap)[k] = (*Auxp)[l1++];
        else (*Ap)[k] = (*Auxp)[m1++];
    }

}

//end

