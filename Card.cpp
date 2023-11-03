#include "Card.hpp"
// #include <iostream>



// Big Five and Constructor
        /**
         * Destructor
         * @post: Destroy the Card object
        */
        Card::~Card() {
            delete bitmap_;
            std::cout << "Card objects are cleared" << std::endl;
        
        }
            
        /**
         * Copy Constructor
         * @post: Construct a new Card object
         * @param: const reference to a Card object
        */
        Card::Card(const Card& rhs) {

            // cardType_ = rhs.cardType_;
            bitmap_ = new int {*rhs.bitmap_};
        }
        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& Card::operator=(const Card& rhs) {
            if ( this != &rhs ) 
                    *bitmap_ = *rhs.bitmap_;
            return *this;
    
        }
        
        /**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
        Card::Card(Card&& rhs){
            rhs.bitmap_ = nullptr;
        }
        
        
        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& Card::operator=(Card&& rhs){
            
            std::swap( bitmap_, rhs.bitmap_);
            return *this; 
        }
        
       
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card() {
            
            cardType_ = POINT_CARD; 
            std:: string instruction_ = "Default";
            bitmap_ = nullptr;
            drawn_ = false; 

        }

        /**
         * @return the string representation of the card type
         */
        std::string Card::getType() const{
            if (cardType_ == CardType::ACTION_CARD) {
                return "This is an Action Card";
            }
            else if (cardType_ == CardType::POINT_CARD) {
                return "This a Point Card";
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

