#include "Item.h"

USING_NS_CC;

Item::Item(){
    m_id = 0;
}

Item::~Item()
{
}

void Item::applyEffect(Player* i_player)
{
}

bool operator==(Item const& i_item, Item const& o_item)
{
    return i_item.m_id == o_item.m_id && i_item.getPosition() == i_item.getPosition();
}
