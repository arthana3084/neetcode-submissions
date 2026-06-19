class Solution {
public:
    bool dfscourse(vector<vector<int>>& prereq,vector<int>& visited,int course,vector<int>& pathvisited)
    {
        visited[course]=1;
        pathvisited[course]=1;
        for(auto neighbour:prereq[course])
        {
            if(!visited[neighbour])
            {
                if(dfscourse(prereq,visited,neighbour,pathvisited))
                {
                    return true;
                }
            }
            else if(pathvisited[neighbour])
            {
                return true;
            }
        }
        pathvisited[course]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq(numCourses);
        vector<int> visited(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        for(auto courses: prerequisites)
        {
            int u=courses[0];
            int v=courses[1];
            prereq[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfscourse(prereq,visited,i,pathvisited))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
