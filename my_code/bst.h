#include <iostream>
using namespace std;

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), parent(p), left(l), right(r) {}
			
			
					
        T get_val() const {
            return data;
        }


        Bst<T>* insert(const T& d) {
			cout << "insert called" << endl;
			if ( d==data)
			{
				cout << "Value of : " << d << " already exists." << endl;
				
				return nullptr;
			}
			else if (d<data)
			{
				cout << "value less than" << endl;
				if (!left)
				{
					cout << "creating child left" << endl;
					left= new Bst(d,this);
					return left;
				}
				else //is not nullptr; traverse the tree
				{
					cout << "going left" << endl;
					left->insert(d);
				}
			}
			else //d is greater than data
			{
				cout << "value greater than" << endl;
				if (!right)
				{
					cout << "creating child right" << endl;
					right= new Bst(d,this);
					return right;
				}
				else //is not nullptr; traverse the tree
				{
					cout << "going right" << endl;
					right->insert(d);
				}
			}
			
        }

		T& min()
		{
			if (!left)
			{
				
				cout << "min is : " << data << endl;
				return data;
			}
			else
			{
				return (left->min());
			}
		}

		Bst<T>* min_node()
		{
			if (left==nullptr)
			{
				
				//cout << "min is : " << data << endl;
				return this;
			}
			else
			{
				return (left->min_node());
			}
		}

		T& max()
		{
			if (!right)
			{
				cout << "max is : " << data << endl;
				return data;
			}
			else
			{
				return (right->max());
			}
		}
	

		Bst<T>* max_node()
		{
			if (!right)
			{
			//	cout << "max is : " << data << endl;
				return this;
			}
			else
			{
				return (right->max_node());
			}
		}
	
		Bst<T>* search(T d)
		{
			if (d==data)
			{
				return this;
			}
			else if (left == nullptr&& d<data)
			{
				return nullptr;
			}
			else if (d<data)
			{
				return (left->search(d));
			}
			else if (right== nullptr && d>data)
			{
				return nullptr;
			}
			else 
			{
				return (right->search(d));
			}
			
			
		}

		// Bst<T>* predecessor(T val)
		// {
			
			// Bst<T>* key = search(val);
			
			// if (key==nullptr)
			// {
				// cerr<< "no such value" << endl;
				// exit(2);
			// }
			// Bst<T>* run_down = key->left;
			// if (run_down!=nullptr)
			// {
				// while (run_down->right!=nullptr)
				// {
					// run_down=run_down->right;
				// }
				// if (run_down!=nullptr)
				// {
					// return (run_down);
				// }
			// }
			// Bst<T>* run_up = key;
			// while (run_up->parent!= nullptr && run_up->parent->data>val)
			// {
				// run_up=run_up->parent;
			// }
			// if (run_up->parent!=nullptr)
			// {
				// if (run_up->parent->data<val)
					
				// {return run_up->parent;}
			// }
	
			// if (run_up->data< val)
			// {
				// return run_up;
			// }
			// else
			// {
				// cerr << "value is a min, no such pred" << endl;
				// exit (3);
			// }
		// }
		
		Bst<T>* predecessor(T val)
		{
			
			Bst<T>* key = search(val);

			if (key==nullptr)
			{
				cerr<< "no such value" << endl;
				exit(2);
			}
			
			if (key->left!=nullptr)
			{
				cout << "there is a smaller node" << endl;
				return ((key->left)->max_node());
			}
			else
			{
				cout << "no smaller node. check the parents now" << endl;
				
				while (key->parent!=nullptr&&key->parent->data>val)
				{
					key=key->parent;
				}
			if (key->parent!=nullptr)
			{
				if (key->parent->data<val)
					
				{return key->parent;}
			}
	
			if (key->data< val)
			{
				return key;
			}
			else
			{
				cerr << "value is a min, no such pred" << endl;
				exit (3);
			}	
				
				
			}
		}




		// Bst<T>* successor(T val)
		// {
			
			// Bst<T>* key = search(val);
			
			// if (key==nullptr)
			// {
				// cerr<< "no such value" << endl;
				// exit(2);
			// }
			
			// Bst<T>* run_down = key->right;
			// if (run_down!=nullptr)
			// {
				// while (run_down->left!=nullptr)
				// {
					// run_down=run_down->left;
				// }
				// if (run_down!=nullptr)
				// {
					// return (run_down);
				// }
			// }
			// Bst<T>* run_up = key;
			// while (run_up->parent!= nullptr && run_up->parent->data<val)
			// {
				// run_up=run_up->parent;
			// }
			// if (run_up->parent!=nullptr)
			// {
				// if (run_up->parent->data>val)
					
				// {return run_up->parent;}
			// }
			// if (run_up->data> val)
			// {
				// return run_up;
			// }
			// else
			// {
				// cerr << "value is a max, no such succ" << endl;
				// exit (3);
			// }
		// }
		
//successor_rec and predecessor_rec are FIXED

		Bst<T>* successor(T val)
		{
			
			Bst<T>* key = search(val);
			cout << "search complete" << endl;
			if (key==nullptr)
			{
				cerr<< "no such value" << endl;
				exit(2);
			}
			 
			//cout << "THIS IS KEY right " << key->right->get_val() << endl;
			if (key->right!=nullptr)
			{
				cout<< "there is a larger node" << endl;
				return ((key->right)->min_node());
			}
			else
			{
				cout << "I must be a left node; check parents" << endl;

			while (key->parent!= nullptr && key->parent->data<val)
			{
				key=key->parent;
			}
			if (key->parent!=nullptr)
			{
				if (key->parent->data>val)
					
				{return key->parent;}
			}
			if (key->data> val)
			{
				return key;
			}
			else
			{
				cerr << "value is a max, no such succ" << endl;
				exit (3);
			}
			}
		}
		



		


    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};





