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

std::string doTest(int n) {
  long x, y, a, b;
  std::cin >> x >> y >> a >> b;
  Point source(x, y);
  Point dest(a, b);
  Ray ray(source, dest);
  long r, s, t, u;
  bool got_intersection = false;
  for (int i = 0 ; i < n ; ++i) {
    std::cin >> r >> s >> t >> u; 
    Segment segment(Point(r, s), Point(t, u));
    if (!got_intersection && CGAL::do_intersect(ray, segment)) {
      got_intersection = true;
    }
  }
  return (got_intersection ? "yes" : "no");
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    std::cout << doTest(n) << "\n";
  }
  return 0;
}
