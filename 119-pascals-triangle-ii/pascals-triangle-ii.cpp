
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex ==  0) {
            return {1};
        }

        if(rowIndex == 1) {
            return {1,1};
        }

        vector<int> previous = {1,1};

        int i = 2;
        while(i <= rowIndex) {
            vector<int>result = {1};
        
            for(int j = 0; j < previous.size()-1; j++) {
                result.push_back(previous[j] + previous[j+1]);
            }

            result.push_back(1);

            previous = result;
            i += 1;
        }
        /*
        for(int j = 0; j < previous.size(); j++) {
                cout<<previous[j]<<" ";
            }
            cout<<endl;
        */
        return previous;
    }
};