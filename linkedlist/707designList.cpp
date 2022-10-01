class MyLinkedList
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int val, LinkedNode *next) : val(val), next(next) {}
    };
    MyLinkedList()
    {
        virNode = new LinkedNode();
        size = 0;
    }

    int get(int index)
    {
        if (index > size - 1 || index < 0)
            return -1;
        else
        {
            LinkedNode *tmpNode = virNode;
            for (int i = 1; i <= index; i++)
            {
                tmpNode = tmpNode->next;
            }
            return tmpNode->val;
        }
    }

    void addAtHead(int val)
    {
        LinkedNode *tmpNode = new LinkedNode(val, virNode->next);
        virNode->next = tmpNode;
        size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *tmpNode = new LinkedNode(val, nullptr);
        LinkedNode *curNode = virNode;
        while (curNode->next != nullptr)
        {
            curNode = curNode->next;
        }
        curNode->next = tmpNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        else if (index < 0)
        {
            return addAtHead(val);
        }
        else if (index == size)
        {
            return addAtTail(val);
        }
        else
        {
            LinkedNode *tmpNode = virNode;
            LinkedNode *newNode = new LinkedNode(val, nullptr);
            while (index--)
            {
                tmpNode = tmpNode->next;
            }
            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size)
            return;
        else
        {
            LinkedNode *cur = virNode;
            while (index--)
            {
                cur = cur->next;
            }
            LinkedNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            size--;
        }
    }

private:
    int size = 0;
    LinkedNode *virNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */