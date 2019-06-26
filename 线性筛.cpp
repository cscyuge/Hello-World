#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+5;

int prim[MAXN],np[MAXN],pn,mu[MAXN],phi[MAXN],d[MAXN],ad[MAXN];

void getp(){
	np[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!np[i]){
			prim[pn++]=i;	
		}
		for (int j=0;j<pn&&i*prim[j]<MAXN;j++){
			np[i*prim[j]]=1;
			if (i%prim[j]==0){
				break;	
			}
		}
	}
}

void getmu(){
	np[1]=1;
	mu[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!np[i]){
			prim[pn++]=i;	
			mu[i]=-1;
		}
		for (int j=0;j<pn&&i*prim[j]<MAXN;j++){
			np[i*prim[j]]=1;
			if (i%prim[j]==0){
				mu[i*prim[j]]=0;
				break;	
			}
			mu[i*prim[j]]=mu[i]*mu[prim[j]];
		}
	}
}

void getphi(){
	np[1]=1;
	phi[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!np[i]){
			prim[pn++]=i;
			phi[i]=i-1;
		}
		for (int j=0;j<pn&&i*prim[j]<MAXN;j++){
			np[i*prim[j]]=1;
			if (i%prim[j]==0){
				phi[i*prim[j]]=phi[i]*prim[j];
				break;	
			}
			phi[i*prim[j]]=phi[i]*phi[prim[j]];
		}
	}
}

void getd(){
	np[1]=1;
	d[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!np[i]){
			prim[pn++]=i;
			d[i]=2;
			ad[i]=1;
		}
		for (int j=0;j<pn&&i*prim[j]<MAXN;j++){
			np[i*prim[j]]=1;
			if (i%prim[j]==0){
				d[i*prim[j]]=d[i]/(ad[i]+1)*(ad[i]+2);
				ad[i*prim[j]]=ad[i]+1;
				break;
			}
			d[i*prim[j]]=d[i]*d[prim[j]];
			ad[i*prim[j]]=1;
		}
	}
}


int main(){
	
	int n;
	double t=clock();
	getp();
	cout<<pn<<endl;
	for (int i=666;i<666+50;i++){
		cout<<prim[i]<<",";
	} 
//	getmu();
//	getphi();
//	getd();

	/*while (cin>>n){
		for (int i=1;i<=n;i++){
			cout<<i<<" :"<<d[i]<<endl;
		}
	}
	cout<<pn<<endl;
	*/
	
}
