#include <bits/stdc++.h>

using namespace std;

int main (){
    ifstream myfile;
    myfile.open("data.csv");

    while(myfile.good()){
        string line;
        getline(myfile, line, ';');
        cout << line << endl;
    }
}