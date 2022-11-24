#include <vector>

#include "Bar.h"
#include "Consts.h"
#include "Platform/Platform.hpp"
#include "SortingAlg.h"

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

	cout << "---Start---" << endl;

	sf::RenderWindow window(sf::VideoMode(screenResolutionX, screenResolutionY), "Sorting Algorithms", sf::Style::Close);
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	sf::Color backgroundColor(223, 53, 33), verticalBarColor(252, 235, 90);

	Bar mainBar;
	mainBar.setColor(verticalBarColor);
	mainBar.setLength(4, screenResolutionY);
	mainBar.setLocation(-screenResolutionX / 2 + mainBar.getLengthX() / 2, 0);

	int maxColumns = screenResolutionY / 5;
	std::vector<HorizontalBar> mHBars;
	mHBars.reserve(maxColumns);
	for (int i = 0; i < maxColumns; i++)
		mHBars.push_back(HorizontalBar(i, Random(1, screenResolutionX / 2)));

	cout << "Vector size: " << mHBars.size() << endl;

	BubbleSort mBSort(&mHBars);

	int steps2Avoid(10), stepsCounter(0);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(backgroundColor);

		stepsCounter++;
		if (stepsCounter >= steps2Avoid)
		{
			stepsCounter = 0;
			mBSort.doStep();
		}
		for (uint i = 0; i < mHBars.size(); i++)
			window.draw(sf::RectangleShape(*(mHBars[i].getRect())));

		window.draw(sf::RectangleShape(*(mainBar.getRect())));
		window.display();
	}

	cout << "---Finish---" << endl;
	return 0;
}
