#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int sumOfDivisors(int num)
{
    int sum = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i;
            if(i != 1 && i != num/i) {
                sum += num/i;
            }
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    vector<int> nums;
    unordered_set<int> s;
    int sum = 0;

    for(int i = 0; i <= 28123; i++) {
        int found = 0;
        if(i < sumOfDivisors(i)) {
            // save abundant numbers 
            s.insert(i);
            nums.push_back(i);
        }
        for(int j = 0; j < nums.size(); j++) {
            int target = i - nums[j];
            if(s.find(target) != s.end()) {
                found = 1;
                break;
            }
        }
        if(!found) {
            sum += i;
        }
    }
    /*
    for(int num: nums) {
        cout << ":" << num << endl; 
    }
    */
 
    cout << sum << endl;

    return 0;
}
