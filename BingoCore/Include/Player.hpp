#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class Player
{

private:

    unsigned int Credits;

    /**
     * Bingo Cards this player is holding
     */
    std::vector<std::shared_ptr<Card>> Cards;

public:

    Player();

    /**
     * Credits the player has available
     *
     * @return unsigned int of credits
     */
    [[nodiscard]] unsigned int CreditsLeft();

    [[nodiscard]] bool TryRemoveCredits(unsigned int Value);

    /**
     * Adds the number of credits to the Player
     *
     * @param Value credits directly added
     */
    void AddCredits(unsigned int Value);

    /**
     * Converts all the credits to real money, and sets the credits to 0
     *
     * @return the money to emit
     */
    [[nodiscard]] unsigned int Collect();


    /**
     * The Bingo cards this player is holding
     *
     * @return
     */
    [[nodiscard]] std::vector<std::shared_ptr<Card>>& GetCards();

    [[deprecated]] void RerollCards();

};

