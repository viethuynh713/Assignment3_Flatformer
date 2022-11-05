#include "Star.h"

Star::Star()
{
}

Star::~Star()
{
}

void Star::applyEffect(Player* i_player)
{
	StarChange(i_player);
	int ran = rand() % 2;
	if (ran == 1) {
		LivesChange(i_player);
	}
}

void Star::StarChange(Player* i_player) {
	i_player->addStar();
}

void Star::LivesChange(Player* i_player)
{
	i_player->addLive();
}

void Star::SpeedChange(Player* i_player)
{
	i_player->addSpeed();
}
