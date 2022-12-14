#include "Bar.h"
#include "Consts.h"

using namespace constants;

Bar::Bar() :
	locX(0),
	locY(0),
	lenX(5),
	lenY(10)
{
	rect = new sf::RectangleShape(sf::Vector2f(lenX, lenY));
	rect->setOrigin(locX, locY);
	rect->setFillColor(sf::Color::Black);
	rect->setOutlineThickness(0.0f);
	rect->setOutlineColor(sf::Color::Black);
}

Bar::~Bar()
{
	delete rect;
}

Bar::Bar(const Bar& other)
{
	locX = other.locX;
	locY = other.locY;
	lenX = other.lenX;
	lenY = other.lenY;
	rect = new sf::RectangleShape(sf::Vector2f(lenX, lenY));
	rect->setOrigin(locX, locY);
	rect->setFillColor(other.rect->getFillColor());
	rect->setOutlineThickness(other.rect->getOutlineThickness());
	rect->setOutlineColor(other.rect->getOutlineColor());
}
Bar& Bar::operator=(const Bar& other)
{
	if (this == &other)
		return *this;

	locX = other.locX;
	locY = other.locY;
	lenX = other.lenX;
	lenY = other.lenY;
	rect = new sf::RectangleShape(sf::Vector2f(lenX, lenY));
	rect->setOrigin(locX, locY);
	rect->setFillColor(other.rect->getFillColor());
	rect->setOutlineThickness(other.rect->getOutlineThickness());
	rect->setOutlineColor(other.rect->getOutlineColor());
	return *this;
}

Bar::Bar(Bar&& other) noexcept
{
	locX = other.locX;
	locY = other.locY;
	lenX = other.lenX;
	lenY = other.lenY;

	rect = other.rect;
	other.rect = NULL;
}

Bar& Bar::operator=(Bar&& other) noexcept
{
	locX = other.locX;
	locY = other.locY;
	lenX = other.lenX;
	lenY = other.lenY;

	rect = other.rect;
	other.rect = NULL;
	return *this;
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

HorizontalBar::HorizontalBar() :
	Bar(),
	leftPart(true)
{
	setColAndVal(0, 100);
}

HorizontalBar::HorizontalBar(int col, int val, bool leftPart) :
	Bar(),
	leftPart(leftPart)
{
	setColAndVal(col, val);
}

HorizontalBar::~HorizontalBar()
{
}

HorizontalBar::HorizontalBar(const HorizontalBar& other) :
	Bar(other),
	leftPart(other.leftPart)
{
	setColAndVal(other.column, other.value);
}
HorizontalBar& HorizontalBar::operator=(const HorizontalBar& other)
{
	Bar::operator=(other);
	leftPart = other.leftPart;
	setColAndVal(other.column, other.value);
	return *this;
}

HorizontalBar::HorizontalBar(HorizontalBar&& other) noexcept :
	Bar(std::move(other)),
	leftPart(other.leftPart)
{
	setColAndVal(other.column, other.value);
}

HorizontalBar& HorizontalBar::operator=(HorizontalBar&& other) noexcept
{
	Bar::operator=(other);
	leftPart = other.leftPart;
	setColAndVal(other.column, other.value);
	return *this;
}

void HorizontalBar::setColAndVal(int col, int val)
{
	column = col;
	value = val;

	setLength(val, 5);
	// setLocation(-screenResolutionX / 2 + lenX / 2, -screenResolutionY + lenY * (1 + column));
	if (leftPart)
		setLocation(-screenResolutionX / 2 + lenX, -screenResolutionY + lenY * (1 + column));
	else
		setLocation(-screenResolutionX / 2, -screenResolutionY + lenY * (1 + column));
}

void HorizontalBar::swap(HorizontalBar& other)
{
	int tmpVal = value;
	setColAndVal(column, other.value);
	other.setColAndVal(other.column, tmpVal);
}

bool HorizontalBar::operator<(const HorizontalBar& other) const
{
	return value < other.value;
}

void HorizontalBar::setIfItIsLeftPart(bool val)
{
	leftPart = val;
}