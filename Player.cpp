/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Genesis Castillo 
Date 11/07/23
Player.cpp implements the Player class.
*/

#include "Player.hpp"

/**
         * @post: Construct a new Player object
         */
        Player::Player(){
            
            hand_;
            score_ = 0;
            opponent_ = nullptr;
            actiondeck_ = nullptr;
            pointdeck_ = nullptr;

        }

        /**
         * @post: Destroy the Player object
         */
        Player::~Player(){
            if (actiondeck_ != nullptr){
                delete actiondeck_;
            }

           if (pointdeck_ != nullptr){
                delete actiondeck_;
        }

        /**
         * @return the player's hand
         */
        const Hand& Player::getHand() const {
                return hand_;

        }

        /**
         * @post: Set the player's hand
         * @param const reference to a hand object
         */
        void Player::setHand(const Hand& hand){
            hand_ = hand; 

        }

        /**
         * @return the Player's current score
         */
        int Player::getScore() const{
            return score_;
        }

        /**
         * @post: Set the player's score
         * @param: score 
         */
        void Player::setScore(const int& score){
            score_ = score;

        }


        /**
         * @post: Play a given action card
         * @param: an Actioncard object
         * Begin the function by reporting the instruction of the card:
         * PLAYING ACTION CARD: [instruction]
         */
        void Player::play(ActionCard&& card){

            std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
        }


        /**
         * @post: Draw a point card and place it in the player's hand
         */
        void Player::drawPointCard(){
            PointCard pointcard = pointdeck_.Draw(); 
            Hand player_hand = pointcard.addCard();
        }


        /**
         * @post: Play a point card from the player's hand and update the player's score
         */
        void Player::playPointCard(){
            PointCard pointcard = pointdeck_.PlayCard();


        }


        /**
         * @post: Set the opponent of the player
         * @param a pointer to a Player opponent 
         */
        void Player::setOpponent(Player* opponent){

        }


        /**
         * @return: a pointer to the player's opponent
         */
        Player* Player::getOpponent(){

        }


        /**
         * @post: set the action deck of the player 
         * @param: A pointer to a deck holding Action cards 
         */
        void Player::setActionDeck(Deck<ActionCard>* actiondeck){

        }


        /**
         * @return a pointer to the player's action deck
         */
        Deck<ActionCard>* Player::getActionDeck(){

        }


        /**
         * @post: set the point deck of the player
         * @param: A pointer to a deck holding Point cards
         */
        void Player::setPointDeck(Deck<PointCard>* pointdeck){

        }


        /**
         * @return: a pointer to the player's point deck
         */
        Deck<PointCard>* Player::getPointDeck(){

        }