

#include <vector>

class Drum
{
    std::vector<int> balls;
    

public:
    
    Drum(int numberOfBalls);

    /**
     *  Extracts a ball from the drum 
    */
    int Extract();

    /**
     * Total number of balls
     * @return
     */
    int Total();
};