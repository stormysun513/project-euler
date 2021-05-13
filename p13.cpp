#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    ifstream ifs("/tmp/data.txt", ios::in);
    string line;
    vector<int> buf(50, 0);
    long ans = 0;

    while(getline(ifs, line)) {
        int c = 0;
        reverse(line.begin(), line.end());
        for(int i = 0; i < line.length(); i++) {
            int digit = line[i] - '0';
            c = c + digit + buf[i];
            buf[i] = c % 10;
            c /= 10;
        }
        for(int i = 50; i < buf.size() && c; i++) {
            c = c + buf[i];
            buf[i] = c % 10;
            c /= 10;
        }
        if(c) {
            buf.push_back(c);
        }
    }

    for(int i = 0; i < 10; i++) {
        ans = ans * 10 + buf[buf.size() - 1 - i];
    }

    cout << ans << endl;

    return 0;
}
