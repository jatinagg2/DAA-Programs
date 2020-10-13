#include <iostream> 
using namespace std; 
#define V 5 
int minkey(int key[],bool mstSet[]) 
{ 
    int min=INT_MAX,minindex; 
    for(int i=0;i<V;i++) 
    { 
        if(mstSet[i]==false && key[i]<min) 
        { 
         min=key[i],minindex=i; 
        } 
   } 
     return minindex; 
} 
void printmst(int parent[],int graph[V][V]){ 
cout<<"Edge \tWeight \n"; 
for(int i=1;i<V;i++) 
{ 
    cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<" \n"; 
} } 
void primMST(int graph[V][V]) 
{ 
    int key[V]; 
    int parent[V]; 
    bool mstSet[V]; 
    for(int i=0;i<V;i++) 
    {
        key[i]=INT_MAX; 
        mstSet[i]=false; 
    } 
    key[0]=0; 
      parent[0]=-1; 
      for (int count=0;count< (V - 1) ;count ++) 
      {
          int u = minkey(key,mstSet); 
          mstSet[u]=true; 
          for(int v=0 ;v<V;v++) 
          { 
              if(graph[u][v]&& mstSet[v]==false && graph[u][v]<key[v]) 
              {
                  parent[v]=u; 
                  key[v]=graph[u][v];
              }
          }
      } 
 printmst(parent,graph); } 
int main() 
{ 
   int graph[V][V]={ 
   {0,2,0,6,0},{2,0,3,8,5}, 
   {0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0} 
}; 
    primMST(graph); 
    return 0; 
}