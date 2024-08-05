#include <iostream>
#include <vector>
using namespace std;

struct Job {
    string jobCode;
    string startTime;
    int duration;
};

vector<Job> createJobList() {
    vector<Job> jobs;
    jobs.push_back({"J001", "08:00", 60});
    jobs.push_back({"J002", "09:00", 45});
    jobs.push_back({"J003", "10:00", 30});
    jobs.push_back({"J004", "11:00", 75});
    jobs.push_back({"J005", "12:00", 90});
    jobs.push_back({"J006", "13:00", 60});
    jobs.push_back({"J007", "14:00", 45});
    jobs.push_back({"J008", "15:00", 30});
    jobs.push_back({"J009", "16:00", 75});
    jobs.push_back({"J010", "17:00", 90});
    return jobs;
}

void displayJobsReverse(const vector<Job>& jobs, int index) {
    if (index < 0) {
        return;
    }

    cout << "Job Code: " << jobs[index].jobCode << endl;
    cout << "Start Time: " << jobs[index].startTime << endl;
    cout << "Duration: " << jobs[index].duration << " minutes" << endl;
    cout << endl;

    displayJobsReverse(jobs, index - 1);
}

void displayCombinations(const vector<Job>& jobs, vector<int>& combination, int start, int k) {
    if (k == 0) {
        for (int i : combination) {
            cout << jobs[i].jobCode << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= jobs.size() - k; ++i) {
        combination.push_back(i);
        displayCombinations(jobs, combination, i + 1, k - 1);
        combination.pop_back();
    }
}

int main() {
    vector<Job> jobs = createJobList();

    cout << "Jobs in reverse order:" << endl;
    displayJobsReverse(jobs, jobs.size() - 1);
    cout << endl;

    cout << "All combinations of 5 jobs:" << endl;
    vector<int> combination;
    displayCombinations(jobs, combination, 0, 5);

    return 0;
}