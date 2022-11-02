#include "TileNode.h"

USING_NS_CC;

TileNode::TileNode()
{
	
}

TileNode::TileNode(int x, int y) {
	
}

TileNode::~TileNode()
{
	
}

bool TileNode::isCollide(Player& player) {
	auto boundingBox = this->getBoundingBox();
	auto playerBoundingBox = player.getBoundingBox();
	if (boundingBox.intersectsRect(playerBoundingBox)) {
		this->doInteract(player);
		return true;
	}
	return false;
}

void TileNode::doInteract(Player& player) {

}