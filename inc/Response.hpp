#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <iostream>
#include <map>
#include <vector>
#include "Connection.hpp"


/* Color Sets */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;250m"

class Connection;

class Response {
public:
    enum TransferType { GENERAL, CHUNKED };
private:
    /* member attributes */
    static std::map<int, std::vector<std::string>> status;
    Connection* _connection;
    int         _status_code;
    std::string _status_description;
    std::map<std::string, std::string> _headers;
    TransferType    _transfer_type;
    std::string     _content;
    Response();

public:
    /* Orthodox Canonical Form (OCF) */
    Response(Connection*, int status_code, const std::string& body = "");
    Response(const Response& other);
    ~Response();
    Response& operator=(const Response& other);

    /* getter & setter */
    Connection*                         getConnection()         const;
    int                                 getStatusCode()         const;
    std::string                         getStatusDescription()  const;
    std::map<std::string, std::string>  getHeaders()            const;
    TransferType                        getTransferType()       const;
    std::string                         getContent()            const;
    
    /* additional methods */
    void                                addHeader(const std::string& key, const std::string& value);
    void                                makeStatus(int code);
    char*                               c_str()                 const;
    /* exception classes */
};

/* operators */
#endif