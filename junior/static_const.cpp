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

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head;
    Node* newNode = new Node;
    newNode->data = 42;
    head->next = newNode;

    cout << head->next->data << endl;

    return 0;
}
