#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int ans = 0, c;
    vector<int> nums(1000, 0);

    nums[0] = 1;
    for(int i = 0; i < 1000; i++) {
        c = 0;
        for(int j = 0; j < 500; j++) {
            nums[j] = 2 * nums[j] + c;
            c = nums[j] / 10;
            nums[j] = nums[j] % 10;
        }
    }
    for(int i = 0; i < 500; i++) {
        ans += nums[i];
    }
    cout << ans << endl;

    return 0;
}
