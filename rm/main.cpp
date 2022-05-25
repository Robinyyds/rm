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
                cout << "�췽��" << endl;
                if(RedFlag==0){
                    cout<<"û��¼��췽��Ϣ"<<endl;
                }else if(RedCar.empty()==1){
                    cout<<"û�б��ִ��"<<endl;
                }else {
                    for (itRed = RedCar.begin(); itRed != RedCar.end(); itRed++) {
                        if(itRed->second.kind=="G")
                            cout << "�췽" << itRed->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itRed->second.kind)
                                 << "   Ѫ����"
                                 << itRed->second.blood << "    ��������Ϣ" << endl;
                        else
                            cout << "�췽" << itRed->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itRed->second.kind)
                             << "   Ѫ����"
                             << itRed->second.blood << "   ������" << itRed->second.heat << "(��������Ϊ��"
                             << itRed->second.heat_max << ")" << endl;
                    }
                }
                    cout << "������" << endl;
                if(BlueFlag==0){
                    cout<<"û��¼��������Ϣ"<<endl;
                }
                else if(BlueCar.empty()==1){
                     cout<<"û�б��ִ��"<<endl;
                }else {
                    for (itBlue = BlueCar.begin(); itBlue != BlueCar.end(); itBlue++) {
                        if(itBlue->second.kind=="G")
                            cout << "����" << itBlue->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itBlue->second.kind)
                                 << "   Ѫ����"
                                 << itBlue->second.blood << "    ��������Ϣ" << endl;
                        else
                            cout << "����" << itBlue->first << "�Ż�����   ���ࣺ" << RobotCar.ChangeName(itBlue->second.kind)
                             << "   Ѫ����"
                             << itBlue->second.blood << "   ������" << itBlue->second.heat << "(��������Ϊ��"
                             << itBlue->second.heat_max << ")" << endl;

                    }
                }
                cout<<"���������"<<endl;
                for(RedDeath = RedDied.begin();RedFlag==1&&RedDeath != RedDied.end();RedDeath++){
                    if(RedDied[RedDeath->first].flag>=2)
                        cout << "�췽" << RedDeath->first << "�Ż���������     ����:" << RedDeath->second.reason << endl;
                }
                for(BlueDeath = BlueDied.begin();BlueFlag==1&&BlueDeath != BlueDied.end();BlueDeath++){
                    if(BlueDied[BlueDeath->first].flag>=2)
                        cout << "����" << BlueDeath->first << "�Ż���������     ����:" << BlueDeath->second.reason << endl;
                }
            return 0;
            }else {
            cout<<"û�и���ָ�����������!!��"<<endl;
        }
        }
}