#include "Bar.h"
#include "Consts.h"
#include "Platform/Platform.hpp"
#include <vector>

using namespace std;
using namespace constants;

int Random(int min, int max);

int Random(int min, int max)
{
	return min + rand() % (max - min);
}

int main()
{
	util::Platform platform;

	cout << "Hello World!" << endl;

	sf::RenderWindow window(sf::VideoMode(screenResolutionX, screenResolutionY), "Sorting Algorithms", sf::Style::Close);
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	sf::Color backgroundColor(223, 53, 33), verticalBarColor(252, 235, 90), horizontalBarColor(sf::Color::Black);

	Bar mainBar;
	mainBar.setColor(verticalBarColor);
	mainBar.setLength(5, screenResolutionY);
	mainBar.setLocation(-screenResolutionX / 2, 0);

	HorizontalBar mHBar(30, 200);
	mHBar.setColor(horizontalBarColor);

	// int nBars2Insert(10);
	// std::vector<HorizontalBar> mHBars;
	// mHBars.reserve(nBars2Insert);
	// for (int i = 0; i < nBars2Insert; i++)
	// 	mHBars.push_back(HorizontalBar(Random(1, screenResolutionX / 2), i));

	std::vector<HorizontalBar> mHBars;
	// mHBars.push_back(mHBar);
	mHBars.push_back(HorizontalBar(0, 40));

	cout << mHBars.size() << endl;
	cout << mHBars[0].getLocationX() << endl;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(backgroundColor);
		// window.draw(sf::RectangleShape(*(mHBar.getRect())));

		window.draw(sf::RectangleShape(*(mHBars.at(0).getRect())));
		// for (uint i = 0; i < mHBars.size(); i++)
		// 	window.draw(sf::RectangleShape(*(mHBars[i].getRect())));

		window.draw(sf::RectangleShape(*(mainBar.getRect())));
		window.display();
	}

	return 0;
}
