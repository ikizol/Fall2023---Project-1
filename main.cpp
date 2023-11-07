#include "Card.hpp"
// #include "ActionCard.hpp"
#include "PointCard.hpp"


int main() {
    // // Creating a card object using the default constructor
    // Card myCard; // when testing for action or pointcard just change them 
    
    // // Setting card details
    // myCard.setType(POINT_CARD);
    // myCard.setInstruction("Sample Instruction");
    
    
    // int* sampleData = new int [80]; // Sample image data
    // for (int i = 0; i < 80; i++){ 
    //     sampleData[i] = i;
    // }
    // actionCard.setImageData(sampleData);
    
    // std::cout << "Card Type: " << myCard.getType() << std::endl;
    // std::cout << "Instruction: " << myCard.getInstruction() << std::endl;
    // std::cout << "Drawn Status: " << myCard.getDrawn() << std::endl;
    
    // // Creating a second card object using the copy constructor
    // Card anotherCard(myCard);
    
    // // Updating details for the second card
    // anotherCard.setDrawn(true);
    
    // std::cout << "\nSecond Card Details:\n";
    // std::cout << "Card Type: " << anotherCard.getType() << std::endl;
    // std::cout << "Instruction: " << anotherCard.getInstruction() << std::endl;
    // std::cout << "Drawn Status: " << anotherCard.getDrawn() << std::endl;
    
    // // Using move assignment operator
    // Card thirdCard;
    // thirdCard = std::move(anotherCard);
    
    // std::cout << "\nThird Card Details (after moving):\n";
    // std::cout << "Card Type: " << thirdCard.getType() << std::endl;
    // std::cout << "Instruction: " << thirdCard.getInstruction() << std::endl;
    // std::cout << "Drawn Status: " << thirdCard.getDrawn() << std::endl;


    // ****** THIS IS TESTING FOR ACTIONCARD / POINTCARD ***** 

// Create an ActionCard object
    PointCard pointCard;

    // // Setting up a sample card
    // pointCard.setType(POINT_CARD);
    pointCard.setInstruction("99");
    pointCard.setDrawn(true);
    
    // Check if the card is playable
    bool isCardPlayable = pointCard.isPlayable();
    if (isCardPlayable) {
        std::cout << "Card is playable!" << std::endl;
    } else {
        std::cout << "Card is not playable." << std::endl;
    }

    int* sampleData = new int [80]; // Sample image data
    for (int i = 0; i < 80; i++){ 
        sampleData[i] = i;
    }
    pointCard.setImageData(sampleData);

     // Print the details of the ActionCard
    pointCard.Print();

    return 0;
}