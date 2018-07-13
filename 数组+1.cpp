class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result;
		vector<int>::iterator it;
		int plus = 1;
		for (it = digits.end() - 1; it >= digits.begin(); --it)
		{
			int sum = *it + plus;
			if (sum > 9)
			{
				plus = 1;
				result.push_back(0);
			}
			else
			{
				result.push_back(sum);
				plus = 0;
			}
		}
		if (plus == 1)  //[9,9,9]
		{
			result.push_back(1);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};