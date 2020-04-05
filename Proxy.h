//
// 代理模式 —— 爱情与代理
//

#ifndef DESIGNPATTERN_PROXY_H
#define DESIGNPATTERN_PROXY_H

#include <iostream>

// 被追求者类
class Girl {
private:
    std::string _name="";
public:
    Girl() = default;
    explicit Girl(std::string &name) {
        _name = name;
    }
    std::string Name() {
        return _name;
    }
};

// 动作接口
class Action {
public:
    virtual void GiveChocolate() = 0;
    virtual void GiveRoses() = 0;
};

// 追求者类
class Pursuit: public Action {
private:
    Girl* _mm = nullptr;
public:
    Pursuit() = default;
    explicit Pursuit(Girl* mm) {
        _mm = mm;
    }
    void GiveChocolate() override {
        std::cout << _mm->Name() << "，给你巧克力！" << std::endl;
    }
    void GiveRoses() override {
        std::cout << _mm->Name() << "，给你玫瑰花！" << std::endl;
    }
};

// 代理类
class Proxy: public Action {
private:
    Pursuit* _gg = nullptr;
public:
    Proxy() = default;
    explicit Proxy(Girl* mm) {
        _gg = new Pursuit(mm);
    }
    void GiveChocolate() override {
        _gg->GiveChocolate();
    }
    void GiveRoses() override {
        _gg->GiveRoses();
    }
};

/*********************************
 *  代理模式客户端                 *
 *  string mmName = "Amy";       *
 *  auto mm = new Girl(mmName);  *
 *  auto bb = new Proxy(mm);     *
 *  bb->GiveChocolate();         *
 *  bb->GiveRoses();             *
 *********************************/

#endif //DESIGNPATTERN_PROXY_H
