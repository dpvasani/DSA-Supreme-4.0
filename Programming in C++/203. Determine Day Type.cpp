class Solution {
public:
    string determineDayType(int day) {
        if (day == 1 || day == 2 || day == 3 || day == 4 || day == 5) {
            return "Weekday";
        } else if (day == 6 || day == 7) {
            return "Weekend";
        } else {
            return "Invalid day";
        }
    }
};