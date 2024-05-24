#include <bits/stdc++.h>
#define author armag - pro
using namespace std;
const int N = 109;
int n, m;
// 3D vector to store Input
vector<int> nt[N][N];
// Set ot vectors to store Output
set<int> nt1[N][N];
// Set of array to store Closure
set<int> closure[N];
// Final State
map<int, bool> final_state;
// Input State
map<int, bool> in_state;
// Function to print output
void print_without_eps()
{
cout << "\nNFA without null moves:\n";
cout << "============================\n";
cout << "Q\t\tSymbols\n";
for (int i = 0; i < n; i++)
{
cout << "Q" << i << "\t";
for (int j = 1; j <= m; j++)
{
cout << "{";
// for (int ii : nt1[i][j])
// cout << ii << " ";
set<int> st = nt1[i][j];
for(auto it = st.begin(); it != st.end(); it++)
{
    cout << *it << " ";
}
// cout << endl;
cout << "}\t";
}
cout << endl;
}
cout << endl;
}
void print_final_State (){
cout << "Final States are (Enter By user)" << endl;
for(auto it = final_state.begin() ; it != final_state.end() ; it++){
cout << it->first << " " ;
}
cout << endl;
cout << "Other than it (If starting state directly reach to the final states than that also be Final State)" << endl;
for(auto it = in_state.begin() ; it != in_state.end() ; it++){
int ini = it->first ;
//Null Closure of intial State
set<int> st = closure[ini];
for(auto i = st.begin() ; i != st.end() ;i++){
if(final_state[*i] == true){
cout << it->first << " ";
}
}
cout << endl;
}
}
int main()
{
cout << "No. of states: ";
cin >> n;
cout << "No. of input symbols: ";
cin >> m;
cout << "Enter transitions:\n\n";
// Transition table
for (int i = 0; i < n; i++)
{
cout << "State " << i << endl;
for (int j = 0; j <= m; j++)
{
cout << "\tNo of transitions for ";
if (j == 0)
cout << "NULL";
else
cout << char(j + 'a' - 1);
cout << ": ";
int temp;
cin >> temp;
nt[i][j].resize(temp);
if (temp == 0)
{
}
else if (temp == 1)
{
cout << "\tEnter the state: ";
}
else
{
cout << "\tEnter the " << temp << " states: ";
}
for (int k = 0; k < nt[i][j].size(); k++)
{
cin >> nt[i][j][k];
}
}
cout << endl;
}
cout << endl;
cout << "Enter a number of Intial State : " << endl;
int in;
cin >> in;
if (in > n)
{
cout << "Intial States can not be more then number of state " << endl;
}
else
{
cout << "Enter the States " << endl;
for (int i = 0; i < in; i++)
{
int x;
cin >> x;
if (x >= n)
{
cout << "State number is less than " << n << endl;
i--;
}
else
{
in_state[x] = true;
}
}
}
cout << endl;
cout << "Enter a number of Final State : " << endl;
int fi;
cin >> fi;
if (fi > n)
{
cout << "Final States can not be more then number of state " << endl;
}
else
{
cout << "Enter the States " << endl;
for (int i = 0; i < fi; i++)
{
int x;
cin >> x;
if (x >= n)
{
cout << "State number is less than " << n << endl;
i--;
}
else
{
final_state[x] = true;
}
}
}
// Finding epsilon closure for each state
//Find all the state from one state that can be reached by null .
for (int i = 0; i < n; i++)
{
queue<int> q;
vector<bool> vis(n, false);
q.push(i);
vis[i] = 1;
while (!q.empty())
{
int top = q.front();
q.pop();
for (int k = 0; k < nt[top][0].size(); k++)
{
int cur = nt[top][0][k];
if (vis[cur] == 0)
{
vis[cur] = 1;
q.push(cur);
}
}
}
for (int j = 0; j < n; j++)
{
if (vis[j] == 1)
closure[i].insert(j);
}
}
cout << "Null Closure of Every state" << endl;
for (int i = 0; i < n; i++)
{
cout << "For State " << i << endl;
set<int> st = closure[i];
for (auto it = st.begin(); it != st.end(); it++)
{
cout << *it << " ";
}
cout << endl;
}
cout << endl;
// Find epsilon* --> symbol --> epsilon* for each state and symbol
for (int i = 0; i < n; i++)
{
for (int ii : closure[i])
{
for (int j = 1; j <= m; j++)
{
for (int k = 0; k < nt[ii][j].size(); k++)
{
int cur = nt[ii][j][k];
for (int iii : closure[cur])
{
nt1[i][j].insert(iii);
}
}
}
}
}
print_without_eps();
print_final_State();
return 0;
}
