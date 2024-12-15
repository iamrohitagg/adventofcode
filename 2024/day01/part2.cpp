//{ Driver Code Starts
// driver code

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <chrono>

using namespace std;


int main(){
    auto start = chrono::high_resolution_clock::now();
    string text;
    ifstream MyFile("input.txt");
    string input;
    vector<int> input1, input2;
    map<int,int> helper;
    while(getline(MyFile, input)){
        istringstream iss(input);
        int num1, num2;
        iss >> num1 >> num2;
        input1.push_back(num1);
        input2.push_back(num2);
    }

    for(int ele : input2){
        helper[ele]++;
    }

    int sum = 0;
    
    for(int ele : input1){
        sum += (helper[ele] * ele);
    }

    MyFile.close();

    cout << "Ans is " << sum << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Program took "  << elapsed.count() << " s" << endl;
    return 0;
}

// 22914157