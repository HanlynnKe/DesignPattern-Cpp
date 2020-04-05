//
// 简单工厂模式 —— 商场促销计算器
//

#ifndef DESIGNPATTERN_SIMPLEFACTORY_II_H
#define DESIGNPATTERN_SIMPLEFACTORY_II_H

// 基本的收银类（基类）
class CashierSF {
public:
    virtual double AcceptCash(double money) {
        double change = 0.0;
        return change;
    }
};

// 正常收银（派生类）
class CommonCashierSF: public CashierSF {
public:
    double AcceptCash(double money) override {
        return money;
    }
};

// 商场打折（派生类）
class DiscountCashierSF: public CashierSF {
private:
    double _discount = 0.0;
public:
    explicit DiscountCashierSF(double discount) {
        if(discount <= 0 || discount >= 10) {
            throw "Invalid discount settings!";
        }
        _discount = discount / 10.0;
    }
    double AcceptCash(double money) override {
        return money * _discount;
    }
};

// 商场满减（派生类）
class RefundCashierSF: public CashierSF {
private:
    int _condition = 0;
    int _refund = 0;
public:
    RefundCashierSF(int condition, int refund) {
        _condition = condition;
        _refund = refund;
    }
    double AcceptCash(double money) override {
        if(money < _condition) {
            return money;
        } else {
            int t = static_cast<int>(money) / _condition;
            return money - t * _refund;
        }
    }
};

// 简单工厂模式
class CashierFactory {
private:
    double _discount = 0.0;
    int _condition = 0;
    int _refund = 0;
public:
    void SetDiscount(double discount) {
        _discount = discount;
    }
    void SetRefundCondition(int condition, int refund) {
        _condition = condition;
        _refund = refund;
    }
    CashierSF* CreateCashier(char mode) {
        CashierSF* c = nullptr;
        switch(mode) {
            case 'c':
                c = new CommonCashierSF();
                break;
            case 'd':
                c = new DiscountCashierSF(_discount);
                break;
            case 'r':
                c = new RefundCashierSF(_condition, _refund);
                break;
            default:
                break;
        }
        return c;
    }
};

// 简单工厂模式 —— 客户端
class MallSF {
private:
    CashierFactory* mFactory;
public:
    MallSF(CashierFactory* factory) {
        mFactory = factory;
    }

    double GetCashier(double money, double discount, int condition, int refund, char mode) {
        mFactory->SetDiscount(discount);
        mFactory->SetRefundCondition(condition, refund);
        CashierSF* csr = mFactory->CreateCashier(mode);
        return csr->AcceptCash(money);
    }
};

/********************************************************************************************
 *  // 简单工厂                                                                              *
 *  auto csf = new CashierFactory();                                                        *
 *  // 客户端                                                                                *
 *  Mall m(csf);                                                                            *
 *  cout << "收银1000元，无优惠，合计：" << m.GetCashier(1000, 0, 0, 0, 'c') << endl;          *
 *  cout << "收银1000元，打8折，合计：" << m.GetCashier(1000, 8, 0, 0, 'd') << endl;           *
 *  cout << "收银1000元，满300减100，合计：" << m.GetCashier(1000, 0, 300, 100, 'r') << endl;  *
 ********************************************************************************************/

#endif //DESIGNPATTERN_SIMPLEFACTORY_II_H
