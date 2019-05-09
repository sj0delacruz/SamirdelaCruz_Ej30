#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;



int main(){
    ofstream outfile;
    int l_max=1, t_max=2;
    float dx=0.01,dt=0.01;
    int num_x=l_max/dx+1,num_t=t_max/dt+1;
    float epsilon=0.1,beta=epsilon*dt/dx;
    
    /*
    condiciones iniciales
    */
    double u[2][num_x];
    for(int i=0;i<num_x;i++){
        u[0][i]=sin(4*M_PI*i*dx)/2;
    }

    /*
    solucion Lax–Wendroff scheme explicit
    */
   outfile.open("dat_ec5.dat");
    for (int j=0;j<num_t;j++){
        for(int i=1;i<num_x-1;i++){
            u[1][i]=u[0][i]- (beta/4)*(pow(u[0][i+1],2)-pow(u[0][i-1],2)) +(pow(beta,2)/8)*( (u[0][i+1]+u[0][i])*(pow(u[0][i+1],2)-pow(u[0][i],2)) -(u[0][i]+u[0][i-1])*(pow(u[0][i],2)-pow(u[0][i-1],2)));
        }

        /*
        imprime linea j, t=j*dTim
        */
        for(int i=0;i<num_x;i++){
        outfile << u[0][i] << " ";
        }
        outfile << "\n";

        for(int i=1;i<num_x-1;i++){
            u[0][i]=u[1][i];
        }
        
    }

    return 0;
}

