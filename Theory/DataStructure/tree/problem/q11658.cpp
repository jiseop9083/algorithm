//백준 11658번 구간 합 구하기3
//그냥 세그먼트로 해보자

#include <iostream>
using namespace std;

int n, m;
long long table[1025][1025];
long long tree[2100][2100];


long long init(int xstart, int xend, int ystart, int yend, int xindex, int yindex) {
	if (xstart == xend && ystart == yend) {
		tree[yindex][xindex] = table[ystart][xstart];
	}
	else {
		int xmid = (xstart + xend) / 2;
		int ymid = (ystart + yend) / 2;
		tree[yindex][xindex] = 
			(init(xstart, xmid, ystart, ymid, (xindex * 2) + 1, (2 * yindex) + 1) +
			init(xstart, xmid, ymid + 1, yend, (xindex * 2) + 1, (2 * yindex) + 2) +
			init(xmid + 1, xend, ystart, ymid, (xindex * 2) + 2, (2 * yindex) + 1) +
			init(xmid + 1, xend, ymid + 1, yend, (xindex * 2) + 2, (2 * yindex) + 2));
	}
	return tree[yindex][xindex];
}

long long sum(int xindex, int yindex, int xstart, int xend, int ystart, int yend, int xleft, int xright, int yleft, int yright) {
	//cout << xleft  << " " << xright << " " << xstart << " " << xend << "    " << yleft << " " << yright << " " << ystart << " " << yend << "\n";
	if (xstart > xright || xend < xleft || ystart > yright || yend < yleft) {
		return 0;//yleft는 위쪽 
	}
	else if (xleft <= xstart && xend <= xright && yleft <= ystart && yend <= yright) {
		return tree[yindex][xindex];
	}
	else {
		int xmid = (xstart + xend) / 2;
		int ymid = (ystart + yend) / 2;
		return (sum((2 * xindex) + 1, (2 * yindex) + 1, xstart, xmid, ystart, ymid, xleft, xright, yleft, yright) +
			sum((2 * xindex) + 1, (2 * yindex) + 2, xstart, xmid, ymid + 1, yend, xleft, xright, yleft, yright) +
			sum((2 * xindex) + 2, (2 * yindex) + 1, xmid + 1, xend, ystart, ymid, xleft, xright, yleft, yright) +
			sum((2 * xindex) + 2, (2 * yindex) + 2, xmid + 1, xend, ymid + 1, yend, xleft, xright, yleft, yright));
	}
}

void change(int xpos, int ypos, long long num, int xindex, int yindex, int xstart, int xend, int ystart, int yend) {
	if (xpos < xstart || xpos > xend || ypos < ystart || ypos > yend) {
		return;
	}
	tree[yindex][xindex] += num;
	if (xstart != xend || ystart != yend) {
		int xmid = (xstart + xend) / 2;
		int ymid = (ystart + yend) / 2;
		change(xpos, ypos, num, (xindex * 2) + 1, (yindex * 2) + 1, xstart, xmid, ystart, ymid);
		change(xpos, ypos, num, (xindex * 2) + 1, (yindex * 2) + 2, xstart, xmid, ymid + 1, yend);
		change(xpos, ypos, num, (xindex * 2) + 2, (yindex * 2) + 1, xmid+ 1, xend, ystart, ymid);
		change(xpos, ypos, num, (xindex * 2) + 2, (yindex * 2) + 2, xmid + 1, xend, ymid + 1, yend);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}
	init(0, n - 1, 0, n - 1, 0, 0);
	for (int i = 0; i < m; i++) {
		int w;
		cin >> w;
		if (w == 0) {
			long long c;
			int x, y;
			cin >> x >> y >> c;
			long long diff = c - table[y-1][x-1];
			table[y-1][x-1] = c;
			change(x-1, y-1, diff, 0, 0, 0, n - 1, 0, n - 1);
		}
		else if (w == 1) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(0, 0, 0, n - 1, 0, n - 1, x1-1, x2-1, y1-1, y2-1) << "\n";
		}
	}
	return 0;
}