#include <SFML/Graphics.hpp>

class Bar
{
public:
	Bar();
	virtual ~Bar();

	sf::RectangleShape* getRect();

	void setLocation(int x, int y);
	int getLocationX();
	int getLocationY();

	void setLength(int x, int y);
	int getLengthX();
	int getLengthY();

	void setColor(sf::Color color);

protected:
	int locX, locY;
	int lenX, lenY;
	sf::RectangleShape *rect;
};

class HorizontalBar : public Bar
{
public:
	HorizontalBar();
	~HorizontalBar();

	void setColAndVal(int col, int val);

private:
	int column, value;
};
