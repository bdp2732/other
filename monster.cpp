#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double pi = 3.141592;
    double width =2;
    double height= 2;
    double vel;
    double angle;
    double ball_h;
    double ball_r;
    double i;
    double g = -9.8;
    int a =0;
    while(1){
        cout << "초기 속도 :";
3        cin >> vel;
        cout << "angle:";
        cin >> angle;
        cout << "진행 시간";
        cin >> a;
        for(i=0; i<=a; i+=0.1 ){
            ball_h = i*vel*cos(angle*pi/180);
            ball_r = i*vel*sin(angle*pi/180)-(1/2)*g*i*i;
            if(ball_h<=0){
                continue;
            } else if (ball_h<0){
                ball_h=0;
                continue;
            }
        }

        if(ball_h<=width && ball_r<=height){
            cout<<"괴물을 쓰러뜨렸습니다"<<endl;
            break;
        } else{
            cout<<"다시 던져보세요" << endl;
        }
    }
    return 0;
}
