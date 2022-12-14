#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char * argv[]) {
    
    if(argc!=1){
        auto nw = atoi(argv[1]) ;

        #pragma omp parallel num_threads(nw)
        {
            #pragma omp critical
            {
                cout << "This is thread" << omp_get_thread_num() << " of" 
                << omp_get_num_threads() << endl;
            }
        }
    }
    else{
        #pragma omp parallel 
        {
            #pragma omp critical
            {
                cout << "This is thread" << omp_get_thread_num() << " of" 
                << omp_get_num_threads() << endl;
            }
        }
    }

    return 0;
}