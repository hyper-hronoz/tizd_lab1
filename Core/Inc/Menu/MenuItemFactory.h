#pragma once
#include "MenuItem.h"
#include "functional"

class MenuItemFactory {
 private:
    uint16_t id = 0;

 public:
    MenuItem* create(std::string, std::function<void()>);
};

