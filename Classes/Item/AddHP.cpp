#include "AddHP.h"

AddHP::AddHP()
{
	Item();
}

AddHP::~AddHP()
{
}

void AddHP::applyEffect(Player* i_player)
{
	HPChange(i_player);
}

void AddHP::HPChange(Player* i_player)
{
	i_player->changeHP(10);
}
