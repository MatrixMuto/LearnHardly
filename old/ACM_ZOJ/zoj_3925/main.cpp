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
        int (*RO)[1001]= new int[1001][1001];
        

//        int* ans = new int[1001*1001]; 
//		int* ans =(int*) malloc(1001*1001*sizeof(int));
        int T = 0;
        //string color="";
		char color[1001];
//        cin >> T;
        scanf("%d\n",&T);
//        clock_t time = clock();
        for (int t = 1; t <= T; t++) {
//        	clock_t time = clock();
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
            	RO[i][j] = i;
//            	cout << "ans[" << i << "][" << i << "]=" << best<< endl; 
			}
			for (int i=1;i<=N-1;i++){
            	j = i+1;
            	ans[i][j] = ans[i][i] + ans[j][j];
            	RO[i][j] = i;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (int i=1;i<=N-2;i++){
            	j = i+2;
            	k = i+1;
            	ans[i][j] = ans[i+1][i+1] ;
				ans[i][j] += ans[i][i]>=ans[j][j]?ans[i][i]:ans[j][j];
            	RO[i][j] = k;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (n = 4; n <= N; n++)
			{
				for (i=1; i<= N-n+1; i++)
				{
					j = i + n -1;
					int m = RO[i][j-1];
					
					best = 2147483647;
				
					for (k=m;k<=RO[i+1][j];k++)
					{	
						temp = ans[k][k] ;
						if (ans[i][k-1] >= ans[k+1][j]) {
							temp += ans[i][k-1];
						}
						else {
							temp += ans[k+1][j];
						}
						if (temp< best)
						{
							best = temp;
							RO[i][j] = k;
						}
					}
					ans[i][j] = best;
//					cout << endl << "ans[" << i << "][" << j << "]=" << best<< endl; 
				}
			}
			cout << ans[1][N] << endl;
//			time = clock()- time;
//			cout << ((float)time)/CLOCKS_PER_SEC << endl;
	}
	return 0;
}

