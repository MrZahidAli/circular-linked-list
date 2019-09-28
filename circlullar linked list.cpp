#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next, *previous ;
};
class linkList{
	private:
		node *head, *tail;
	public:
		linkList(){
			head = NULL;
			tail = NULL;
		}
		void creatList(int value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = head;
			temp -> previous = tail;
			
			if(head == NULL){
				head = temp;
				tail = temp;
			//	cout<<"if"<<endl;
			}
			else{
			//	cout<<"else"<<endl;
				tail -> next = temp;
				temp -> next = head;
				tail = temp;
				head -> previous = tail;
			//	cout<< tail->data<<endl;
			//	cout<< head->data<<endl;
			}
			
		}
		void inserAt(int value, int position){
			node *temp2 = new node;
			node *temp = head;
			temp2 -> data = value;
			for(int i = 1; temp -> next != head; i++){
				if ( i == position){
					node *temp3 = temp -> next;
					temp -> next = temp2;
					temp2 -> previous = temp;
					temp2 -> next = temp3;
					temp3 -> previous = temp2;
				}
				temp = temp -> next;
			}
		
		}
		void printList(){
			node *temp = new node;
			temp = head;
			while(temp -> next != head){
				cout << temp -> data << "\t";
				temp = temp -> next;
			}
			cout << temp -> data;
		}
		void search(int value){
			node *temp = new node;
			temp = head;
			bool find;
			while(temp != NULL){
				if(temp -> data == value){
					cout << temp -> data;
					find = true;
					break;
				}
				else{
					temp = temp -> next;
					find = false;
				}
			}
			if(find == false){
					cout << "not found";
			}
		}
		void removeElement(int remValue) {
		if(head == NULL){
			cout<<"NULL";
		}
		else{
    		node *prev = head;
    		node *current = head->next;
    		while(current != NULL) {
        		if(current -> data == remValue) { 
            		break;
        		}
        		else {
           			prev = current; 
            		current = current->next;
        		}
    		}
    		if(current == head) {
    			if(head -> data == remValue)
    			{
	        		cout << "Head Deleted: " <<"\n";
	        		head = head -> next;
	        		prev->next = current->next;
        			delete current;
	        	}
    		} else {
        		cout << "Deleted: " << "\n";
        		prev->next = current->next;
        		delete current;
    		}
    	}
		}
		void sortedList(){
			node *prev = head;
			while(prev != NULL){
				node *current = head;
				while(current != NULL){				
					if(prev -> data < current -> data){
						prev -> data = prev -> data + current -> data;
						current -> data = prev -> data - current -> data;
						prev -> data = prev -> data - current -> data;										
					}
					current = current -> next;					
				}
				prev = prev -> next;				
									
			}
		}
};
int main(){
	linkList a;
	a.creatList(1);
	a.creatList(3);
	a.creatList(7);
	a.creatList(6);
	a.creatList(8);
//	a.creatList(8);
//	a.creatList(0);
//	a.creatList(16);
	a.printList();
	a.inserAt(4, 5);
	
//	cout<< endl;
//	a.removeElement(72);
	cout << endl;
	a.printList();
//	a.search(7);   //working
//	a.sortedList();       //sorted problem
//	cout<<"sorted linked list"<<endl;
//	a.printList();
	return 0;
}
