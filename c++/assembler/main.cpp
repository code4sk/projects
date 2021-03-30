#include <bits/stdc++.h>

using namespace std;

void ins(unordered_map<string, pair<string, int>> &m){
    m["ADD A"] = {"87", 1};
    m["ADD B"] = {"80", 1};
    m["ADD C"] = {"81", 1};
    m["ADD D"] = {"82", 1};
    m["ADD E"] = {"83", 1};
    m["ADD H"] = {"84", 1};
    m["ADD L"] = {"85", 1};
    m["ADD M"] = {"86", 1};
    m["MOV A B"] = {"3E", 1};
    m["RET"] = {"1A", 1};
    m["DCR C"] = {"1A", 1};
    m["DCR A"] = {"2A", 1};
    m["DCR B"] = {"4A", 1};
    m["DCR D"] = {"5A", 1};
    m["DCR E"] = {"6A", 1};
    m["DCR H"] = {"7A", 1};
    m["DCR L"] = {"8E", 1};
    m["INX H"] = {"91", 1};
    m["DCR"] = {"1A", 1};
    m["HLT"] = {"6F", 1};
    m["ADI"] = {"4F", 2};
    m["JMP"] = {"5E", 3};
    m["JNZ"] = {"2D", 3};
    m["JZ"] = {"2E", 3};
    m["CALL"] = {"7F", 3};

}

void showSymbolTable(unordered_map<string, int> &symbol){
    for(auto it = symbol.begin();it != symbol.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}


int main()
{
    unordered_map <string, pair<string, int>> m;
    unordered_map<string, int> symbol;

    ins(m);
    string str;
    string extra[20001];
    int addr = 2000;
    int ctr = 0;
    vector<string> v;
    do{
        cout<<addr<<" -> ";
        stringstream ss;
        getline(cin, str);
        int it = str.find(":");
        if(it != -1){
            symbol[str.substr(0, it)] = addr;
            str = str.substr(it+1);
        }
        ss<<str;
        string temp;
        if(str.find("JMP") != -1 || str.find("JNZ") != -1 || str.find("JZ") != -1 || str.find("CALL") != -1){
            while(ss>>temp){

            }
            //cout<<temp<<endl;
            for(int i=str.length()-1;i>=0;i--){
                if(str[i] == ' '){
                    v.push_back(str.substr(0, i));
                    //cout<<str.substr(0, i)<<endl;
                    break;
                }
            }
            //cout<<"OH "<<temp<<endl;
            extra[ctr] = temp;
            addr += 3;
        } else {
            v.push_back(str);
            addr++;
        }
        ctr++;
    } while(str != "quit" && str != "QUIT");
    addr = 2000;
    cout<<endl<<"Symbol table\n\n";
    showSymbolTable(symbol);
    cout<<endl<<"Machine code\n";
    cout<<endl;
    for(int i=0;i<v.size();i++){
        stringstream ss;

        if(m.find(v[i]) == m.end()){
            if(v[i] != "QUIT")
            cout<<"Sorry can not parse this instruction \""<<v[i]<<"\""<<endl;
            break;
        }
        ss<<v[i];
        string temp;
        ss>>temp;
        getline(ss, temp);
        cout<<addr<<" -> ";
        cout<<m[v[i]].first<<" ";
        if(m[v[i]].second > 1){
            if(symbol.find(extra[i]) == symbol.end()){
                cout<<"Sorry can not parse this label \""<<extra[i]<<"\""<<endl;
                break;
            }
            cout<<symbol[extra[i]];
        }
        cout<<endl;
        addr += m[v[i]].second;
    }
    return 0;
}
