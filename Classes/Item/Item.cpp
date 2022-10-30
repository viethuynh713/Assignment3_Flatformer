#include "Item.h"


Item::Item(){

}

Item::~Item()
{
}

void Item::applyEffect(const Player& i_player)
{
}

bool operator==(Item const& i_item, Item const& o_item)
{
    return i_item.m_id == o_item.m_id && i_item.m_position == i_item.m_position;
}
