//{ Driver Code Starts
// driver code

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <chrono>

using namespace std;

int getSum(string str){
    int sum = 1;
    istringstream iss(str);
    int num;

    while(iss >> num){
        sum = sum * num;
    }
    return sum;
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    string text;
    ifstream MyFile("input.txt");
    string input;
    while(getline(MyFile, input)){
        text += input;
    }
    
    size_t ind = 0;
    int sum  = 0; 
    bool applyMul = true;
    while(ind < text.size()){
        if(text.substr(ind, 4) == "do()"){
            applyMul = true;
        }else if(text.substr(ind, 7) == "don't()"){
            applyMul = false;
        }

        if(applyMul && text.substr(ind, 4) == "mul("){
            int start = ind;            
            ind += 4;
            while(isdigit(text[ind])){
                ind++;
            }
            if(text[ind]==','){
                ind++;
            }else{
                continue;
            }
            while(isdigit(text[ind])){
                ind++;
            }
            
            if(text[ind] == ')'){
                string got = text.substr(start + 4, ind - start);
                for(size_t i = 0; i < got.size(); i++){
                    if(!isdigit(got[i])){
                        got[i] = ' ';
                    }
                }
                
                sum += getSum(got);
            }
        }
        ind++;
    }
    // "mul(30)"
    MyFile.close();


    cout << sum << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Program took "  << elapsed.count() << " s" << endl;
    return 0;
}
