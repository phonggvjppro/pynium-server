#include <iostream>
#ifdef __WIN32__
#include <winsock2.h>
#else
#include <sys/sock.h>
#endif
#include <mutex>

class SocketClient{
    
    private:
        SOCKET client;
        std::mutex m;

    public:
        SocketClient(SOCKET _client) {
            client = _client;
            
        }  

        void send(std::string data) {
            std::lock_guard<std::mutex> lk(m);
        }

        std::string recv() {
            std::lock_guard<std::mutex> lk(m);
        }
        void close() {
            closesocket(client);
        }

        ~SocketClient() {
            close();
        }

}