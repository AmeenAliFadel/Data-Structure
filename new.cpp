// اسماء الطلاب المشاركين في الوظيفة
// عمار نزار اسد 
// وجد محمد حشمة 
// امين علي فاضل 
// يزن نظير بركات
// مجد مازن ليلا
// علي كمال صالح
// آنا وليد سعد 
// جودي منذر سعيد 
// جوى غيث سلمان 
// طوني ادور داؤود
// حيدرة ايمن عفيف
// كريم عبد اللطيف تعمري
// تالا سامر ابراهيم
// سنيتيا امين صائغ
// زينب مهدي قيطازو




#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS
void dfs(const vector<vector<int>> &graph, int v, vector<bool> &visited)
{
    visited[v] = true;
    for (int neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            dfs(graph, neighbor, visited);
        }
    }
}
// تمثيل البيان باستخدام Adjacency List
vector<vector<int>> getTranspose(const vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> transposeGraph(V);
    for (int u = 0; u < V; ++u)
    {
        for (int v : graph[u])
        {
            transposeGraph[v].push_back(u);
        }
    }
    return transposeGraph;
}

bool isStronglyConnected(const vector<vector<int>> &graph)
{
    int V = graph.size();

    vector<bool> visited(V, false);
    dfs(graph, 0, visited);

    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }

    // إنشاء البيان المعكوس
    vector<vector<int>> gTranspose = getTranspose(graph);

    fill(visited.begin(), visited.end(), false);

    // تنفيذ DFS
    dfs(gTranspose, 0, visited);

    // إذا لم يتم زيارة جميع العقد في البيان المعكوس، فإن البيان ليس متصلاً بقوة
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }

    return true;
}
// Start Schmedit Algorithm
const int MAXN = 100;
vector<int> adj[MAXN];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); ++i)
    {
        int n = adj[v][i];

        if (!visited[n])
        {
            if (isCyclicUtil(n, visited, v))
                return true;
        }
        else if (n != parent)
        {
            return true;
        }
    }

    return false;
}

bool isCyclic(int n)
{
    bool visited[MAXN];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(i, visited, -1))
                return true;
        }
    }

    return false;
}
// End Schmedit Algorithm
// Start Melhorn Algorithm
void MelhornAlgorithm(const std::vector<int> &inputArray)
{
    stack<int> stack1;
    stack<int> stack2;

    // Push elements into stack1
    for (int element : inputArray)
    {
        stack1.push(element);
    }

    // Process the stacks
    while (!stack2.empty() || !stack1.empty())
    {
        if (!stack1.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        else
        {
            while (!stack2.empty())
            {
                cout << stack2.top() << " ";
                stack2.pop();
            }
        }
    }
}
// End Melhorn Algorithm

int main()
{
    // تمثيل البيان كقائمة مجاورة
    vector<vector<int>> graph = {{1}, {2}, {0}, {4}, {}};

    if (isStronglyConnected(graph))
    {
        cout << "Graph is strongly connected" << endl;
    }
    else
    {
        cout << "Graph is not strongly connected" << endl;
    }
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    if (isCyclic(n))
    {
        cout << "The graph is cyclic." << endl;
    }
    else
    {
        cout << "The graph is acyclic." << endl;
    }
    vector<int> inputArray = {1, 2, 3, 4, 5};
    MelhornAlgorithm(inputArray);
    return 0;
}
