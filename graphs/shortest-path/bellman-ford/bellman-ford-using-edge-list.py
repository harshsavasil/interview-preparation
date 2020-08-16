from typing import List


class Edge:
    def __init__(self, source, destination, cost):
        self.source = source
        self.destination = destination
        self.cost = cost


def shortest_distance(vertices: List[int], edges: List[Edge], startingNode: int) -> List[int]:
    numOfVertices = len(vertices)
    distance = [float('inf') for _ in range(numOfVertices)]
    distance[startingNode] = 0
    for _ in vertices:
        for edge in edges:
            if edge.cost + distance[edge.source] < distance[edge.destination]:
                distance[edge.destination] = distance[edge.source] + edge.cost

    for _ in vertices:
        for edge in edges:
            if edge.cost + distance[edge.source] < distance[edge.destination]:
                distance[edge.destination] = float('-inf')

    return distance


edges = []
vertices = set()
edges.append(Edge(0, 1, 5))
edges.append(Edge(1, 6, 60))
edges.append(Edge(1, 5, 30))
edges.append(Edge(1, 2, 20))
edges.append(Edge(6, 7, -50))
edges.append(Edge(7, 8, -10))
edges.append(Edge(5, 6, 5))
edges.append(Edge(5, 8, 50))
edges.append(Edge(5, 4, 25))
edges.append(Edge(2, 3, 10))
edges.append(Edge(2, 4, 75))
edges.append(Edge(3, 2, -15))
edges.append(Edge(4, 9, 100))

for edge in edges:
    vertices.add(edge.source)
    vertices.add(edge.destination)

print(shortest_distance(vertices, edges, 0))
