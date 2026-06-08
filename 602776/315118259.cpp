#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Node {
  Node* p = nullptr;
  Node* l = nullptr;
  Node* r = nullptr;
  int sign{};
  int mn = 1e9;
  int mx = -1e9;
  int mostleft{};

  bool max_inv{};
  bool min_inv{};

  Node(int v) {
    mn = v;
    mostleft = v;
    mx = v;
  }

  Node() {}
};

pair<string, Node*> normalize(string& s) {
  int n = s.length();

  vector<int> st;
  vector<int> poses(n, -1);

  for(int i = 0;i < n;i++) {
    if(s[i] == '(') {
      st.push_back(i);
    } else if(s[i] == ')') {
      poses[st.back()] = i;
      st.pop_back();
    }
  }

  auto build_tree = [&](auto&& self, int l, int r, string& s) -> Node* {
    if(r - l == 1) {
      assert(s[l] >= '0' && s[r] <= '9');
      Node* ret = new Node();
      ret->mn = ret->mx = s[l] - '0';
      return ret;
    }

    vector<Node*> vals;
    vector<char> ops;
    for(int i = l;i < r;i++) {
      if(s[i] == '(') {
        vals.push_back(self(self, i + 1, poses[i], s));
        i = poses[i];
      } else if(s[i] == '+' || s[i] == '-') {
        ops.push_back(s[i]);
      } else {
        Node* val = new Node(s[i] - '0');
        vals.push_back(val);
      }
    }

    assert(vals.size() == ops.size() + 1);

    Node* ret = vals[0];

    for(int i = 1;i < vals.size();i++) {
      int sgn = ops[i - 1] == '+' ? 1 : -1;
      Node* root = new Node();
      root->sign = sgn;
      root->l = ret;
      root->r = vals[i];
      root->mostleft = root->l->mostleft;
      ret->p = root;
      ret = root;
    }

    return ret;
  };

  Node* root = build_tree(build_tree, 0, n, s);

  auto dfs = [&](auto&& self, Node* node) -> string {
    if(node->sign == 0) {
      return to_string(node->mn);
    }

    string res = self(self, node->l);
    string op = node->sign == -1 ? "-" : "+";
    if(node->r->sign != 0) {
      res = res + op + "(" + self(self, node->r) + ")";
      return res;
    } else {
      res = res + op + self(self, node->r);
      return res;
    }
  };

  string res = dfs(dfs, root);

  return pair<string, Node*>(res, root);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  s = normalize(s).first;
  // cout << s << endl;

  auto p = normalize(s);

  Node* root = p.second;

  auto slv = [&](auto&& self, Node* root) -> void {
    if(root->sign == 0) {
      // cout << "leaf " << root->mn << endl;
      return;
    }

    string op = root->sign == 1 ? "+" : "-";
    // cout << op << endl;

    self(self, root->l);
    self(self, root->r);
    if(root->sign == -1) {

      int lval_mx = root->l->mx;
      int rval_mx = -root->r->mn;
      if(root->r->sign != 0 && rval_mx < (root->r->mx - 2 * root->r->mostleft)) {
        rval_mx = (root->r->mx - 2 * root->r->mostleft);
        root->max_inv = true;
      }

      int lval_mn = root->l->mn;
      int rval_mn = -root->r->mx;
      if(root->r->sign != 0 && rval_mn > (root->r->mn - 2 * root->r->mostleft)) {
        rval_mn = (root->r->mx - 2 * root->r->mostleft);
        root->min_inv = true;
      }

      // cout << lval_mn << ' ' << rval_mn << endl;
      // cout << lval_mx << ' ' << rval_mx << endl;
      // cout << endl;

      root->mn = lval_mn + rval_mn;
      root->mx = lval_mx + rval_mx;

    } else {
      root->mn = root->l->mn + root->r->mn;
      root->mx = root->l->mx + root->r->mx;
    }

  };

  slv(slv, root);

  auto restore_ans = [&](auto&& self, Node* v, bool need_max) -> string {
    if(v->sign == 0) {
      return to_string(v->mn);
    }
    // cout << v->mx << ' ' << v->mn << endl;
    // cout << v->max_inv << ' ' << v->min_inv << endl;
    // cout << endl;
    if(need_max) {
      if(v->max_inv) {
        string op = v->sign == 1 ? "+" : "-";
        return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
      } else {
        string op = v->sign == 1 ? "+" : "-";
        if(v->r->sign != 0)
          return self(self, v->l, need_max) + op + "(" + self(self, v->r, (op == "-") ^ need_max) + ")";
        else
          return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
      }
    } else {
      if(v->min_inv) {
        string op = v->sign == 1 ? "+" : "-";
        return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
      } else {
        string op = v->sign == 1 ? "+" : "-";
        if(v->r->sign != 0)
          return self(self, v->l, need_max) + op + "(" + self(self, v->r, (op == "-") ^ need_max) + ")";
        else
          return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
      }
    }
  };

  cout << root->mx << '\n';
  cout << restore_ans(restore_ans, root, 1) << endl;
}