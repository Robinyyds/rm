#include<iostream>
#include <vector>
#include <map>
using namespace std;
class Car{
public:
    int blood;
    int heat_max;
    int heat;
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
            return "����";
        }else if(name=="S"){
            return "�ڱ�";
        }else if(name=="Y"){
            return "Ӣ��";
        }else if(name=="G"){
            return "����";
        }
    return " ";
    }
};
class DiedReason{
public:
    string reason;
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
                RedCar[CarNum].kind = CarKind;
                RedCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                RedCar[CarNum].heat_max=RobotCar.HeatCheck(CarKind);
                RedCar[CarNum].heat= 0;
            } else if (CarTeam == "B") {
                BlueCar[CarNum].kind = CarKind;
                BlueCar[CarNum].blood = RobotCar.BloodCheck(CarKind);
                BlueCar[CarNum].heat_max=RobotCar.HeatCheck(CarKind);
                BlueCar[CarNum].heat= 0;
            }
        } else if (CarCommand == "F") {
            cin >> CarTeam >> CarNum >> CarHurt;
            if (CarTeam == "R") {
                RedCar[CarNum].blood -= CarHurt;
                if (RedCar[CarNum].blood <= 0) {
                    RedDied[CarNum].reason = "blood";
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
            cin >> CarTeam >> CarNum >> CarHeat;
            if (CarTeam == "R") {
                if(RedCar[CarNum].kind=="Y")
                    RedCar[CarNum].heat += CarHeat*30;
                else
                    RedCar[CarNum].heat += CarHeat*15;
                if (RedCar[CarNum].heat >=RedCar[CarNum].heat_max) {
                    RedDied[CarNum].reason = "heat";
                    RedCar.erase(CarNum);
                }
            } else if (CarTeam == "B") {
                if(BlueCar[CarNum].kind=="Y")
                    BlueCar[CarNum].heat += CarHeat*30;
                else
                    BlueCar[CarNum].heat += CarHeat*15;
                if (BlueCar[CarNum].heat >=BlueCar[CarNum].heat_max) {
                    BlueDied[CarNum].reason = "heat";
                    BlueCar.erase(CarNum);
                }
            }
            } else if (CarCommand == "END") {
                map<int, Car>::iterator itRed, itBlue;
                map<int, DiedReason>::iterator  RedDeath,BlueDeath;
                cout << "�췽��" << endl;
                if(RedCar.size()==0){
                    cout<<"û�б��ִ��"<<endl;
                }else {
                    for (itRed = RedCar.begin(); itRed != RedCar.end(); itRed++) {
                        cout << "�췽" << itRed->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itRed->second.kind)
                             << "   Ѫ����"
                             << itRed->second.blood << "   ������" << itRed->second.heat << "(��������Ϊ��"
                             << itRed->second.heat_max << ")" << endl;
                    }
                }
                    cout << "������" << endl;
                if(BlueCar.size()==0){
                     cout<<"û�б��ִ��"<<endl;
                }else {
                    for (itBlue = BlueCar.begin(); itBlue != BlueCar.end(); itBlue++) {
                        cout << "����" << itBlue->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itBlue->second.kind)
                             << "   Ѫ����"
                             << itBlue->second.blood << "   ������" << itBlue->second.heat << "(��������Ϊ��"
                             << itBlue->second.heat_max << ")" << endl;

                    }
                }
                cout<<"���������"<<endl;
                for(RedDeath = RedDied.begin();RedDeath != RedDied.end();RedDeath++){
                        cout<<"�췽"<<RedDeath->first<<"�Ż���������     ����:"<<RedDeath->second.reason<<endl;
                }
                for(BlueDeath = BlueDied.begin();BlueDeath != BlueDied.end();BlueDeath++){
                        cout<<"����"<<BlueDeath->first<<"�Ż���������     ����:"<<BlueDeath->second.reason<<endl;
                }
            return 0;
            }
        }
}