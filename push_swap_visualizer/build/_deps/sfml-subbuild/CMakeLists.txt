# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(sfml-populate NONE)

include(ExternalProject)
ExternalProject_Add(sfml-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-sources.zip"
                    SOURCE_DIR          "/nfs/homes/dsa-mora/42lisboa/push_swap/push_swap_visualizer/build/_deps/sfml-src"
                    BINARY_DIR          "/nfs/homes/dsa-mora/42lisboa/push_swap/push_swap_visualizer/build/_deps/sfml-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
