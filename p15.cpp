#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<long> > grid(21, vector<long>(21, 1));

    for(int i = 1; i < grid.size(); i++) {
        for(int j = 1; j < grid[i].size(); j++) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    cout << grid[20][20] << endl;
    return 0;
}
