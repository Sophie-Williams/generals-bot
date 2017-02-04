#include <sio_client.h>

#include "map.h"
#include "network.h"

network n;

void on_connected();

int main() {
    n.connect([]() { std::cout << "Connected" << std::endl; });
}

void on_connected() {
    n.login();
    n.join_private("arstarstarst");
    n.set_force_start("arstarstarst", true);
}
