#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Node {
  Node* p = nullptr;
  vector<Node*> children;
  vector<string> ops;
  vector<bool> br_min;
  vector<bool> br_max;
  int sign{};
  int mn = 1e9;
  int mx = -1e9;

  bool max_inv{};
  bool min_inv{};

  Node(int v) {
    mn = v;
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
      assert(s[l] >= '0' && s[l] <= '9');
      Node* ret = new Node();
      ret->mn = ret->mx = s[l] - '0';
      return ret;
    }

    vector<Node*> vals;
    vector<bool> in_par;
    vector<string> ops;
    for(int i = l;i < r;i++) {
      if(s[i] == '(') {
        vals.push_back(self(self, i + 1, poses[i], s));
        in_par.push_back(1);
        i = poses[i];
      } else if(s[i] == '+' || s[i] == '-') {
        ops.push_back(s[i] == '+' ? "+" : "-");
      } else {
        Node* val = new Node(s[i] - '0');
        vals.push_back(val);
        in_par.push_back(0);
      }
    }

    assert(vals.size() == ops.size() + 1);

    Node* ret = new Node();
    ret->children = vals;
    ret->ops = ops;
    ret->br_min = in_par;
    ret->br_max = in_par;

    return ret;
  };

  Node* root = build_tree(build_tree, 0, n, s);

  auto dfs = [&](auto&& self, Node* node) -> string {
    if(node->children.size() == 0) {
      return to_string(node->mn);
    }

    if(node->children.size() == 1) {
      return self(self, node->children[0]);
    }

    string res = "";
    for(int i = 0;i < node->children.size();i++) {
      if(node->br_max[i])
        res += "(" + self(self, node->children[i]) + ")";
      else
        res += "" + self(self, node->children[i]) + "";
      if(i < node->ops.size()) {
        res += node->ops[i];
      }
    }

    return res;
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

  auto slv = [&](auto&& self, Node* v) -> void {

    for(Node* u : v->children) {
      self(self, u);
    }

    if(v->children.size() == 1) {
      v = v->children[0];
      return;
    }

    if(v->children.size() == 0) {
      return;
    }

    auto& c = v->children;
    auto& ops = v->ops;

    int mx = c[0]->mx;
    int mn = c[0]->mn;
    for(int i = 1;i < c.size();i++) {
      if(ops[i - 1] == "+") {
        mx += c[i]->mx;
        mn += c[i]->mn;
      } else if(!v->br_max[i] || c[i]->children.size() == 0) {
        int mul = ops[i - 1] == "+" ? 1 : -1;
        mx += mul == -1 ? -c[i]->mn : c[i]->mx;
        mn += mul == -1 ? -c[i]->mx : c[i]->mn;
      } else {
        int tmx1 = -c[i]->mn;
        int tmx2 = -c[i]->children[0]->mn + (c[i]->mx - c[i]->children[0]->mx);

        if(tmx2 > tmx1) {
          mx += tmx2;
          v->br_max[i] = 0;

        } else {
          mx += tmx1;
        }

        int tmn1 = -c[i]->mx;
        // cout << "tmn1: " << tmn1 << endl;
        int tmn2 = -c[i]->children[0]->mx + (c[i]->mn - c[i]->children[0]->mn);
        if(tmn2 < tmn1) {
          mn += tmn2;
          v->br_min[i] = 0;
          // cout << tmn1 << ' ' << tmn2 << endl;
        } else {
          mn += tmn1;
          cout << tmn1 << ' ';
          // cout << tmn1 << ' ' << tmn2 << endl;
        }
      }
    }
    // cout << endl;

    v->mx = mx;
    v->mn = mn;
  };

  slv(slv, root);

  auto dfs = [&](auto&& self, Node* node, bool is_max) -> string {
    if(node->children.size() == 0) {
      return to_string(node->mn);
    }

    if(node->children.size() == 1) {
      return self(self, node->children[0], is_max);
    }

    auto& br = is_max ? node->br_max : node->br_min;

    string res = "";
    for(int i = 0;i < node->children.size();i++) {
      bool is_min = i != 0 && node->ops[i - 1] == "-";
      if(br[i])
        res += "(" + self(self, node->children[i], is_max ^ is_min) + ")";
      else
        res += "" + self(self, node->children[i], is_max ^ is_min) + "";
      if(i < node->ops.size()) {
        res += node->ops[i];
      }
    }
    // cout << is_max << endl;
    // cout << res << endl;
    // for(auto e : br)
      // cout << e;
    // cout << endl;

    return res;
  };

  cout << root->mx << '\n';
  cout << dfs(dfs, root, 1) << '\n';
  // slv(slv, root);

  // auto restore_ans = [&](auto&& self, Node* v, bool need_max) -> string {
  //   if(v->sign == 0) {
  //     return to_string(v->mn);
  //   }
  //   // cout << v->mx << ' ' << v->mn << endl;
  //   // cout << v->max_inv << ' ' << v->min_inv << endl;
  //   // cout << endl;
  //   if(need_max) {
  //     if(v->max_inv) {
  //       string op = v->sign == 1 ? "+" : "-";
  //       return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
  //     } else {
  //       string op = v->sign == 1 ? "+" : "-";
  //       if(v->r->sign != 0)
  //         return self(self, v->l, need_max) + op + "(" + self(self, v->r, (op == "-") ^ need_max) + ")";
  //       else
  //         return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
  //     }
  //   } else {
  //     if(v->min_inv) {
  //       string op = v->sign == 1 ? "+" : "-";
  //       return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
  //     } else {
  //       string op = v->sign == 1 ? "+" : "-";
  //       if(v->r->sign != 0)
  //         return self(self, v->l, need_max) + op + "(" + self(self, v->r, (op == "-") ^ need_max) + ")";
  //       else
  //         return self(self, v->l, need_max) + op + self(self, v->r, (op == "-") ^ need_max);
  //     }
  //   }
  // };

  // cout << restore_ans(restore_ans, root, 1) << endl;
}