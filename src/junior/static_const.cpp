#include "static_const.h"


int StaticConst::instanceCount = 0;  // 全局初始化类变量

void StaticConst::display() {
    cout << "调用类方法" << endl;
    cout << "当前实例个数是：" << instanceCount << endl;
}

void high_precision() {

    cpp_dec_float_50 a("123456789012345678901234567890.12345678901234567890");
    cpp_dec_float_50 b("987654321098765432109876543210.98765432109876543210");

    cpp_dec_float_50 sum = a + b;
    cpp_dec_float_50 product = a * b;

    cout << "a + b = " << sum << endl;
    cout << "a * b = " << product << endl;

    string s = "csp-j";
    boost::to_upper(s);
    cout << s << endl;

}

void staticVariable() {
    static int sv = 0;
    cout << sv << " ";
    sv++;
}
