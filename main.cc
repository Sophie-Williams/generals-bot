#include <iostream>
#include <vector>

#include <sio_client.h>

#include "map.h"


const std::string address = "http://botws.generals.io";
const sio::string_message::ptr user_id = sio::string_message::create("areallynicebotmadebydavid"); 

void login(sio::client& client);
void login_success(sio::message::list const& ack);
void on_connected(sio::client& socket);
void join_private(sio::client& client, std::string game_id);
void set_force_start(sio::client& client, std::string queue_id);

int main() {
    sio::client client;
    client.connect(address);
    client.set_open_listener([&client]() { on_connected(client); });
}

void on_connected(sio::client& client) {
    std::cout << "Successfully connected!" << std::endl;
    login(client);
    join_private(client, "arstarstarst");
    set_force_start(client, "arstarstarst"); 
}
 
void login(sio::client& client) {
    sio::message::list msgs;

    msgs.push(user_id);
    msgs.push(sio::string_message::create("david"));

    client.socket()->emit("set_username", msgs);
}

void join_private(sio::client& client, std::string game_id) {
    sio::message::list join;
    // custom_game_id
    join.push(sio::string_message::create(game_id));
    // user_id
    join.push(user_id);
    client.socket()->emit("join_private", join); 
}

void set_force_start(sio::client& client, std::string queue_id) {
    sio::message::list l;
    l.push(sio::string_message::create(queue_id));
    l.push(sio::bool_message::create(true));
    client.socket()->emit("set_force_start", l);
}
