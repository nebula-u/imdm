#include <iostream>
#include <fstream>
#include <string>
#include "json.h"

void demo_simple()
{
    std::ifstream ifs;
    ifs.open("../test_data/test.json");
 
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root, false))
    {
        std::cerr << "parse failed \n";
        return;
    }
 
    std::string name = root["name"].asString(); // 实际字段保存在这里
    int age = root["age"].asInt(); // 这是整型，转化是指定类型

    std::cout << name << std::endl;
    std::cout << age << std::endl;
}


int main(){
    std::cout << "server start" << std::endl;
    demo_simple();
    return 0;
}