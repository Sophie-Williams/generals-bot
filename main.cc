#include <iostream>

#include <sio_client.h>

#include "map.h"
#include "network.h"

network n;

void on_connected();
void on_game_update(sio::event& event);

int main() {
    n.connect([]() { std::cout << "Connected" << std::endl; });
}

void on_connected() {
    n.login();
    n.join_private("arstarstarst");
    n.set_force_start("arstarstarst", true);
}

void on_game_update(sio::event& event) {
    std::cout << event.get_name() << std::endl;
}
