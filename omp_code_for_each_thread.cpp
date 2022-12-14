#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char * argv[]) {
    int nw= (argc == 1 ? 1 : atoi(argv[1]));
    int x = 1;

    omp_lock_t printlock;
    omp_init_lock(&printlock);

    #pragma omp parallel num_threads(nw)
    {
        auto id = omp_get_thread_num();
        
        if(id == 1){
            omp_set_lock(&printlock);
            cout << "Ciao from id " << id << endl;
            omp_unset_lock(&printlock);
        } else {
            omp_set_lock(&printlock);
            
            for (int i=0; i<4; i++)
                cout << "Ciao " ;
            
            cout << endl; 
            omp_unset_lock(&printlock);
        }
    }  
    
    return(0);
}