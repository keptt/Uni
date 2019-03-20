#include "storage.h"

Storage::Storage(const std::string& addressC, double sC, const std::string& purposeC, const std::string &conditionsOfStoringC):
    Building(addressC, sC, purposeC){
    conditionsOfStoring = conditionsOfStoringC;
}

Storage::Storage():Building (){
    conditionsOfStoring = "";
}

std::string Storage::getConditionsOfStoring() const{
    return conditionsOfStoring;
}

void Storage::print(){
    using namespace std;
    cout << "__________________________\n";
    cout << "Storage class\n";
    Building::print();
    cout << "Usloviya: " << conditionsOfStoring << endl;
    cout << "__________________________\n\n";
}
