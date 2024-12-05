//
// Created by Pling on 04/11/2024.
//


#ifndef STATERECEIVER_HPP
#define STATERECEIVER_HPP
#include "TCPConnector.hpp"
#include <thread>
#include <queue>
#include <iostream>
#include <fstream>
#include <chrono>
#include <mutex>
#include "DataTypes.hpp"

class RoverReceiver {
private:
    std::string ip;
    uint16_t port;
    std::queue<std::pair<long long, std::vector<uint8_t>>> packets;
    std::unique_ptr<TCPConnector> client;
    std::thread receiverThread;
    std::thread handleThread;
    std::shared_ptr<RoverFrame> state;
    std::shared_ptr<RoverFrame> parse(const std::vector<uint8_t> &bytes);

public:
    std::mutex m;
    RoverReceiver(std::string& _ip, uint16_t _port);

    [[nodiscard]] RoverFrame getFrame() const {return *state;}

};
#endif //STATERECEIVER_HPP
