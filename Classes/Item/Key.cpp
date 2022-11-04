#include "Key.h"
Key::Key()
{
}

Key::~Key()
{
}

void Key::applyEffect(Player* i_player)
{
	i_player->addKey(1);
}
