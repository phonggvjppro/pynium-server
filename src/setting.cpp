#include <iostream>

class Setting {
    private: 
        int port, max_cons;

    public:  
        Setting( int port, int max_cons) {
            this->port = port;
            this->max_cons = max_cons;
        }

        int get_port() {
            return port;
        }

        int get_max_cons() {
            return max_cons;
        }

}