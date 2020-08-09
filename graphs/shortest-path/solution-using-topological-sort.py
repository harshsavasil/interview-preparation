# Given a directed unweighted graph. perform dfs

def dfs(visited, node, directed_graph, topological_order):
    visited[node] = True
    for neighbor in directed_graph[node]:
        if not visited[neighbor[0]]:
            dfs(visited, neighbor[0], directed_graph, topological_order)
    topological_order.append(node)


if __name__ == '__main__':
    directed_graph = {
        1: [(2, 2)],
        2: [(3, -3), (4, 3)],
        3: [(4, 4), (5, 2)],
        4: [(5, -2)],
        5: [],
        6: [(7, 1)],
        7: []
    }
    start_node = 2
    end_node = 5
    num_of_nodes = len(directed_graph)
    visited = {node: False for node in directed_graph}
    topological_order = []
    dfs(visited, start_node, directed_graph, topological_order)
    topological_order.reverse()
    print('Topological Order: {0}'.format(topological_order))
    if end_node in topological_order:
        # initialise shortest path from start_node as 0
        shortest_path = {node: float('inf') for node in topological_order}
        shortest_path[start_node] = 0  # starting point
        for node in topological_order:
            for neighbor in directed_graph[node]:
                shortest_path[neighbor[0]] = min(
                    shortest_path[neighbor[0]], shortest_path[node] + neighbor[1])
        print('Minimum Cost Path from starting node {0} is as follows: {1}.'.format(
            start_node, shortest_path))
    else:
        print('{0} is not reachable from {1}.'.format(end_node, start_node))
