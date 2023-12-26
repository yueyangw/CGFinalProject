//
// Created by York Wu on 2023/12/20.
//

#ifndef PROJECT_FILESYSTEM_H
#define PROJECT_FILESYSTEM_H

#include <string>
#include <cstdlib>

class FileSystem {
private:
    typedef std::string (*Builder)(const std::string &path);

public:
    static std::string getPath(const std::string &path) {
        static std::string (*pathBuilder)(std::string const &) = getPathBuilder();
        return (*pathBuilder)(path);
    }

private:
    static std::string const &getRoot() {
        static char const *envRoot = getenv("LOGL_ROOT_PATH");
        static char const *givenRoot = (envRoot != nullptr ? envRoot : "/Users/joyce/Projects/CLionProjects/CGFinalProject/src");
        static std::string root = (givenRoot != nullptr ? givenRoot : "");
        return root;
    }

    //static std::string(*foo (std::string const &)) getPathBuilder()
    static Builder getPathBuilder() {
        if (getRoot() != "")
            return &FileSystem::getPathRelativeRoot;
        else
            return &FileSystem::getPathRelativeBinary;
    }

    static std::string getPathRelativeRoot(const std::string &path) {
        return getRoot() + std::string("/") + path;
    }

    static std::string getPathRelativeBinary(const std::string &path) {
        return "../../../" + path;
    }


};

#endif //PROJECT_FILESYSTEM_H
