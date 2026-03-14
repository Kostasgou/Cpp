#include "box.h"
#include "block.h"
#include "util.h"
#include <cmath>
void block::update(float dt)
{
    GameObject::update(dt);
}

void block::draw()
{
    float x = m_pos_x + m_state->m_global_offset_x;
    float y = m_pos_y + m_state->m_global_offset_y;

    blockk_brush.texture = m_state->getFullAssetPath("asteroids.png");

    graphics::drawRect(x, y, 1.8*w_g, 1.8*h_g, blockk_brush);

    if (m_state->m_debugging)
        graphics::drawRect(x, y, w_g, h_g, blockk_brush_debug);

}




void block::init()
{
    Box(m_pos_x, m_pos_y, w_g, h_g);
    blockk_brush.outline_opacity = 0.0f;
    blockk_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(blockk_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
    SETCOLOR(blockk_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);

}




