#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int info;
	struct node *next;
}*head , *tail;

class single_list{
	public:
		node* create_node(int);
		void tambahawal();
		void insert_pos();
		void tambahakhir();
		void hapusawal();
		void hapusakhir();
		void delete_pos();
		void display();
		
		single_list(){
			head = NULL;
			tail = NULL;
		}
};

int kosong(){
 if(head == NULL) return 1;
 else return 0;
}

int main(){
	int n, node, elemen, posisi, i;
	single_list s1;
	head=NULL;
	while (1){
		cout<<"1. masukan node di awal"<<endl;
		cout<<"2. masukan node di akhir"<<endl;
		cout<<"3. hapus node awal"<<endl;
		cout<<"4. hapus node akhir"<<endl;
		cout<<"5. masukan node pada posisi tertentu"<<endl;
		cout<<"6. menghapus node tertentu"<<endl;
		cout<<"7. display linked list"<<endl;
		cout<<"8. exit"<<endl;
		cout<<"pilihan : ";
		cin>>n;
		switch(n){
			case 1:
				cout<<"Masukan node di awal"<<endl;
				s1.tambahawal();
				cout<<endl;
				break;
			case 2:
				cout<<"Masukan node di akhir"<<endl;
				s1.tambahakhir();
				cout<<endl;
				break;
			case 3:
				cout<<"hapus node awal"<<endl;
				s1.hapusawal();
				cout<<endl;
				break;
			case 4:
				cout<<"hapus node akhir"<<endl;
				s1.hapusakhir();
				break;
			case 5:
				cout<<"masukan node di posisi tertentu"<<endl;
				s1.insert_pos();
				cout<<endl;
				break;
			case 6:
				cout<<"menghapus node tertentu"<<endl;
				s1.delete_pos();
				cout<<endl;
				break;
			case 7:
				cout<<"display list"<<endl;
				s1.display();
				cout<<endl;
				break;
			case 8:
				cout<<"byee"<<endl;
				return 0;
			default:
				cout<<"tidak ada pilihan";
		}
	}
}
node *single_list::create_node(int value){
	struct node *temp, *s;
	temp = new(struct node);
	if (temp==NULL){
		cout<<"Memory not allocated"<<endl;
		return 0;
	} else {
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
	}
void single_list::tambahawal(){
	int value;
	cout<<"Masukan value: ";cin>>value;
	struct node *temp, *p;
	temp= create_node(value);
	if (head==NULL){
		head = temp;
		head->next = NULL;
	} else {
		p = head;
		head = temp;
		head->next = p;
	}
	cout<<"Elemnt dimasukan pada awal"<<endl;
}
	
void single_list::tambahakhir(){
 int databaru;
 cout<<" Masukkan value: ";cin>>databaru;
 struct node *baru,*bantu;
 baru = new node;
 baru->info = databaru;
 baru->next = NULL;
 if(kosong()==1){
head=baru;
 tail=baru;
 tail->next = NULL;
 }
 else {
  tail->next = baru;
  tail=baru;
 }
 cout<<"Data masuk\n";
}

void single_list::insert_pos(){
	int value, pos, counter = 0;
	cout<<"masukan value: ";cin>>value;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	cout<<"masukan posisi yang ingin dituju";cin>>pos;
	int i;
	s = head;
	while (s!=NULL){
		s = s->next;
		counter ++;
	}
	if (pos==1){
		if (head == NULL){
		head = temp;
		head->next= NULL;
		} else {
			ptr = head;
			head = temp;
			head->next=ptr;
		}
		}
	else if (pos>1 && pos <= counter){
			s = head;
			for (i=1; i<pos;i++){
				ptr =s;
				s=s->next;
			}
			ptr->next = temp;
			temp->next = s;
		} else {
			cout<<"posisi terlalu jauh"<<endl;
			
		}
	
}


void single_list::delete_pos(){
	int pos, i, counter = 0;
	if (head == NULL){
		cout<<"list kosong"<<endl;
		return;
	}
	cout<<"masukan posisi yang ingin dihapus";cin>>pos;
	struct node *s, *ptr;
	s = head;
	if (pos==1){
		head = s->next;
	} else {
		while (s!=NULL){
			s=s->next;
			counter++;
	}
		if (pos>0 &&pos <=counter){
			s = head;
			for (i=1; i<pos;i++){
				ptr = s;
				s=s->next;
			}
			ptr->next = s->next;
		} else {
			cout<<"posisi diluar jangkauan"<<endl;
		}
		free(s);
		cout<<"elemen telah dihapus"<<endl;
	}
}

void single_list::display(){
	struct node *temp;
	if (head==NULL) {
		cout<<"List is empty"<<endl;
		return;
	}
	temp = head;
	cout<<"elemen dari list nya adalah : "<<endl;
	while (temp != NULL){
		cout<<temp->info<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void single_list::hapusawal(){
	struct node *hapus;
     int d;
     if (kosong()==0){
          if(head!=tail){
           hapus = head;
           d = hapus->info;
           head = head->next;
           delete hapus;
          } else {
           d = tail->info;
           head=tail=NULL;
          }
   cout<<d<<" Terhapus"<<endl;
     } else cout<<"Masih kosong\n";
}	
	
void single_list::hapusakhir(){
     struct node *bantu,*hapus;
     int d;
     if (kosong()==0){
      bantu = head;
          if(head!=tail){
               while(bantu->next!=tail){
                bantu = bantu->next;
               }
               hapus = tail;
               tail=bantu;
               d = hapus->info;
               delete hapus;
               tail->next = NULL;
            }else {
            d = tail->info;
             head=tail=NULL;
            }
      cout<<d<<" Terhapus\n"<<endl;
     } else cout<<"Masih kosong\n";
}	
