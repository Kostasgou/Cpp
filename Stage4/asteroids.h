#pragma once
#include "gameobject.h"
#include <sgg\graphics.h>
#include "box.h"
#include "util.h"


class Asteroids : public Box, public GameObject {

    graphics::Brush Asteroids_brush;
    graphics::Brush Asteroids_brush_debug;
    std::vector<std::string> m_sprites;

    const float w_g = 1.0f;
    const float h_g = 1.0f;


public:
    void update(float dt) override;
    void draw() override;
    void init() override;


    Asteroids(std::string name = "block", float x = 0.0f, float y = 0.0f) : GameObject(name) {
        this->m_pos_x = x;
        this->m_pos_y = y;

    }



};
