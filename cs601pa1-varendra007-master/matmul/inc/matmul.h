#ifndef MATMUL_H
#define MATMUL_H
#include <bits/stdc++.h>
# define NDEBUG
#include <assert.h>
#include<sys/time.h>

class matrix{
    private:
    size_t M,N;
    public:
    double *data;
    matrix(){
        data=NULL;
        M=0;
        N=0;
    }
    size_t fetchM(){
        return M;
    }
    size_t fetchN(){
        return N;
    }
    void create(size_t m,size_t n,double val){
        M=m;
        N=n;
        data = new double[M*N];
        double value=val;
        for(size_t index=0;index < M*N; ++index){
            data[index]=value;
            value+=val;
        }
    }
    void displaymatrix(){
        size_t i;
        size_t j;
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                printf("%8f ",data[i*M + j]);
            }
            printf("\n");
        }
    }
};

void matrixmulcomp(matrix &A, matrix &B, matrix &C){
    assert(A.fetchM() == B.fetchM() && B.fetchM() == C.fetchM());
    assert(A.fetchN() == B.fetchN() && B.fetchN() == C.fetchN());
    
    size_t m = A.fetchM();
    size_t n = B.fetchN();
    size_t r = A.fetchN();

    for(size_t i = 0; i < m; ++i){
        for(size_t j = 0; j < n; ++j){
            for(size_t k = 0; k < r; ++k){
                C.data[i*m+j] = C.data[i*m+j] + A.data[i*m+k] * B.data[k*m+j];
            }
        }
    }

}

#endif // !MATMUL_H