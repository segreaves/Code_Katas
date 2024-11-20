#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

/// <summary>
/// Implements a directed graph.
/// </summary>
template<typename T>
class Graph
{
public:
    /// <summary>
    /// Traverse from 'from' vertex to 'to' vertex using the Breadth First Search algorithm (BFS).
    /// </summary>
    /// <param name="from"></param>
    /// <param name="to"></param>
    /// <returns></returns>
    int traverse(const T& from, const T& to)
    {
        // Check if the from vertex is in the graph
        if (m_adj.find(from) == m_adj.end())
        {
            std::cout << "Starting vertex not found in graph." << "\n";
            return -1;
        }

        // Set the starting conditions of the algorithm
        std::unordered_set<T> visited;
        std::queue<std::pair<T, int>> queue;
        queue.push({ from, 0 });

        // Loop through the graph vertices
        while (!queue.empty())
        {
            auto [curr, level] = queue.front();// Get the next vertex in the queue
            queue.pop();// Remove the vertex from the queue

            if (visited.find(curr) != visited.end())
                continue;// Do not re-visit vertices

            if (curr == to)
                return level;// If objective found then exit with true
            
            // Mark current vertex as visited
            visited.insert(curr);
            // Add all edges of curr to queue
            for (const auto& out_neighbor : m_adj[curr])
            {
                if (visited.find(out_neighbor) == visited.end())
                    queue.push({ out_neighbor, level + 1 });
            }
        }
        return -1;// If reached here, then there is no path
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph)
    {
        for (const auto& [vertex, edges] : graph.m_adj)
        {
            os << vertex << " -> ";
            for (const auto& edge : edges)
                os << edge << " ";
            os << "\n";
        }
        return os;
    }

    void operator+=(const std::pair<T, T>& edge)
    {
        m_adj[edge.first].push_back(edge.second);
    }

    void operator+=(const std::pair<T, std::vector<T>>& edges)
    {
        for (const auto& edge : edges.second)
            m_adj[edges.first].push_back(edge);
    }
private:
    std::unordered_map<T, std::vector<T>> m_adj;
};

int main()
{
    // Create a graph of bands
    Graph graph_bands = Graph<std::string>();

    // Adding edges to the graph
    graph_bands += std::make_pair<std::string, std::vector<std::string>>("Radiohead", { "Muse", "Kashmir", "Queens of the Stone Age" });
    graph_bands += std::make_pair<std::string, std::vector<std::string>>("The Strokes", { "Julian Casablancas", "Arctic Monkeys" });
    graph_bands += std::make_pair<std::string, std::vector<std::string>>("Kashmir", { "Nirvana", "David Bowie" });
    graph_bands += std::make_pair<std::string, std::vector<std::string>>("David Bowie", { "Johnny Cash", "The Killers" });
    graph_bands += std::make_pair<std::string, std::vector<std::string>>("The Killers", { "Jim Croche" });

    // Print the graph
    std::cout << graph_bands;

    // Traverse
    int dist_bands = graph_bands.traverse("Radiohead", "Jim Croche");
    if (dist_bands)
        std::cout << "Found path from Radiohead to Jim Croche (" << dist_bands << ")" << "\n";
    else
        std::cout << "No path from Radiohead to Jim Croche" << "\n";
    
    std::cout << "-----------------------------------------------------\n";

    // Create graph of ints
    Graph graph = Graph<int>();

    // Adding edges to the graph
    graph += std::make_pair<int, std::vector<int>>(1, { 2, 3, 4 });
    graph += std::make_pair<int, std::vector<int>>(2, { 5, 6 });
    graph += std::make_pair<int, std::vector<int>>(3, { 7 });
    graph += std::make_pair<int, std::vector<int>>(4, { 8 });
    graph += std::make_pair<int, std::vector<int>>(5, { 9 });
    graph += std::make_pair<int, std::vector<int>>(6, { 10 });

    // Print the graph
    std::cout << graph;

    // Traverse
    int dist_ints = graph.traverse(1, 10);
    if (dist_ints)
        std::cout << "Found path from 1 to 10 (" << dist_ints << ")" << "\n";
    else
        std::cout << "No path from 1 to 10" << "\n";
}
