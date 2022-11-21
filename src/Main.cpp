#include "Platform/Platform.hpp"
#include "Bar.h"

int Random(int min, int max);

int Random(int min, int max)
{
  return min + rand() % (max - min);
}

int main()
{
	util::Platform platform;

	std::cout << "Hello World!" << std::endl;

	int resolutionX(1280), resolutionY(720);
	sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Sorting Algorithms", sf::Style::Close);
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	Bar mBar;
	mBar.setColor(sf::Color(0,0,0));
	mBar.setLength(resolutionX/2,5);
	mBar.setLocation(-resolutionX/2 + mBar.getLengthX()/2,-resolutionY+5);

	Bar mainBar;
	mainBar.setColor(sf::Color(252,235,90));
	mainBar.setLength(5,resolutionY);
	mainBar.setLocation(-resolutionX/2,0);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// window.clear();
		window.clear(sf::Color(223,53,33));
		window.draw(sf::RectangleShape(*(mBar.getRect())));
		window.draw(sf::RectangleShape(*(mainBar.getRect())));
		window.display();

		// mBar.setLocation(-Random(0,resolutionX),-Random(0,resolutionY));
		// mBar.setLength(Random(0,resolutionX/10),Random(0,resolutionY/10));
		// mBar.setColor(sf::Color(Random(0,255), Random(0,255), Random(0,255)));
	}

	return 0;
}
