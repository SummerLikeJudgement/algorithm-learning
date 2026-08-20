// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：true
// 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
// 示例 2：

// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 

// 提示：

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// prerequisites[i] 中的所有课程对 互不相同


/// 【拓扑排序】注意图的存储和入度操作
const int N = 2005;
const int M = 5005;

class Solution {
public:
    int h[N];
    int ne[M];
    int e[M];
    int idx = 0;
    int d[N];// 每个点的入度

    // 增加边b->a
    void add(int b, int a)
    {
        e[idx] = a;
        ne[idx] = h[b];
        h[b] = idx;
        idx++;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // init
        memset(h, -1, sizeof h);
        for(int i=0 ; i<prerequisites.size() ; i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            add(b, a);
            // 更新入度
            d[a]++;
        }
        // 队列
        int tt = -1;
        int hh = 0;
        int q[N];
        // 拓扑排序
        for(int i=0 ; i<numCourses ; i++)
            if(!d[i])
                q[++tt] = i;
        while(tt>=hh)
        {
            int t = q[hh++];
            for(int i=h[t] ; i!=-1 ; i=ne[i])
            {
                int j = e[i];
                d[j]--;
                if(!d[j])
                    q[++tt] = j;
            }
        }
        if(tt == numCourses-1)
            return true;
        else
            return false;

    }
};