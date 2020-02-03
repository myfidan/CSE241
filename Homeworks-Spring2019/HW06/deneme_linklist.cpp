#include<iostream>

class linklist{
	public:
		linklist(){}
		linklist(int data_,linklist* link_):data(data_),link(link_){
			
		}
		int get_data(){
			return data;
		}
		linklist* get_link(){
			return link;
		}
		void set_data(int data_){
			data=data_;
		}
		void set_link(linklist* link_){
			link=link_;
		}
	private:
		int data;
		linklist* link;	
};

int main(){
	
}
