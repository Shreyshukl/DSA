class Solution {
public:
    int n;
    pair<int,int>getCoordinates(int num)
    {
        int Rt = (num-1)/n;
        int Rb = (n-1)-Rt;

        int col = (num-1)%n;
        //right to left
        if(n%2==0&&Rb%2==0 || n%2==1&&Rb%2==1) //dono odd ya dono even
        {
            col = (n-1)-col;
        }
        return make_pair(Rb,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
         n = board.size();
        queue<int>q;
        q.push(1);
        int steps = 0;
        vector<vector<bool>>visited(n , vector<bool>(n,false));
        visited[n-1][0] = true;
        //bfs
        while(!q.empty())
        {
            int N = q.size();

            while(N--)
            {
                int x = q.front();
                q.pop();
                 if(x==n*n)
                {
                    return steps;
                }

                for(int k = 1 ; k<=6 ; k++)
                {
                    int val = x+k;
                    if(val>n*n)
                    {
                        break;
                    }
                     pair<int,int>coord = getCoordinates(val);
                        int row = coord.first;
                        int col = coord.second;
                   
                    if(visited[row][col]==false)
                    {   
                        if(board[row][col]!=-1)
                        {
                            q.push(board[row][col]);
                        }
                        else
                        {
                           q.push(val);
                        }
                        visited[row][col]=true;  
                    }
                }
            } 
            steps++;
        }
        return -1;
    }
};
