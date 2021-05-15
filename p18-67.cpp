#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<int> > pyramid;
    ifstream ifs("/tmp/data.txt", ios::in);
    string line;
    
    while(getline(ifs, line)) {
        int num;
        vector<int> nums;
        stringstream ss;
        ss << line;
        while(ss >> num) {
            nums.push_back(num);
        }
        pyramid.push_back(nums);
    }
    /*
    for(int i = 0; i < pyramid.size(); i++) {
        for(int j = 0; j < pyramid[i].size(); j++) {
            cout << pyramid[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int i = pyramid.size() - 2; i >= 0; i--) {
        for(int j = 0; j < pyramid[i].size(); j++) {
            int temp = pyramid[i][j];
            pyramid[i][j] = temp + max(pyramid[i + 1][j], pyramid[i + 1][j + 1]);
        }
    }
    cout << pyramid[0][0] << endl;

    return 0;
}
