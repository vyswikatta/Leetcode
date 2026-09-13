typedef struct {
    int requests[10000];
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));

    obj->front = 0;
    obj->rear = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    // Add the new request
    obj->requests[obj->rear] = t;
    obj->rear++;

    // Remove requests older than t - 3000
    while (obj->front < obj->rear &&
           obj->requests[obj->front] < t - 3000) {
        obj->front++;
    }

    // Number of requests currently in the range
    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}