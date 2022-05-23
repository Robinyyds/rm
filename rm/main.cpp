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
            return "����";
        }else if(name=="S"){
            return "�ڱ�";
        }else if(name=="Y"){
            return "Ӣ��";
        }else if(name=="G"){
            return "����";
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
                cout << "�췽��" << endl;
                for (itRed = RedCar.begin(); itRed != RedCar.end(); itRed++) {
                    if (itRed->second.kind == "Y")
                        cout << "�췽" << itRed->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itRed->second.kind) << "   Ѫ����"
                             << itRed->second.blood << "   ������" << itRed->second.heat_42 << endl;
                    else
                        cout << "�췽" << itRed->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itRed->second.kind) << "   Ѫ����"
                             << itRed->second.blood << "   ������" << itRed->second.heat_17 << endl;
                }
                    cout << "������" << endl;
                for (itBlue = BlueCar.begin(); itBlue != BlueCar.end(); itBlue++) {
                        if (itBlue->second.kind == "Y")
                            cout << "����" << itBlue->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itBlue->second.kind) << "   Ѫ����"
                                 << itBlue->second.blood << "   ������" << itBlue->second.heat_42 << endl;
                        else
                            cout << "����" << itBlue->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itBlue->second.kind) << "   Ѫ����"
                                 << itBlue->second.blood << "   ������" << itBlue->second.heat_17 << endl;
                }
                cout<<"���������"<<endl;
                for(RedDeath = RedDied.begin();RedDeath != RedDied.end();RedDeath++){
                    cout<<"�췽"<<RedDeath->first<<"�Ż���������     ����:"<<RedDeath->second.reason<<endl;
                }
                for(RedDeath = RedDied.begin();RedDeath != RedDied.end();RedDeath++){
                cout<<"����"<<BlueDeath->first<<"�Ż���������     ����:"<<RedDeath->second.reason<<endl;
                }
            return 0;
            }
        }
}