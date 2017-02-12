#include <iostream>

#include <sio_client.h>

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
    std::cout << "TURN: " << event.get_message()->get_map()["turn"]->get_int() << std::endl;
}

