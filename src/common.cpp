#include "common.h"
#include <fstream>
#include <sstream>

std::optional<std::string> LoadTextFile(const std::string& filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        SPDLOG_ERROR("failed to open file: {}", filename);
        return {}; // optional의 비어있는 객체를 반환한다는 뜻
    }
    std::stringstream text;
    text << fin.rdbuf();
    return text.str();
}