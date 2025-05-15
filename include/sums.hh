#pragma once

#include "kahan.h"

namespace edu0bm412 {

// interface
struct iSummator {
    virtual void add_value(double v) = 0;
    virtual double get_value() const = 0;
};

// abstract summator base class
class AbstractSummator : public iSummator {
public:
    iSummator & operator+=(double v) {
        add_value(v);
        return *this;
    }

    iSummator & operator-=(double v) {
        add_value(-v);
        return *this;
    }

    operator double() const {
        return get_value();
    }
};

// simplest possible implementation -- ordinary summator
class SimpleSummator : public AbstractSummator {
private:
    double _s;
public:
    void add_value(double v) override;
    double get_value() const override;
};

// Kahan summator
class KahanSummator : public AbstractSummator {
    // ...
};


}  // namespace edu0bm412

