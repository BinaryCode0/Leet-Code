#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

struct node {
	int row;
	int col;
	int val;
	node *nxt;
};

void sortn(node &nd);
void AdditionMulti(node &s1, node &s2, int n, int m, int n1, int m1, int asize, int bsize);
void transpose(node &s1, int n, int m, int asize);
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	/*is Single Test case?*///cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

void sortn(node *nd) {
	node *ii = nd->nxt;
	node *jj  = ii->nxt;
	int inter;
	while (ii != NULL) {
		jj = ii->nxt;
		while (jj != NULL) {
			if (ii->row > jj->row) {
				inter = ii->row;
				ii->row = jj->row;
				jj->row = inter;

				inter = ii->col;
				ii->col = jj->col;
				jj->col = inter;

				inter = ii->val;
				ii->val = jj->val;
				jj->val = inter;
			}
			else if (ii->row == jj->row) {
				if (ii->col > jj->col) {
					inter = ii->col;
					ii->col = jj->col;
					jj->col = inter;

					inter = ii->val;
					ii->val = jj->val;
					jj->val = inter;
				}

			}
			jj = jj->nxt;
		}
		ii = ii->nxt;
	}


}


void AdditionMulti(node *head, node *head1, int n, int m) {

	node *headA;
	node *curA;
	node *nnA = new node();

	headA = nnA;
	nnA->row = n;
	nnA->col = m;
	nnA->val = 0;
	nnA->nxt = NULL;
	curA = headA;

	node *i = head->nxt;
	node *j = head1->nxt;

	int c = 1;
	while (j != NULL && i != NULL) {

		if (j->row == i->row && j->col == i->col) {
			c++;
			node *nnA = new node();
			nnA->row = j->row;
			nnA->col = j->col;
			nnA->val = j->val + i->val;
			nnA->nxt = NULL;
			curA->nxt = nnA;
			curA = nnA;
			j = j->nxt;
			i = i->nxt;
		}
		else if (i->row == j->row && i->col > j->col) {
			c++;
			node *nnA = new node();
			nnA->row = j->row;
			nnA->col = j->col;
			nnA->val = j->val;
			nnA->nxt = NULL;
			curA->nxt = nnA;
			curA = nnA;
			j = j->nxt;
		}
		else if (i->row == j->row && i->col < j->col) {
			c++;
			node *nnA = new node();
			nnA->row = i->row;
			nnA->col = i->col;
			nnA->val = i->val;
			nnA->nxt = NULL;
			curA->nxt = nnA;
			curA = nnA;
			i = i->nxt;

		}
		else if (i->row < j->row) {
			c++;
			node *nnA = new node();
			nnA->row = i->row;
			nnA->col = i->col;
			nnA->val = i->val;
			nnA->nxt = NULL;
			curA->nxt = nnA;
			curA = nnA;
			i = i->nxt;
		}
		else if (i->row > j->row) {
			c++;
			node *nnA = new node();
			nnA->row = j->row;
			nnA->col = j->col;
			nnA->val = j->val;
			nnA->nxt = NULL;
			curA->nxt = nnA;
			curA = nnA;
			j = j->nxt;
		}
	}

	while (j != NULL) {
		c++;
		node *nnA = new node();
		nnA->row = j->row;
		nnA->col = j->col;
		nnA->val = j->val;
		nnA->nxt = NULL;
		curA->nxt = nnA;
		curA = nnA;
		j = j->nxt;
	}

	while (i != NULL) {
		c++;
		node *nnA = new node();
		nnA->row = i->row;
		nnA->col = i->col;
		nnA->val = i->val;
		nnA->nxt = NULL;
		curA->nxt = nnA;
		curA = nnA;
		i = i->nxt;
	}

	cout << "******Addition********" << endl;
	int Adsize = c - 1;
	node *Addit = headA;
	while (Addit != NULL) {
		cout << Addit->row << " " << Addit->col << " " << Addit->val << endl;
		Addit = Addit->nxt;
	}

	/********MUltiply************/

	node *headM;
	node *curM;
	node *nnM = new node();

	headM = nnM;
	nnM->row = n;
	nnM->col = m;
	nnM->val = 0;
	nnM->nxt = NULL;
	c = 1;
	curM = headM;

	i = head->nxt;
	j = head1->nxt;

	while (i != NULL) {
		node *j = head1->nxt;
		while (j != NULL) {
			if (i->col == j->row) {
				c++;
				node *nnM = new node();
				nnM->row = i->row;
				nnM->col = j->col;
				nnM->val = i->val * j->val;
				nnM->nxt = NULL;
				curM->nxt = nnM;
				curM = nnM;
			}
			j = j->nxt;
		}
		i = i->nxt;
	}

	cout << "********MULtiply********" << endl;
	node *headM1;

	nnM = new node();
	nnM->row = n;
	nnM->col = m;
	nnM->val = 0;
	nnM->nxt = NULL;
	headM1 = nnM;
	curM = headM1;

	int non = 0, cc = 1;
	node *k = headM->nxt;
	while (k != NULL) {
		non = 0;
		cc++;

		while (k->nxt != NULL && k->row == k->nxt->row && k->col == k->nxt->col) {
			non = non + k->val;
			k = k->nxt;
		}
		non = non + k->val;

		node *nnM = new node();
		nnM->row = k->row;
		nnM->col = k->col;
		nnM->val = non;
		nnM->nxt = NULL;
		curM->nxt = nnM;
		curM = nnM;
		k = k->nxt;
	}

	curM = headM1;
	while (curM != NULL) {
		cout << curM->row << " " << curM->col << " " << curM->val << endl;
		curM = curM->nxt;
	}


}

