#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "func.h"
using namespace std;

const vector<string> input(const string& s, const char& c)
{
    string buff = "";
    vector<string> v;
    for (auto n : s) {
        if (n != c)
            buff += n;
        else
            if (n == c && buff != "") {
                v.push_back(buff);
                buff = "";
            }
    }
    if (buff != "")
        v.push_back(buff);
    return v;
}


vector<string> InputLine() {
    int n;
    cin >> n;
    string read;
    vector<string> all_line;


    for (int i = 0; i <= n; i++) {//input line 
        getline(cin, read);
        all_line.push_back(read);
    }
    all_line.erase(all_line.begin());//delete space

    return all_line;
}

void input() {

    vector<vector<string>> split_arr;
    vector<string> all_line = InputLine();

    for (int i = 0; i < all_line.size(); i++) {//push word in vector
        split_arr.push_back(input(all_line[i], ' '));
    }

    vector<string> result = split_arr[0];
    vector<string> res;
    for (int i = 1; i < split_arr.size(); i++) {
        sort(result.begin(), result.end());
        sort(split_arr[i].begin(), split_arr[i].end());
        set_intersection(result.begin(), result.end(), split_arr[i].begin(), split_arr[i].end(), back_inserter(res));
        result = res;
        res.clear();
    }

    for (const auto& o : result)
        cout << o << endl;

}