// TODO implement

class Deque {
    public:
    virtual void addLast(int num) = 0;
    virtual void addFirst(int num) = 0;
    virtual int removeFirst() = 0;
    virtual int removeLast() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
};