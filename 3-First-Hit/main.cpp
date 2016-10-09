#include <iostream>
#include <vector>
#include <string>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Ray_2.h>
#include <CGAL/Point_2.h>
#include <CGAL/Segment_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Ray_2<Kernel> Ray;
typedef CGAL::Point_2<Kernel> Point;
typedef CGAL::Segment_2<Kernel> Segment;

long ft_to_long(const Kernel::FT& x) {
  double a = std::floor(CGAL::to_double(x));
  while (a > x) a -= 1;
  while (a+1 <= x) a += 1;
  return a;
}

void find_best(const Point &source, boost::optional<Point> &best, 
    const Point &current) {
  if (!best || (CGAL::squared_distance(source, *best) > 
        CGAL::squared_distance(source, current))) {
      best = current;
    }
  }

void doTest(int n) {
  long x, y, a, b;
  std::cin >> x >> y >> a >> b;
  Point source(x, y);
  Point dest(a, b);
  Ray ray(source, dest);
  long r, s, t, u;
  boost::optional<Point> best;

  for (int i = 0 ; i < n ; ++i) {
    std::cin >> r >> s >> t >> u; 
    Segment segment(Point(r, s), Point(t, u));
    if (CGAL::do_intersect(ray, segment)) {
      auto intersection = CGAL::intersection(ray, segment);
      if (const Point *p = boost::get<Point>(&*intersection)) {
        find_best(source, best, *p);
      }
      else if (const Segment *s = boost::get<Segment>(&*intersection)) {
        find_best(source, best, s->source());
        find_best(source, best, s->target());
      }
    }
  }
  if (!best) {
    std::cout << "no\n";
    return;
  }
  std::cout << ft_to_long(best->x()) << " " << ft_to_long(best->y()) << "\n"; 
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    doTest(n);
  }
  return 0;
}
