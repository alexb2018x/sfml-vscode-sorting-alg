#include <SFML/Graphics.hpp>

class Bar
{
public:
	Bar();
	virtual ~Bar();

	Bar(const Bar& other);
	Bar& operator=(const Bar& other);

	Bar(Bar&& other) noexcept;
	Bar& operator=(Bar&& other) noexcept;

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
	sf::RectangleShape* rect;
};

class HorizontalBar : public Bar
{
public:
	HorizontalBar();
	HorizontalBar(int col, int val);
	~HorizontalBar();

	HorizontalBar(const HorizontalBar& other);
	HorizontalBar& operator=(const HorizontalBar& other);

	HorizontalBar(HorizontalBar&& other) noexcept;
	HorizontalBar& operator=(HorizontalBar&& other) noexcept;

	void setColAndVal(int col, int val);

private:
	int column, value;
};
