#include "Star.h"

Star::Star()
{
}

Star::~Star()
{
}

void Star::applyEffect(const Player& i_player)
{
}

void Star::LivesChange(Player& i_player)
{
	i_player.addLive();
}

void Star::SpeedChange(Player& i_player)
{
	i_player.addSpeed();
}
