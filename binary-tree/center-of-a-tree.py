from queue import Queue

# Refer the below link for problem.
# https://www.youtube.com/watch?v=nzF_9bjDzdc&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&index=4


def getCentreOfTree(tree):
    leaves = []
    degree = {}
    for node in tree:
        degree[node] = len(tree[node])
        if degree[node] <= 1:  # nodes with degree = 0, 1
            leaves.append(node)
    count = len(leaves)
    n = len(tree)
    while count < n:
        new_leaves = []
        for node in leaves:
            for neighbor in tree[node]:
                degree[neighbor] -= 1
                if degree[neighbor] == 1:
                    new_leaves.append(neighbor)
            degree[node] = 0
        count += len(new_leaves)
        leaves = new_leaves
    return leaves


if __name__ == '__main__':
    # undirected graph with no cycles therefore a tree
    tree = {
        0: [1],
        1: [0, 3, 4],
        2: [3],
        3: [1, 2, 6, 7],
        4: [1, 5, 8],
        5: [4],
        6: [3, 9],
        7: [3],
        8: [4],
        9:  [6]
    }
    print(getCentreOfTree(tree))
