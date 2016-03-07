#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
		int* R = new int[1000];
        int* B = new int[1000];
        int (*ans)[1001]= new int[1001][1001];
        int (*AA)[1001]= new int[1001][1001];
        

//        int* ans = new int[1001*1001]; 
//		int* ans =(int*) malloc(1001*1001*sizeof(int));
        int T = 0;
        //string color="";
		char color[1001];
//        cin >> T;
        scanf("%d\n",&T);
//        clock_t time = clock();
        for (int t = 1; t <= T; t++) {
        	clock_t time = clock();
        	int N,K; 
//            cin >> N >> K;
            scanf("%d %d",&N,&K);
            for (int i = 1; i <= N; i++) {
//                cin >> R[i];
                scanf("%d",&R[i]);
            }
            for (int i = 1; i <= N; i++) {
//                cin >> B[i];
                scanf("%d",&B[i]);
            }
			scanf("\n");
//			cin >> color ;
			scanf("%s\n",&color[1]);
            int best,left,right,temp,best_r,best_l;
            int n,i,j,k;
            for (int i=1;i<=N;i++){
            	j = i;
            	if (color[j] == 'R') {
                    best = R[j]<(B[j] + K)?R[j]:(B[j] + K);
                }
				else 
                {
                    best = B[j]<(R[j]+K)?B[j]:(R[j]+K);
                }
            	ans[i][j] = best;
            	AA[i][j] = i;
//            	cout << "ans[" << i << "][" << i << "]=" << best<< endl; 
			}
			for (int i=1;i<=N-1;i++){
            	j = i+1;
            	ans[i][j] = ans[i][i] + ans[j][j];
            	AA[i][j] = i;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (int i=1;i<=N-2;i++){
            	j = i+2;
            	k = i+1;
            	ans[i][j] = ans[i+1][i+1] ;
				ans[i][j] += ans[i][i]>=ans[j][j]?ans[i][i]:ans[j][j];
            	AA[i][j] = k;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (n = 4; n <= N; n++)
			{
				for (i=1; i<= N-n+1; i++)
				{
					j = i + n -1;
					best = 2147483647;
					int BB = AA[i][j-1];
					for (;BB<=j-1;BB++)
					{
						if (ans[i][BB+1] < ans[BB+2][j])
						{
							AA[i][j] = BB;
							break;
						}
					}
					
					for(k=i;k<=BB-1;k++)
					{
						temp = ans[k][k] + ans[k+1][j] ;
						if (temp < best)
							best = temp;
						//cout << ans[k+1][j] << " "; 
						cout << "ans[" << k+1 << "][" << j << "]=" << ans[k+1][j]<< endl;
					}
					for(k=BB;k<=j;k++)
					{
						temp = ans[i][k-1]+ans[k][k]  ;
						if (temp < best)
							best = temp;
						//cout << ans[i][k-1] << " ";
						cout << "ans[" << i << "][" << k-1 << "]=" << ans[i][k-1]<< endl;
					}
					ans[i][j] = best;
					cout << "ans[" << i << "][" << j << "]=" << best<< endl << endl; 
//					cout << "AA[" << i << "][" << j << "]=" << AA[i][j]<< endl; 
				}
			}
			cout << ans[1][N] << endl;
			time = clock()- time;
			cout << ((float)time)/CLOCKS_PER_SEC << endl;
	}
	return 0;
}


