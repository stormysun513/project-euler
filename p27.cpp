#include <iostream>

#define MAX_SIZE (1 << 20)

using namespace std;

static int primes[MAX_SIZE];

void preparePrimeTable(void)
{
    primes[0] = 1;
    primes[1] = 1;
    for(int i = 2; i < MAX_SIZE; i++) {
        if(primes[i] == 0) {
            for(int j = 2 * i; j < MAX_SIZE; j += i) {
                primes[j] = 1;
            }
        }
    }
}

int numOfPrimes(int a, int b)
{
    int i = 0, val;

    val = i * i + a * i + b;
    while(val >= 0 && val < MAX_SIZE && primes[val] == 0) {
        i++;
        val = i * i + a * i + b;
    }
    return i;
}

int main(int argc, char **argv)
{
    int ans = -1, curr = -1;

    preparePrimeTable();

    for(int a = -999; a <= 999; a++) {
        for(int b = -1000; b <= 1000; b++) {
            int temp = numOfPrimes(a, b);
            if(temp > curr) {
                curr = temp;
                ans = a * b;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
