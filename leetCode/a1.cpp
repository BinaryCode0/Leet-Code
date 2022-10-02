#include<bits/stdc++.h>
using namespace std;
#define MAX 250000;
struct node {
	int row;
	int col;
	int val;
};

void sortn(node &nd, int n);
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


void sortn(node *nd, int n) {
	int inter;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nd[i].row > nd[j].row) {
				inter = nd[i].row;
				nd[i].row = nd[j].row;
				nd[j].row =  inter;

				inter = nd[i].col;
				nd[i].col = nd[j].col;
				nd[j].col = inter;

				inter = nd[i].val;
				nd[i].val = nd[j].val;
				nd[j].val = inter;
			}

			else if (nd[i].row == nd[j].row) {
				if (nd[i].col > nd[j].col) {
					inter = nd[i].col;
					nd[i].col = nd[j].col;
					nd[j].col = inter;

					inter = nd[i].val;
					nd[i].val = nd[j].val;
					nd[j].val = inter;
				}
			}
		}
	}
}




void solve()
{
	int n, m, count = 0, n1, m1;
	int asize, bsize;
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

	node s1[count + 1];
	s1[0].row = n;
	s1[0].col = m;
	s1[0].val = count;
	asize = count + 1;
	count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0) {
				s1[count].row = i;
				s1[count].col = j;
				s1[count].val = a[i][j];
				count++;
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

	node s2[count + 1];
	s2[0].row = n1;
	s2[0].col = m1;
	s2[0].val = count;
	bsize = count + 1;
	count = 1;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			if (b[i][j] != 0) {
				s2[count].row = i;
				s2[count].col = j;
				s2[count].val = b[i][j];
				count++;
			}
		}
	}


	/*ADDITION*/
	node *s3 = (node *)malloc(sizeof(node));
	s3->row = n;
	(s3)->col = m;
	(s3)->val = 0;
	//cout << s3[0].val << " " << s3[0].col << " " << s3[0].val << endl;
	int c = 1, j = 1, i = 1;

	while (j < bsize && i < asize) {

		if (s1[i].row == s2[j].row && s1[i].col == s2[j].col) {
			c++;
			s3 = (node *)realloc(s3, sizeof(node) * c);
			s3[c - 1].row = s1[i].row;
			s3[c - 1].col = s1[i].col;
			s3[c - 1].val = s1[i].val + s2[j].val;
			j++; i++;
			//cout << s3[c - 1].row << " " << s3[c - 1].col << " " << s3[c - 1].val << endl;
		}
		else if (s1[i].row == s2[j].row && s1[i].col > s2[j].col) {
			c++;
			s3 = (node *)realloc(s3, sizeof(node) * c);
			s3[c - 1].row = s2[j].row;
			s3[c - 1].col = s2[j].col;
			s3[c - 1].val = s2[j].val;
			j++;
		}
		else if (s1[i].row == s2[j].row && s1[i].col < s2[j].col) {
			c++;
			s3 = (node *)realloc(s3, sizeof(node) * c);
			s3[c - 1].row = s1[i].row;
			s3[c - 1].col = s1[i].col;
			s3[c - 1].val = s1[i].val;
			i++;
		}
		else if (s1[i].row < s2[j].row) {
			c++;
			s3 = (node *)realloc(s3, sizeof(node) * c);
			s3[c - 1].row = s1[i].row;
			s3[c - 1].col = s1[i].col;
			s3[c - 1].val = s1[i].val;
			i++;
		}
		else if (s1[i].row > s2[j].row) {
			c++;
			s3 = (node *)realloc(s3, sizeof(node) * c);
			s3[c - 1].row = s2[j].row;
			s3[c - 1].col = s2[j].col;
			s3[c - 1].val = s2[j].val;
			j++;
		}
		if (i >= asize || j >= bsize) {break;}
	}

	while (j < bsize) {
		c++;
		s3 = (node *)realloc(s3, sizeof(node) * c);
		s3[c - 1].row = s2[j].row;
		s3[c - 1].col = s2[j].col;
		s3[c - 1].val = s2[j].val;
		j++;
	}
	while (i < asize) {
		c++;
		s3 = (node *)realloc(s3, sizeof(node) * c);
		s3[c - 1].row = s1[i].row;
		s3[c - 1].col = s1[i].col;
		s3[c - 1].val = s1[i].val;
		i++;
	}
	s3[0].val = c - 1;
	for (int i = 0; i < c; i++) {
		cout << s3[i].row << " " << s3[i].col << " " << s3[i].val << endl;
	}


	/*MULTIPLY*/

	node *s4 = (node *)malloc(sizeof(node));
	s4->row = n;
	s4->col = m;
	s4->val = 0;
	c = 1;
	for (i = 1; i < asize; i++) {
		for (j = 1; j < bsize; j++) {
			if (s1[i].col == s2[j].row) {
				c++;
				s4 = (node *)realloc(s4, sizeof(node) * c);
				s4[c - 1].row = s1[i].row;
				s4[c - 1].col = s2[j].col;
				s4[c - 1].val = s1[i].val * s2[j].val;
			}
		}
	}
	cout << "*************************" << endl;
	node *s5 = (node *)malloc(sizeof(node));
	s5->row = n;
	s5->col = m;
	s5->val = 0;
	int non = 0, cc = 1;
	for (int i = 1; i < c; i++) {
		non = 0;
		cc++;
		//cout << s4[i].row << " " << s4[i].col << " " << s4[i].val << endl;
		while (s4[i].row == s4[i + 1].row && s4[i].col == s4[i + 1].col) {
			non = non + s4[i].val;
			i++;
		}
		non = non + s4[i].val;
		s5 = (node *)realloc(s5, sizeof(node) * c);
		s5[cc - 1].row = s4[i].row;
		s5[cc - 1].col = s4[i].col;
		s5[cc - 1].val = non;

	}

	for (int i = 0; i < cc; i++) {
		cout << s5[i].row << " " << s5[i].col << " " << s5[i].val << endl;
	}

	cout << "***********************" << endl;
	/**Transpose**/
	int temper;
	for (i = 1; i < asize; i++) {
		temper = s1[i].row;
		s1[i].row = s1[i].col;
		s1[i].col = temper;
	}

	sortn(s1, asize);

	for (int i = 0; i < asize; i++) {
		cout << s1[i].row << " " << s1[i].col << " " << s1[i].val << endl;
	}



}
