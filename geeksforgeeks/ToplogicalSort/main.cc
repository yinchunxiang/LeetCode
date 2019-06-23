//
// Created by alexkkk on 2019-05-11.
//

#include "Graph.h"
#include "ThirdParty/PrettyPrinter/pprint.hpp"

int main(int argc, char* argv[]) {
  Graph<int> graph;
  graph.AddEdge(-1, 0);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  pprint::PrettyPrinter printer;
  {
    auto result = graph.Output(-1);
    printer.print(result);
  }
  {
    auto result = graph.Output(0);
    printer.print(result);
  }
  return 0;
}