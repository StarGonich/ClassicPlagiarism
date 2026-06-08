#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    deque<int>main_d = {}, now_d = {};
    vector<char>is_in_main_d(k, '\0');
    vector<vector<char>>a(n, vector<char>(m, '\0')), b(n, vector<char>(m, '\0'));
    vector<vector<vector<char>>>all_configs(k, vector<vector<char>>(n, vector<char>(m, '\0')));
    for(int q = 0; q < k; q++){
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                cin >> all_configs[q][i][j];
                all_configs[q][i][j] -= '0';
            }
        }
    }
    for(int i_of_config = 0; i_of_config < k; i_of_config++){
        if(!is_in_main_d[i_of_config]){
            now_d = {i_of_config};
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    a[i][j] = '\0';
                    if(i > 0){
                        if(j > 0){
                            a[i][j] += all_configs[i_of_config][i - 1][j - 1];
                        }
                        a[i][j] += all_configs[i_of_config][i - 1][j];
                        if(j + 1 < m){
                            a[i][j] += all_configs[i_of_config][i - 1][j + 1];
                        }
                    }
                    if(j > 0){
                        a[i][j] += all_configs[i_of_config][i][j - 1];
                    }
                    if(j + 1 < m){
                        a[i][j] += all_configs[i_of_config][i][j + 1];
                    }
                    if(i + 1 < n){
                        if(j > 0){
                            a[i][j] += all_configs[i_of_config][i + 1][j - 1];
                        }
                        a[i][j] += all_configs[i_of_config][i + 1][j];
                        if(j + 1 < m){
                            a[i][j] += all_configs[i_of_config][i + 1][j + 1];
                        }
                    }
                    //cout << (char)(a[i][j] + '0') << ' ';
                    if(all_configs[i_of_config][i][j]){
                        a[i][j] = (bool)('\1' < a[i][j] && a[i][j] < '\4');
                    }
                    else{
                        a[i][j] = (bool)(a[i][j] == '\3');
                    }
                }
                //cout << '\n';
            }
            bool isfirst = 1;
            while(true){
                if((!isfirst) && a == b){
                    while(now_d.size()){
                        //cout << 'b';
                        is_in_main_d[now_d.front()] = 1;
                        main_d.push_back(now_d.front());
                        now_d.pop_front();
                    }
                    goto start_from_next_config;
                }
                for(int i_find_same = 0; i_find_same < k; i_find_same++){
                    if(a == all_configs[i_find_same]){
                        if(is_in_main_d[i_find_same]){
                            while(now_d.size()){
                                //cout << 'c';
                                is_in_main_d[now_d.back()] = 1;
                                main_d.push_front(now_d.back());
                                now_d.pop_back();
                            }
                            goto start_from_next_config;
                        }
                        else{
                            //cout << 'a';
                            now_d.push_back(i_find_same);
                        }
                        break;
                    }
                }
                isfirst = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        b[i][j] = '\0';
                        if(i > 0){
                            if(j > 0){
                                b[i][j] += a[i - 1][j - 1];
                            }
                            b[i][j] += a[i - 1][j];
                            if(j + 1 < m){
                                b[i][j] += a[i - 1][j + 1];
                            }
                        }
                        if(j > 0){
                            b[i][j] += a[i][j - 1];
                        }
                        if(j + 1 < m){
                            b[i][j] += a[i][j + 1];
                        }
                        if(i + 1 < n){
                            if(j > 0){
                                b[i][j] += a[i + 1][j - 1];
                            }
                            b[i][j] += a[i + 1][j];
                            if(j + 1 < m){
                                b[i][j] += a[i + 1][j + 1];
                            }
                        }
                        if(a[i][j]){
                            b[i][j] = (bool)('\1' < b[i][j] && b[i][j] < '\4');
                        }
                        else{
                            b[i][j] = (bool)(b[i][j] == '\3');
                        }
                    }
                }
                if(a == b){
                    while(now_d.size()){
                        //cout << 'b';
                        is_in_main_d[now_d.front()] = 1;
                        main_d.push_back(now_d.front());
                        now_d.pop_front();
                    }
                    goto start_from_next_config;
                }
                for(int i_find_same = 0; i_find_same < k; i_find_same++){
                    if(b == all_configs[i_find_same]){
                        if(is_in_main_d[i_find_same]){
                            while(now_d.size()){
                                //cout << 'c';
                                is_in_main_d[now_d.back()] = 1;
                                main_d.push_front(now_d.back());
                                now_d.pop_back();
                            }
                            goto start_from_next_config;
                        }
                        else{
                            //cout << 'a';
                            now_d.push_back(i_find_same);
                        }
                        break;
                    }
                }
                isfirst = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        a[i][j] = '\0';
                        if(i > 0){
                            if(j > 0){
                                a[i][j] += b[i - 1][j - 1];
                            }
                            a[i][j] += b[i - 1][j];
                            if(j + 1 < m){
                                a[i][j] += b[i - 1][j + 1];
                            }
                        }
                        if(j > 0){
                            a[i][j] += b[i][j - 1];
                        }
                        if(j + 1 < m){
                            a[i][j] += b[i][j + 1];
                        }
                        if(i + 1 < n){
                            if(j > 0){
                                a[i][j] += b[i + 1][j - 1];
                            }
                            a[i][j] += b[i + 1][j];
                            if(j + 1 < m){
                                a[i][j] += b[i + 1][j + 1];
                            }
                        }
                        if(b[i][j]){
                            a[i][j] = (bool)('\1' < a[i][j] && a[i][j] < '\4');
                        }
                        else{
                            a[i][j] = (bool)(a[i][j] == '\3');
                        }
                    }
                }
            }
        }
        start_from_next_config:;
    }
    while(main_d.size()){
        cout << main_d.front() + 1 << ' ';
        main_d.pop_front();
    }
    return 0;
}
