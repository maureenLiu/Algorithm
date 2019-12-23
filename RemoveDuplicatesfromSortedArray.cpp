#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			if(nums.empty()) return 0;
			if(nums.size() < 2) return nums.size();
			/*printf("vector array number:\n");
			for(std::vector<int>::iterator m = nums.begin(); m != nums.end();m++) {
				printf("%d ", *m);
			} */
			int k = 0;//要保留的数的下标
			int i = 1;//待定的数的下标
			while(i < nums.size()) {
				if(nums[k] != nums[i]) {
					nums[++k] = nums[i];
				}
				i++;
			}
			return k+1;
		}
};

int main() 
{
	int arr[] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> nums(arr, arr+10);
	Solution solution;
	int len = solution.removeDuplicates(nums);
	for(int i = 0; i < len; i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}
