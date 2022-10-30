#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::AddItem(const Item& i_item)
{
    m_itemList.emplace_back(i_item);
}

void ItemManager::RemoveItem(const Item& i_item)
{

}

void ItemManager::ApplyEffect(Player& i_player)
{
}

void ItemManager::GenerateItem()
{
    m_itemList = std::vector<Item>();
}
