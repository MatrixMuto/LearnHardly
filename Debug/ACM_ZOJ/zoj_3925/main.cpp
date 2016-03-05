#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
		int* R = new int[1000];
        int* B = new int[1000];
//        int (*ans)[1001]= new int[1001][1001];
//        int* ans = new int[1001*1001]; 
		int* ans =(int*) malloc(1001*1001*sizeof(int));
        int T = 0;
        //string color="";
		char color[1001];
//        cin >> T;
        scanf("%d\n",&T);
        for (int t = 1; t <= T; t++) {
        	
        	int N,K; 
//            cin >> N >> K;
            scanf("%d %d",&N,&K);
            for (int i = 0; i < N; i++) {
//                cin >> R[i];
                scanf("%d",&R[i]);
            }
            for (int i = 0; i < N; i++) {
//                cin >> B[i];
                scanf("%d",&B[i]);
            }
			scanf("\n");
//			cin >> color ;
			scanf("%s\n",color);
            int best,left,right,temp;
            int n,i,j;
            clock_t time = clock();
            for (n = 1; n <= 1; n++) {
                for (i = 0; i < N-n+1; i++) {
                    best = 2147483647;
                    for (j = i; j <= i+n-1; j++) {
                    	   if (color[j] == 'R') {
                                best =R[j]<(B[j] + K)?R[j]:(B[j] + K);
                            }
							else 
                            {
                                best = B[j]<(R[j]+K)?B[j]:(R[j]+K);
                            }
                    }
//                    ans[i][n] = best;
                    ans[i*N+n] = best;
                    //cout << "ans[" << i << "][" << n << "]=" << best<< endl; 
                }
            }
			for (n = 2; n <= N; n++) {
                for (i = 0; i < N-n+1; i++) {
                    best = 2147483647;
                    //j==i
                    j = i;
//                    temp = ans[j][1] + ans[j + 1][i + n - 1 - j];
                    temp = ans[i*N+1] + ans[(j+1)*N+i+n-1-j];
                    if(temp < best)
                        best = temp;
                    //j==i+n-1
                    j = i+n-1;
//                    temp = ans[j][1] + ans[i][j - i];
                    temp = ans[i*N+1] + ans[i*N +j -i];
                    if(temp < best)
                        best = temp;
					int* ans_i = ans+ i*N;
					int* ans_j = ans_i;
                    for (j = i+1; j <= i+n-1-1; j++) {
//                            left = -1;
//                            right = -1;
//                            left = ans[i][j - i];
//							temp = ans[j*N+1];
							temp = *(ans_j+1);
							ans_j += N;
							left = *(ans_i + j-i);
//                            right = ans[j + 1][i + n - 1 - j];
//							right = ans[(j+1)*N+i+n-1-j];
							right = *(ans_j+i+n-1-j); 
//                            if (j - 1 >= i) {
//                                left = ans[i][j - i];
////                                left = ans[i*N +j -i];
////                                if(left>best) continue;
//                            }
//                            if (j + 1 <= i + n - 1) {
//                                //right = ans[j + 1][(i + n - 1) - (j + 1) + 1];
//                                right = ans[j + 1][i + n - 1 - j];
////                                right = ans[(j+1)*N+i+n-1-j];
////                                if(right>best) continue;
//                            }
//                            temp = ans[j][1] + (left>right?left:right);
							temp += (left>right?left:right);
                            if(temp < best)
                            	best = temp; 
                    }
//                    ans[i][n] = best;
					ans[i*N+n] = best; 
                    //cout << "ans[" << i << "][" << n << "]=" << best<< endl; 
                }
            }
//			cout << ans[0][N] << endl; 
			cout << ans[N] << endl; 
			time = clock()- time;
			cout << ((float)time)/CLOCKS_PER_SEC << endl;
        }
	return 0;
}
