#include <iostream>
using namespace std;


void staticVariable() {
    static int sv = 0;
    cout << sv << " ";
    sv++;
}

class StaticConst {
    public: 
        static const int maxInstances = 2;
        static int instanceCount;
    
    StaticConst() {
        if (instanceCount < maxInstances) {
            instanceCount++;
            cout << "创建第 " << instanceCount << " 个实例" <<endl;
        } else {
            cout << "已达到能创建实例的最大数量！！！" << endl;
        }
    }
};

int StaticConst::instanceCount = 0;

int main() {
    for (int i = 0; i < 3; i++) {
        StaticConst sc;
    }

    return 0;
}
