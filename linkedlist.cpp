#include <iostream>

using namespace std;

struct ElemtList{
	char info;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First = NULL;
}

void createElemt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Masukkan satu huruf : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL)
		First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void traversal(List First){
	pointer pBantu;
	pBantu=First;
	while(pBantu != NULL){
		cout<<pBantu->info;
		pBantu=pBantu->next;
	}
	cout<<endl;
}

void traversal2(List First){
	pointer pBantu;
	if(First=NULL){
		cout << "List kosong"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout << pBantu->info;
			pBantu= pBantu->next;
		}while(pBantu!=NULL);
	}
}

void deleteFirst(List& First, pointer& pHapus){
	if (First==NULL){
		pHapus=NULL;
		cout << "List kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void insertLast(List& First, pointer pBaru){

	pointer last;
	cout<<"Insert Last"<<endl;
	if(First==NULL){
		First=pBaru;
	}
	else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
	last->next=pBaru;
	}
}

void deleteLast(List& First, pointer& pHapus){
	pointer last,precLast;
	cout << "Delete last"<<endl;
	if (First==NULL){
		pHapus=NULL;
		cout << "List Kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		last=First;
		precLast=NULL;
		while(last->next !=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void linearSearch(List First,int key, int& found, pointer& pCari){
	found=0;
	pCari=First;
	while (found==0 && pCari!=NULL) {
		if (pCari->info==key)
			found=1;
		else
			pCari=pCari->next;
}

}

void insertAfter(List& First, pointer pCari, pointer pBaru){
	if(pCari->next==NULL)
		pCari->next=pBaru;
	else{
		pBaru->next=pCari->next;
		pCari->next=pBaru;
	}
}

void deleteAfter(List& First, pointer pCari, pointer& pHapus){
	if(pCari->next==NULL){
		pHapus = NULL;
		cout<<"Tidak ada yang dihapus"<<endl;
	}
	else{
		pHapus = pCari->next;
		pCari->next = pHapus -> next;
		pHapus->next=NULL;
	}
}

int main(){
	pointer p;
	pointer pCari;
	List Ma08;
	int ketemu;
	char kunci;

	createList(Ma08);

	createElemt(p);
	insertFirst(Ma08,p);
	traversal(Ma08);
	deleteFirst(Ma08,p);

	createElemt(p);
	insertFirst(Ma08,p);
	traversal(Ma08);

	createElemt(p);
	insertFirst(Ma08,p);
	traversal(Ma08);

	createElemt(p);
	insertLast(Ma08,p);
	traversal(Ma08);

	deleteLast(Ma08,p);
	traversal(Ma08);

	cout<<"Kunci : ";cin>>kunci;
	linearSearch(Ma08,kunci,ketemu,pCari);
	if (ketemu){
		cout << "Ditemukan Yang dicari " <<endl;
		createElemt(p);
		insertAfter(Ma08,pCari,p);
		traversal(Ma08);
	}else{
		cout << "Tidak ditemukan" << endl;
	}

	deleteAfter(Ma08,pCari,p);
	traversal(Ma08);

	return 0;
}
