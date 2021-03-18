#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	string field;
};

void display(node* first) {
	while (first != NULL) {
		cout << first->field << " ";
		first = first->next;
	}
	cout << endl;
}
int add(node** first, node* toBeAdded) {
	node* temp = *first;
	if (temp == NULL) {
		*first = toBeAdded;
		(*first)->next = NULL;
	} else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = toBeAdded;
		toBeAdded->next = NULL;
	}
	return 0;
}

int add(node** first, node* toBeAdded, int i) {
	node* temp = *first;
	if (i == 0) {
		toBeAdded->next = *first;
		*first = toBeAdded;
	} else {
		int j = 0;
		i--;
		while (j < i) {
			temp = temp->next;
		}
		node* temp2 = temp->next;
		temp->next = toBeAdded;
		toBeAdded->next = temp2;
	}
	return 0;
}

bool contain(node* first, string f) {
	if (first == NULL) {
		return false;
	}
	if (f == first->field) {
		return true;
	}
	node* temp = first;
	while (temp->next != NULL) {
		temp = temp->next;
		if (temp->field == f) {
			return true;
		}
	}
	return false;
}

bool remove(node** first, string n) {
	node* temp = *first;
	if (temp != NULL) {
		if (temp->field == n){
			node* tempTwo = (*first)->next;
			delete temp;
			*first = tempTwo;
			return true;
		} else {
			while (temp->next != NULL) {
				if (temp->next->field == n) {
					node* tempTwo = temp->next->next;
					delete temp->next;
					temp->next = tempTwo;
					return true;
				}
				temp = temp->next;
			}
		}
	}
	return false;
}

void removeAll(node** head, string n) {
	while (remove(head, n));
}

bool isEmpty(node* head) {
	return (head == NULL); 
}

void clear(node** head) {
	while (*head != NULL) {
		node* temp = (*head)->next;
		delete *head;
		*head = temp;
	}
	*head = NULL;
}

int length(node* head) {
	int sum = 0;
	node* temp = head;
	while (temp != NULL) {
		sum++;
		temp = temp->next;
	}
	return sum;
}

int indexOf(node* head, string n) {
	int index = -1;
	int mB = 0;
	node* temp = head;
	while (temp != NULL) {
		if (temp->field == n) {
			index = mB;
			break;
		} else {
			temp = temp->next;
			mB++;
		}
	}
	return index;
}

node* toArray(node* head){
	int m = length(head);
	node* mb = new node [m];
	node* temp = head;
	int i = 0;
	while (i < m) {
		mb[i].field = temp->field;
		temp = temp->next;
		i++;
	}
	return mb;
}

void reverse(node** head) {
	node* next;
	node* capture = NULL;
	node* pres = *head;
	int limit = length(*head);
	int i = 0;
	while (i < limit) {
		next = pres->next;
		pres->next = capture;
		capture = pres;
		pres = next;
		i++;
	}
	*head = capture;
}

void removeRep(node** head) {
	node* temp = *head;
	while (temp != NULL) {
		if (temp->next != NULL) {
			remove(&temp->next, temp->field);
		}
		temp = temp->next;
	}
}
int main() {
	node* head = NULL;
	node* a = new node;
	a->field = "10";
	node* c = new node;
	c->field = "20";
	add(&head, a);
	display(head);
	add(&head, c);
	display(head);
	cout << contain(head, "10") << endl;
	cout << contain(head, "30") << endl;
	remove(&head, "30");
	display(head);
	remove(&head, "10");
	display(head);
	cout << "length is: " << length(head) << endl;
	node* d = new node;
	d->field = "40";
	node* e = new node;
	e->field = "60";
	node* f = new node;
	f->field = "10";
	node* g = new node;
	g->field = "10";
	add(&head, d);
	add(&head, e);
	display(head);
	cout << isEmpty(head) << endl;
	cout << length(head) << endl;
	display(head);
	cout << indexOf(head, "50") << endl;
	cout << indexOf(head, "10") << endl;
	add(&head, f, 0);
	add(&head, g, 0);
	display(head);
	node* capture = toArray(head);
	int limit = length(head);
	int i = 0;
	while (i < limit)
		cout << capture[i++].field << " ";
	cout << endl;
	cout << "========" << endl;
	display(head);
	reverse(&head);
	cout << "========" << endl;
	display(head);
	removeRep(&head);
	display(head);
	clear(&head);
	delete [] capture;
	display(head);
	return 0;
}
