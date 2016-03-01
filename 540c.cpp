#include<bits/stdc++.h>

using namespace std;

int visit[505][505];
string a[505];
int n,m,win;
int sj,si,dj,di;
void dfs(int i,int j){
	//cout << 'i' << ' ' << i << ' ' << 'j' << ' ' << j  << endl;
	if(i<0 || j<0 || j>m-1 || i>n-1 || win==1)
		return;
//	cout << 'i' << ' ' << i << ' ' << 'j' << ' ' << j  << endl;
	visit[i][j]=1;
	if((max(i-1,0)==di && j==dj) || (min(i+1,n-1)==di && j==dj) || (i==di && max(j-1,0)==dj) || (i==di && min(j+1,m-1)==dj)){//check dest
		win = 1;
//		cout << "i is " << i << "\tj is " << j << endl;
		visit[di][dj]=1;
//		cout << visit[di][dj] << ' '<<di <<' '<< dj << endl;
		return;
	}
	if(i-1>=0 && j>=0 && visit[i-1][j]==0 && a[i-1][j]=='.')
		dfs(i-1,j);
	if(i+1>=0 && j>=0 && visit[i+1][j]==0 && a[i+1][j]=='.')
		dfs(i+1,j);
	if(j-1>=0 && i>=0 && visit[i][j-1]==0 && a[i][j-1]=='.')
		dfs(i,j-1);
	if(i>=0 && j+1>=0 && visit[i][j+1]==0 && a[i][j+1]=='.')
		dfs(i,j+1);
}

int check(int i,int j){
	if(!visit[max(i-1,0)][j]&&a[max(i-1,0)][j]=='.'){
//		cout << visit[max(i-1,0)][j] << ' ' << max(i-1,0) << ' ' << j << endl;
//	cout << "hello1" << endl;
		return 1;}
	if(!visit[min(i+1,n-1)][j]&&a[min(i+1,n-1)][j]=='.'){
//	cout << "hello2" << endl;
		return 1;}
	if(!visit[i][max(0,j-1)]&&a[i][max(0,j-1)]=='.'){
//	cout << "hello3" << endl;
		return 1;}
	if(!visit[i][min(j+1,m-1)]&&a[i][min(j+1,m-1)]=='.'){
//	cout << "helloi4" << endl;
		return 1;}
	return 0;
}

int adjacent(int si,int sj,int di, int dj){
	if(si-1==di && sj==dj)
		return 1;
	if(si+1==di && sj==dj)
		return 1;
	if(si==di && sj-1==dj)
		return 1;
	if(si==di && sj+1==dj)
		return 1;
	return 0;
}
	
	
int main(){
	int st=0; //assuming .
	win = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cin >> si >> sj >> di >> dj;//i for row,j for column
	si--;sj--;di--;dj--;
	if(a[di][dj]=='X'){
		st=1;
		a[di][dj]='.';
	}
	dfs(si,sj);
//	cout << "done" << endl;
//	cout << win << endl;
//	cout << check(di,dj) << endl;
//	cout << adjacent(si,sj,di,dj) << endl;
//	cout << st << endl;
	if(!win)
		cout << "NO" << endl;
	else{
		if(st&&di!=si&&dj!=sj)
			cout << "YES" << endl;
		else if(adjacent(si,sj,di,dj)){
			if(st){
				cout << "YES" << endl;
			}
			else{
				if(check(di,dj))
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
		else if(check(di,dj))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}






