#include "../inc/matmul.h"

#ifdef PAPI
#include"papi.h"

//for handling error messages
inline void handle_error(int retval)
{
	printf("PAPI error %d: %s\n",retval, PAPI_strerror(retval));
	exit(1);
}
#endif

void matmul3(matrix &A, matrix &B, matrix &C,size_t N){
}

void Test(size_t n,size_t N){
    
}

int main(int argc, char *argv[]){
    size_t n,N;
    if(argc!=3){
        printf("Incorrect arguments passed\n");
        exit(0);
    }
    #ifdef PAPI
	int retval, EventSet=PAPI_NULL;
	long long values[4] = {(long long)0, (long long)0, (long long)0, (long long)0};

	retval = PAPI_library_init(PAPI_VER_CURRENT);
	if(retval != PAPI_VER_CURRENT)
		handle_error(retval);
	
	retval = PAPI_create_eventset(&EventSet);
	if (retval != PAPI_OK) 
		handle_error(retval);
 
	// Add event L1 Total Cache Misses 
	retval = PAPI_add_event(EventSet, PAPI_L1_TCM);
	if (retval != PAPI_OK) 
		handle_error(retval);
	
	// Add event L2 Total cache misses
	retval = PAPI_add_event(EventSet, PAPI_L2_TCM);
	if (retval != PAPI_OK) 
		handle_error(retval);

	// TOTAL cycles 
	retval = PAPI_add_event(EventSet, PAPI_TOT_CYC);
	if (retval != PAPI_OK) 
		handle_error(retval);
	
	// TOTAL instructions 
	retval = PAPI_add_event(EventSet, PAPI_TOT_INS);
	if (retval != PAPI_OK) 
		handle_error(retval);
#endif
    n=atoi(argv[1]);
    N=atoi(argv[2]);
    matrix A,B,C1,C2;
    A.create(n,n,2.0);
    B.create(n,n,3.0);
    C1.create(n,n,0.0);
    C2.create(n,n,0.0);

    assert(A.fetchM() == B.fetchM() && B.fetchM() == C1.fetchM());
    assert(A.fetchN() == B.fetchN() && B.fetchN() == C1.fetchN());

    size_t m = A.fetchM();
    size_t ni = B.fetchN();
    size_t r = A.fetchN();

    struct timeval tv_before, tv_after;
// col-wise
    gettimeofday(&tv_before, NULL);
    #ifdef PAPI
	retval = PAPI_start(EventSet);
	if (retval != PAPI_OK) handle_error(retval);
    #endif
    for(size_t U = 0; U < N; U++){
        for(size_t k=0; k < r; k++){
            for(size_t i = 0; i < m/N;i++){
                for(size_t j=0; j < ni; j++){
                    C1.data[(i + (U *  m/ N)) * m + j] += A.data[(i + (U * m / N)) * m + k] * B.data[k * m + j];
                }
            }
        }
    }
    #ifdef PAPI
	retval = PAPI_stop(EventSet, values);
	if (retval != PAPI_OK) handle_error(retval);
    #endif
    gettimeofday(&tv_after, NULL);
	printf("time(n=%zu): %ld (us)\n",n,((tv_after.tv_sec - tv_before.tv_sec)*1000000L + tv_after.tv_usec) - tv_before.tv_usec);
    #ifdef PAPI
	float ratio = values[0]/(float)(values[1]);
	printf("total L1 misses:%lld total L2 misses:%lld total instructions:%lld total cycles:%lld\n", values[0],values[1], values[3], values[2]);
    #endif
    matrixmulcomp(A,B,C2);

    for(size_t i = 0; i < A.fetchM() ; i++){
        for(size_t j = 0 ; j < B.fetchN() ; j++){
            if(C1.data[i*n + j] != C2.data[i*n + j]){
                printf("Test Error at (%zu,%zu)\n",i,j);
            }
        }
    }
    printf("Test Ok\n");
    return 0;
}