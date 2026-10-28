class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for (const auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        vector<string> itinerary;
        itinerary.reserve(tickets.size() + 1);

        vector<string> st;
        st.reserve(tickets.size() + 1);
        st.push_back("JFK");

        while (!st.empty()) {
            string airport = st.back();
            
            if (!adj[airport].empty()) {
                string next = adj[airport].top();
                adj[airport].pop();
                st.push_back(next);
            } else {
                itinerary.push_back(airport);
                st.pop_back();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
