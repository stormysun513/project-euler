#include <iostream>
#include <unordered_set>
#include <cmath>

#define SIZE 100

using namespace std;

int main(int argc, char **argv)
{
    int count = 0;
    unordered_set<double> s;

    for(int a = 2; a <= SIZE; a++) {
        for(int b = 2; b <= SIZE; b++) {
            double val = pow(a, b);
            if(s.find(val) != s.end()) {
                continue;
            }
            s.insert(val);
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
