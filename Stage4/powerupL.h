#pragma once

#include "gameobject.h"
#include "gamestate.h"
#include <sgg\graphics.h>
#include "box.h"
#include "player.h"
#include <string>
#include "util.h"

class PowerUpl : public Box, public GameObject {

    graphics::Brush powerupL_brush;
    graphics::Brush powerupL_brush_debug;
    const float w_g = 0.5f;
    const float h_g = 0.5f;

    std::string backround = "life.png";

public:
    void update(float dt) override {
        float delta_time = dt / 1000.0f;


        float xDistance = abs(m_state->getPlayer()->m_pos_x - m_pos_x);
        float yDistance = abs(m_state->getPlayer()->m_pos_y - m_pos_y);



        float yy = m_state->getPlayer()->m_pos_y - m_pos_y;
        float xx = m_state->getPlayer()->m_pos_x - m_pos_x;

        float kk = sqrt(xx * xx + yy * yy);

        xx /= kk;
        yy /= kk;


        m_pos_y += yy * delta_time * delta_time * 200;

        GameObject::update(dt);
    }

    void draw() override {
        float x = m_pos_x + m_state->m_global_offset_x;
        float y = m_pos_y + m_state->m_global_offset_y;
        powerupL_brush.texture = m_state->getFullAssetPath(backround);
        graphics::drawRect(x, y, w_g, h_g, powerupL_brush);

        if (m_state->m_debugging)
            graphics::drawRect(x, y, w_g, h_g, powerupL_brush_debug);
    }

    void init() override {
        Box(m_pos_x, m_pos_y, w_g, h_g);
        powerupL_brush.outline_opacity = 0.0f;
        powerupL_brush_debug.fill_opacity = 0.1f;
        SETCOLOR(powerupL_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
        SETCOLOR(powerupL_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);
    }

    PowerUpl(std::string name = "power", float x = 5.0f, float y = 10.0f) : GameObject(name) {
        this->m_pos_x = x;
        this->m_pos_y = y;
    }
};
