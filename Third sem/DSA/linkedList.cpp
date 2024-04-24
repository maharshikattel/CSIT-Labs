
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    int totalNodes;

public:
    LinkedList()
    {
        head = NULL;
        totalNodes = 0;
    }

    Node *createNode(int data)
    {
        Node *node = new Node();
        node->next = NULL;
        node->info = data;
        return node;
    }

    int insertNode(int data, int position = 1)
    {
        Node *newNode = createNode(data);
        Node *agent = head;
        totalNodes++;
        if (head == NULL)
            head = newNode;
        else
        {
            if (position == 1)
            {
                newNode->next = head;
                head = newNode;
            }
            else if (position == -1)
            {
                while (agent->next != NULL)
                    agent = agent->next;
                agent->next = newNode;
            }
            else
            {
                for (int i = 1; i < position - 1; i++)
                    agent = agent->next;
                newNode->next = agent->next;
                agent->next = newNode;
            }
        }
        return 0;
    }

    void deleteNode(int position = 1)
    {
        if (head == NULL)
        {
            printf("List underflow");
            exit(0);
        }
        else
        {
            --totalNodes;
            Node *agent = head;
            if (position == 1)
            {
                agent = head;
                head = head->next;
            }
            else if (position == -1)
            {
                Node *newLast = NULL;
                while (agent->next != NULL)
                {
                    newLast = agent;
                    agent = agent->next;
                }
                newLast->next = NULL;
            }
            else
            {
                for (int i = 1; i < position - 1; i++)
                    agent = agent->next;
                Node *temp = agent;
                agent = agent->next;
                temp->next = agent->next;
            }
            cout << "Deleted " << agent->info << " from list\n";
            delete agent;
        }
    }
    void display()
    {
        Node *agent = head;
        for (int i = 1; i <= totalNodes; i++)
        {
            cout << i << "\t" << agent->info << "\n";
            agent = agent->next;
        }
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    for (int i = 0; i < 30; i = i + 6 )
        list->insertNode(i);
    list->insertNode(-55, -1);
    list->insertNode(972, 7);
    list->display();
    list->deleteNode();
    list->deleteNode(-1);
    list->deleteNode(4);
    list->display();
    return 0;
}
