#include<iostream>
#include<set>
#include<vector>
using namespace std;

bool solve(vector<int>& a,int k)
{
	set<int> s;
	for(int i=0;i<a.size();i++)
	{
		if(s.find(k - a[i]) != s.end())
		{
			return true;
		}
		else
		{
			s.insert(a[i]);
		}
	}
	return false;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	bool ans = solve(a,k);
	cout << ans << endl;
	return 0;
}
