import heapq

def a_star(graph, start, goal, heuristic):
    # Priority queue (min-heap)
    open_list = []
    heapq.heappush(open_list, (0, start))

    # Cost from start to each node
    g_cost = {node: float('inf') for node in graph}
    g_cost[start] = 0

    # To reconstruct path
    parent = {start: None}

    while open_list:
        current_f, current = heapq.heappop(open_list)

        print(f"Visiting: {current}")

        # Goal reached
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return path

        # Explore neighbors
        for neighbor, cost in graph[current]:
            temp_g = g_cost[current] + cost

            if temp_g < g_cost[neighbor]:
                g_cost[neighbor] = temp_g
                f_score = temp_g + heuristic[neighbor]

                heapq.heappush(open_list, (f_score, neighbor))
                parent[neighbor] = current

    return None


# -------- Graph (weighted) --------
graph = {
    'A': [('B', 1), ('C', 3)],
    'B': [('D', 1), ('E', 5)],
    'C': [('F', 2)],
    'D': [],
    'E': [('G', 1)],
    'F': [('G', 2)],
    'G': []
}

# -------- Heuristic values --------
heuristic = {
    'A': 6,
    'B': 4,
    'C': 4,
    'D': 3,
    'E': 1,
    'F': 2,
    'G': 0
}

# -------- Run A* --------
start = 'A'
goal = 'G'

path = a_star(graph, start, goal, heuristic)

if path:
    print("Shortest path found:", path)
else:
    print("No path found")