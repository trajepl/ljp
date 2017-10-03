// adjacency matrix
typedef struct Node {
    int id;
    char *info;
}Node;

typedef struct Graph {
    int edges[maxSize][maxSize];
    int n, e;             // number of nodes and edges
    Node node[maxSize]    // information of nodes
}Graph;

// adjacency table
typedef struct ArcNode {
    int id;
    char *info;
    struct ArcNode *next;
}ArcNode;

typedef struct VNode {
    char *data;
    ArcNode *frist;
}Vnode;

typedef struct Graph {
    VNode *adjlist[maxSize];
    int n, e;            // number of nodes and edges
}Graph;

// traverse graph
// dfs-adjacency table
int visit[maxSize];

void dfs(Graph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    Visit(v);           // operate the node V
    p = G->adjlist[v].first;
    while(p != NULL) {
        if(visit[p->id] == 0) {
            dfs(G, p->id);
            p = p->next;
        }
    }
}

// bfs-adjacency
void bfs(Graph *G, int v, int visit[maxSize]) {
    ArcNode *p;
    int que[maxSize], front = 0, rear = 0;
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize;
    que[rear] = v;
    while(front != rear) {
        front = (front + 1) % maxSize;
        j = que[front];
        p = G->adjlist[j].first;
        while(p != NULL) {
            if(visit[p->id] == 0) {
                Visit(p->id);
                visit[p->id] = 1;
                rear = (rear + 1) % maxSize;
                que[rear] = p->id;
            }
            p = p->next;
        }
    }
}
