#ifndef HTTPRESPONSEDATA_H
#define HTTPRESPONSEDATA_H

/* This data belongs to the HttpResponse */

#include "HttpParser.h"
#include "AsyncSocketData.h"
#include <functional>

namespace uWS {

template <bool SSL>
struct HttpResponseData : HttpParser, AsyncSocketData<SSL> {

    // asyncsocketdata will hold the outgoing buffer to hold the header if not sent off in one go

    // inStream, outStream
    std::function<void(std::string_view)> inStream;
    std::function<std::string_view(int)> outStream;

    int offset = 0;
    // writeHandler

};

}

#endif // HTTPRESPONSEDATA_H