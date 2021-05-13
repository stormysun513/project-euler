#include <iostream>
#include <vector>
#include "parser.h"

using namespace std;

int solution(vector<vector<int> >& nums, int count)
{
	int ans = 0;

	for(int i = 0; i < nums.size(); i++) {
		for(int j = 0; j < (nums[i].size() - count + 1); j++) {
			int temp = 1;
			for(int k = 0; k < count; k++) {
				temp *= nums[i][j + k];
			}
			ans = max(ans, temp);
			if(i < (nums.size() - count + 1)) {
				temp = 1;
				for(int k = 0; k < count; k++) {
					temp *= nums[i + k][j + k];
				}
				ans = max(ans, temp);
			}
			if(i >= count - 1) {
				temp = 1;
				for(int k = 0; k < count; k++) {
					temp *= nums[i - k][j + k];
				}
				ans = max(ans, temp);
			}
		}
	}
	for(int j = 0; j < nums[0].size(); j++) {
		for(int i = 0; i < nums.size() - count + 1; i++) {
			int temp = 1;
			for(int k = 0; k < count; k++) {
				temp *= nums[i + k][j];
			}
			ans = max(ans, temp);
		}
	}

	return ans;
}

int main(int argc, char **argv)
{	
	int ans;
	Parser p;
	vector<vector<int> > nums = p.load_matrix("/tmp/data.txt");
	/*
	for(int i = 0; i < nums.size(); i++) {
		cout << "Row " << i << ", Length: " << nums[i].size() << endl;
		for(int j = 0; j < nums[i].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	*/
	ans = solution(nums, 4);
	cout << ans << endl;
	return 0;
}
