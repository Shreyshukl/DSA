class StockPrice {
public:
    unordered_map<int,int>timestapToprice;
    multiset<int>prices;
    int latestTimeStamp = 0; 
    StockPrice() {
        timestapToprice.clear();
        prices.clear();
        latestTimeStamp = 0;
    }
    
    void update(int timestamp, int price) {
       if(timestapToprice.count(timestamp))
       {
        int oldPrice = timestapToprice[timestamp];
        prices.erase(prices.find(oldPrice));
       }
       timestapToprice[timestamp]=price;
       prices.insert(price);
       latestTimeStamp = max(latestTimeStamp,timestamp);
    }
    
    int current() {
        return timestapToprice[latestTimeStamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

