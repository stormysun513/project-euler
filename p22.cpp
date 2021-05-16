#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    unsigned long score = 0;
    ifstream ifs("/tmp/data.txt", ios::in);
    ofstream ofs("/tmp/out.txt", ios::out);
    string line;
    vector<string> list;
    int index;

    while(getline(ifs, line, ',')) {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        list.push_back(line);
    }
    sort(list.begin(), list.end());
    for(int i = 0; i < list.size(); i++) {
        line = list[i];
        ofs << line << endl;
    }

    index = 1;
    for(string name: list) {
        int temp = 0;
        for(char c: name) {
            temp += (c - 'A' + 1);
        }
        score += (temp * index);
        index++;
    }
    cout << score << endl;

    ifs.close();
    ofs.close();

    return 0;
}
