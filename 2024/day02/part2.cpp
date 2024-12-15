#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <chrono>

using namespace std;

bool isSafe(vector<int> nums, size_t size){
    bool asc = true;
    bool desc = true;
    for(size_t i = 1;i < size;++i){
        int diff = abs(nums[i] - nums[i - 1]);
        if(!(diff >= 1 && diff <= 3)) return false;
        if(nums[i] > nums[i - 1]) desc = false;
        if(nums[i] < nums[i - 1]) asc = false;
    }
    return asc || desc;
}

// check if the array is safe after removing any one element
bool checkAfterRemove(vector<int> nums, size_t size){
    vector<int> inner = nums;
    for(size_t i = 0;i < size; ++i){
        // remove element
        inner.erase(inner.begin() + i);
        if(isSafe(inner, size - 1)) return true;
        // restore array to original
        inner = nums;
    }
    return false;
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    string text;
    ifstream MyFile("input.txt");
    string input;
    int ans = 0;
    while(getline(MyFile, input)){
        istringstream iss(input);
        int num;
        vector<int> inner;
        while(iss >> num){
            inner.push_back(num);
        }
        // store size as it will be used many times
        size_t size = inner.size();
        if(isSafe(inner, size)){
            ans++;
        }else{
            if(checkAfterRemove(inner,size)){
                ans++;
            }
        }
    }

    MyFile.close();

    cout << "Ans is " << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Program took "  << elapsed.count() << " s" << endl;
    return 0;
}

// 22914157