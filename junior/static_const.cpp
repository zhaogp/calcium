#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::multiprecision;


void staticVariable() {
    static int sv = 0;
    cout << sv << " ";
    sv++;
}

class StaticConst {
    public: 
        static const int maxInstances = 2;  // 类常量，可以在类中初始化
        static int instanceCount;  // 类变量，不能在类中初始化

        static void display(){
            cout << "调用类方法" << endl;
            cout << "当前实例个数是：" << instanceCount << endl;
        };
    
    StaticConst() {
        if (instanceCount < maxInstances) {
            instanceCount++;
            cout << "创建第 " << instanceCount << " 个实例" <<endl;
        } else {
            cout << "已达到能创建实例的最大数量！！！" << endl;
        }
    }
};

int StaticConst::instanceCount = 0;  // 全局初始化类变量

struct Node {
    int data;
    Node* next;
};

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

int main() {
    high_precision();

    return 0;
}
