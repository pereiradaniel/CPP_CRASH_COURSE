// Listing 4-24

struct Point {
	int x, y;

};

Point make_transpose(Point p) {
	int tmp = p.x;
	p.x = p.y;
	return p;
}