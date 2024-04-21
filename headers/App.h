// App.h

#ifndef APP_H
#define APP_H


#include <map>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "BloomFilter.h"
#include "BloomFilterManager.h"
#include "ICommand.h"

// header for app
class App {
    
private:
    Menu menu;
    BloomFilterManager bloomFilterManager;
    //BloomFilter bloomFilter;
    std::shared_ptr<BloomFilter> bloomFilter;  // Shared BloomFilter instance
    std::map<int, std::unique_ptr<ICommand>> commands;
    void setCommands(); // set map of commands
    std::mutex mtx; // For thread-safe access to the BloomFilter

    void handleClient(int clientSock);
    void startServer(int port);
    void initalizeBloomFilter(int sock);
    
    
public:
    // constractor
    App();
    void run(); // run the app
};

#endif // APP_H