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
int* c = new int[1024*1024];
int num_of[1024]; 
int N,K;
int best; 


int main(int argc, char** argv) {
    int T = 0;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d",&N,&K);
        for (int i = 0; i <N; i++) {
            scanf("%d",&R[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d",&B[i]);
        }
        scanf("\n");
		scanf("%s\n",color);
		clock_t time = clock();	
		for (int j=0;j<N;j++)
		{
			num_of[j] = (1+j)*j/2;
		}
		for (int i=0; i<N; i++)
		{
			int j = i;
        	if (color[j] == 'R') {
                best = R[j]<(B[j] + K)?R[j]:(B[j] + K);
            }
			else 
            {
                best = B[j]<(R[j]+K)?B[j]:(R[j]+K);
            }
			c[num_of[j]+i] = best;  
//			cout << "ans[" << i << "][" << j << "]=" << c[num_of[j]+i]<< endl; 
		}	
		for (int i=0;i<N-1;i++){
        	int j = i+1;
        	c[num_of[j]+i] = ans[i][i] + ans[j][j];
        	c[num_of[j]+i] = c[num_of[i]+i] + c[num_of[j]+j];
//        	cout << "ans[" << i << "][" << j << "]=" << c[num_of[j]+i]<< endl; 
		}
		int temp,left,right;
		for (int n = 3; n <= N; n++)
		{
			for (int i=0;i<N-n+1;i++)
			{
				int j = i + n -1;
				best = 2147483647;
				for (int k=i+1;k<=j-1;++k)
//					for (k=cho[i][j-1];k<=cho[i+1][j];++k)
				{
					temp = c[num_of[k]+k];
//					left = c[num_of[k-1]+i] ;
//					right = c[num_of[j]+k+1];
					
					temp +=left>right?left:right;
					if (temp < best)
					{
						best = temp;
					}
//						cout << k << " ";
				}
//				c[num_of[j]+i] = best; 
				
//				cout <<"ans[" << i << "][" << j << "]=" << c[num_of[j]+i]<< endl; 
			}
		}
		cout << c[num_of[N-1]] << endl;
		time = clock()- time;
        cout << ((float)time)/CLOCKS_PER_SEC << endl;
    }

	return 0;
}
