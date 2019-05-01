#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class JobNode {
    public:
        int data;
        bool completed; // visited node
        bool processing;
        vector< JobNode* > dependantJobs;

        JobNode(int value) {
            this->data = value;
            this->completed = false;
            this->processing = false;
        }
};

class JobGraph {
    public:
        vector< JobNode* > jobNodes;
        unordered_map<int, JobNode*> jobs;

        JobGraph(vector<int> jobs) {
            for(int job: jobs) {
                addNode(job);
            }
        }
        void addNode(int job) {
            jobs[job] = new JobNode(job);
            jobNodes.push_back(jobs[job]);
        }
        JobNode* getNode(int job) {
            return jobs[job];
        }
        void addDependency(int prerequisite, int job) {
            JobNode* currentJob = getNode(job);
            JobNode* prerequisiteJob = getNode(prerequisite);
            prerequisiteJob->dependantJobs.push_back(currentJob);
        }
        bool dfsUtil(JobNode* node, stack<int> &topologicalOrder) {
            if (node->completed) return false;
            if (node->processing) return true;
            node->processing = true;
            for(auto dependantJob: node->dependantJobs) {
                bool containsCycle = dfsUtil(dependantJob, topologicalOrder);
                if (containsCycle) return true;
            }
            node->completed = true;
            node->processing = false;
            topologicalOrder.push(node->data);
            return false;
        }
        vector<int> getTopologicalSort() {
            vector<int> sortedOrder;
            stack<int> topologicalOrder;
            for (auto jobNode : jobNodes) {
                bool containsCycle = dfsUtil(jobNode, topologicalOrder);
                if (containsCycle) return {};
            }
            while(!topologicalOrder.empty()) {
                sortedOrder.push_back(topologicalOrder.top());
                topologicalOrder.pop();
            }
            return sortedOrder;
        }
};


int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int num_of_jobs;
    cin >> num_of_jobs;
    vector<int> jobs;
    for(int i = 0; i < num_of_jobs; i++) {
        int job;
        cin >> job;
        jobs.push_back(job);
    }
    JobGraph graph = JobGraph(jobs);
    int num_of_dependencies;
    cin >> num_of_dependencies;
    for(int i = 0; i < num_of_dependencies; i++) {
        int prerequisite_job, job;
        cin >> prerequisite_job >> job;
        graph.addDependency(prerequisite_job, job);
    }
    vector<int> topologicalSort = graph.getTopologicalSort();
    cout << "The Ordering of Jobs should be as follows to avoid any conflicts using DFS: " << endl;
    for(int i = 0; i < topologicalSort.size(); i++) {
        cout << topologicalSort[i] << " ";
    }
    cout << endl;
    return 0;
}