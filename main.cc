#include <string>
#include <iostream>

#include <sio_client.h>
#include <sio_message.h>

#include "map.h"
#include "network.h"


void on_connected(network& n);
void on_game_update(sio::event& event);

int main() {
    network n;
    n.connect([&n]() { on_connected(n); });
}

void on_connected(network& n) {
    n.login();
    n.join_private("arstarstarst");
    n.set_force_start("arstarstarst", true);
    n.on_game_update(&on_game_update);
    std::cout << "Connected!" << std::endl;
}

void on_game_update(sio::event& event) {
    std::cout << "Got game update, displaying data:" << std::endl;

    sio::message::ptr msg = event.get_message();
    std::map<std::string, sio::message::ptr> map = msg->get_map();

    std::cout << "TURN: " << map["turn"]->get_int() << std::endl;

    // TODO: Use this map data somehow
    std::vector<int> map_diff;
    for (auto m : map["map_diff"]->get_vector()) {
        int d = m->get_int();
        map_diff.push_back(d);
    }

    std::cout << "[";
    for (auto m : map_diff) {
        std::cout << m << " ";
    }
    std::cout << "]" << std::endl;
}

