#ifndef NETWORK_H
#define NETWORK_H

#include <functional>
#include <iostream>

#include <sio_client.h>

const std::string address = "http://botws.generals.io";
const std::string user_name = "david";
const sio::string_message::ptr user_id = sio::string_message::create("areallynicebotmadebydavid");

class network {
    public:
        void connect(std::function<void()>);
        void login();
        void join_private(std::string game_id);
        void set_force_start(std::string queue_id,
                bool force_start = true);

    private:
        sio::client client;
};


#endif
