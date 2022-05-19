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
        Red_Blood.resize(100);
        if(x=='B') {
            Red_Blood[k] = 100;
        }
        else if(x=='S')
            Red_Blood[k]=200;
        else if(x=='Y')
            Red_Blood[k]=200;
        else if(x=='G')
            Red_Blood[k]=200;
    }
    void Red_Heat17_init(char x,int k){
        Red_Heat17.resize(100);
        if(x=='B')
            Red_Heat17[k]=200;
        else if(x=='S')
            Red_Heat17[k]=300;
        else if(x=='Y')
            Red_Heat17[k]=0;
        else if(x=='G')
            Red_Heat17[k]=0;
    }

    void Red_Heat42_init(char x,int k){
        Red_Heat42.resize(100);
        if(x=='B')
            Red_Heat42[k]=0;
        else if(x=='S')
            Red_Heat42[k]=0;
        else if(x=='Y')
            Red_Heat42[k]=300;
        else if(x=='G')
            Red_Heat42[k]=0;
    }
    void Blue_Blood_init(char x,int k){
        Blue_Blood.resize(100);
        if(x=='B')
            Blue_Blood[k]=100;
        else if(x=='S')
            Blue_Blood[k]=200;
        else if(x=='Y')
            Blue_Blood[k]=200;
        else if(x=='G')
            Blue_Blood[k]=200;
    }
    void Blue_Heat17_init(char x,int k){
        Blue_Heat17.resize(100);
        if(x=='B')
            Blue_Heat17[k]=200;
        else if(x=='S')
            Blue_Heat17[k]=300;
        else if(x=='Y')
            Blue_Heat17[k]=0;
        else if(x=='G')
            Blue_Heat17[k]=0;
    }

    void Blue_Heat42_init(char x,int k){
        Blue_Heat42.resize(100);
        if(x=='B')
            Blue_Heat42[k]=0;
        else if(x=='S')
            Blue_Heat42[k]=0;
        else if(x=='Y')
            Blue_Heat42[k]=300;
        else if(x=='G')
            Blue_Heat42[k]=0;
    }
//private:
    vector<int> Red_Blood;

    vector<int> Red_Heat17;
    vector<int> Red_Heat42;
    vector<int> Blue_Blood;
    vector<int> Blue_Heat17;
    vector<int> Blue_Heat42;
};

int main() {
    char a[20], cnt;

    vector<char> red_ca(100);
    vector<char> blue_ca(100);
    Car myCar;
    int t = 0;
    int red_count=-1;
    int blue_count=-1;
    int red_temp[1000]={0};
    int blue_temp[1000]={0};
    char teamNumber, carNumber;
    int number,damage,s,shoot;
    while (t != 1) {
        cin.getline(a, 20);


        if (a[0] != 'E') {
            if (a[0] == 'A') {                           //命令字判断
                teamNumber = a[2];
                carNumber = a[4];
                number = atoi(&a[6]);

                if (teamNumber == 'R') {
                    red_count++;
                    red_temp[red_count]=number;
                    red_ca[number]=carNumber;

                   myCar.Red_Blood_init(carNumber, number);
                    myCar.Red_Heat17_init(carNumber, number);
                    myCar.Red_Heat42_init(carNumber, number);

                } else if (teamNumber == 'B') {
                    blue_count++;
                    blue_temp[blue_count]=number;
                    blue_ca[number]=carNumber;
                    //blue_ca.push_back(carNumber);
                    myCar.Blue_Blood_init(carNumber, number);
                    myCar.Blue_Heat17_init(carNumber, number);
                    myCar.Blue_Heat42_init(carNumber, number);
                }
            }else if(a[0] == 'F'){
                teamNumber = a[2];
                number = atoi(&a[4]);
                for(s=4;a[s]!=' ';s++);
                damage=atoi(&a[s]);
                if (teamNumber == 'R') {
                    myCar.Red_Blood[number]-=damage;
                } else if (teamNumber == 'B') {
                    myCar.Blue_Blood[number]-=damage;
                }
            }else if(a[0] == 'H'){
                teamNumber = a[2];
                number = atoi(&a[4]);
                for(s=4;a[s]!=' ';s++);
                shoot=atoi(&a[s]);
                if (teamNumber == 'R') {
                    if(red_ca[number]=='Y')
                        myCar.Red_Heat42[number]-=30*shoot;
                    else if(red_ca[number]=='B'||red_ca[number]=='S')
                        myCar.Red_Heat17[number]-=15*shoot;
                } else if (teamNumber == 'B') {
                    if(blue_ca[number]=='Y')
                        myCar.Blue_Heat42[number]-=30*shoot;
                    else if(blue_ca[number]=='B'||blue_ca[number]=='S')
                        myCar.Blue_Heat17[number]-=15*shoot;
                }
            }
        }else {
            t = 1;
        }
    }
    cout<<"Team : Red"<<endl;
    for (int tmp = 0; red_temp[tmp]!=0;tmp++){
        cout<<"The car:"<< red_ca[red_temp[tmp]]<<"   Blood:"<<myCar.Red_Blood[red_temp[tmp]]<<"  17mm:"<<myCar.Red_Heat17[red_temp[tmp]]<<"  42mm:"<<myCar.Red_Heat42[red_temp[tmp]]<<endl;
    }
    cout<<"Team : Blue"<<endl;
    for (int tmp = 0;blue_temp[tmp]!=0;tmp++){
        cout<<"The car:"<< blue_ca[blue_temp[tmp]]<<"  Blood:"<<myCar.Blue_Blood[blue_temp[tmp]]<<"  17mm:"<<myCar.Blue_Heat17[blue_temp[tmp]]<<"  42mm:"<<myCar.Blue_Heat42[blue_temp[tmp]]<<endl;
    }

    return 0;

}
