/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Genesis Castillo
Date 11/05/23
PointCard.hpp defines the PointCard class and inherits from the Card Class.
*/



#include "PointCard.hpp"

/**
         * @post: Construct a new Point Card object
         */
        PointCard::PointCard() :Card(){
            setType(POINT_CARD);
            setInstruction("");
            setDrawn(false);
            setImageData(nullptr);
        }


        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
        bool PointCard::isPlayable(){
            if (getDrawn() == true) {

                std::string instruction = getInstruction();
                int string_int = std::stoi(instruction);
                
                if (1 <= string_int || string_int <= 99) {
                    
                    return true;
                }
            else 
                return false;
            

            }

            return false;
        }


        /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void PointCard::Print() const {

            std::cout << "Type: " << getType() << std::endl;
            std::cout << "Points: " << getInstruction() << std::endl;
            std::cout << "Card: "<< std::endl;
            if (getImageData() != nullptr){
                for (int i =0; i < 79; i++) {
                    std::cout << getImageData()[i];
                }
                std::cout << std::endl; //formatting (left to right)

            }
            else { 
               std::cout <<"No image data"<< std::endl;
            }
        }
