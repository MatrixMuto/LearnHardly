#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

char color[1001];
int* R = new int[1000];
int* B = new int[1000];
int (*ans)[1024]= new int[1024][1024];

int N,K;

int s_min(int i, int j);
int minmax(int n)
{
	return s_min(1,n);
}

int s_max(int,int,int,int);
int s_min(int i, int j)
{
	int value = 2147483647;
	if (ans[i][j] != -1)
	{
		value = 10;
		return value;
	}
	
	if (i>j)
    {
        return -2147483647;
    }
    
	if (i == j)
    {
        if (color[j] == 'R') {
            value = R[j] <(B[j] + K) ? R[j] : (B[j]+K);
        }
        else
        {
            value = B[j] <(R[j] + K) ? B[j] : (R[j]+K);
        }
    }
    else if (i+1 == j)
    {
    	value = s_min(i,i) + s_min(j,j);
	}
    else {
    	for (int k=i; k<=j; k++)
//    	for (int k=j; k>=i; k--)
    	{
            int temp = s_max(i,j,k,value);
            if (temp < value)
                value = temp;
    	}
	}
    //cout << i <<".." <<j << "=" <<value <<endl;
    ans[i][j] = value;
    return value;
}

int s_max(int i,int j, int k,int best)
{
	int mid  = s_min(k,k);
	if (mid >= best)
		return best;

    int left = s_min(i,k-1);
    if (left + mid >= best)
        return best;

    int right = s_min (k+1,j);
    return left>=right ? left+mid: right+mid;
}

int main(int argc, char** argv) {
    int T = 0;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d",&N,&K);
        for (int i = 1; i <= N; i++) {
            scanf("%d",&R[i]);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d",&B[i]);
        }
        scanf("\n");
		scanf("%s\n",&color[1]);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans[i][j] = -1;
			}
		}
		clock_t time = clock();
        cout << minmax(N*3/4) << endl;
        time = clock()- time;
        cout << ((float)time)/CLOCKS_PER_SEC << endl;
    }

	return 0;
}
