struct Point{
	int x;
	int y;
};
struct Points {
	Point* points;
	int noOfPoints;
};
class AbstractItem {
public:
	virtual void onDraw() {};
	virtual Points* getPoints() {};
};