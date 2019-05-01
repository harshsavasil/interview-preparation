#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class JobNode {
    public:
        int data;
        vector<int> dependents;
        int numOfPrerequisites;

        JobNode(int value) {
            this->data = value;
            this->dependents = {};
            this->numOfPrerequisites = 0;
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
            this->jobs[job] = new JobNode(job);
            jobNodes.push_back(this->jobs[job]);
        }
        JobNode* getNode(int job) {
            return jobs[job];
        }
        void addDependency(int prerequisite, int job) {
            JobNode* currentJob = getNode(job);
            JobNode* prerequisiteJob = getNode(prerequisite);
            prerequisiteJob->dependents.push_back(job);
            currentJob->numOfPrerequisites += 1;
        }
        void removeDependencies(JobNode* currentJob, queue<JobNode*> &processingJobs) {
            while (!currentJob->dependents.empty()) {
                int dependent = currentJob->dependents.back();
                JobNode* dependentJob = getNode(dependent);
                dependentJob->numOfPrerequisites -= 1;
                if (dependentJob->numOfPrerequisites == 0) {
                    processingJobs.push(dependentJob);
                }
                currentJob->dependents.pop_back();
            }
        }
        vector<int> getTopologicalSort() {
            vector<int> sortedOrder;
            queue<JobNode*> processingJobs;
            for (auto jobNode : this->jobNodes) {
                if (jobNode->numOfPrerequisites == 0) {
                    processingJobs.push(jobNode);
                }
            }
            while(!processingJobs.empty()) {
                JobNode* processed = processingJobs.front();
                processingJobs.pop();
                sortedOrder.push_back(processed->data);
                removeDependencies(processed, processingJobs);
            }
            // Cyclic
            if (sortedOrder.size() != this->jobNodes.size()) return {};
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
    cout << "The Ordering of Jobs should be as follows to avoid any conflicts using Kahn's algorithm: " << endl;
    for(int i = 0; i < topologicalSort.size(); i++) {
        cout << topologicalSort[i] << " ";
    }
    cout << endl;
    return 0;
}