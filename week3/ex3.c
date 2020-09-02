#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *next;
	int value;
};

struct linkedList
{
	node *head;
	void  print_list(){
		node *temp = head;
		while(temp != NULL){
			printf("%d ", temp->value);
			temp = temp->next;
		}

		if (head != NULL)
			printf("\n");
		else
			printf("List is empty\n");
	}

	void insert_node(int elem){
	    
		if (head == NULL){
			head = (node*) malloc(sizeof(node));
			head->value = elem;
			head->next = NULL;
		}
		else{
			node *temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = (node*) malloc(sizeof(node));
			temp = temp->next;
			temp->value = elem;
			temp->next = NULL;
		}
	}

	void delete_node(int elem){
	    if (head == NULL){
	        printf("List is empty\n");
	    } else if (head->value == elem){
	        node* temp = head;
	        head = head->next;
	        free(temp);
	        printf("Element deleted\n");
	    } else{
	        node *temp = head;
			while(temp->next != NULL && temp->next->value != elem){
				temp = temp->next;
			}
			
			if (temp->next == NULL){
			    printf("Element didn`t find in list\n");
			} else{
			    node *temp2 = temp->next;
			    temp->next = temp->next->next;
			    free(temp2);
			    printf("Element deleted\n");
			}
	    }
	}
};

int main(){
    linkedList list = {NULL};
    list.print_list();
    list.insert_node(5);
    list.print_list();
    
    list.delete_node(1);
    list.delete_node(5);
    list.delete_node(5);
    
    for (int i = 0; i < 10; i++)
        list.insert_node(i);
    
    list.print_list();
    list.delete_node(5);
    list.delete_node(8);
    list.print_list();
    
	return 0;
}
