cmake_minimum_required(VERSION 3.16)

# comentarios
project(ACC_cluster_app VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -pthread)

find_package(Threads REQUIRED)


add_executable(ACC_cluster_app)

target_sources(ACC_cluster_app PRIVATE
                src/main.c
                comm/can_bus.c
                app/app.c
                middleware/middleware.c

                
)

target_include_directories(ACC_cluster_app PRIVATE
                        ${CMAKE_CURRENT_SOURCE_DIR}/comm
                        ${CMAKE_CURRENT_SOURCE_DIR}/middleware
                        ${CMAKE_CURRENT_SOURCE_DIR}/app
)

target_link_libraries(ACC_cluster_app
                        PRIVATE
                        Threads::Threads
)


# Para Yocto
include(GNUInstallDirs)

install(TARGETS ACC_cluster_app
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# install(FILES monitor.service
#         DESTINATION /lib/systemd/system
# )







