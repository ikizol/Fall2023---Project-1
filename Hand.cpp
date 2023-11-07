/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Genesis Castillo
Date 11/06/23
Hand.cpp Defines the Hand class.
*/



#include "Hand.hpp"

// Big Five and constructor
        /**
         * @post: Construct a new Hand object
         */
        Hand::Hand(){
            cards_;
        }
        /**
         * @post: Destroy the Hand object
         */
        Hand::~Hand(){
            cards_.clear();

        }
        /**
         * Copy Constructor
         * @param: other Hand object
         */
        Hand::Hand(const Hand& other){

        }
        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
        Hand& Hand::operator=(const Hand& other){

        }
        /**
         * Move Constructor
         * @param: other Hand object
         */
        Hand::Hand(Hand&& other){

        }
        /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
        Hand& Hand::operator=(Hand&& other){

        }

        /**
         * @return Hand
         */
        const std::deque<PointCard>& Hand::getCards() const{

        }
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void Hand::addCard(PointCard&& card){

        }

        /**
         * @return true if hand is empty, false otherwise
         */
        bool Hand::isEmpty() const{
            if(cards_.empty()) {
                return true;
            }
            else 
                return false;

        }

        /**
         * @post: Reverse the hand
         */
        void Hand::Reverse(){
            
           if (cards_.empty()) {
                return;

           }

           else {
                /* Use for loop to traverse from from last element 
                 *then push this order into new queue
                 *then tranfer this info back into orginal deque 
                 *
                **/
                
                for (int i = 0; i < cards_.size(); i--) {
                    cards_.pop_back(i);
                    std::deque<PointCard> PointQueue;
                    PointQueue.push_front(i);
                }
                
                
                PointCard element = cards_.front();
                




           }

    }




        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int Hand::PlayCard(){

        }
