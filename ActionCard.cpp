#include "ActionCard.hpp"



/**
         * @post: Construct a new Action Card object
        */
        ActionCard::ActionCard() : Card(){
        //do this for Point Card 
        }

        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
         bool ActionCard::isPlayable() { 
            if (getDrawn() == true) { 
                
            
            std::string drawPlayCards = "[A-Z ]+[ 0-9]+[A-Z]+\\([A-Z]\\)"; //regex instruction for draw and play 
            std::string reverseSwapCards = "[A-Z ]+"; 

            std::regex DrawPlay(drawPlayCards);
            std::regex ReverseSwap(reverseSwapCards);
            
            if (regex_match(getInstruction(), DrawPlay)) {
                return true;
            }

            else if (regex_match(getInstruction(), ReverseSwap)) {
                return true;
            }

            else {
                return false;
            }
            }
                
            return false;
            
        }

        
        /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void ActionCard::Print() const {
            std::cout << "Card Type: " << getType() << std::endl;
            std::cout << "Instruction: " << getInstruction() << std::endl;
            std::cout << "Card: "<< std::endl;
            if (getImageData() != nullptr){
                for (int i =0; i < 80; i++) {
                    std::cout << getImageData()[i];
                }
                std::cout << std::endl; //formatting (left to right)

            }
            else { 
               std::cout <<"No image data"<< std::endl;
            }
    
        }















//if (getDrawn() == true) { 
//need if staements for each instruction
//look up regex match 
//what do you do for parts of sentence that do not change
//how does regex handle any valid num greater or equal to 0 

//  if (getDrawn() == true) { 


//             }

//             else {
//                 return false;
//             }