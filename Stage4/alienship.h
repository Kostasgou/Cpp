#pragma once
#include "gameobject.h"
#include <sgg\graphics.h>
#include "box.h"
#include "util.h"


class AlienShip : public Box, public GameObject {

    graphics::Brush alienship_brush;
    graphics::Brush alienship_brush_debug;
    const float w_g = 1.0f;
    const float h_g = 1.0f;
    const float m_accel_horizontal = 20.0f;
    const float m_accel_vertical = 300.1f;
    const float m_max_velocity = 5.0f;
    const float m_gravity = 10.0f;
public:
    float move = 0.0f;
    int k = 1;


public:
    void update(float dt) override;
    void draw() override;
    void init() override;
    float m_speed = 200.0f;          // Αρχική ταχύτητα
    float m_original_speed = 200.0f; // Αποθήκευση της αρχικής ταχύτητας
    float m_slow_down_timer = 0.0f;  // Χρόνος μείωσης ταχύτητας


    AlienShip(std::string name = "block", float x = 0.0f, float y = 0.0f) : GameObject(name){
        this->m_pos_x = x;
        this->m_pos_y = y;

    }


};
