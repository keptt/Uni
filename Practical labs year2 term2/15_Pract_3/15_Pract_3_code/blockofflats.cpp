#include "blockofflats.h"

BlockOfFlats::BlockOfFlats(const std::string & addressC, double sC, const std::string & purposeC,
                           unsigned int numOfFlatsC) : Building(addressC, sC, purposeC){
    numOfFlats = numOfFlatsC;
}

BlockOfFlats::BlockOfFlats():Building (){
    numOfFlats = 0;
}

unsigned int BlockOfFlats::getNumOfFlats() const{
    return numOfFlats;
}

void BlockOfFlats::print(){
    using namespace std;
    cout << "__________________________\n";
    cout << "BlockOfFlats class\n";
    Building::print();
    cout << "K-vo kvartir: " << numOfFlats << endl;
    cout << "__________________________\n\n";
}
