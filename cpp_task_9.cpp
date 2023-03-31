#include <iostream>

#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string path;
    std::cout << "Podaj sciezke do katalogu: ";
    std::getline(std::cin, path);

    if (!fs::is_directory(path)) {
        std::cerr << "Podany argument nie jest katalogiem." << std::endl;
        return 1;
    }

    for (const auto &entry: fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.path())) {
            std::cout << entry.path().filename().string() << " " << fs::file_size(entry) << " B" << std::endl;
        }
    }

    return 0;
}