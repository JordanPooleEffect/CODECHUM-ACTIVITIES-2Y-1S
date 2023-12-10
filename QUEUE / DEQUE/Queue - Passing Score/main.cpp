#include <iostream>
#include "singlyqueue.h"
using namespace std;

// TODO 2: Implement the method and return a queue that contains only the passing scores.
Queue* passing_only(Queue* scores, int passing) {
    Queue* pass = new SinglyQueue();
    while(!scores->isEmpty()){
        int s = scores->dequeue();
        if(s >= passing){
            pass->enqueue(s);
        }
    }
    return pass;
}

int main() {
    Queue* queue = new SinglyQueue();
    int passing, scores;

    // TODO 1: Let the user enter the elements until zero (0).
    // and place the elements in the given queue.
    cout << "Enter score: ";
    cin >> scores;
    while(scores != 0){
        queue->enqueue(scores);
        cout << "Enter score: ";
        cin >> scores;
    }
    cout << "Enter passing score: ";
    cin >> passing;

    // DO NOT MODIFY the following code.
    Queue* res = passing_only(queue, passing);
    cout << "Passing scores: ";
    if (res->isEmpty()) {
        cout << "(none)";
    }
    while (!res->isEmpty()) {
        cout << res->dequeue() << " ";
    }

    return 0;
}