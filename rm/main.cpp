#include<iostream>
#include<iomanip>
#include <vector>
#include <map>
using namespace std;
class Car{
public:
    int blood;
    int heat_17;
    int heat_42;
    string team;
    string kind;
    int number;
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
    }
    int Heat17Check(string CarKind){
        if(CarKind=="B"){
            return 200;
        }else if(CarKind=="S"){
            return 300;
        }else if(CarKind=="Y"){
            return -1;
        }else if(CarKind=="G"){
            return -1;
        }
    }
    int Heat42Check(string CarKind){
        if(CarKind=="B"){
            return -1;
        }else if(CarKind=="S"){
            return -1;
        }else if(CarKind=="Y"){
            return 300;
        }else if(CarKind=="G"){
            return -1;
        }
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
    }
};
class DiedReason{
public:
    string reason;
    int CarNum;
};
int main() {
    string CarTeam;
    string CarKind;
    int CarNum;
    int CarHurt;
    int CarHeat;
    Car RobotCar;
    string CarCommand;
    map<int, Car> RedCar, BlueCar;
    map<int, DiedReason> RedDied, BlueDied;
    while (1) {
        cin >> CarCommand;
        if (CarCommand == "A") {
            cin >> CarTeam >> CarKind >> CarNum;
            if (CarTeam == "R") {
                RedCar[CarNum].number = CarNum;
                RedCar[CarNum].kind = CarKind;
                RedCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                RedCar[CarNum].heat_17 = RobotCar.Heat17Check(CarKind);
                RedCar[CarNum].heat_42 = RobotCar.Heat42Check(CarKind);
            } else if (CarTeam == "B") {
                BlueCar[CarNum].number = CarNum;
                BlueCar[CarNum].kind = CarKind;
                BlueCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                BlueCar[CarNum].heat_17 = RobotCar.Heat17Check(CarKind);
                BlueCar[CarNum].heat_42 = RobotCar.Heat42Check(CarKind);
            }
        } else if (CarCommand == "F") {
            cin >> CarTeam >> CarNum >> CarHurt;
            if (CarTeam == "R") {
                RedCar[CarNum].blood -= CarHurt;
                if (RedCar[CarNum].blood <= 0) {
                    RedDied[CarNum].reason = "blood";
                    RedDied[CarNum].CarNum = CarNum;
                    RedCar.erase(CarNum);
                }
            } else if (CarTeam == "B") {
                BlueCar[CarNum].blood -= CarHurt;
                if (BlueCar[CarNum].blood <= 0) {
                    BlueDied[CarNum].reason = "blood";
                    BlueCar.erase(CarNum);
                }
            }
            } else if (CarCommand == "H") {
                
            } else if (CarCommand == "END") {
                map<int, Car>::iterator itRed, itBlue;
                map<int, DiedReason>::iterator  RedDeath,BlueDeath;
                cout << "红方存活：" << endl;
                for (itRed = RedCar.begin(); itRed != RedCar.end(); itRed++) {
                    if (itRed->second.kind == "Y")
                        cout << "红方" << itRed->first << "号机器人   种类：" << RobotCar.ChangeName(itRed->second.kind) << "   血量："
                             << itRed->second.blood << "   热量：" << itRed->second.heat_42 << endl;
                    else
                        cout << "红方" << itRed->first << "号机器人   种类：" << RobotCar.ChangeName(itRed->second.kind) << "   血量："
                             << itRed->second.blood << "   热量：" << itRed->second.heat_17 << endl;
                }
                    cout << "蓝方存活：" << endl;
                for (itBlue = BlueCar.begin(); itBlue != BlueCar.end(); itBlue++) {
                        if (itBlue->second.kind == "Y")
                            cout << "蓝方" << itBlue->first << "号机器人   种类：" << RobotCar.ChangeName(itBlue->second.kind) << "   血量："
                                 << itBlue->second.blood << "   热量：" << itBlue->second.heat_42 << endl;
                        else
                            cout << "蓝方" << itBlue->first << "号机器人   种类：" << RobotCar.ChangeName(itBlue->second.kind) << "   血量："
                                 << itBlue->second.blood << "   热量：" << itBlue->second.heat_17 << endl;
                }
                cout<<"伤亡情况："<<endl;
                for(RedDeath = RedDied.begin();RedDeath != RedDied.end();RedDeath++){
                    cout<<"红方"<<RedDeath->first<<"号机器人死亡     死因:"<<RedDeath->second.reason<<endl;
                }
                for(RedDeath = RedDied.begin();RedDeath != RedDied.end();RedDeath++){
                cout<<"蓝方"<<BlueDeath->first<<"号机器人死亡     死因:"<<RedDeath->second.reason<<endl;
                }
            return 0;
            }
        }
}