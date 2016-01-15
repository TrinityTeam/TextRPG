#include "scene.hpp"



Scene::Scene(const std::string& title):
    title {title} {

}



const std::string& Scene::getTitle() const {
    return title;
}