void transpose(node *head) {

	cout << "****Transpose********" << endl;

	node *cur = head->nxt;

	int temper;
	while (cur != NULL) {
		temper  = cur->row;
		cur->row = cur->col;
		cur->col = temper;
		cur = cur->nxt;
	}

	sortn(head);

	cur = head;
	while (cur != NULL) {
		cout << cur->row << " " << cur->col << " " << cur->val << endl;
		cur = cur->nxt;
	}

}

void solve() {

	int n, m, count = 0, n1, m1;
	int asize, bsize;
	int number;
	cin >> number;
	if (number == 1) {
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] != 0) {
					count++;
				}
			}
		}

		node *head;
		node *cur;
		node *nn = new node();
		head = nn;
		nn->row = n;
		nn->col = m;
		nn->val = count;
		asize = count + 1;
		nn->nxt = NULL;
		cur = head;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) {
					node *nn = new node();
					nn->row = i;
					nn->col = j;
					nn->val = a[i][j];
					nn->nxt = NULL;
					cur->nxt = nn;
					cur = nn;

				}
			}
		}


		count = 0;
		cin >> n1 >> m1;
		int b[n1][m1];
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m1; j++) {
				cin >> b[i][j];
				if (b[i][j] != 0) {
					count++;
				}
			}
		}


		node *head1;
		node *cur1;
		node *nn1 = new node();
		head1 = nn1;
		nn1->row = n1;
		nn1->col = m1;
		nn1->val = count;
		bsize = count + 1;
		nn1->nxt = NULL;
		cur1 = head1;

		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m1; j++) {
				if (b[i][j] != 0) {
					node *nn = new node();
					nn->row = i;
					nn->col = j;
					nn->val = b[i][j];
					nn->nxt = NULL;
					cur1->nxt = nn;
					cur1 = nn;

				}
			}
		}

		AdditionMulti(head, head1, n, m);

	}
	else if (number == 2) {

		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] != 0) {
					count++;
				}
			}
		}

		node *head;
		node *cur;
		node *nn = new node();
		head = nn;
		nn->row = n;
		nn->col = m;
		nn->val = count;
		asize = count + 1;
		nn->nxt = NULL;
		cur = head;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) {
					node *nn = new node();
					nn->row = i;
					nn->col = j;
					nn->val = a[i][j];
					nn->nxt = NULL;
					cur->nxt = nn;
					cur = nn;

				}
			}
		}
		transpose(head);
	}
	else {
		cout << "invalid" << endl;
	}
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				count++;
			}
		}
	}

	node *head;
	node *cur;
	node *nn = new node();
	head = nn;
	nn->row = n;
	nn->col = m;
	nn->val = count;
	asize = count + 1;
	nn->nxt = NULL;
	cur = head;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0) {
				node *nn = new node();
				nn->row = i;
				nn->col = j;
				nn->val = a[i][j];
				nn->nxt = NULL;
				cur->nxt = nn;
				cur = nn;

			}
		}
	}


	count = 0;
	cin >> n1 >> m1;
	int b[n1][m1];
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			cin >> b[i][j];
			if (b[i][j] != 0) {
				count++;
			}
		}
	}


	node *head1;
	node *cur1;
	node *nn1 = new node();
	head1 = nn1;
	nn1->row = n1;
	nn1->col = m1;
	nn1->val = count;
	bsize = count + 1;
	nn1->nxt = NULL;
	cur1 = head1;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			if (b[i][j] != 0) {
				node *nn = new node();
				nn->row = i;
				nn->col = j;
				nn->val = b[i][j];
				nn->nxt = NULL;
				cur1->nxt = nn;
				cur1 = nn;

			}
		}
	}


	/*cur = head;
	cur1 = head1;

	while (cur != NULL) {
		cout << cur->row << " " << cur->col << " " << cur->val << endl;
		cur = cur->nxt;
	}

	cout << "****************" << endl;
	while (cur1 != NULL) {
		cout << cur1->row << " " << cur1->col << " " << cur1->val << endl;
		cur1 = cur1->nxt;
	}*/



	/***ADDITION***/





}
