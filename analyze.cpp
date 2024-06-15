#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;




vector<string> extractVariables(const string& code) {
    vector<string> variables;
    regex varPattern("(int|double|float|char|bool)\\s+(\\w+)");
    auto words_begin = sregex_iterator(code.begin(), code.end(), varPattern);
    auto words_end = sregex_iterator();
    
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        variables.push_back(match.str());
    }
    
    return variables;
}

// Function to extract arrays and their sizes
vector<pair<string, int>> extractArrays(const string& code) {
    vector<pair<string, int>> arrays;
    regex arrayPattern("(int|double|float|char|bool)\\s+(\\w+)\\[(\\d+)\\]");
    auto words_begin = sregex_iterator(code.begin(), code.end(), arrayPattern);
    auto words_end = sregex_iterator();
    
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string type = match.str(1);
        string name = match.str(2);
        int size = stoi(match.str(3));
        arrays.push_back({name, size});
    }
    
    return arrays;
}

// Function to analyze space complexity
void analyzeSpaceComplexity(const string& code) {
    vector<string> variables = extractVariables(code);
    vector<pair<string, int>> arrays = extractArrays(code);
    
    // Analyze variables
    cout << "Variables:\n";
    for (const auto& var : variables) {
        cout << "  " << var << " - Space: O(1)\n";
    }
    
    // Analyze arrays
    cout << "Arrays:\n";
    for (const auto& array : arrays) {
        cout << "  " << array.first << "[" << array.second << "] - Space: O(" << array.second << ")\n";
    }
    
    // Add more analysis for other data structures and recursive functions
}


int n;
void func(int& op){
    // ---- PASTE YOUT FUNCTION HERE (add n = your input_size) -----
    n = 57;
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j *= 2) {
            op++;
        }
    }
}
 
int main(){
    long long a_op[8]={0};
    unordered_map<int,string>mp;
    int op = 0;
    func(op);
   
    mp[0] = "O(n)";
    mp[1] = "O(logn)";
    mp[2] = "O(n^2)";
    mp[3] = "O(n^3)";
    mp[4] = "O(nlogn)";
    mp[5] = "O(n^2logn)";
    mp[6] = "O(1)";
    mp[7] = "O(2^n)";

    a_op[0] = abs(n-op);
    a_op[1] = abs(log2(n)-op);
    a_op[2] = abs(n*n-op);
    a_op[3] = abs(n*n*n-op);
    a_op[4] = abs(n*log2(n)-op);
    a_op[5] = abs(n*n*log2(n)-op);
    a_op[6] = abs(1-op);
    a_op[7] = abs(op-pow(2,n));

    int mini = INT_MAX;
    int ind = -1;

    for(int i=0; i<8; i++){
        if(a_op[i]<mini){
            mini = a_op[i];
            ind = i;
        }
    }

    cout<<"Time-Complexity of the given function is: "<<mp[ind]<<endl;

     string code = R"(
        int a;
        int b[10];
        double c;
        float d[20];
        char e[5];
        bool f;
        
        void exampleFunction(int n) {
            int* arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = i;
            }
            delete[] arr;
        }
    )";
    
    analyzeSpaceComplexity(code);
return 0;
}