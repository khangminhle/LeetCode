class Solution {
public:

    struct Process {
        int id;
        string status;
        int timestamp;

        Process(int i, string s, int t) : id(i), status(s), timestamp(t) {}
    };

    Process extractInfo(string str) {

        // Tìm vị trí 2 dấu hai chấm
        size_t firstColon = str.find(':');
        size_t lastColon = str.find_last_of(':');

        // Cắt chuỗi và chuyển đổi
        int id = stoi(str.substr(0, firstColon));
        string status = str.substr(firstColon + 1, lastColon - firstColon - 1);
        int timestamp = stoi(str.substr(lastColon + 1));


        return Process(id, status, timestamp);
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int m = logs.size();
        vector<int> times(n);
        vector<Process> pStack;

        for(int i = 0; i < m; i++) {
            Process p = extractInfo(logs[i]);
           
            if(p.status == "start") {
                if(pStack.size() > 0) {
                    Process previousP = pStack.back();
                    times[previousP.id] += p.timestamp - previousP.timestamp;
                }
                pStack.push_back(p);
            } else {
                Process newp = pStack.back();
                pStack.pop_back();
            
                int timeRange = p.timestamp - newp.timestamp + 1;
                times[p.id] += timeRange;
                

                if(pStack.size() == 0) {
                    continue;
                }

                Process previousP = pStack.back();
                pStack.pop_back();
                previousP.timestamp = p.timestamp + 1;
                pStack.push_back(previousP);
            }
        }
        return {times};
    }
};
