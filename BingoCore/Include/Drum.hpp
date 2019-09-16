

#include <vector>

class Drum
{
    std::vector<int> balls;
    

public:
    
    Drum(int numberOfBalls);

    /**
     *  Extracts N balls from the drum
    */
    std::vector<int> Extract(int N);

    /**
     * Total number of balls
     * @return
     */
    int Total();
};