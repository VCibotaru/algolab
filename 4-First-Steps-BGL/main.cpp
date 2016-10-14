#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>

using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS, no_property, 
        property<edge_weight_t, int>> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::vertex_iterator VertexIterator;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::edge_iterator EdgeIterator;
typedef property_map<Graph, edge_weight_t>::type WeightMap;
typedef property_map<Graph, vertex_index_t>::type IndexMap;

const int SOURCE_VERTEX = 0;

void doTest() {
  int n, m, source, dest, w;
  Edge e;
  bool success;
  std::cin >> n >> m;
  Graph g(n);
  WeightMap weight_map = boost::get(edge_weight, g);
  for (int i = 0 ; i < m ; ++i) {
    std::cin >> source >> dest >> w;
    boost::tie(e, success) = add_edge(source, dest, g);
    weight_map[e] = w;
  }

  int MST_w = 0;
  std::vector<Edge> edges;
  boost::kruskal_minimum_spanning_tree(g, std::back_inserter(edges));
  for (Edge &e: edges) {
    MST_w += weight_map[e];
  }
  std::cout << MST_w << " ";



  std::vector<int> weights;
  std::vector<int> d(num_vertices(g));
  boost::dijkstra_shortest_paths(g, SOURCE_VERTEX, distance_map(
        make_iterator_property_map(d.begin(), get(vertex_index, g))));
  std::cout << *std::max_element(d.begin(), d.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  unsigned test_count;
  std::cin >> test_count;
  for (unsigned i = 0 ; i < test_count ; ++i) {
    doTest();
    std::cout << "\n";
  }
  return 0;
}
