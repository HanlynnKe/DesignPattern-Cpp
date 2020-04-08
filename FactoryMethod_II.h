//
// 工厂方法模式 —— 雷锋工厂
//

#ifndef DESIGNPATTERN_CPP_FACTORYMETHOD_II_H
#define DESIGNPATTERN_CPP_FACTORYMETHOD_II_H

#include <iostream>

// 雷锋
class LeiFeng {
public:
    void Sweep() {
        std::cout << "扫地" << std::endl;
    }
    void Wash() {
        std::cout << "洗衣" << std::endl;
    }
    void BuyRice() {
        std::cout << "买米" << std::endl;
    }
};

// 学雷锋的大学生
class Undergraduate: public LeiFeng {};
// 社区志愿者
class Volunteer: public LeiFeng {};

// 雷锋工厂
class IFactory_LF {
public:
    virtual LeiFeng* CreateLeiFeng() = 0;
};

// 学雷锋的大学生工厂
class UndergraduateFactory: public IFactory_LF {
public:
    LeiFeng* CreateLeiFeng() override {
        return new Undergraduate();
    }
};
// 社区志愿者工厂
class VolunteerFactory: public IFactory_LF {
public:
    LeiFeng* CreateLeiFeng() override {
        return new Volunteer();
    }
};

/**********************************************************
 *  // 工厂方法                                            *
 *  IFactory_LF* factory = new UndergraduateFactory();    *
 *  LeiFeng* student = factory->CreateLeiFeng();          *
 *  student->BuyRice();                                   *
 *  student->Sweep();                                     *
 *  student->Wash();                                      *
 **********************************************************/

#endif //DESIGNPATTERN_CPP_FACTORYMETHOD_II_H
