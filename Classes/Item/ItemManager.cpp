#include "ItemManager.h"

USING_NS_CC;

ItemManager::ItemManager()
{
    m_itemList = std::vector<Item*>();
}

ItemManager::~ItemManager()
{
}

void ItemManager::AddItem(Item* i_item)
{
    m_itemList.emplace_back(i_item);
}

void ItemManager::RemoveItem(Item i_item)
{
    /*for (auto i = m_itemList.begin(); i != m_itemList.end(); i++) {
        if (i == i_item) {
            m_itemList.erase(i);
        }
    }*/
}

void ItemManager::ApplyEffect(Player& i_player)
{
}

void ItemManager::GenerateItem()
{
    m_itemList = std::vector<Item>();
}
