class MovieRentingSystem {
    typedef pair<int, int> P;
    unordered_map<int, set<P>> available; 
    unordered_map<int, unordered_map<int, int>> shopMovieToPrice;
    set<tuple<int, int, int>> rented; 
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry : entries){
            available[entry[1]].insert({entry[2], entry[0]});
            shopMovieToPrice[entry[0]][entry[1]] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;

        if(available.count(movie)){
            for(auto& [_, shop] : available[movie]){
                ans.push_back(shop);
                if(ans.size() == 5){
                    return ans;
                }
            }
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int& price = shopMovieToPrice[shop][movie];

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int& price = shopMovieToPrice[shop][movie];

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;

        for(auto& [_, shop, movie] : rented){
            ans.push_back({shop, movie});
            if(ans.size() == 5){
                return ans;
            }
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */