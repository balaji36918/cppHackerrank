#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    /* enter no of lines of your markup language code and no of query lines*/
    int n, q, i;
    cin >> n >> q;
    string temp;
    vector<string> hrml;
    vector<string> quer;
    cin.ignore();

    //this loop to input the attributes in a markup language style
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        hrml.push_back(temp);
    }
    //this loop to input the queries
    for (int i = 0; i < q; i++) {
        getline(cin, temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    //remove the unnecessary charactesr and ssstream ops to fetch the results for your queries
    for (int i = 0; i < n; i++) {

        temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());
        if (temp.substr(0, 2) == "</")
        {
            tag.pop_back();
        }
        else {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            string temp1 = "";

            if (tag.size() > 0) {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;

            }
            else {
                temp1 = t1;
                
            }
            tag.push_back(temp1);
            m[*tag.rbegin() + "~" + p1] = v1;

            while (ss) {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }
    for (i = 0; i < q; i++) {
        if (m.find(quer[i]) == m.end()) {
            cout << "Not Found!\n";
        }
        else {
            cout << m[quer[i]] << endl;
        }
    }

    return 0;
}
