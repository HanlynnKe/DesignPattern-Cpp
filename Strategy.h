//
// 策略模式 —— 商场促销计算器
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H

// 基本的收银类（基类）
class Cashier {
public:
    virtual double AcceptCash(double money) {
        double change = 0.0;
        return change;
    }
};

// 正常收银（派生类）
class CommonCashier: public Cashier {
public:
    double AcceptCash(double money) override {
        return money;
    }
};

// 商场打折（派生类）
class DiscountCashier: public Cashier {
private:
    double _discount = 0.0;
public:
    explicit DiscountCashier(double discount) {
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
class RefundCashier: public Cashier {
private:
    int _condition = 0;
    int _refund = 0;
public:
    RefundCashier(int condition, int refund) {
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

// 策略模式
class CashierContext {
private:
    Cashier* strategy;
public:
    explicit CashierContext(Cashier* st) {
        strategy = st;
    }

    double GetResult(double money) {
        return strategy->AcceptCash(money);
    }
};

// 策略模式 —— 客户端
class Mall {
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

    double GetCashier(double money, double discount, int condition, int refund, char mode) {
        CashierContext* csr = nullptr;
        Cashier* strategy;
        switch(mode) {
            case 'c':
                csr = new CashierContext(new CommonCashier());
                break;
            case 'd':
                SetDiscount(discount);
                csr = new CashierContext(new DiscountCashier(_discount));
                break;
            case 'r':
                SetRefundCondition(condition, refund);
                csr = new CashierContext(new RefundCashier(_condition, _refund));
                break;
            default:
                break;
        }
        return csr->GetResult(money);
    }
};

/********************************************************************************************
 *  // 策略模式客户端                                                                         *
 *  Mall m;                                                                                 *
 *  cout << "收银1000元，无优惠，合计：" << m.GetCashier(1000, 0, 0, 0, 'c') << endl;          *
 *  cout << "收银1000元，打8折，合计：" << m.GetCashier(1000, 8, 0, 0, 'd') << endl;           *
 *  cout << "收银1000元，满300减100，合计：" << m.GetCashier(1000, 0, 300, 100, 'r') << endl;  *
 ********************************************************************************************/

#endif //DESIGNPATTERN_STRATEGY_H
