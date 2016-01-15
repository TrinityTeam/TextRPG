#pragma once
#include <memory>
#include <json/reader.h>
#include <fstream>
#include "scene.hpp"



class SceneReader {
    using unique_ptr =  std::unique_ptr<Scene>;

public:
    SceneReader() = delete;
    SceneReader(const SceneReader&) = delete;
    SceneReader(SceneReader&&) = delete;

    static unique_ptr readData(const std::string& filepath) {
        Json::Value root;
        std::ifstream in {filepath};
        SceneReader::reader.parse(in, root, false);
        auto scene = std::make_unique<Scene>(root["title"].asString());

        return scene;
    }

private:
    static Json::Reader reader;

};
