









#include <iostream>
#include <string>

#define MAX(a,b) ((a>b)?(a):(b))

using namespace std;

int dp[1001][1001];

int lcs(const string &s, const string &t){
  int m = s.size(), n = t.size();
  if (m == 0 || n == 0) return 0;
  for (int i=0; i<=m; ++i)
    dp[i][0] = 0;
  for (int j=1; j<=n; ++j)
    dp[0][j] = 0;
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
      if (s[i] == t[j])
	dp[i+1][j+1] = dp[i][j]+1;
      else
	dp[i+1][j+1] = MAX(dp[i+1][j], dp[i][j+1]);
  return dp[m][n];
	
  

}

int main(){
  string s, t;
  getline(cin, s);
  getline(cin, t);
  int caso = 1;
  while (!cin.eof()){
    cout << "Case #"<< caso <<": you can visit at most " << lcs(s, t) << " cities." << endl;
    ++caso;
    getline(cin, s);
    if (s == "#") break;
    getline(cin, t);
  }
  return 0;
}
