#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


struct node
{
	double data;
	node* left;
	node* right;
};

struct tree
{
	node* root;
};

void init_tree(tree& a)
{
	a.root = NULL;
}

node* create_node(double x)
{
	node* p = new node();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

bool add_node_tree(tree& a, double x)
{
	//input : tree,x
	//out put true or false

	bool check = false;
	node* add = create_node(x);
	if (a.root == NULL)
	{
		a.root = add;
		check = true;
	}
	else
	{
		node* p = a.root;
		node* pre = NULL;

		while (p != NULL)
		{
			pre = p;
			if (p->data == x)
			{
				check = false;
				break;
			}

			if (p->data < x)
			{
				p = p->right;
				check = true;
			}
			else
			{
				p = p->left;
				check = true;
			}
		}

		if (check == true)
		{
			if (pre->data > x)
			{
				pre->left = add;
			}
			else
			{
				pre->right = add;
			}
		}


	}
	return check;
}

void display_node(node* p)
{
	//input: node *root
	if (p->left == NULL)
	{
		cout << "<Left : NULL>";
	}
	else
	{
		cout << "<Left : " << &p->left << ">";
	}

	cout << "<data : " << p->data << ">";

	if (p->right == NULL)
	{
		cout << "<right : NULL>";
	}
	else
	{
		cout << "<right : " << &p->right << ">";
	}

}



bool find_x(tree a, double x)
{
	//input : tree a, double x
	//output: true or false
	bool check = false;
	node* p = a.root;
	while (p != NULL)
	{
		if (p->data == x)
		{
			check = true;
			break;
		}

		if (p->data > x)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

	return check;
}

void NLR(node* root)
{
	//input: node *root
	if (root != NULL)
	{
		display_node(root);
		cout << endl;
		NLR(root->left);
		NLR(root->right);
	}
}


void LRN(node* root)
{
	//input: node *root
	if (root != NULL)
	{

		LRN(root->left);
		LRN(root->right);
		display_node(root);
		cout << endl;
	}
}

void LNR(node* root)
{
	//input: node *root
	if (root != NULL)
	{

		LRN(root->left);
		display_node(root);
		cout << endl;
		LRN(root->right);

	}
}

void input_random_tree(tree &a)
{
	//input: tree a
	srand(time(0));
	
	int n = 25 + rand() % 41;
	for (int i = 0; i < n; i++)
	{
		double x = -39.1 + rand() % 147;
		add_node_tree(a, x);
	}
}


void count_node_co_2_nhanh(node* root, int& count)
{
	//input node root,int count
	if (root != NULL)
	{
		if (root->left != NULL && root->right != NULL)
		{
			count++;
		}

		count_node_co_2_nhanh(root->left,count);
		count_node_co_2_nhanh(root->right,count);
	}
}

void xuat_node_nhanh(tree a, double x)
{
	node* p = a.root;
	while (p != NULL)
	{
		if (p->data == x)
		{
			NLR(p);
			break;
		}

		if (p->data > x)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

}

void sao_chep_tree(node *old_tree,node *&new_tree)
{
	//input node oldtree and node new_tree
	if (old_tree == NULL)
	{
		new_tree = old_tree;
	}
	else
	{
		new_tree = new node;
		new_tree->data = old_tree->data;
		sao_chep_tree(old_tree->left, new_tree->left);
		sao_chep_tree(old_tree->right, new_tree->right);
	}
}


void input_array_tree(tree &a, double arr[], int length)
{
	//input : tree a,array,length

	for (int i = 0; i < length; i++)
	{
		add_node_tree(a, arr[i]);
	}
}


int count_chan_le(node *root, int& count_chan, int& count_le)
{
	if (root != NULL)
	{
		if (int(root->data) % 2 == 0)
		{
			count_chan++;
		}
		else
		{
			count_le++;
		}

		count_chan_le(root->left, count_chan, count_le);
		count_chan_le(root->right, count_chan, count_le);
	}

	if (count_chan > count_le)
	{
		return 1;
	}

	if (count_chan == count_le)
	{
		return 0;
	}

	if (count_chan < count_le)
	{
		return -1;
	}
}
int main()
{
	tree a;
	init_tree(a);

	int choice;
	do
	{
		cout << "1.. add node treee.." << endl;
		cout << "2.. random.." << endl;
		cout << "3.. NLR.." << endl;
		cout << "4.. LRN.." << endl;
		cout << "5.. LNR.." << endl;
		cout << "6...find x... tree" << endl;
		cout << "7. count node tree" << endl;
		cout << "8. xuat node tree" << endl;
		cout << "9...sao chep tree" << endl;
		cout << "10...input array" << endl;
		cout << "11.count chan le" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1 :
			{
				double x;
				cout << "nhap x: ";
				cin >> x;

				bool check = add_node_tree(a, x);
				if (check == true)
				{
					cout << "add thanh cong" << endl;
				}
				else
				{
					cout << "add khong thanh cong" << endl;
				}
				break;
			}

			case 2:
			{
				input_random_tree(a);
				break;
			}
			case 3:
			{
				NLR(a.root);
				break;
			}

			case 4:
			{
				LRN(a.root);
				break;
			}

			case 5:
			{
				LNR(a.root);
				break;
			}
			
			case 6:
			{

				double x;
				cout << "nhap x: ";
				cin >> x;

				bool search = find_x(a, x);
				if (search == true)
				{
					cout << "x co trong tree" << endl;
				}
				else
				{
					cout << "x khong co trong tree " << endl;
				}
				break;
			}

			case 7:
			{
				int count = 0;
				count_node_co_2_nhanh(a.root, count);

				cout << "so node co 2 nhanh : " << count << endl;
				break;
			}

			case 8:
			{
				double x;
				cout << "nhap gia tri x: ";
				cin >> x;

				xuat_node_nhanh(a, x);

				break;
			}

			case 9:
			{
				tree b;
				init_tree(b);
				sao_chep_tree(a.root, b.root);
				NLR(b.root);
				break;
			}

			case 10:
			{
				double arr[] = { -50.1,75.2,-25.3,30.4,-10.5,90.5,-70.1,60.2,30.4,-70.7,90.5 };
				input_array_tree(a, arr, 11);
				break;
			}

			case 11:
			{
				int count_chan = 0;
				int count_le = 0;
				int result = count_chan_le(a.root, count_chan, count_le);
				cout << "result : " << result << endl;
				break;
			}
	
		}


	} while (choice > 0);

	//test github
}