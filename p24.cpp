#include <iostream>
#include <vector>

using namespace std;


/*
 *  6789, 6798, 6879, 6897, 6978, 6987
 * */
int main(int argc, char **argv)
{
    vector<int> nums(10);
    
    for(int i = 0; i < nums.size(); i++) {
        nums[i] = i;
    }

    for(int i = 1; i < 1000000; i++) {
        int first, second, index;
        int j = nums.size() - 2, k;
        while(j >= 0 && nums[j] > nums[j + 1]) {
            j--;
        }
        if(j < 0) {
            break;
        }
        first = nums[j];
        k = j + 1;
        index = k;
        second = 10;
        while(k < nums.size()) {
            if(nums[k] < second && nums[k] > first) {
                second = nums[k];
                index = k;
            }
            k++;
        }
        nums[j] = second;
        nums[index] = first;
        sort(nums.begin() + j + 1, nums.end());
        /*
        if(i <= 10) {
            for(int i = 0; i < nums.size(); i++) {
                cout << nums[i];
            }
            cout << endl;
        }
        */
    }
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;

    return 0;
}
