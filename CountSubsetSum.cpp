
int f(int i, int target, vector<int>& arr, vector<vector<int>> &dp){
	if(target == 0) return 1;
	if(i==0) return (target == arr[0]);

	if(dp[i][target]!=-1) return dp[i][target];
	int np = f(i-1,target,arr,dp);
	int p = 0;
	if(arr[i] <= target)
		p = f(i-1,target-arr[i],arr,dp);
	return dp[i][target] = (np + p)%(int)(1e9+7);
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1 , k , arr,dp);
}
