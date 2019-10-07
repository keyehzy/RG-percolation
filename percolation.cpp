#include <bits/stdc++.h>

using namespace std;

void ff(vector<vector<int>> &arr, vector<int> &visited, int i, int j){
  //  cout << "i:" << i << " j:" << j << '\n';
  visited.push_back(i);
  if(i >= 0 && i < (int)arr.size() && j >=0 && j < (int)arr.size() && arr[i][j]==1){
    arr[i][j]=2;
    ff(arr,visited,i+1,j);
    ff(arr,visited,i-1,j);
    ff(arr,visited,i,j+1);
    ff(arr,visited,i,j-1);
    
    ff(arr,visited,i+1,j+1);
    ff(arr,visited,i+1,j-1);
    ff(arr,visited,i-1,j+1);
    ff(arr,visited,i-1,j+1);
  }
}

int percolate(vector<vector<int>> arr){
  vector<int> visited;
  for (int i = 0; i < (int)arr.size(); i++) ff(arr, visited, 0, i);
  
  for (int i : visited){
    if (i==(int)arr.size()) return true;
  }
  return false;
}

vector<vector<int>> rg(vector<vector<int>> arr){
  int m = (int)arr.size();
  if(m < 4) return arr;
  
  vector<vector<int>> newa(m/2, vector<int>(m/2, 0));
  
  for (int k = 0; k < m/2; k++){
    for (int l = 0; l < m/2; l++){
      vector<vector<int>> grain(2, vector<int>(2, 0));
      //cout << "\ngrain" << '\n';
      for (int i = 0; i < 2; i++){
	for (int j = 0; j < 2; j++){
	  grain[i][j] = arr[2*k + i][2*l + j];
	  //cout << "i:" << 2*k+i << " j:" << 2*l+j << ' ';
	  //cout << arr[2*k + i][2*l + j] << ' ';
	}
	//cout << '\n';
      }
      newa[k][l] = percolate(grain);
      //cout << newa[k][l] << '\n';
    }
  }
  return rg(newa);
}

void use_rg(vector<vector<int>> arr){
  vector<vector<int>> newa(2, vector<int>(2, 0));
  newa = rg(arr);
  // cout << '\n';
  // for (int i = 0; i < 2; i++){
  //   for (int j = 0; j < 2; j++){
  //     cout << newa[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  puts("using RG");
  percolate(newa) ? puts("percolate") : puts("not percolate");
}

int main() {
  int n;
  double p;

  cin >> n >> p;

  vector<vector<int>> arr(n, vector<int>(n, 0));  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      double rnd = (double) rand() / (RAND_MAX);
      if (rnd < p) arr[i][j] = 1;
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  use_rg(arr);
  
  puts("Trivial");
  percolate(arr) ? puts("percolate") : puts("not percolate");
}
