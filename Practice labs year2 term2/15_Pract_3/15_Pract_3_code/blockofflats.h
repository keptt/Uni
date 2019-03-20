#ifndef BLOCKOFFLATS_H
#define BLOCKOFFLATS_H
#include "building.h"
//class Building;

class BlockOfFlats : public Building{
private:
    unsigned int numOfFlats;
public:
    BlockOfFlats(const std::string&, double, const std::string&, unsigned int);
    BlockOfFlats();
    unsigned int getNumOfFlats() const;

    void print();
};

#endif // BLOCKOFFLATS_H
