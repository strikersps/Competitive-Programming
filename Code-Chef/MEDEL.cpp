/*https://www.codechef.com/COOK111B/problems/MDL/*/
/*AUthor:-invictus1599*/
#include <iostream>
using namespace std;
int del(int a[],int x,int n){
	int i;
	if(x<=n-2){
		for(i=x;i<n;i++)
			a[i]=a[i+1];
	}
}
int main() {
	int t;
	cin>>t;
	while(--t>=0){
	    int n,i,t;
	    cin>>n;
	    int a[n];
	    t=n;
	    for(i=0;i<n;i++)cin>>a[i];
	    while(t>=3){
	    	if(a[0]>=a[1] && a[0]>=a[2]){
	    		if(a[1]>=a[2])
	    			del(a,1,t);
	    		else
	    			del(a,2,t);
			}
			else if(a[1]>=a[2]){
				if(a[0]>=a[2])
					del(a,0,t);
				else
					del(a,2,t);
			}
			else{
				if(a[1]>=a[0])
					del(a,1,t);
				else
					del(a,0,t);
			}
			t--;
		}
	    for(i=0;i<2;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
