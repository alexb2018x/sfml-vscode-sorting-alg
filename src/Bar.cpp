#include "Bar.h"
#include "Consts.h"

using namespace constants;


Bar::Bar():locX(0),locY(0),lenX(5), lenY(10)
{
	rect = new sf::RectangleShape(sf::Vector2f(lenX, lenY));
	rect->setOrigin(locX, locY);
	rect->setFillColor(sf::Color(175, 205, 255));
	rect->setOutlineThickness(0.0f);
	rect->setOutlineColor(sf::Color::Black);
}

Bar::~Bar()
{
	delete rect;
}

sf::RectangleShape* Bar::getRect()
{
	return rect;
}

void Bar::setLocation(int x, int y)
{
	locX = x;
	locY = y;
	rect->setOrigin(locX, locY);
}

int Bar::getLocationX()
{
	return locX;
}

int Bar::getLocationY()
{
	return locY;
}

void Bar::setLength(int x, int y)
{
	lenX = x;
	lenY = y;
	rect->setSize(sf::Vector2f(lenX, lenY));
}

int Bar::getLengthX()
{
	return lenX;
}

int Bar::getLengthY()
{
	return lenY;
}

void Bar::setColor(sf::Color color)
{
	rect->setFillColor(color);
}


HorizontalBar::HorizontalBar():Bar()
{
	setColAndVal(0, 100);
	rect->setFillColor(sf::Color::Black);
}

HorizontalBar::~HorizontalBar()
{
}

void HorizontalBar::setColAndVal(int col, int val)
{
	column = col;
	value = val;

	setLength(val * 2, 5);
	setLocation(-screenResolutionX/2 + lenX/2, -screenResolutionY + lenY * (1 + column));
}