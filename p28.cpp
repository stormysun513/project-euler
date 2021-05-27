#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int num = 1001 * 2 - 1, last[4];
    long sum = 0;

    sum = 1;
    for(int i = 0; i < 4; i++) {
        last[i] = 1;
    }
    for(int i = 1; i < num; i++) {
        int val = last[i % 4] + i * 2;
        last[i % 4] = val;
        cout << val << endl;
        sum += val;
    }
    cout << sum << endl;

    return 0;
}
