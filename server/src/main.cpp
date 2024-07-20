#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "json.h"

const int PORT = 16008;
const int BUFFER_SIZE = 1024;

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
    int age = root["age"].asInt();              // 这是整型，转化是指定类型

    std::cout << name << std::endl;
    std::cout << age << std::endl;
}

int main()
{
    std::cout << "server start" << std::endl;
    demo_simple();
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // 创建监听socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return 1;
    }

    // 设置socket选项，允许地址重用
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        return 1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 绑定socket到指定的端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        return 1;
    }

    // 开始监听连接
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        return 1;
    }
    std::cout << "Server listening on port " << PORT << std::endl
              << std::endl;

    // 等待并接受客户端连接
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept failed");
        return 1;
    }

    char buffer[BUFFER_SIZE] = {0};
    int valread;

    // 接收客户端发送的数据
    while (1)
    {
        std::cout<<1<<std::endl;
        valread = read(client_socket, buffer, BUFFER_SIZE);
        std::cout<<3<<std::endl;
        std::cout << "Received message from client: \r\n"
                  << buffer << std::endl;

        // 返回消息给客户端
        const char *hello = "Server: ";
        send(client_socket, hello, strlen(hello), 0);   
        send(client_socket, buffer, strlen(buffer), 0);
        std::cout << "Echo message sent to client" << std::endl
                  << std::endl;
    }

    // 关闭连接
    close(client_socket);
    close(server_fd);
    std::cout<<5<<std::endl;
    //goto
    return 0;
}