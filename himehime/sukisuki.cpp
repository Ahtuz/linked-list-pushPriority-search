#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ctr=0;

struct Project{
	char name[30];
	int diff;
	Project *next;
	Project *prev;
}*curr, *head, *tail = NULL;

void pushPriority(char name[], int diff){
	curr = (Project*) malloc (sizeof(Project));
	strcpy(curr->name, name);
	curr->diff=diff;
	ctr++;

	if(head==NULL){
		head = tail = curr;
		head->next = NULL;
		tail->prev = NULL;
	}
	else{
		if(curr->diff > head->diff){
			curr->next = head;
			head->prev = curr;
			head = curr;
			head->prev = NULL;
		}
		else if(curr->diff < tail->diff){
			curr->prev = tail;
			tail->next = curr;
			tail = curr;
			tail->next = NULL;
		}
		else{
			Project *p = head;
			while(p->diff > curr->diff){
				p = p->next;
			}
			curr->next = p;
			curr->prev = p->prev;
			p->prev->next = curr;
			p->prev = curr;
		}
	}
}

void reg(){
	char nameTemp[30];
	int diffTemp;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Input project name:");
	scanf("%s", &nameTemp); fflush stdin;
	printf("\nInput project difficulty:");
	scanf("%d", &diffTemp); fflush stdin;

	pushPriority(nameTemp, diffTemp);
}

void pushHead(char name[], int diff){
	curr=(Project)malloc(sizeof(Project));
	strcpy(curr->name,name);
	curr->diff=diff;

	if(head==NULL){
		head=tail=curr;
		head->prev=NULL;
		tail->next=NULL;
	}
	else{
		curr->next=head;
		head->prev = curr;
		head=curr;
		head->prev = NULL;
	}
}

void pushTail(char name[], int diff){
	curr=(Project)malloc(sizeof(Project));

}



void popTail(){
	curr=tail;

	if(head==tail){
		head=tail=NULL;
		free(curr);
	}
	else{
		tail=tail->prev;
		free(curr);
		tail->next = NULL;
	}
}

void popAll(){
	curr=head;

	while(head!=NULL){
		head=head->next;
		free(curr);
		curr=head;
	}
	tail=NULL;
}

void popHead(){
	curr=head;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Deleted:\n");
	printf("%s", curr->name);
	printf(" %d", curr->diff);

	if(head==tail){
		head=tail=NULL;
		free(curr);
	}
	else{
		head=head->next;
		free(curr);
		head->prev = NULL;
	}
}

void view(){
	curr=head;
	int i=1;

	while(curr!=NULL){
		printf("%-3d | %-20s | %-5d \n", i, curr->name, curr->diff);
		curr= curr->next;
		i++;
	}
}

void search(){
	char search[40];
	int found;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Input project name:");
	scanf("%s",  &search); fflush stdin;
	curr=head;

	for(int i=0;i<ctr;i++){
		if(strcmp(curr->name, search)==0){
			printf("Found!\n");
			printf("%s", curr->name);
			printf(" %d", curr->diff);
			found=1;
			break;
		}
		else{
			curr=curr->next;
			found=0;
		}
	}

	if(found==0){
		printf("Not found!");
	}
}


int main(){
	int choose;

	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("Shurima Project Manager\n");
		printf("=======================\n");
		printf("1. Register new project\n");
		printf("2. Assign programmer to project\n");
		printf("3. View project\n");
		printf("4. Search project\n");
		printf("5. Exit\n");

		do{
			printf("Choose:");
			scanf("%d", &choose); fflush stdin;
		}while(choose > 5 || choose < 1);

		switch(choose){
		case 1:
			reg();
			getchar();
			break;
		case 2:
			popHead();
			getchar();
			break;
		case 3:
			view();
			getchar();
			break;
		case 4:
			search();
			getchar();
			break;
		}

	}while(choose != 5);

	getchar();
	return 0;
}


