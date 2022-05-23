
#include<iostream>
#include<iomanip>
#include <vector>
#include <map>
using namespace std;

//char TheName[4][20]={"infantry","guard","hero","engineer"};
class Car{
public:
    int blood;
    int heat_17;
    int heat_42;
    string team;
    string kind;

};
int BloodCheck(string CarKind){
    if(CarKind=="infantry"){
        return 100;
    }else if(CarKind=="guard"){
        return 200;
    }else if(CarKind=="hero"){
        return 200;
    }else if(CarKind=="engineer"){
        return 200;
    }
}
int Heat17Check(string CarKind){
    if(CarKind=="infantry"){
        return 200;
    }else if(CarKind=="guard"){
        return 300;
    }else if(CarKind=="hero"){
        return -1;
    }else if(CarKind=="engineer"){
        return -1;
    }
}
int Heat42Check(string CarKind){
    if(CarKind=="infantry"){
        return -1;
    }else if(CarKind=="guard"){
        return -1;
    }else if(CarKind=="hero"){
        return 300;
    }else if(CarKind=="engineer"){
        return -1;
    }
}
int main() {
    string CarTeam;
    string CarKind;
    int CarNum;
    int CarHurt;
    int CarHeat;
    string CarCommand;
    map<int,Car> RedCar,BlueCar;
    while (1) {
        if(CarCommand=="A"){
            cin >>CarTeam>>CarKind>>CarNum;
            if(CarTeam=="R"){
                RedCar[CarNum].kind=CarKind;
                RedCar[CarNum].blood=BloodCheck(CarKind);
                RedCar[CarNum].heat_17=Heat17Check(CarKind);
                RedCar[CarNum].heat_42= Heat42Check(CarKind);
            }
        }else if(CarCommand=="F"){

        }else if(CarCommand=="H"){

        }else if(CarCommand=="End"){

        }

    }
}