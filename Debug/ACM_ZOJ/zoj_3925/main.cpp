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
        int (*cho)[1001]= new int[1001][1001];
//        int* ans = new int[1001*1001]; 
//		int* ans =(int*) malloc(1001*1001*sizeof(int));
        int T = 0;
        //string color="";
		char color[1001];
//        cin >> T;
        scanf("%d\n",&T);
//        clock_t time = clock();
        for (int t = 1; t <= T; t++) {
        	
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
            int best,left,right,temp;
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
            	cho[i][j] = i;
//            	cout << "ans[" << i << "][" << i << "]=" << best<< endl; 
			}
			for (int i=1;i<=N-1;i++){
            	j = i+1;
            	ans[i][j] = ans[i][i] + ans[j][j];
            	cho[i][j] = i;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (int i=1;i<=N-2;i++){
            	j = i+2;
            	k = i+1;
            	ans[i][j] = ans[k][k] + ans[i][k-1]>ans[k+1][j]?ans[i][k-1]:ans[k+1][j];
            	cho[i][j] = k;
//            	cout << "ans[" << i << "][" << j << "]=" << ans[i][j]<< endl; 
			}
			for (n = 4; n <= N; n++)
			{
				for (i=1;i<=N-n+1;i++)
				{
					j = i + n -1;
					best = 2147483647;
					for (k=i+1;k<=j-1;++k)
//					for (k=cho[i][j-1];k<=cho[i+1][j];++k)
					{
						temp = ans[k][k];
						left = ans[i][k-1] ;
						right = ans[k+1][j];
						temp +=left>right?left:right;
						if (temp < best)
						{
							best = temp;
							cho[i][j] = k;
						}
//						cout << k << " ";
					}
					ans[i][j] = best; 
//					cout << endl << "ans[" << i << "][" << j << "]=" << best<< endl; 
				}
			}
			cout << ans[1][N] << endl;
	}
	return 0;
}
//            for (n = 1; n <= 1; n++) {
//                for (i = 0; i < N-n+1; i++) {
//                    best = 2147483647;
//                    for (j = i; j <= i+n-1; j++) {
//                    	   if (color[j] == 'R') {
//                                best =R[j]<(B[j] + K)?R[j]:(B[j] + K);
//                            }
//							else 
//                            {
//                                best = B[j]<(R[j]+K)?B[j]:(R[j]+K);
//                            }
//                    }
//                    ans[i][n] = best;
//                    cho[i][n] = i;
////                    ans[i*N+n] = best;
//                    //cout << "ans[" << i << "][" << n << "]=" << best<< endl; 
//                }
//            }
//			for (n = 2; n <= N; n++) {
//                for (i = 0; i < N-n+1; i++) {
//                    best = 2147483647;
//                    //j==i
//                    j = i;
//                    temp = ans[j][1] + ans[j + 1][i + n - 1 - j];
////                    temp = ans[i*N+1] + ans[(j+1)*N+i+n-1-j];
//                    if(temp < best){
//                    	best = temp;
//                    	cho[i][n] = j;
//					}
//                    //j==i+n-1
//                    j = i+n-1;
//                    temp = ans[j][1] + ans[i][j - i];
////                    temp = ans[i*N+1] + ans[i*N +j -i];
//                    if(temp < best){
//                    	best = temp;
//                    	cho[i][n] = j;
//					}
////					int* ans_i = ans+ i*N;
////					int* ans_j = ans_i;
//					
////                    for (j = i+1; j <= i+n-1-1; j++) {
// 					for (j = cho[i][n-1]; j <= cho[i+1][n-1]; j++) {
////                            left = -1;
////                            right = -1;
////                            left = ans[i][j - i];
//							temp = ans[j][1];
//							left = ans[i][j - i];
//							right = ans[j + 1][i + n - 1 - j];
//							temp += (left>right?left:right);
//                            if(temp < best)
//                            {
//                            	best = temp;
//                            	cho[i][n] = j;
//							}
////							temp = *(ans_j+1);
////							ans_j += N;
////							left = *(ans_i + j-i);
////                            right = ans[j + 1][i + n - 1 - j];
////							right = ans[(j+1)*N+i+n-1-j];
////							right = *(ans_j+i+n-1-j); 
////                            if (j - 1 >= i) {
////                                left = ans[i][j - i];
//////                                left = ans[i*N +j -i];
//////                                if(left>best) continue;
////                            }
////                            if (j + 1 <= i + n - 1) {
////                                //right = ans[j + 1][(i + n - 1) - (j + 1) + 1];
////                                right = ans[j + 1][i + n - 1 - j];
//////                                right = ans[(j+1)*N+i+n-1-j];
//////                                if(right>best) continue;
////                            }
////                            temp = ans[j][1] + (left>right?left:right);
//							
//                    }
//                    ans[i][n] = best;
////					ans[i*N+n] = best; 
////                    cout << "ans[" << i << "][" << n << "]=" << best<< endl; 
//                }
//            }
//			cout << ans[0][N] << endl; 
//			cout << ans[N] << endl; 

//        	time = clock()- time;
//			cout << ((float)time)/CLOCKS_PER_SEC << endl;

