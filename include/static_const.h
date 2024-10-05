#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::multiprecision;


struct Node {
    int data;
    Node* next;
};

class StaticConst {
    StaticConst() {
        if (instanceCount < maxInstances) {
            instanceCount++;
            cout << "创建第 " << instanceCount << " 个实例" <<endl;
        } else {
            cout << "已达到能创建实例的最大数量！！！" << endl;
        }
    }
    public: 
        static const int maxInstances = 2;  // 类常量，可以在类中初始化
        static int instanceCount;  // 类变量，不能在类中初始化

        static void display();
};

void high_precision();

void staticVariable();
