#include <iostream>
using namespace std;


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

int main() {
    int x = 100;
    const int* ptr = &x;
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << "信息学奥林匹克" << endl;

    return 0;
}
