#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> coords;

int main() {
    
    int n = 0, m = 0;
    
    cin >> n >> m;
    char soteholm[1502][1502];
    bool visited[1502][1502];
    
    
    for(int i = 1; i <= n; i++){ // Add to area
    
        for(int j = 1; j <= m; j++){
        
            cin >> soteholm[i][j];
            if(soteholm[i][j] == '1'){ // If soteholm is land then we have we visited it
            
                visited[i][j] = true;
            
            } else {
            
                visited[i][j] = false;
            
            }

        }
    
    }
    
    
    for(int i = 0; i != m + 1; i++){ // Add extra sea to top and right
        
        soteholm[0][i] = '0';
        soteholm[n+1][i] = '0';
        
        visited[0][i] = false;
        visited[n+1][i] = false;
        
    }
    
    for(int i = 0; i != n + 1; i++){ // Add extra sea to bottom and left
        
        soteholm[i][0] = '0';
        soteholm[i][m+1] = '0';
        
        visited[i][0] = false;
        visited[i][m+1] = false;
        
    }
    
    soteholm[n+1][m+1] = '0'; // special case for last corner
    visited[n+1][m+1] = false;
    
    n += 2; // make n and m larger because of extra sea zone
    m += 2;
    
    queue<coords>Q; // Queue to tell sea from water
    Q.push(coords(0, 0));
    soteholm[0][0] = '2'; // From now on water = 0, land = 1 and sea = 2
    visited[0][0] = true;
    
    while(!Q.empty()){ // BFS to mark all sea
    
        coords u = Q.front();
        Q.pop();
        
        if(u.first > 0 && soteholm[u.first - 1][u.second] == '0' && visited[u.first - 1][u.second] == false){
        
            Q.push(coords(u.first - 1, u.second));
            soteholm[u.first - 1][u.second] = '2';
            visited[u.first - 1][u.second] = true;
        
        }
        
        if(u.second > 0 && soteholm[u.first][u.second - 1] == '0' && visited[u.first][u.second - 1] == false){
            
            Q.push(coords(u.first, u.second - 1));
            soteholm[u.first][u.second - 1] = '2';
            visited[u.first][u.second - 1] = true;
            
        }
        
        if(u.first < n && soteholm[u.first + 1][u.second] == '0' && visited[u.first + 1][u.second] == false){
            
            Q.push(coords(u.first + 1, u.second));
            soteholm[u.first + 1][u.second] = '2';
            visited[u.first + 1][u.second] = true;
        
        }
        
        if(u.second < m && soteholm[u.first][u.second + 1] == '0' && visited[u.first][u.second + 1] == false){
            
            Q.push(coords(u.first, u.second + 1));
            soteholm[u.first][u.second + 1] = '2';
            visited[u.first][u.second + 1] = true;
            
        }
    
    }
    
    
    int count = 0;
    
    for(int i = 0; i < n; i++){ // Find every place where land is connected to sea
        
        for(int j = 0; j < m; j++){

            
            if(soteholm[i][j] == '1' && soteholm[i-1][j] == '2'){ // coast left
                
                count++;
                
            }
            
            if(soteholm[i][j] == '1' && soteholm[i+1][j] == '2'){ // coast right
                
                count++;
                
            }
            
            if(soteholm[i][j] == '1' && soteholm[i][j-1] == '2'){ // coast top
                
                count++;
                
            }
            
            if(soteholm[i][j] == '1' && soteholm[i][j+1] == '2'){ // coast down
                
                count++;
                
            }
            
        
        }
    
    }
    
    
    
    cout << count;
    
    return 0;

}
