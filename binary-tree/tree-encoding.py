from queue import Queue

# Refer the below link for problem.
# https://www.youtube.com/watch?v=nzF_9bjDzdc&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&index=4


def dfs(node, tree):
    if node is None:
        return ""
    encoding = '0'
    for child in tree[node]:
        childEncoding = dfs(child, tree)
        encoding += childEncoding
    encoding += '1'
    return encoding


def getEncoding(root, tree):
    """
    Perform a dfs and append 0 as you enter a node and 1 when you leave the node.
    """
    return dfs(root, tree)


if __name__ == '__main__':
    # undirected graph with no cycles therefore a tree
    tree = {
        0: [],
        1: [0, 2],
        2: [],
        3: [5],
        4: [1, 3],
        5: []
    }
    print(getEncoding(4, tree))
