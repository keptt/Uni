#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
//#include <ofstream>
#include <fstream>
#include "deque.h"
#include "writetofile.h"
#include "readfromfile.h"

using namespace testing;

TEST(Test, TestingDeque)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(TestEmpty, TestingDeque)
{
    Deque d;

    EXPECT_EQ((int)0, d.size());
}

TEST(TestingContainer, testAddingDelitingElement)
{
    Deque d;
    unsigned int workersQuantity = 345;
    unsigned int clientsQuantity = 435;
    unsigned int branchesQuantity = 45;
    unsigned int statMoneyCapital = 453;
    std::string name = "dfsh";
    std::string hqCountry = "sdh";
    std::string description = "dsfhr";
    std::string insuranceType = "asghasd";
    std::string insuranceConditions = "asg";
    int minInsuranceSum = 234;
    int cashYearlyFlow = 234;

    CommercialOrg *elem = new InsuranceComp(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
                                            hqCountry, description, insuranceType, insuranceConditions, minInsuranceSum);
    d.pushFront(elem);

    EXPECT_EQ((int)1, d.size());
    ///EXPECT_EQ(elem, d.popBack());!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///EXPECT_EQ((int)0, d.size());

    CommercialOrg *elem2 = new Bank(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
                                            hqCountry, description, cashYearlyFlow);

    d.pushFront(elem2);
    EXPECT_EQ((int)2, d.size());
    ///EXPECT_EQ(elem2, d.popFront());//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///EXPECT_EQ((int)0, d.size());
}

TEST(TestingContainer, testClearingContainer)
{
    Deque d;
    unsigned int workersQuantity = 345;
    unsigned int clientsQuantity = 435;
    unsigned int branchesQuantity = 45;
    unsigned int statMoneyCapital = 453;
    std::string name = "dfsh";
    std::string hqCountry = "sdh";
    std::string description = "dsfhr";
    std::string insuranceType = "asghasd";
    std::string insuranceConditions = "asg";
    int minInsuranceSum = 234;
    int cashYearlyFlow = 234;

    CommercialOrg *elem = new InsuranceComp(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
                                            hqCountry, description, insuranceType, insuranceConditions, minInsuranceSum);
    CommercialOrg *elem2 = new Bank(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
                                            hqCountry, description, cashYearlyFlow);
    d.pushFront(elem);
    d.pushFront(elem2);
    d.pushFront(elem2);
    d.pushFront(elem);

    d.clear();
    EXPECT_EQ((int)0, d.size());
}

//TEST(DISABLE_TestingContainer, DISABLE_testWriteReadFromFile)
//{
//    using namespace std;

//    unsigned int workersQuantity = 345;
//    unsigned int clientsQuantity = 435;
//    unsigned int branchesQuantity = 45;
//    unsigned int statMoneyCapital = 453;
//    std::string name = "dfsh";
//    std::string hqCountry = "sdh";
//    std::string description = "dsfhr";
//    std::string insuranceType = "asghasd";
//    std::string insuranceConditions = "asg";
//    int minInsuranceSum = 234;
//    int cashYearlyFlow = 234;

//    Deque d;
//    Deque d2;
//    CommercialOrg *elem = new InsuranceComp(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
//                                            hqCountry, description, insuranceType, insuranceConditions, minInsuranceSum);
//    CommercialOrg *elem2 = new Bank(name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital,
//                                            hqCountry, description, cashYearlyFlow);

////    d.pushFront(elem);
////    d.pushFront(elem2);
////    d.pushFront(elem2);
////    d.pushFront(elem);

//    WriteToFile wf(d);
//    ReadFromFile rf(d2);

//    wf.write("test.txt");
//    rf.read("test.txt");

//    //EXPECT_EQ(d, d2);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    EXPECT_EQ((int)4, d.size());
//    EXPECT_EQ((int)4, d2.size());


//    rf.read("test.txt");
//    EXPECT_EQ((int)8, d2.size());
//}
