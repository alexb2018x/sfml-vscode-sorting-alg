#include "Platform/Platform.hpp"
#include "Bar.h"
#include "Consts.h"

using namespace constants;


int Random(int min, int max);

int Random(int min, int max)
{
  return min + rand() % (max - min);
}

int main()
{
	util::Platform platform;

	std::cout << "Hello World!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(screenResolutionX, screenResolutionY), "Sorting Algorithms", sf::Style::Close);
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	sf::Color backgroundColor(223,53,33), verticalBarColor(252,235,90), horizontalBarColor(sf::Color::Black);

	Bar mainBar;
	mainBar.setColor(verticalBarColor);
	mainBar.setLength(5,screenResolutionY);
	mainBar.setLocation(-screenResolutionX/2,0);

	HorizontalBar mHBar;
	mHBar.setColAndVal(3, 200);
	mHBar.setColor(horizontalBarColor);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(backgroundColor);
		window.draw(sf::RectangleShape(*(mHBar.getRect())));
		window.draw(sf::RectangleShape(*(mainBar.getRect())));
		window.display();
	}

	return 0;
}
