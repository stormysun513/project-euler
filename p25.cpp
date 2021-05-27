#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int i = 1, first = -1;
    int k = i % 2;
    vector<vector<int> > nums(2, vector<int>(1000, 0));

    nums[0][0] = 1, nums[1][0] = 1;

    while(nums[k][999] == 0) {
        for(int j = 0; j < nums[k].size() - 1; j++) {
            int c = nums[k][j] + nums[(k + 1) % 2][j];
            nums[k][j] = c % 10;
            nums[k][j + 1] += c / 10;
        }
        i++;    
        k = i % 2;    
    }
    cout << i << endl;

    return 0;
}
