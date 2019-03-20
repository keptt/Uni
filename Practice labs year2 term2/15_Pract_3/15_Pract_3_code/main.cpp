#include <iostream>
#include "building.h"
#include "storage.h"
#include "blockofflats.h"

using namespace std;

#include <string.h>

void input(std::string &address, double &s, std::string &purpose){
    cout << "VVedite adressu: ";
    getline(cin, address);
    //while((getchar()) != '\n');
    cout << "VVedite s: ";
    cin >> s;
    while((getchar()) != '\n');
    cout << "VVedite cil' budivli: ";
    getline(cin, purpose);
    //while((getchar()) != '\n');
}

void inputBlockOfFlats(std::string &address, double &s, std::string &purpose, unsigned int &numFlats){
    input(address, s, purpose);
    cout << "VVedite k-st' kvartir: ";
    cin >> numFlats;
    while((getchar()) != '\n');
}

void inputStorage(std::string &address, double &s, std::string &purpose, std::string &conditions){
    input(address, s, purpose);
    cout << "VVedite usloviya hraneniya: ";
    getline(cin, conditions);
}

int main(){
    std::string address, purpose, conditions;
    double s;
    unsigned int numFlats;

    Building *general_obj;

    inputBlockOfFlats(address, s, purpose, numFlats);

    BlockOfFlats obj1(address, s, purpose, numFlats);

    inputStorage(address, s, purpose, conditions);

    Storage obj2(address, s, purpose, conditions);

    general_obj = &obj1;
    general_obj->print();

    general_obj = &obj2;
    general_obj->print();

    return 0;
}
