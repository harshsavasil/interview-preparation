# Given a directed unweighted graph. perform dfs

def dfs(visited, node, directed_graph):
    visited[node] = True
    # print('{0}->'.format(node))
    for neighbor in directed_graph[node]:
        if not visited[neighbor]:
            dfs(visited, neighbor, directed_graph)


if __name__ == '__main__':
    directed_graph = {
        1: [2],
        2: [3],
        3: [2, 4, 5],
        4: [5],
        5: [],
        6: [7],
        7: []
    }

    num_of_nodes = len(directed_graph)
    num_of_connected_components = 0
    visited = {node: False for node in directed_graph}
    for node in directed_graph:
        if not visited[node]:
            num_of_connected_components += 1
            dfs(visited, node, directed_graph)
    print(num_of_connected_components)
