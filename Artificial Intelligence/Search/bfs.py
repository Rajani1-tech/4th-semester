from collections import deque

def bfs(graph, start):
    visited = set()  # to keep track of visited vertices
    queue = deque([start])  # enqueue the starting vertex
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")  # process the current vertex (e.g., print it)

        # Enqueue all adjacent vertices that haven't been visited
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)

# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print("BFS traversal starting from vertex 'A':")
bfs(graph, 'A')
