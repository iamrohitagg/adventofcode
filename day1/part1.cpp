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
    while(getline(MyFile, input)){
        istringstream iss(input);
        int num1, num2;
        iss >> num1 >> num2;
        input1.push_back(num1);
        input2.push_back(num2);
    }

    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());
    int sum = 0;
    for(int i = 0;i < input1.size(); i++){
        sum += abs(input1[i] - input2[i]);
    }

    MyFile.close();

    cout << "Ans is " << sum << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Program took "  << elapsed.count() << " s" << endl;
    return 0;
}

// 22914157