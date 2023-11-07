/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Genesis Castillo
Date 11/03/23
Card.hpp defines the Card class and its member functions.
*/


#include "Card.hpp"





// Big Five and Constructor
        /**
         * Destructor
         * @post: Destroy the Card object
        */
        Card::~Card() {
            delete[] bitmap_;
            // std::cout << "Card objects are cleared" << std::endl;
        
        }
            
        /**
         * Copy Constructor
         * @post: Construct a new Card object
         * @param: const reference to a Card object
        */
        Card::Card(const Card& rhs) {
            
            //copying everying except the pointer 
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            drawn_ = rhs.drawn_;
            
            //allocation mem for new array 
            if (rhs.bitmap_ != nullptr) {
                bitmap_ = new int [80];
            for (int i =0; i < 80; i++) {
                bitmap_[i] = rhs.bitmap_[i];
            }
            }
            else {
                bitmap_ = nullptr;
            }
            
            
        }
        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& Card::operator=(const Card& rhs) {
            
            if (this != &rhs) {
                cardType_ = rhs.cardType_;
                instruction_ = rhs.instruction_;
                drawn_ = rhs.drawn_;

                delete[] bitmap_; // two object that are same type copy ob2 to 1 
                if (rhs.bitmap_ != nullptr){ //confirming there values in the array bitmap is pointing to array 
                    bitmap_ = new int [80];
                    for (int i =0; i < 80; i++) {
                bitmap_[i] = rhs.bitmap_[i];
            }
                }

                else  {  // rhs.bitmap_ == nullptr (assignment to say equal to each other)
                    bitmap_ = nullptr;
                }

            }

            return *this;  // this a reference is pointer to current Card object 
            
         
        }
        
        /**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
    Card::Card(Card&& rhs) {
        //lvalue into rvalue references in order to transfer and copy values 
        // because rvalues references are temp and deleted naturally 

    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    drawn_ = std::move(rhs.drawn_);
    bitmap_ = std::move(rhs.bitmap_);
    
}
        
        
        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& Card::operator=(Card&& rhs){
            
            std::swap( cardType_, rhs.cardType_);
            std::swap( instruction_, rhs.instruction_);
            std::swap( drawn_, rhs.drawn_);
            std::swap( bitmap_, rhs.bitmap_);
            
            return *this; 


        }
        
       
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card() {
            
            cardType_ = POINT_CARD; 
            instruction_ = "";
            bitmap_ = nullptr;
            drawn_ = false; 

        }

        /**
         * @return the string representation of the card type
         */
        std::string Card::getType() const{
            if (cardType_ == ACTION_CARD) {
                return "ACTION_CARD";
            }
            else if (cardType_ == POINT_CARD) {
                return "POINT_CARD";
            }
            else {
                return "Type of card does not exist";
            }  

        }
        /**
         * @post: set the card type
         * @param const reference to a CardType object
         */
        void Card::setType(const CardType& type) {
            cardType_ = type; 
        }

        /**
         * @return the string representation of the card instruction
        */
        const std::string& Card::getInstruction() const {
            return instruction_;
        }
        /**
         * @post: set the card instruction
         * @param: const reference to an instruction 
         */
        void Card::setInstruction(const std::string& instruction){
            instruction_ = instruction;
        }

        /**
         * @return the image data
         */
        const int* Card::getImageData() const{
            return bitmap_;
        }
        /**
         * @post: Set the image data
         * @param pointer to an array of integers
         */
        void Card::setImageData(int* data){ 
            bitmap_ = data;
        }

        /**
         * @return the drawn status of the card
        */
        bool Card::getDrawn() const{
            return drawn_;
        }
        /**
         * @post: set the drawn status of the card
         * 
         * @param: const reference to a boolean
         */
        void Card::setDrawn(const bool& drawn){
            drawn_ = drawn; 
        }

