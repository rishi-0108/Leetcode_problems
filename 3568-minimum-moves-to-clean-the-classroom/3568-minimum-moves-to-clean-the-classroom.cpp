class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }
                if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

        // litter ID for each cell
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        /*
            best[r][c][mask] = maximum energy with which
            we have reached (r,c) having collected 'mask'.
        */
        int states = 1 << k;

        vector<int> best(m * n * states, -1);

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * states + mask);
        };

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, 0, energy});
        best[index(sr, sc, 0)] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, en] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Can't move with zero energy
                    if (en == 0)
                        continue;

                    int nen = en - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        nen = energy;
                    }

                    int idx = index(nr, nc, nmask);

                    // Already reached this state with >= energy
                    if (best[idx] >= nen)
                        continue;

                    best[idx] = nen;
                    q.push({nr, nc, nmask, nen});
                }
            }

            moves++;
        }

        return -1;
    }
};