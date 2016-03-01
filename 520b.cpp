#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	vector<int> check(40005);
	deque<int> q,l;
	cin >> a >> b;
	q.push_back(a);
	l.push_back(0);
	check[a]=1;
	for(int i=0;;i++){
		if(q.front()==b){
			cout << l.front() << endl;
			break;
		}
		if(!check[q.front()-1]){
			q.push_back(q.front()-1);
			l.push_back(l.front()+1);
			check[q.front()-1]=1;
		}
		if(!check[q.front()*2]){
			if(q.front()<=b){
				q.push_back(q.front()*2);
				l.push_back(l.front()+1);
				check[q.front()*2]=1;
			}
		}
		q.pop_front();
		l.pop_front();
	}
	return 0;
}


