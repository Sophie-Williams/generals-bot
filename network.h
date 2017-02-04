#ifndef NETWORK_H
#define NETWORK_H

#include <functional>
#include <iostream>
#include <memory>

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

        typedef std::function<void(sio::event&)> listener;

        void on_game_start(listener);
        void on_game_update(listener);
        void on_game_lost(listener);
        void on_game_won(listener);
        void on_message_received(listener);
        void on_stars_received(listener);
        void on_rank_received(listener);

    private:
        std::unique_ptr<sio::client> client;
};


#endif
