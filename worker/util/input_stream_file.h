// Copyright (c) 2016, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once
#include "error_code.h"
#include "boost/noncopyable.hpp"
#include <stdio.h>

namespace baidu {
namespace ucp {
namespace file {

class InputStreamFile : public boost::noncopyable {
public:
    explicit InputStreamFile(const std::string& path);
    ~InputStreamFile();

    bool IsOpen();
    bool Eof();
    baidu::ucp::system::ErrorCode GetLastError();
    baidu::ucp::system::ErrorCode ReadLine(std::string& line);
    baidu::ucp::system::ErrorCode Read(void* buf, size_t& size);

private:
    std::string path_;
    FILE* file_;
    bool opened_;
    int errno_; // last_erro
};
}
}
}
