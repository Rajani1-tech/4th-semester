from queue import PriorityQueue

def heuristic(node, goal):
    # Define the heuristic function (distance) between two nodes
    # Here, we can use a dictionary to specify the distances between nodes
    distances = {
        'A': 7,
        'B': 6,
        'C': 5,
        'D': 4,
        'E': 3,
        'F': 2,
        'G': 0
    }
    return distances[node]

def gbfs_search(graph, start, goal):
    visited = set()
    queue = PriorityQueue()
    queue.put((heuristic(start, goal), start, [start]))

    while not queue.empty():
        _, current_node, path = queue.get()

        if current_node == goal:
            return path

        if current_node not in visited:
            visited.add(current_node)

            for neighbor in graph[current_node]:
                if neighbor not in visited:
                    queue.put((heuristic(neighbor, goal), neighbor, path + [neighbor]))

    return None

# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E', 'G'],
    'G': ['F']
}

start = 'A'
goal = 'G'

print("GBFS search from vertex 'A' to 'G':")
path = gbfs_search(graph, start, goal)
if path is not None:
    print("Path:", path)
else:
    print("No path found.")
