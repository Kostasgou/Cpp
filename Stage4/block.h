#pragma once
#include "gameobject.h"
#include <sgg\graphics.h>
#include "box.h"
#include "util.h"


class block : public Box, public GameObject {

    graphics::Brush blockk_brush;
    graphics::Brush blockk_brush_debug;
    const float w_g = 1.0f;
    const float h_g = 1.0f;
   

public:
    void update(float dt) override;
    void draw() override;
    void init() override;
    

    block(std::string name = "block", float x = 0.0f, float y = 0.0f) : GameObject(name) {
        this->m_pos_x = x;
        this->m_pos_y = y;

    }

    

};
