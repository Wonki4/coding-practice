#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char str[1000001];
typedef struct node {
    char value;
    struct node * pre;
    struct node * next;
} node;

int main(void) {
    int test_case;
    cin>>test_case;
    for(int n = 0; n<test_case; n++) {
        node * head = (node *)malloc(sizeof(node));
        node * cur = head;
        head->pre = NULL;
        head->next = NULL;
        head->value = '\0';
        memset(str, 0, 1000001);
        cin>>str;
        int i = 0;
        while(str[i]!='\0') {
            if(str[i] == '<' || str[i] == '>' || str[i] == '-') {
                if(str[i] == '<') {
                    if(cur->pre != NULL) cur = cur->pre;
                }
                else if(str[i] == '>') {
                    if(cur->next != NULL) cur = cur->next;
                }
                else if(str[i] == '-') {
                    if(cur!=head) {
                        node * temp = cur;
                        if(cur->next !=NULL) {
                            cur->pre->next = cur->next;
                            cur->next->pre = cur->pre;
                        }
                        else cur->pre->next = NULL;
                        cur = cur->pre;
                        free(temp);
                    }
                }
            }
            else {
                node * temp = (node *)malloc(sizeof(node));
                temp->value = str[i];
                if(cur->next != NULL) temp->next =cur->next;
                else temp->next = NULL;
                temp->pre = cur;
                if(cur->next != NULL) cur->next->pre = temp;
                cur->next= temp;
                cur = temp;
            }
            i++;
        }
        
        
        cur = head->next;
        while(cur!=NULL) {
            cout<<cur->value;
            cur = cur->next;
        }
        cout<<"\n";
    }
}


