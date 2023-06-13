#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
      int result;
      for(int i = 0; i < nums.size(); i++)
      {
        result = target - nums[i];
        for(int j = i + 1; j < nums.size(); j++)
        {
          if(result == nums[j])
          {
            return {i, j};
          }
        }
      }
      return {0, 0};
    };
};

int main() {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = s.twoSum(nums, target);
  cout << "[" << result[0] << "," << result[1] << "]" << endl;
  return 0;
}