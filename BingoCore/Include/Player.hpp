#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class Player
{

    unsigned int credits;

    /**
     * Bingo Cards this player is holding
     */
    std::vector<std::shared_ptr<Card>> cards;

public:

    Player();

    /**
     * Credits the player has available
     *
     * @return unsigned int of credits
     */
    [[nodiscard]] unsigned int creditsLeft() const;

    /**
     * Tries to remove the credits from the player, otherwise returns false
     *
     * @param value
     * @return true if removed, false if not enough
     */
    [[nodiscard]] bool pay(unsigned int value);

    /**
     * Adds the number of credits to the Player
     *
     * @param value credits directly added
     */
    void addCredits(unsigned int value);

    /**
     * Converts all the credits to real money, and sets the credits to 0
     *
     * @return the money to emit
     */
    [[nodiscard]] unsigned int collect();

    /**
     * The Bingo cards this player is holding
     *
     * @return
     */
    [[nodiscard]] const std::vector<std::shared_ptr<Card>>& getCards() const;

    /**
     * Gets new Bingo cards, discarding the previous ones
     */
    void changeCards();

};

