#include "HttpServer.hpp"

void HttpServer::run() {
        //Creating server socket
    //AF_INET -> IPv4 protocol
    //SOCK_STREAM -> TCP socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Defining Server Address
    //sockaddr_in: It is the data type that is used to store the address of the socket
    //htons(): Converts port to network byte order
    //INADDR_ANY: Accept connections on any IP
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8082);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //Binding Socket to Adrees
    //Bind only accepts sockadrr* 
    bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));
    //Listen for incoming connections
    listen(serverSocket, 5);
    std::cout << "Server runnig in port 8082"<<std::endl;
    
    while(true) {
       

        //Accept Client Connection
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        std::cout<< "Client connected"<<std::endl;
        //Receive Data from Client
        char buffer[1024] = {0};
        recv(clientSocket, buffer, sizeof(buffer), 0);
        std::cout << "Message from client: " << buffer << std::endl;

        //Send Data to Client
        const char* res = "HTTP/1.1 200 OK\r\nContent-Length: 10\r\nContent-Type: text/plain\r\n\r\nA resposta";
        send(clientSocket, res, strlen(res), 0);

        close(clientSocket);
    }
    //Close Server Socket
    close(serverSocket);    

}