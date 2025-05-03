class Solution {
    public:
        vector<double> convertTemperature(double celsius) {
           vector<double> out = {0, 0}; 
           out[0] = celsius + 273.15;
           out[1] = celsius * 1.80 + 32.00;
           return out;
        }
    };