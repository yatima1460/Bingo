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
    [[nodiscard]] unsigned int CreditsLeft() const;

    /**
     * Tries to remove the credits from the player, otherwise returns false
     * @param Value
     * @return true if removed, false if not enough
     */
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
    [[nodiscard]] const std::vector<std::shared_ptr<Card>>& GetCards() const;

    /**
     * Gets new Bingo cards, discarding the previous ones
     */
    void ChangeCards(unsigned int n, unsigned int width, unsigned int height, unsigned int maxN);

};

