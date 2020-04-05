//
// 策略模式与简单工厂结合 —— 商场促销计算器
//

#ifndef DESIGNPATTERN_STRATEGY_II_H
#define DESIGNPATTERN_STRATEGY_II_H

// 基本的收银类（基类）
class CashierS {
public:
    virtual double AcceptCash(double money) {
        double change = 0.0;
        return change;
    }
};

// 正常收银（派生类）
class CommonCashierS: public CashierS {
public:
    double AcceptCash(double money) override {
        return money;
    }
};

// 商场打折（派生类）
class DiscountCashierS: public CashierS {
private:
    double _discount = 0.0;
public:
    explicit DiscountCashierS(double discount) {
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
class RefundCashierS: public CashierS {
private:
    int _condition = 0;
    int _refund = 0;
public:
    RefundCashierS(int condition, int refund) {
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

// 策略模式与工厂模式结合
class CashierContextS {
private:
    double _discount = 0.0;
    int _condition = 0;
    int _refund = 0;
    CashierS* strategy = nullptr;
public:
    void SetDiscount(double discount) {
        _discount = discount;
    }

    void SetRefundCondition(int condition, int refund) {
        _condition = condition;
        _refund = refund;
    }

    explicit CashierContextS(char mode, double discount, int condition, int refund) {
        switch(mode) {
            case 'c':
                strategy = new CommonCashierS();
                break;
            case 'd':
                SetDiscount(discount);
                strategy = new DiscountCashierS(_discount);
                break;
            case 'r':
                SetRefundCondition(condition, refund);
                strategy = new RefundCashierS(_condition, _refund);
                break;
            default:
                break;
        }
    }

    double GetResult(double money) {
        return strategy->AcceptCash(money);
    }
};

// 改进策略模式 —— 客户端
class MallS {
public:
    double GetCashier(double money, double discount, int condition, int refund, char mode) {
        auto csr = new CashierContextS(mode, discount, condition, refund);
        return csr->GetResult(money);
    }
};

/********************************************************************************************
 *  // 策略模式客户端                                                                         *
 *  MallS m;                                                                                *
 *  cout << "收银1000元，无优惠，合计：" << m.GetCashier(1000, 0, 0, 0, 'c') << endl;          *
 *  cout << "收银1000元，打8折，合计：" << m.GetCashier(1000, 8, 0, 0, 'd') << endl;           *
 *  cout << "收银1000元，满200减50，合计：" << m.GetCashier(1000, 0, 200, 50, 'r') << endl;    *
 ********************************************************************************************/

#endif //DESIGNPATTERN_STRATEGY_II_H
