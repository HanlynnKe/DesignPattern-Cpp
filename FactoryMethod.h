//
// 工厂方法模式 —— 计算器
//

#ifndef DESIGNPATTERN_CPP_FACTORYMETHOD_H
#define DESIGNPATTERN_CPP_FACTORYMETHOD_H

// 基本的运算类（基类）
class Operation_FM {
public:
    virtual double Calculate(double a, double b) {
        double res = 0.0;
        return res;
    }
};

// 加法类（派生类）
class OperationAdd_FM: public Operation_FM {
public:
    double Calculate(double a, double b) override {
        return a + b;
    }
};

// 减法类（派生类）
class OperationSub_FM: public Operation_FM {
public:
    double Calculate(double a, double b) override {
        return a - b;
    }
};

// 乘法类（派生类）
class OperationMul_FM: public Operation_FM {
public:
    double Calculate(double a, double b) override {
        return a * b;
    }
};

// 除法类（派生类）
class OperationDiv_FM: public Operation_FM {
public:
    double Calculate(double a, double b) override {
        if(b == 0.0) {
            throw "Division by zero condition!";
        }
        return a / b;
    }
};

// 工厂方法模式
class IFactory {
public:
    virtual Operation_FM* CreateOperation() = 0;
};

class AddFactory: public IFactory {
public:
    Operation_FM* CreateOperation() override {
        return new OperationAdd_FM();
    }
};

class SubFactory: public IFactory {
public:
    Operation_FM* CreateOperation() override {
        return new OperationSub_FM();
    }
};

class MulFactory: public IFactory {
public:
    Operation_FM* CreateOperation() override {
        return new OperationMul_FM();
    }
};

class DivFactory: public IFactory {
public:
    Operation_FM* CreateOperation() override {
        return new OperationDiv_FM();
    }
};

/**********************************************************
 *  // 工厂方法                                            *
 *  IFactory* operFactory = new AddFactory();             *
 *  Operation_FM* oper = operFactory->CreateOperation();  *
 *  cout << "1 + 2 = " << oper->Calculate(1, 2) << endl;  *
 **********************************************************/

#endif //DESIGNPATTERN_CPP_FACTORYMETHOD_H
