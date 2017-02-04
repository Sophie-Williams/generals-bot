#include "network.h"

void network::connect(std::function<void()> f) {
    client.connect(address);
    client.set_open_listener(f);
}

void network::login() {
    sio::message::list msgs;
    msgs.push(user_id);
    msgs.push(sio::string_message::create(user_name));
    client.socket()->emit("set_username", msgs);
}

void network::join_private(std::string game_id) {
    sio::message::list join;
    join.push(sio::string_message::create(game_id));
    join.push(user_id);
    client.socket()->emit("join_private", join);
}

void network::set_force_start(std::string queue_id, bool force_start) {
    sio::message::list l;
    l.push(sio::string_message::create(queue_id));
    l.push(sio::bool_message::create(force_start));
    client.socket()->emit("set_force_start", l);
}

void network::on_game_start(listener l) {
    client.socket()->on("game_start", l);
}

void network::on_game_update(listener l) {
    client.socket()->on("game_update", l);
}

void network::on_game_lost(listener l) {
    client.socket()->on("game_lost", l);
}

void network::on_game_won(listener l) {
    client.socket()->on("game_won", l);
}

void network::on_message_received(listener l) {
    client.socket()->on("chat_message", l);
}

void network::on_stars_received(listener l) {
    client.socket()->on("stars", l);
}

void network::on_rank_received(listener l) {
    client.socket()->on("rank", l);
}
