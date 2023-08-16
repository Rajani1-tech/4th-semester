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

def astar_search(graph, start, goal):
    visited = set()
    queue = PriorityQueue()
    queue.put((0, start, [start]))

    while not queue.empty():
        cost, current_node, path = queue.get()

        if current_node == goal:
            return path

        if current_node not in visited:
            visited.add(current_node)

            for neighbor in graph[current_node]:
                new_cost = cost + graph[current_node][neighbor]
                priority = new_cost + heuristic(neighbor, goal)
                queue.put((priority, neighbor, path + [neighbor]))

    return None

# Example usage:
graph = {
    'A': {'B': 2, 'C': 3},
    'B': {'A': 2, 'D': 4, 'E': 3},
    'C': {'A': 3, 'F': 2},
    'D': {'B': 4},
    'E': {'B': 3, 'F': 1},
    'F': {'C': 2, 'E': 1, 'G': 5},
    'G': {'F': 5}
}

start = 'A'
goal = 'G'

print("A* search from vertex 'A' to 'G':")
path = astar_search(graph, start, goal)
if path is not None:
    print("Path:", path)
else:
    print("No path found.")
