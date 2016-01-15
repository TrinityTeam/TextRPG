#pragma once
#include <string>



class Scene {
public:
    Scene(const std::string& title);

    const std::string& getTitle() const;

private:
    std::string title;

};
