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

