#include<iostream>
#include<string>
using namespace std;

class Node{
	public:
	int data;
	Node *next;

	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
class Linkedlist{
public:
	Node* head;
	Node* tail;
	int size=0;

	Linkedlist(){
		head=tail=NULL;
	}

	void insertAtBeg(int n){
		Node* Newnode=new Node(n);
		if(size==0){
			head=tail=Newnode;
		}
		else{
			Newnode->next=head;
			head=Newnode;
		}
		size++;
	}

	void insertAtidx(int n,int idx){
		Node* Newnode=new Node(n);
		Node* temp=head;
		if(idx<0 || idx>size)return;
		else if(idx==0) insertAtBeg(n);
		else if(idx==size)insertAtEnd(n);
		else{
			for(int i=1;i<idx-1;i++){
				temp = temp->next;
			}
			Newnode->next=temp->next;
			temp->next=Newnode;
			size++;
		}
	}
	void insertAtEnd(int n){
		Node* Newnode=new Node(n);
		if(size==0){
			head=tail=Newnode;
		}
		else{
			tail->next = Newnode;
			tail=Newnode;
		}
		size++;
	}

	void deleteHead(){
		head = head->next;
		size++;
	}

	void deleteEnd(){
		Node* temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;

		
	}
	void getidx(int n){
		Node *temp=head;
		int i=1;
		while(i<n){
			temp=temp->next;
			i++;
		}
		cout<<"element found at index "<<n<<" is "<<temp->data;
	}
	void display(){
		Node* temp;
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main(){
	Linkedlist ll;
	ll.insertAtBeg(12);
	ll.display();
	cout<<ll.size<<endl;

	ll.insertAtEnd(123);
	cout<<ll.size<<endl;
	ll.display();
	ll.insertAtEnd(4);
	ll.insertAtEnd(5);
	ll.insertAtEnd(6);
	ll.insertAtEnd(7);
	ll.insertAtidx(2345,4);
	ll.display();
	ll.deleteHead();
	ll.display();
	ll.deleteEnd();
	ll.display();
	ll.getidx(2);
}