#pragma once
#include <json/reader.h>
#include <memory>
#include <fstream>



template<typename Data>
class DataReader {
public:
    DataReader() = delete;
    DataReader(const DataReader&) = delete;
    DataReader(DataReader&&) = delete;
    virtual ~DataReader() = default;

    static std::unique_ptr<Data> readData(const std::string& filepath) {
        throw std::logic_error("Unspecified data\n");
    }

protected:
    static Json::Value parseFile(const std::string& filepath) {
        Json::Value root;
        std::ifstream in {filepath};
        reader.parse(in, root, false);
        return std::move(root);
    }

    static Json::Reader reader;
};



template<typename T>
Json::Reader DataReader<T>::reader {};
