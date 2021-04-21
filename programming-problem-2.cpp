// Put into leetcode
//Dominic Grant
//6/28/2020
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {//initializing of the arrays and the ints needed
        int visited[100] = {}, visiteda[100] = {}, visitedb[100] = {}, g = 0, G = 0, i = 0;
        while(i < graph.size())//goes through the regular G and goes through it
        {
            if(visited[i] == 0)
            {
                dfs(graph, visited, visited, i);
                g++;
            }
            i++;
        }
        i = 0;
        while(i < graph.size())//goes through the G' and goes through the double versions of it as in the a set and b set
        {
            if(visiteda[i] == 0)
            {
                dfs(graph, visiteda, visitedb, i);
                G++;
            }
            if(visitedb[i] == 0)
            {
                dfs(graph, visitedb, visiteda, i);
                G++;
            }
            i++;
        } 
        bool checked = ((2*g) == G);//Checks that the connectivity of the regular G is half that of the G' and prints it out.
        if(checked==1)
            cout << "The output is true." << endl;
        else
            cout << "The output is false." << endl;
        return checked;
    }
    void dfs(vector<vector<int>>& graph, int visiteda[], int visitedb[], int i)//The dfs algorithm
    {
        visiteda[i] = 1;
        if(graph[i].size() == 0)//if there's no graph it automatically returns, otherwise it continues
        return;
        int j = 0;
        while(j < graph[i].size())//loop that goes through the length of the graph
        {
            if(visitedb[graph[i][j]] != 1)//as long as it's not equal to 1 it recursively calls itself 
            dfs(graph, visitedb, visiteda, graph[i][j]);
            j++;
        }
    }
};