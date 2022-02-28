#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    WSADATA wsaData{}; //win socket
    SOCKET SendRecvSocket; //Сокет для приема передачи
    sockaddr_in ServerAdr{}, ClientAdr{}; //структуры для организации клинтского и серверного адреса
    int err, maxlen = 512, ClientAdrSize = sizeof(ClientAdr);
    char* recvBuf = new char[maxlen];
    string resultString{};
    //char* resultString = new char[maxlen];
    bool workFlag = true;
    auto closeWord = "exit";

    WSAStartup(MAKEWORD(2,2),&wsaData); //for win socket

    SendRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //create socket type adr, type receive, protocol

    ServerAdr.sin_family = AF_INET; //ipv4
    ServerAdr.sin_addr.s_addr = INADDR_ANY; //192.168./..../
    ServerAdr.sin_port = htons(1444);
    err = bind(SendRecvSocket,(sockaddr*)&ServerAdr,sizeof (ServerAdr)); // link socket with socketAddr
    if(err == SOCKET_ERROR){
        cout << "bind failed" << WSAGetLastError() << endl;
        closesocket(SendRecvSocket);
        WSACleanup();
        return 1;
    }

    while(workFlag){
        err = recvfrom(SendRecvSocket, recvBuf, maxlen, 0, (sockaddr*)&ClientAdr,&ClientAdrSize);
        if(err>0){
            recvBuf[err] = '\0';
            cout<<recvBuf<< " ";
            if(recvBuf == closeWord)
                workFlag = false;
            resultString = "Client send: ";
            resultString.append(recvBuf);
            sendto(SendRecvSocket, recvBuf, strlen(recvBuf), 0, (sockaddr*)&ClientAdr,sizeof(ClientAdr));
        }
        else{
            cout<<"recv failed" << WSAGetLastError() << endl;
            closesocket(SendRecvSocket);
            WSACleanup();
        }
    }
    delete[] recvBuf;
    return 0;
}
