#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int ans = 0;
    vector<int> nums(200, 0), c(200, 0);
    nums[0] = 1;

    for(int i = 1; i <= 100; i++) {
        for(int j = 0; j < nums.size(); j++) {
            int temp = nums[j] * i;
            int k = j;
            while(temp) {
                c[k] += temp % 10;
                temp /= 10;
                k++;
            }
            if(c[j] >= 10) {
                c[j + 1] += c[j] / 10;
                c[j] = c[j] % 10; 
            }
        }
        for(int j = 0; j < c.size(); j++) {
            nums[j] = c[j];
            c[j] = 0;
        }
    }
    for(int j = 0; j < nums.size(); j++) {
        ans += nums[j];
    }
    cout << ans << endl;

    return 0;
}
