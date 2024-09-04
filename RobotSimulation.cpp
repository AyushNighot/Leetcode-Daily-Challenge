class Solution {
private:
    string solve(string dir, int val){
        if(val == -1){ // turn right
            if(dir == "+y"){ dir = "+x"; }
            else if(dir == "+x"){ dir = "-y"; }
            else if(dir == "-y"){ dir = "-x"; }
            else if(dir == "-x"){ dir = "+y"; }
        } else if(val == -2){ // turn left
            if(dir == "+y"){ dir = "-x"; }
            else if(dir == "-x"){ dir = "-y"; }
            else if(dir == "-y"){ dir = "+x"; }
            else if(dir == "+x"){ dir = "+y"; }
        }

        return dir;
    }

public:
    int robotSim(vector<int>& c, vector<vector<int>>& obs) {
        int mx = 0;
        int x = 0, y = 0;
        string dir = "+y"; // initial direction

        set<pair<int, int>> um;
        for(auto &val : obs){
            um.insert({val[0], val[1]});
        }

        for(auto &val : c){
            if(val == -1 || val == -2){
                dir = solve(dir, val);
                continue;
            }

            if(dir == "+y"){
                for(int i = 0; i < val; i++){
                    if(um.find({x, y + 1}) != um.end()){
                        break;
                    }
                    y++;
                }
            } else if(dir == "-y"){
                for(int i = 0; i < val; i++){
                    if(um.find({x, y - 1}) != um.end()){
                        break;
                    }
                    y--;
                }
            } else if(dir == "+x"){
                for(int i = 0; i < val; i++){
                    if(um.find({x + 1, y}) != um.end()){
                        break;
                    }
                    x++;
                }
            } else if(dir == "-x"){
                for(int i = 0; i < val; i++){
                    if(um.find({x - 1, y}) != um.end()){
                        break;
                    }
                    x--;
                }
            }
            mx = max(mx, x*x + y*y);
        }

        return mx;
    }
};
