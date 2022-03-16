#include<iostream>
#include <fstream>
#include<time.h>
#include<cmath>


double f_rand(void);//0~-1까지 random인 함수 생성

double k = 8617343E-11;
double T = 0.00001;
int nmax1 =100000;
int nmax2 =100;
int Linka=0;  //Link spin, Link1은 spin1의 Link를 의미한다.
int Linkb=0;
int Link1a=0;
int Link1b=0;
int Link=0;
int Link1=0;
int dE=0;
int main(){
    srand((unsigned int)time(NULL));
    int spin[100] [100] = {};
    int spin1[100] [100] = {};
    for(int i=0;i<nmax2;++i) {
        for (int j = 0; j < nmax2; ++j) {
            spin1[i][j] = 1;
            spin[i][j] =  1;//스핀 배열 생성 -1은 up spin 1은 down spin을 의미함.
        }
    }

    double dEa;
    for(int i=0;i<nmax1;++i){
        int a = f_rand()*100;
        int b = f_rand()*100;
        spin1[a][b]=spin[a][b]*-1;
        for(int j=0;j<nmax2-1;++j) {
            for (int k = 0; k < nmax2-1; ++k) {
                Linka+=spin[j][k]+spin[j][k+1];
                Linkb+=spin[j][k]+spin[j+1][k];
                Link1a+=spin1[j][k]+spin1[j][k+1];
                Link1b+=spin1[j][k]+spin1[j+1][k];
            }
        }
        Link=(Linka+Linkb)*-1;
        Link1=(Link1a+Link1b)*-1;
        dE=Link1-Link;
        if (dE <= 0 or f_rand() <= exp(-dE / (k*T))){
            spin[a][b] = spin1[a][b];
        }
        else{
            spin1[a][b]=spin[a][b];

        }
        Link=0;
        Link1=0;
        Linka=0;
        Linkb=0;
        Link1a=0;
        Link1b=0;
    }

    return 0;
}

double f_rand(void)
{
    double a;
    a = rand() / (double) RAND_MAX;
    return a;
}
