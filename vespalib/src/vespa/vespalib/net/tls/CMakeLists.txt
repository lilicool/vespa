# Copyright 2018 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
vespa_add_library(vespalib_vespalib_net_tls OBJECT
    SOURCES
    crypto_codec.cpp
    crypto_codec_adapter.cpp
    crypto_exception.cpp
    maybe_tls_crypto_engine.cpp
    maybe_tls_crypto_socket.cpp
    peer_credentials.cpp
    peer_policies.cpp
    policy_checking_certificate_verifier.cpp
    protocol_snooping.cpp
    tls_context.cpp
    tls_crypto_engine.cpp
    tls_crypto_socket.cpp
    transport_security_options.cpp
    transport_security_options_reading.cpp
    DEPENDS
)
find_package(OpenSSL)
target_include_directories(vespalib_vespalib_net_tls PUBLIC ${OPENSSL_INCLUDE_DIR})

