aux_source_directory(. NLOHMANN_JSON_SRCS)

add_executable(nlohmann_json_demo ${NLOHMANN_JSON_SRCS})
target_link_libraries(nlohmann_json_demo CONAN_PKG::nlohmann_json)
