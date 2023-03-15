#pragma once

#include <cstdint>
#include <sstream>
#include <iostream>

#include "KMSError.h"

class KMSClient {
public:
    /// <summary>
    /// Set the KMS server via slmgr.vbs
    /// </summary>
    /// <param name="server">Hostname/ip address of KMS server</param>
    /// <param name="port">KMS port</param>
    static void set_kms_server(const std::wstring& server, uint16_t port = 1688);

    /// <summary>
    /// Set the system product key (gvlk i.e., KMS key) via slmgr.vbs
    /// </summary>
    /// <param name="key">Product key</param>
    static void set_gvlk_key(const std::wstring& key);

    /// <summary>
    /// Request activation from the KMS server via slmgr.vbs
    /// </summary>
    static void request_activation();
};
