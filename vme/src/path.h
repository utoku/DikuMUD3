#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <boost/graph/strong_components.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include "structs.h"
#include "utils.h"
#include "interpreter.h"
#include "comm.h"
#include "db.h"
#include "handler.h"
#include "utility.h"
#include "common.h"
#include "constants.h"
#include <vector>
int path_weight (unit_data * from, unit_data *to, int dir);
void create_sc_graph (int num_of_sc);
void create_sc_dijkstra ();
extern unit_data *room_head;

using namespace boost;
namespace boost {
enum edge_dir_t { edge_dir = 101 };
BOOST_INSTALL_PROPERTY(edge, dir);
}

typedef adjacency_list < vecS, vecS, directedS, no_property,
        property < edge_weight_t, int > >graph_world_t;
typedef adjacency_list < vecS, vecS, directedS, no_property,
        property < edge_weight_t, int,
        property < edge_dir_t, int > > >graph_t;

extern std::vector < graph_t > sc_graphs;
extern std::vector < std::vector< unit_data * > >sc_room_ptr;
using namespace std;
