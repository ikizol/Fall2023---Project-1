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
            cards_ = other.cards_;
            
        }
        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
        Hand& Hand::operator=(const Hand& other){

            if(this != &other) {
                cards_ = other.cards_;
            }

            return *this;
        }
        /**
         * Move Constructor
         * @param: other Hand object
         */
        Hand::Hand(Hand&& other){
            cards_ = std::move(other.cards_);

        }
        /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
        Hand& Hand::operator=(Hand&& other){    
            std::swap(cards_ ,other.cards_);
            return *this;
        }

        /**
         * @return Hand
         */
        const std::deque<PointCard>& Hand::getCards() const{
                return cards_;

        }
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void Hand::addCard(PointCard&& card){
            card.setDrawn(true);
            cards_.push_back(std::move(card));
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
            
          std::reverse(cards_.begin(), cards_.end());

           }

        
        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int Hand::PlayCard(){
        
         try {
                
            PointCard card = cards_.front();
            cards_.pop_front();
                
                if(isEmpty() || !card.isPlayable()) {
                throw std::runtime_error("Invalid Arguement"); 
                cards_.pop_front();   
            }

            else {
                int points_ = std::stoi(card.getInstruction());
                return points_;
            } 
        } catch (const std::exception &error_ ){ //catching an error 

            std::cerr << "ERROR!" << error_.what() <<std::endl;

            }

        }
    
            
            
            
            
            
            
            
            
    

        }
