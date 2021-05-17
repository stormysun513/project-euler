#include <iostream>
#include <unordered_map>

using namespace std;

int d(int num)
{
    int sum = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            if(i != num/i && i != 1) {
                sum += (i + num/i);
            } else {
                sum += i;
            }
        } 
    }
    return sum;
}

int main(int argc, char **argv)
{
    unsigned long sum = 0;
    unordered_map<int, int> m;

    for(int i = 1; i <= 10000; i++) {
        int d1, d2;
        if(m.find(i) != m.end()) {
            d1 = m[i];
        } else {
            d1 = d(i);
            m.insert({i, d1});
        }
        if(m.find(d1) != m.end()) {
            d2 = m[d1];
        } else {
            d2 = d(d1);
            m.insert({d1, d2});
        }
        if(i != d1 && i == d2) {
            sum += i;
        }
    }
    /*
    for(int i = 1; i <= 284; i++) {
        cout << i << ":" << m[i] << endl;
    }
    */
    cout << sum << endl;

    return 0;
}
