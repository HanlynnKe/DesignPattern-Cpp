//
// 装饰模式 —— 服装搭配
// 把需要的功能按正确顺序串联起来进行控制
//

#ifndef DESIGNPATTERN_DECORATOR_H
#define DESIGNPATTERN_DECORATOR_H

#include <iostream>
#include <string>

// ConcreteComponent
class Person {
private:
    std::string _name;
public:
    Person() {
        _name = "";
    }
    explicit Person(std::string &name) {
        _name = name;
    }
    virtual void Show() {
        std::cout << "装扮的" << _name << std::endl;
    }
};

// Decorator
class Finery: public Person {
protected:
    Person* _component;
public:
    void Decorate(Person* component) {
        _component = component;
    }
    void Show() override {
        if(_component != nullptr) {
            _component->Show();
        }
    }
};

// ConcreteDecorator
class TShirt: public Finery {
public:
    void Show() override {
        std::cout << "大T恤 ";
        Finery::Show();
    }
};
class BigTrouser: public Finery {
public:
    void Show() override {
        std::cout << "阔腿裤 ";
        Finery::Show();
    }
};

/*********************************
 *  装饰模式客户端                 *
 *  string name = "小柯";        *
 *  auto k = new Person(name);   *
 *  auto ts = new TShirt();      *
 *  auto bt = new BigTrouser();  *
 *  bt->Decorate(k);             *
 *  ts->Decorate(bt);            *
 *  ts->Show();                  *
 *********************************/

#endif //DESIGNPATTERN_DECORATOR_H
