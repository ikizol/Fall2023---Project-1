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
        Player::Player() {
            score_ = 0;
            opponent_ = nullptr;
        }

        /**
         * @post: Destroy the Player object
         */
        Player::~Player(){}

        
        const Hand& Player::getHand() const {
                return hand_;
        }


        
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
        void Player::play(ActionCard&& card) {
            std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;

            std::string card_instruct = card.getInstruction();
            
            
            if (card_instruct == "REVERSE HAND"){
                hand_.Reverse();
            }

            else if (card_instruct == "SWAP HAND WITH OPPONENT") {
                    std::swap(hand_, opponent_->hand_); //this is a fucntion within player function
            }

            else if (card_instruct.find("DRAW ") == 0){ //if it finds the word in the instruction then it will return 0
                    int num = std::stoi(card_instruct.substr(5, card_instruct.find(" CARD"))); //5 is the 5th character in the instruction 
                    for (int i = 0; i < num; i++) {
                    drawPointCard();
                }
             }
        

            else if (card_instruct.find("PLAY ") == 0) {
                 int num = std::stoi(card_instruct.substr(5, card_instruct.find(" CARD")));
                  for  (int i = 0; i < num; i++) {
                    playPointCard();
                }
            }

        }



        /**
         * @post: Draw a point card and place it in the player's hand
         */
        void Player::drawPointCard(){
           

           if (pointdeck_ != nullptr && !pointdeck_->IsEmpty()) {
                
                PointCard pointcard = pointdeck_ -> Draw(); 
                hand_.addCard(std::move(pointcard));

           }
            
        }

        

        /**
         * @post: Play a point card from the player's hand and update the player's score
         */
        void Player::playPointCard(){
        
            if (!hand_.isEmpty()) {
                
                int playerPoint_ = hand_.PlayCard();
                score_ += playerPoint_;
            }

        }

    /**
         * @post: Set the opponent of the player
         * @param a pointer to a Player opponent 
         */
        void Player::setOpponent(Player* opponent){
                opponent_ = opponent; 
        }


        /**
         * @return: a pointer to the player's opponent
         */
        Player* Player::getOpponent(){
            return opponent_;

        }


        /**
         * @post: set the action deck of the player 
         * @param: A pointer to a deck holding Action cards 
         */
        void Player::setActionDeck(Deck<ActionCard>* actiondeck){
                actiondeck_ = actiondeck;
        }


        /**
         * @return a pointer to the player's action deck
         */
        Deck<ActionCard>* Player::getActionDeck(){
            return actiondeck_;
        }


        /**
         * @post: set the point deck of the player
         * @param: A pointer to a deck holding Point cards
         */
        void Player::setPointDeck(Deck<PointCard>* pointdeck){
                pointdeck_ = pointdeck;
        }


        /**
         * @return: a pointer to the player's point deck
         */
        Deck<PointCard>* Player::getPointDeck(){
            return pointdeck_;

        }
