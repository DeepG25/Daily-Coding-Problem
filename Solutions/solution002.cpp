#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int>& a)
{
  int n = a.size();
  vector<int> ans(n);
  vector<int> pre(n),post(n);
  pre[0] = 1;
  for(int i=1;i<n;i++)
  {
    pre[i] = pre[i-1]*a[i-1];
  }

  post[n-1] = 1;
  for(int i=n-2;i>=0;i--)
  {
    post[i] = post[i+1]*a[i+1];
  }

  for(int i=0;i<n;i++)
  {
    ans[i] = pre[i]*post[i];
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin >> a[i];
  }
  vector<int> ans = solve(a);
  for(int i=0;i<n;i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
