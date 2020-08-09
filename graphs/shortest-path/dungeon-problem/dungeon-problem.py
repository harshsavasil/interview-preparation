from queue import Queue


def get_neighbors(node, directed_graph, L, R, C):
    dx = [1, -1, 0, 0, 0, 0]
    dy = [0, 0, 1, -1, 0, 0]
    dz = [0, 0, 0, 0, 1, -1]
    neighbors = []
    for i in range(6):
        new_x = node[0] + dx[i]
        new_y = node[1] + dy[i]
        new_z = node[2] + dz[i]
        if 0 <= new_x < L and 0 <= new_y < R and 0 <= new_z < C and directed_graph[new_x][new_y][new_z] != '#':
            neighbors.append((new_x, new_y, new_z))
    return neighbors


def generate_previous_node_in_shortest_path(node, directed_graph, L, R, C):
    bfs_queue = Queue()
    visited = {}
    prev = {}
    prev[node] = None
    visited[node] = True
    bfs_queue.put(node)
    while not bfs_queue.empty():
        current_node = bfs_queue.get()
        if directed_graph[current_node[0]][current_node[1]][current_node[2]] == 'E':
            return prev
        possible_neighbors = get_neighbors(
            current_node, directed_graph, L, R, C)
        for neighbor in possible_neighbors:
            if neighbor not in visited:
                visited[neighbor] = True
                prev[neighbor] = current_node
                bfs_queue.put(neighbor)
    return prev


def construct_shortest_path(start, end, prev):
    current = end
    path = []
    while current:
        path.append(current)
        current = prev.get(current)
    path.reverse()
    if path[0] == start:
        return path
    return []


def get_shortest_path(start, end, directed_graph, L, R, C):
    prev = generate_previous_node_in_shortest_path(
        start, directed_graph, L, R, C)
    return construct_shortest_path(start, end, prev)


if __name__ == '__main__':
    with open("input.in") as input_file:
        while True:
            L, R, C = [int(x)
                       for x in input_file.readline().strip().split(' ')]
            if L == 0 and R == 0 and C == 0:
                break
            start_index = None
            end_index = None
            levels = []
            for i in range(L):
                board = []
                for j in range(R):
                    row = list(input_file.readline().strip())
                    if 'S' in row:
                        start_index = (i, j, row.index('S'))
                    if 'E' in row:
                        end_index = (i, j, row.index('E'))
                    board.append(row)
                input_file.readline()
                levels.append(board)
            # print(start_index, end_index)
            path = get_shortest_path(start_index, end_index, levels, L, R, C)
            if len(path) == 0:
                print("Trapped!")
            else:
                print("Escaped in {0} minute(s).".format(len(path) - 1))
