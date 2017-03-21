#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <tuple>

using namespace std;

typedef vector< tuple<int,int> > tuple_list;
int max_count = -1;
char a[100][100] = {0};

tuple<int, int> fileopen(void){
	int cnt, i=1, j=0;
	string s;
	a[100][100] = {0};
	freopen("../in.txt","r",stdin);

	while(!cin.eof()) {
		cin >> s;
		cnt++;
		for (int j = 0; j <= s.length()+1; ++j) {
			if(j==0 || j==s.length()+1)
				a[i][j] = '#';

			else
				a[i][j] = s[j-1];
		}
		i++;
	}
	
	for (j=0; j<=s.length()+1; ++j){
		a[0][j] = '#';
		a[i-1][j] = '#';
	}
	cin.clear();
	return make_tuple(i, j);
}

int DFS(int srow, int scol, int row, int col, int counter, tuple_list &list)
{
	a[srow][scol] = '#';
	if(a[srow][scol] == 35 && a[srow+1][scol] == 35 && a[srow][scol-1] == 35 && a[srow][scol+1] == 35 && a[srow-1][scol] == 35){

		max_count = max(max_count,counter);

		if (max_count == counter){
			list.clear();
			list.push_back( tuple<int, int>(srow, scol));
			//cout << srow << " " << scol << endl;
			return max_count;
		}
		return 0;
	}
 	counter++;
    for (int i = srow-1; i <= srow+1; i++){
    	for (int j=scol-1; j <= scol+1; j++){

    		if((a[i][j] == 46) && ((i==srow && j!=scol) || (i!=srow && j==scol))){
    			if (DFS(i, j, row, col, counter, list) != 0)
    				list.push_back( tuple<int, int>(srow, scol));

    		}
    	}
    }
}

	
int main(){
	tuple_list list;
	auto t = fileopen();
	int i = get<0>(t), j = get<1>(t);

	for (int x = 1; x < i-1; x++) {
		for(int y = 1; y< j-1; y++){
			if(a[x][y] == 46){
				DFS(x, y, i, j, 0, list);
				fileopen();
			}
		}
	}

	cout << max_count+1 << endl;

    for (int i = 0; i <= max_count; i++)
     	a[get<0>(list[i])][get<1>(list[i])] = '0'+max_count-i;

    for (int x = 1; x < i-1; x++) {
		for(int y = 1; y< j-1; y++){
			cout << a[x][y];
		}
		cout << endl;
	}

	return 0;
}