#include "graph.h"
#include "List.h"

int len(Node* x)
{
    return sizeof(x)/ sizeof(Node);
}
int[] Dijkstra(Graph G,int src,int[] dist,int[] pred)
{
    int i, x, y;
    int[] M = NULL;

    for(int x = 0; x < G->order; x++)
    {
        for(int i = 0; i < len(G.head); i++)
        {
            if(G.head[i][0] == src && G.head[i][1] == x)
            {
                dist[x] = G.head[i][2];
                pred[x] = x;
                M =
            }
        }
    }

}