cmake_minimum_required(VERSION 3.20)

project(Falloban
    VERSION 0.1.0
    LANGUAGES CXX
)

# ============================================================
# Developer options
# ============================================================

option(FALLOBAN_ENABLE_LTO
    "Enable LTO where supported"
    ON
)

option(FALLOBAN_RELWITHDEBINFO_O3
    "Use -O3 for RelWithDebInfo on GCC/Clang"
    ON
)

# ============================================================
# Dependencies
# ============================================================

find_package(raylib 5.5 REQUIRED)

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)

FetchContent_MakeAvailable(nlohmann_json)

# ============================================================
# Sources
# ============================================================

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/core/*.cpp"
)

# ============================================================
# Target
# ============================================================

add_executable(Falloban
    ${SOURCES}
)

target_compile_features(Falloban
    PRIVATE
        cxx_std_23
)

target_include_directories(Falloban
    PRIVATE
        "${PROJECT_SOURCE_DIR}/core"
)

target_link_libraries(Falloban
    PRIVATE
        raylib
        nlohmann_json::nlohmann_json
)

# ============================================================
# LTO
# ============================================================

if(FALLOBAN_ENABLE_LTO)

    include(CheckIPOSupported)

    check_ipo_supported(
        RESULT ipo_supported
        OUTPUT ipo_error
        LANGUAGES CXX
    )

    if(ipo_supported)

        set_property(TARGET Falloban PROPERTY
            INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE
        )

        set_property(TARGET Falloban PROPERTY
            INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE
        )

        message(STATUS "LTO: supported")

    else()

        message(STATUS "LTO: not supported (${ipo_error})")

    endif()

endif()

# ============================================================
# RelWithDebInfo / profiling
# ============================================================

if(
    FALLOBAN_RELWITHDEBINFO_O3
    AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang"
)

    target_compile_options(Falloban
        PRIVATE
            $<$<CONFIG:RelWithDebInfo>:-O3>
    )

endif()

# ============================================================
# Installation
# ============================================================

install(TARGETS Falloban
    RUNTIME DESTINATION bin
)

if(EXISTS "${PROJECT_SOURCE_DIR}/resources")

    install(
        DIRECTORY "${PROJECT_SOURCE_DIR}/resources/"
        DESTINATION "share"
    )

endif()

# ============================================================
# Packaging
# ============================================================

set(CPACK_PACKAGE_NAME "Falloban")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_VENDOR "denzov")

set(CPACK_GENERATOR
    "TGZ;ZIP"
)

include(CPack)
