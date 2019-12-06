#include <iostream>

enum Orientation
{
	Vertical,
	Horizontal
};

struct Point
{
	int x;
	int y;
};

struct Wire
{
	Point start;
	Point end;

	Wire(const Point& s, const Point& e)
	{
		start = {s.x, s.y};
		end = {e.x, e.y};

		if (s.x > e.x) {
			start.x = e.x;
			end.x = s.x;
		}
		if (s.y > e.y) {
			start.y = e.y;
			end.y = s.y;
		}
	}

	Orientation orientation()
	{
		if (start.x == end.x)
			return Orientation::Vertical;
		if (start.y == end.y)
			return Orientation::Horizontal;
		return (Orientation)-1;
	}
};

const Point intersection(Wire& a, Wire& b)
{
	if (a.orientation() == Orientation::Vertical) {
		if (a.start.x >= b.start.x && a.start.x <= b.end.x && b.start.y >= a.start.y && b.start.y <= a.end.y) {
			return {a.start.x, b.start.y};
		}
	}

	if (a.orientation() == Orientation::Horizontal) {
		if (b.start.x >= a.start.x && b.start.x <= a.end.x && a.start.y >= b.start.y && a.start.y <= b.end.y) {
			return {b.start.x, a.start.y};
		}
	}
	return {-1, -1};
}

int main()
{
	Wire a({2, 5}, {2, 0});
	Wire b({0, 3}, {5, 3});

	const Point x = intersection(a, b);

	std::cout << "Intersection @ (" << x.x << ", " << x.y << ")" << std::endl;

	return 0;
}