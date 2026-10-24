class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        string arriveq = arriveAlice > arriveBob ? arriveAlice : arriveBob;
        string leaveq = leaveAlice < leaveBob ? leaveAlice : leaveBob;
        if (leaveAlice < arriveBob)
            return 0;
        if (leaveBob < arriveAlice)
            return 0;
        int arrivedate = stoi(arriveq.substr(3, 2));
        int leavedate = stoi(leaveq.substr(3, 2));
        int arrivemonth = stoi(arriveq.substr(0, 2));
        int leavemonth = stoi(leaveq.substr(0, 2));
        vector<int> monthday = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (leavemonth == arrivemonth)
            return leavedate - arrivedate + 1;
        else {
            int days =
                ((monthday[arrivemonth - 1] - arrivedate) + (leavedate) + 1);
            for (int i = arrivemonth + 1; i < leavemonth; i++) {
                days += monthday[i - 1];
            }
            return days;
        }
    }
};