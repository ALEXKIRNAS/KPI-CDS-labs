#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int Nmax = 1e3;
vector < pair<int, int> > g[Nmax]; // ����

int d[Nmax]; // ����� �������� �� �������� ������� �� ��� �����
int p[Nmax]; // ����� ��� ���������� ��������
char u[Nmax]; // ̳��� ����, �� ���������� ������� ��� ���������


void deis(int s, int n) {

	for (int i = 0; i <= n; i++) d[i] = INF;
	d[s] = 0;
	p[s] = -1;

	for (int i = 0; i<n; ++i) {
		int v = -1;

		for (int z = 0; z<n; z++)
			if (!u[z] && (v == -1 || d[z] < d[v]))
				v = z;

		if (d[v] == INF)
			break;

		u[v] = true;

		for (int j = 0; j<g[v].size(); ++j) {

			int to = g[v][j].first;
			int	len = g[v][j].second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}

		}

	}

}


int main() {
	int n, m;
	cin >> n >> m;

	pair <int, int> t;
	for (int i = 0; i<m; i++)
	{
		int from, to, w;
		cin >> from >> to >> w;

		t.first = to;
		t.second = w;

		g[from].push_back(t);
	}

	int s = 1; // ��������� �������

	deis(s, n);

	cout << "Min len to:" << endl;
	for (int i = 1; i <= n; i++) cout << i << " - " << d[i] << endl;

	int end = 5; // ������� �� ��� �������� ����
	vector <int> way;

	// ³��������� ��������
	while (end != -1) {
		way.push_back(end);
		end = p[end];
	}

	cout << "Way:" << endl;
	for (int i = way.size() - 1; i >= 0; i--) cout << way[i] << " ";
}