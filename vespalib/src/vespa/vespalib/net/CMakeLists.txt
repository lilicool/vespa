# Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
vespa_add_library(vespalib_vespalib_net OBJECT
    SOURCES
    async_resolver.cpp
    crypto_engine.cpp
    crypto_socket.cpp
    selector.cpp
    server_socket.cpp
    socket.cpp
    socket_address.cpp
    socket_handle.cpp
    socket_options.cpp
    socket_spec.cpp
    sync_crypto_socket.cpp
    DEPENDS
)
