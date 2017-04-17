#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
point pivot;
stack<point> convex_hull;
const double PI = 3.141592654;
#define x real()
#define y imag()
bool comp(point a, point b){
	if(arg(a-pivot) == arg(b-pivot))return abs(a-pivot) > abs(b-pivot);
	return arg(a-pivot) > arg(b-pivot);
}
int orientation(point p1, point p2, point p3){
	double angle = remainder(arg(p1-p2)-arg(p3-p2),2*PI);
	if(angle == 0)return 0;
	if(angle > 0)return -1;
	if(angle < 0)return 1;
}
point second_from_top(){
	point t = convex_hull.top();
	convex_hull.pop();
	point s_t = convex_hull.top();
	convex_hull.push(t);
	return s_t;
}
int main(){
	int n;
	cin >> n;
	vector<point> points(n);
	int lowest_index = 0;
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a>> b;
		points[i] = point(a,b);
		if(points[lowest_index].y >= b){
			if(points[lowest_index].y == b && points[lowest_index].x > a){
				lowest_index = i;
			}
			else lowest_index = i;
		}
	}
	pivot = points[lowest_index];
	points.erase(points.begin()+lowest_index);
	sort(points.begin(),points.end(),comp);
	convex_hull.push(pivot);
	convex_hull.push(points[0]);
	for(int i = 1; i < points.size(); i++){
		while(orientation(second_from_top(),convex_hull.top(),points[i]) != 1){
			convex_hull.pop();
		}
		convex_hull.push(points[i]);
	}
	cout << convex_hull.size() << endl;
	while(!convex_hull.empty()){
		cout << convex_hull.top() << endl;
		convex_hull.pop();
	}
}
