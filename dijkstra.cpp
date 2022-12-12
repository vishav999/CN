#include<unordered_map>
#include<list>
#include<set>
#include<climits>
#include<vector>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    // creating the adjacency list first
    unordered_map<int,list<pair<int,int> > > adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
       
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    // creating the distance vector
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    //now at src dist[src]=0
    dist[source]=0;
   
    // now creating the set where would be storing the required pairs
    set<pair<int,int> >st;
    st.insert(make_pair(0,source));
   
    while(!st.empty()){
        auto top=*(st.begin());
       
        int nodedis=top.first;
        int node=top.second;
        st.erase(st.begin());
        // traverse on neighboours
        for(auto neigh:adj[node]){
            if((nodedis+neigh.second) < dist[neigh.first]){
                // check it's record in set
                auto record=st.find(make_pair(dist[neigh.first],neigh.first));
                 if(record!=st.end()){       // means record found so erase it
                     st.erase(record);
                 }  
                 // now update distance
                 dist[neigh.first]=nodedis+neigh.second;
                   // put record in st
                 st.insert(make_pair(dist[neigh.first],neigh.first));
            }
        }
           
    }
    return dist;
}