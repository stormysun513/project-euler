#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> table(2000000, 1);
vector<int> prime;

void calPrime(void)
{
	for(int p = 2; p <= table.size() ; p++) {
		if(table[p]) {
			for(int i = 2 * p; i <= table.size(); i += p) {
				table[i] = 0;
			}
			prime.push_back(p);
		}
	}
}

int devCount(long num)
{
	int ans = 1;

	for(int i = 0; i < prime.size(); i++) {
		int count = 0, p = prime[i];
		while(num % p == 0) {
			num /= p;
			count++;
		}
		ans *= (count + 1);
	}

	return ans;
}

int solution(void)
{
	int n = 1, cnt;
	long num;

	num = n * (n + 1) / 2;
	//cout << n << ": " << num  << endl;
	while((cnt = devCount(num)) <= 500) {
		//cout << n << ": " << cnt << endl;
		n++;
		num = n * (n + 1) / 2;
	}

	return num;
}

int main(int argc, char **argv)
{
	calPrime();
	cout << solution() << endl;
	//cout << devCount(76576500) << endl;
	return 0;
}
