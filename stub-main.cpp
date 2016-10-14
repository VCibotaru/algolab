#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* #include <boost/graph/adjacency_list.hpp> */
/* #include <boost/graph/dijkstra_shortest_paths.hpp> */
/* #include <boost/graph/kruskal_min_spanning_tree.hpp> */

/* using namespace boost; */
/* typedef adjacency_list<vecS, vecS, undirectedS, no_property, */ 
/*         property<edge_weight_t, int>> Graph; */
/* typedef graph_traits<Graph>::vertex_descriptor Vertex; */
/* typedef graph_traits<Graph>::vertex_iterator VertexIterator; */
/* typedef graph_traits<Graph>::edge_descriptor Edge; */
/* typedef graph_traits<Graph>::edge_iterator EdgeIterator; */
/* typedef property_map<Graph, edge_weight_t>::type WeightMap; */
/* typedef property_map<Graph, vertex_index_t>::type IndexMap; */

int doTest() {
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  unsigned test_count;
  std::cin >> test_count;
  for (unsigned i = 0 ; i < test_count ; ++i) {
    std::cout << doTest() << "\n";
  }
  return 0;
}
