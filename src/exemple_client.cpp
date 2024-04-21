#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() {
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;  // Return on error
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        close(sock);
        return 1;  // Return on error
    }

    while (true) {
        cout << "Enter a message (type 'exit' to quit): ";
        string input;
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        int sent_bytes = send(sock, input.c_str(), input.length(), 0);
        if (sent_bytes < 0) {
            perror("error sending to server");
            continue;
        }

        char buffer[4096];
        int read_bytes = recv(sock, buffer, sizeof(buffer), 0);
        if (read_bytes == 0) {
            cout << "Connection is closed by server." << endl;
            break;
        } else if (read_bytes < 0) {
            perror("error receiving from server");
            break;
        } else {
            buffer[read_bytes] = '\0';  // Null-terminate the received data
            cout << "Received from server: " << buffer << endl;
        }
    }

    close(sock);
    return 0;
}
