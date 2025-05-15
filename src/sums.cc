#include "sums.hh"

namespace edu0bm412 {

void
SimpleSummator::add_value(double v) {
    _s += v;
}

double
SimpleSummator::get_value() const {
    return _s;
}

}  // namespace edu0bm412

