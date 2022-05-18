#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Car{
public:
    int check_red_number(){
        int number_r;
        number_r=Red_Blood.size();
        return number_r;
    }
    int check_blue_number(){
        int number_b;
        number_b=Blue_Blood.size();
        return number_b;
    }
    void Red_Blood_init(char x,int k){
        if(x=='B')
            Red_Blood.push_back(100);
        else if(x=='S')
            Red_Blood.push_back(200);
        else if(x=='Y')
            Red_Blood.push_back(200);
        else if(x=='G')
            Red_Blood.push_back(200);
    }
    void Red_Heat17_init(char x,int k){
        if(x=='B')
            Red_Heat17.push_back(200);
        else if(x=='S')
            Red_Heat17.push_back(300);
        else if(x=='Y')
            Red_Heat17.push_back(0);
        else if(x=='G')
            Red_Heat17.push_back(0);
    }

    void Red_Heat42_init(char x,int k){
        if(x=='B')
            Red_Heat42.push_back(0);
        else if(x=='S')
            Red_Heat42.push_back(0);
        else if(x=='Y')
            Red_Heat42.push_back(300);
        else if(x=='G')
            Red_Heat42.push_back(0);
    }
    void Blue_Blood_init(char x,int k){
        if(x=='B')
            Blue_Blood.push_back(100);
        else if(x=='S')
            Blue_Blood.push_back(200);
        else if(x=='Y')
            Blue_Blood.push_back(200);
        else if(x=='G')
            Blue_Blood.push_back(200);
    }
    void Blue_Heat17_init(char x,int k){
        if(x=='B')
            Blue_Heat17.push_back(200);
        else if(x=='S')
            Blue_Heat17.push_back(300);
        else if(x=='Y')
            Blue_Heat17.push_back(0);
        else if(x=='G')
            Blue_Heat17.push_back(0);
    }

    void Blue_Heat42_init(char x,int k){
        if(x=='B')
            Blue_Heat42.push_back(0);
        else if(x=='S')
            Blue_Heat42.push_back(0);
        else if(x=='Y')
            Blue_Heat42.push_back(300);
        else if(x=='G')
            Blue_Heat42.push_back(0);
    }
//private:
    vector<int>Red_Blood;
    vector<int>Red_Heat17;
    vector<int>Red_Heat42;
    vector<int>Blue_Blood;
    vector<int>Blue_Heat17;
    vector<int>Blue_Heat42;
};

int main() {
    char a[20], cnt;
    vector<char> red_ca;
    vector<char> blue_ca;
    Car myCar;
    int t = 0;
    char teamNumber, carNumber;
    int number;
    while (t != 1) {
        cin.getline(a, 20);
        if (a[0] != 'E') {
            if (a[0] == 'A') {                           //命令字判断
                teamNumber = a[2];
                carNumber = a[4];
                number = atoi(&a[6]);
                if (teamNumber == 'R') {
                    red_ca.push_back(carNumber);
                   myCar.Red_Blood_init(carNumber, number);
                    myCar.Red_Heat17_init(carNumber, number);
                    myCar.Red_Heat42_init(carNumber, number);
                } else if (teamNumber == 'B') {
                    blue_ca.push_back(carNumber);
                    myCar.Blue_Blood_init(carNumber, number);
                    myCar.Blue_Heat17_init(carNumber, number);
                    myCar.Blue_Heat42_init(carNumber, number);
                }
            }
        }else {
            t = 1;
        }
    }
    cout<<"Team : Red"<<endl;
    for (int tmp = 0; tmp < myCar.check_red_number();tmp++){
        cout<<"The car:"<< red_ca[tmp]<<"   Blood:"<<myCar.Red_Blood[tmp]<<"  17mm:"<<myCar.Red_Heat17[tmp]<<"  42mm:"<<myCar.Red_Heat42[tmp]<<endl;
    }
    cout<<"Team : Blue"<<endl;
    for (int tmp = 0; tmp < myCar.check_blue_number();tmp++){
        cout<<"The car:"<< blue_ca[tmp]<<"  Blood:"<<myCar.Blue_Blood[tmp]<<"  17mm:"<<myCar.Blue_Heat17[tmp]<<"  42mm:"<<myCar.Blue_Heat42[tmp]<<endl;
    }

    return 0;

}
