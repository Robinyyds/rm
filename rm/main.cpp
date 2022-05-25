#include<iostream>
#include <vector>
#include <map>
using namespace std;
class Car{
public:
    int blood=0;
    int heat_max=0;
    int heat=0;
    string team;
    string kind;
    int BloodCheck(string CarKind){
        if(CarKind=="B"){
            return 100;
        }else if(CarKind=="S"){
            return 200;
        }else if(CarKind=="Y"){
            return 200;
        }else if(CarKind=="G"){
            return 200;
        }
        return -1;
    }
    int HeatCheck(string CarKind){
        if(CarKind=="B"){
            return 200;
        }else if(CarKind=="S"){
            return 300;
        }else if(CarKind=="Y"){
            return 300;
        }else if(CarKind=="G"){
            return 0;
        }
      return -1;
    }
    string ChangeName(string name){
        if(name=="B"){
            return "步兵";
        }else if(name=="S"){
            return "哨兵";
        }else if(name=="Y"){
            return "英雄";
        }else if(name=="G"){
            return "工程";
        }
    return " ";
    }
};
class DiedReason{
public:
    string reason;
    int flag=0;
};
int ErrorCheck(){

}
int main() {
    string CarTeam;
    string CarKind;
    int CarNum;
    int CarHurt;
    int CarHeat;
    Car RobotCar;
    string CarCommand;
    int RedFlag=0,BlueFlag=0;
    map<int, Car> RedCar, BlueCar;
    map<int, DiedReason> RedDied, BlueDied;
    RedDied.clear();
    BlueDied.clear();
    while (1) {
        cin >> CarCommand;
        if (CarCommand == "A") {
            cin >> CarTeam >> CarKind >> CarNum;
            if (CarTeam == "R") {
                RedFlag=1;
                RedCar[CarNum].kind = CarKind;
                RedCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                RedCar[CarNum].heat_max=RobotCar.HeatCheck(CarKind);
                RedDied[CarNum].flag++;
                RedCar[CarNum].heat= 0;
            } else if (CarTeam == "B") {
                BlueFlag=1;
                BlueCar[CarNum].kind = CarKind;
                BlueCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                BlueCar[CarNum].heat_max=RobotCar.HeatCheck(CarKind);
                BlueDied[CarNum].flag++;
                BlueCar[CarNum].heat= 0;
            }
        } else if (CarCommand == "F") {
            cin >> CarTeam >> CarNum >> CarHurt;
            if (CarTeam == "R") {
                RedCar[CarNum].blood -= CarHurt;
                if (RedCar[CarNum].blood <= 0) {
                    RedDied[CarNum].reason = "blood";
                    RedDied[CarNum].flag++;
                    RedCar.erase(CarNum);
                }
            } else if (CarTeam == "B") {
                BlueCar[CarNum].blood -= CarHurt;
                if (BlueCar[CarNum].blood <= 0) {
                    BlueDied[CarNum].reason = "blood";
                    BlueDied[CarNum].flag++;
                    BlueCar.erase(CarNum);
                }
            }
            } else if (CarCommand == "H") {
            cin >> CarTeam >> CarNum >> CarHeat;
            if (CarTeam == "R") {
                if(RedCar[CarNum].kind=="Y")
                    RedCar[CarNum].heat += CarHeat*30;
                else if(RedCar[CarNum].kind=="G")
                    RedCar[CarNum].heat =-1;
                else
                    RedCar[CarNum].heat += CarHeat*15;
                if (RedCar[CarNum].heat >=RedCar[CarNum].heat_max) {
                    RedDied[CarNum].reason = "heat";
                    RedDied[CarNum].flag++;
                    RedCar.erase(CarNum);
                }
            } else if (CarTeam == "B") {

                if(BlueCar[CarNum].kind=="Y")
                    BlueCar[CarNum].heat += CarHeat*30;
                else if(BlueCar[CarNum].kind=="G")
                    BlueCar[CarNum].heat =-1;
                else
                    BlueCar[CarNum].heat += CarHeat*15;


                if (BlueCar[CarNum].heat >=BlueCar[CarNum].heat_max) {
                    BlueDied[CarNum].reason = "heat";
                    BlueDied[CarNum].flag++;
                    BlueCar.erase(CarNum);
                }
            }
            } else if (CarCommand == "END"||CarCommand == "End"||CarCommand == "end") {
                map<int, Car>::iterator itRed, itBlue;
                map<int, DiedReason>::iterator  RedDeath,BlueDeath;
                cout << "红方存活：" << endl;
                if(RedFlag==0){
                    cout<<"没有录入红方信息"<<endl;
                }else if(RedCar.empty()==1){
                    cout<<"没有兵种存活"<<endl;
                }else {
                    for (itRed = RedCar.begin(); itRed != RedCar.end(); itRed++) {
                        if(itRed->second.kind=="G")
                            cout << "红方" << itRed->first << "号机器人   种类：" << RobotCar.ChangeName(itRed->second.kind)
                                 << "   血量："
                                 << itRed->second.blood << "    无热量信息" << endl;
                        else
                            cout << "红方" << itRed->first << "号机器人   种类：" << RobotCar.ChangeName(itRed->second.kind)
                             << "   血量："
                             << itRed->second.blood << "   热量：" << itRed->second.heat << "(热量上限为："
                             << itRed->second.heat_max << ")" << endl;
                    }
                }
                    cout << "蓝方存活：" << endl;
                if(BlueFlag==0){
                    cout<<"没有录入蓝方信息"<<endl;
                }
                else if(BlueCar.empty()==1){
                     cout<<"没有兵种存活"<<endl;
                }else {
                    for (itBlue = BlueCar.begin(); itBlue != BlueCar.end(); itBlue++) {
                        if(itBlue->second.kind=="G")
                            cout << "蓝方" << itBlue->first << "号机器人   种类：" << RobotCar.ChangeName(itBlue->second.kind)
                                 << "   血量："
                                 << itBlue->second.blood << "    无热量信息" << endl;
                        else
                            cout << "蓝方" << itBlue->first << "号机器人   种类：" << RobotCar.ChangeName(itBlue->second.kind)
                             << "   血量："
                             << itBlue->second.blood << "   热量：" << itBlue->second.heat << "(热量上限为："
                             << itBlue->second.heat_max << ")" << endl;

                    }
                }
                cout<<"阵亡情况："<<endl;
                for(RedDeath = RedDied.begin();RedFlag==1&&RedDeath != RedDied.end();RedDeath++){
                    if(RedDied[RedDeath->first].flag>=2)
                        cout << "红方" << RedDeath->first << "号机器人死亡     死因:" << RedDeath->second.reason << endl;
                }
                for(BlueDeath = BlueDied.begin();BlueFlag==1&&BlueDeath != BlueDied.end();BlueDeath++){
                    if(BlueDied[BlueDeath->first].flag>=2)
                        cout << "蓝方" << BlueDeath->first << "号机器人死亡     死因:" << BlueDeath->second.reason << endl;
                }
            return 0;
            }else {
            cout<<"没有该项指令，请重新输入!!！"<<endl;
        }
        }
}