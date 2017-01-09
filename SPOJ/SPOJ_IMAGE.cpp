#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using std::pair;
using std::make_pair;

pair<bool, bool> matrix[22][22];
int rows, columns, y, x, perimeter;

int main(){
    ios_base::sync_with_stdio(false);
    queue<pair<int, int> > Q;
    char inp;
    cin >> rows >> columns >> y >> x;
    while(!(rows == 0 && rows == columns && columns == y && y == x)){
        perimeter = 0;
        for(int iii=0; iii<=columns+1; iii++){
            for(int jjj=0; jjj<= rows+1; jjj++){
                matrix[iii][jjj].first = false;
                matrix[iii][jjj].second = false;
            }
        }
        for(int jjj=1; jjj<=rows; jjj++){
            for(int iii=1; iii<=columns; iii++){
                cin >> inp;
                matrix[iii][jjj].first = ((inp == 'X')?(true):(false));
            }
        }

        int xx = x, yy = y;
        Q.push(make_pair(xx, yy));
        if(matrix[xx][yy].first && !matrix[xx][yy].second){
            if(!matrix[xx-1][yy].first){
                ++perimeter;
            }
            if(!matrix[xx][yy+1].first){
                ++perimeter;
            }
            if(!matrix[xx][yy-1].first){
                ++perimeter;
            }
            if(!matrix[xx+1][yy].first){
                ++perimeter;
            }
            matrix[xx][yy].second = true;
        }
        while(!Q.empty()){
            pair<int, int> cur_point = Q.front();
            Q.pop();
            // *..
            // .X.
            // ...
            xx = cur_point.first-1, yy = cur_point.second-1;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }
            //...
            //*X.
            //...
            ++yy;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //...
            //.X.
            //*..
            ++yy;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //...
            //.X.
            //.*.
            ++xx;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //.*.
            //.X.
            //...
            yy -= 2;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //..*
            //.X.
            //...
            ++xx;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //...
            //.X*
            //...
            ++yy;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }

            //...
            //.X.
            //..*
            ++yy;
            if(matrix[xx][yy].first && !matrix[xx][yy].second){
                if(!matrix[xx-1][yy].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy+1].first){
                    ++perimeter;
                }
                if(!matrix[xx][yy-1].first){
                    ++perimeter;
                }
                if(!matrix[xx+1][yy].first){
                    ++perimeter;
                }
                Q.push(make_pair(xx, yy));
                matrix[xx][yy].second = true;
            }
            //cout << cur_point.first << " " << cur_point.second << endl;
        }

        cout << perimeter << endl;

        cin >> rows >> columns >> y >> x;
    }
    return 0;
}
