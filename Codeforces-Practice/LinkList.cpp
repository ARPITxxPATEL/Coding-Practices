#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct Node{
        int data;
        Node *next;
        Node(int x){
            data = x;
            next = NULL;
        }
};
void printlist(Node *temp){
    while (temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *insert_beg(Node *head,int x){
    Node *newnode = new Node(x);
    newnode->next = head;
    return newnode;
}
Node *insert_end(Node *head,int x){
    Node *newnode = new Node(x);
    if (head==NULL) return newnode;
    Node *temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
Node *insert_pos(Node *head,int x,int pos){
    if (pos==1) return insert_beg(head,x);
    if (head==NULL) return NULL;
    Node *newnode = new Node(x);
    int count = 1;
    Node *temp = head;
    while (temp!=NULL){
        if (pos==count+1){
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        count++;
        temp = temp->next;
    }
    return head;
}
Node *insert_sort(Node *head,int x){
    Node *newnode = new Node(x);
    if (head==NULL) return newnode;
    Node *temp = head;
    if (head->data>=x){
        newnode->next = head;
        return newnode;
    }
    while (temp->next!=NULL){
        if (temp->next->data>=x){
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
void middle_ele(Node *head){
    if (head==NULL) return;
    Node *slow{head},*fast{head};
    while (fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << "middle element " << slow->data << endl;
}
void nth_ele_last(Node *head,int n){
    if (head==NULL) return;
    Node *temp{head},*ans{head};
    int cnt = 1;
    while (temp->next!=NULL){
        if (n==cnt) ans = ans->next;
        else cnt++;
        temp = temp->next;
    }
    if (n==cnt) cout << "nth element from last " << ans->data << endl;
}
Node *delete_beg(Node *head){
    if (head->next==NULL) return NULL;
    Node *temp = head->next;
    delete head;
    return temp;
}
Node *delete_end(Node *head){
    if (head==NULL) return NULL;
    if (head->next==NULL){
        delete head;
        return NULL;}
    Node *temp = head;
    while (temp->next->next!=NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return head;
}
Node *reverse_linklist(Node *head){
    if (head==NULL) return NULL;
    if (head->next==NULL) return head;
    Node *prev{NULL},*curr{head},*temp;
    while (curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void remove_dupli_fromsorted(Node *head){
    if (head==NULL) return;
    Node *curr{head};
    while (curr->next!=NULL){
        if (curr->data==curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else{
            curr = curr->next;
        }
    }
}

Node *reverse_kgroups(Node *head,int k){
    Node *curr = head,*prev = NULL,*nxt = NULL;
    int count = 0;
    while (curr!=NULL && count<k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if (curr!=NULL){
        head->next = reverse_kgroups(curr,k);
    }
    return prev;
}

int main()
{
    Node *head = new Node(5);  //20
    head->next = new Node(10);  //20 10
    head->next->next = new Node(15);    //20 10 40

    head = insert_end(head,20);  //5 20 10 40
    head = insert_end(head,25);    //5 20 10 40 15
    //head = insert_pos(head,25,6);    //5 20 10 40 15 8
    //head = delete_end(head);    //5 20 10 40 15
    printlist(head);
    middle_ele(head);
    nth_ele_last(head,6);
    head = reverse_kgroups(head,1);
    printlist(head);
    return 0;
}