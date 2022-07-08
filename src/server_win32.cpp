#include <netinet/in.h> 
#include <map>
#include <iostream>
#include <pthread.h>
#include "setting.cpp"
#include "socket_client.cpp"
#include <ctime>
#include <mutex>


// VARIABLES
Setting _setting;
bool isStop;
std::mutex m;
std::map<std::string, SocketClient> lst_cons;
SOCKET server;

//FUNCTIONS
void __init__(Setting setting) {
    _setting = setting;
    isStop = false;
}

void create_session_id(SocketClient client) {
    std::lock_guard<std::mutex> lk(m);
    std::string temp_session;
    while(lst_cons.find(temp_session) == lst_cons.end()) {
        temp_session = random_string(LOWER+DIGIT, 16);
    }
    client.send(temp_session);
    lst_cons[temp_session] = client;
}

void close_all() {
    lst_cons.clear();
}
bool start_server() 
{
    WSADATA wsadata;
    if(WSAStartup(2,2) !=0) {
        throw "Can't initialize winsock!";
    }
    if((server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        
    }
    sockaddr_in addr;
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    addr.sin_port = htons(_setting.get_port());
    addr.sin_family = AF_INET;

    if(bind(server, (sockaddr*)&addr, sizeof(addr)) <0) {

    }
    if(listen(server, _setting.get_max_cons()) <0) {

    }
    pthread_t thread;
    pthread_create(&thread, []{
        while(!isStop) {
            sockaddr_in client_addr;
            SOCKET client = accept(server, (sockaddr*)&client_addr, &sizeof(client_addr));
            SocketClient socketclient(client);
            Sleep(1000);
            create_session_id(client);
        }
        pthread_exit(NULL);
    })
}


