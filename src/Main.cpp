#include "Bar.h"
#include "Consts.h"
#include "Platform/Platform.hpp"
#include "SortingAlg.h"
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
	std::vector<HorizontalBar> mHBarsLeft, mHBarsRight;
	mHBarsLeft.reserve(maxColumns);
	mHBarsRight.reserve(maxColumns);
	for (int i = 0; i < maxColumns; i++)
	{
		int rand = Random(1, screenResolutionX / 2);
		mHBarsLeft.push_back(HorizontalBar(i, rand));
		mHBarsRight.push_back(HorizontalBar(i, rand, false));
	}

	cout << "Vector size: " << mHBarsLeft.size() << endl;

	BubbleSort mBSort(&mHBarsLeft);

	int steps2Avoid(
		3
		// 10
		),
		stepsCounter(0);

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
		for (uint i = 0; i < mHBarsLeft.size(); i++)
			window.draw(sf::RectangleShape(*(mHBarsLeft[i].getRect())));
		for (uint i = 0; i < mHBarsRight.size(); i++)
			window.draw(sf::RectangleShape(*(mHBarsRight[i].getRect())));

		window.draw(sf::RectangleShape(*(mainBar.getRect())));
		window.display();
	}

	cout << "---Finish---" << endl;
	return 0;
}
