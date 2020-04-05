//
// 简单工厂模式 —— 计算器
//

#ifndef DESIGNPATTERN_SIMPLEFACTORY_H
#define DESIGNPATTERN_SIMPLEFACTORY_H

// 基本的运算类（基类）
class Operation {
public:
    virtual double Calculate(double a, double b) {
        double res = 0.0;
        return res;
    }
};

// 加法类（派生类）
class OperationAdd: public Operation {
public:
    double Calculate(double a, double b) override {
        return a + b;
    }
};

// 减法类（派生类）
class OperationSub: public Operation {
public:
    double Calculate(double a, double b) override {
        return a - b;
    }
};

// 乘法类（派生类）
class OperationMul: public Operation {
public:
    double Calculate(double a, double b) override {
        return a * b;
    }
};

// 除法类（派生类）
class OperationDiv: public Operation {
public:
    double Calculate(double a, double b) override {
        if(b == 0.0) {
            throw "Division by zero condition!";
        }
        return a / b;
    }
};

// 简单工厂模式
class OperationFactory {
public:
    static Operation* CreateOperate(char op) {
        Operation* o = nullptr;
        switch(op) {
            case '+':
                o = new OperationAdd();
                break;
            case '-':
                o = new OperationSub();
                break;
            case '*':
                o = new OperationMul();
                break;
            case '/':
                o = new OperationDiv();
                break;
            default:
                break;
        }
        return o;
    }
};

// 简单工厂模式 —— 客户端
class Calculator {
private:
    OperationFactory *mFactory;

public:
    Calculator(OperationFactory* factory) {
        mFactory = factory;
    }

    double Operate(double a, double b, char op) {
        Operation* opt = mFactory->CreateOperate(op);
        return opt->Calculate(a, b);
    }
};

/****************************************************
 *  // 简单工厂                                      *
 *  auto opf = new OperationFactory();              *
 *  // 客户端                                        *
 *  Calculator ins(opf);                            *
 *  cout << "1 + 2 = " << ins.Operate(1,2,'+');     *
 ****************************************************/

#endif //DESIGNPATTERN_SIMPLEFACTORY_H
