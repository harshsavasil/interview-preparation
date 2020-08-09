# Given a directed unweighted graph. perform dfs

def dfs(visited, node, directed_graph, stack=[]):
    visited[node] = True
    print('{0}->'.format(node))
    for neighbor in directed_graph[node]:
        if not visited[neighbor]:
            dfs(visited, neighbor, directed_graph, stack)
    stack.append(node)


if __name__ == '__main__':
    directed_graph = {
        1: [2],
        2: [3, 4],
        3: [4, 5],
        4: [5],
        5: [],
        6: [7],
        7: []
    }

    num_of_nodes = len(directed_graph)
    visited = {node: False for node in directed_graph}
    stack = []
    for node in directed_graph:
        if not visited[node]:
            dfs(visited, node, directed_graph, stack)
    stack.reverse()
    print(stack)
