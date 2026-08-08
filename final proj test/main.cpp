//
//  main.cpp
//  final proj test
//
//  Created by Ricardo Acosta on 4/27/26.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Deck.hpp"
#include "Hand.hpp"
using namespace std;
void StartGame(Deck*& d, Hand*& mh, Hand*& dh);
int main() {
    
    
    // create the window
    float windowWidth = 800.f;
    float windowHeight = 700.f;
    sf::RenderWindow window(sf::VideoMode({800, 700}), "My window");
    window.setFramerateLimit(30);
    
    sf::Texture texture("Sprites/clubs_2.png");
    
    //font
    sf::Font font;
    if(!font.openFromFile("Fonts/GalaferaMedium.ttf"))
    {
        std::cerr << "Error loading font.\n";
            return -1;
    }
    
    
    
    sf::Text dealerText(font, "Dealers hand");
    dealerText.setPosition({windowWidth / 4 - (dealerText.getLocalBounds().size.x) / 2, 25.f});
    
    sf::Text PlayerText(font, "Your hand");
    PlayerText.setPosition({
        windowWidth / 4 - (PlayerText.getLocalBounds().size.x) / 2,
        windowHeight / 2 + 10.f
    });
    
    sf::Text PlayerScore(font, "N/a");
    PlayerScore.setPosition({
        windowWidth / 4 - (PlayerScore.getLocalBounds().size.x) / 2 + 120.f,
        windowHeight / 2 + 10.f
    });
    
    sf::Text DealerScore(font, "N/a");
    DealerScore.setPosition({windowWidth / 4 - (dealerText.getLocalBounds().size.x) / 2 + 220.f, 25.f});
    
    sf::Text won(font, "Won:");
    won.setPosition({
        windowWidth / 4 - (won.getLocalBounds().size.x) / 2 + 200.f,
        windowHeight / 2 + 10.f
    });
    
    sf::Text wonScore(font, "?");
    wonScore.setPosition({
        windowWidth / 4 - (wonScore.getLocalBounds().size.x) / 2 + 260.f,
        windowHeight / 2 + 10.f
    });
    
    sf::Text lost(font, "Lost:");
    lost.setPosition({
        windowWidth / 4 - (lost.getLocalBounds().size.x) / 2 + 340.f,
        windowHeight / 2 + 10.f
    });
    
    sf::Text lostScore(font, "?");
    lostScore.setPosition({
        windowWidth / 4 - (lostScore.getLocalBounds().size.x) / 2 + 400.f,
        windowHeight / 2 + 10.f
    });


    
    Deck* myDeckptr = NULL;
    Hand* myHandptr = NULL;
    Hand* DeealersHandPtr = NULL;
    int cardIndex = 47;
    int hitClicked = 0;
    bool gameOver = false;
    int Winning = 0;
    int losing = 0;
    
    StartGame(myDeckptr, myHandptr, DeealersHandPtr);
    
    //sprites
    
    string backImage = "Sprites/back.png";
    string placeholder = "Sprites/placeholder.png";
    
   
    sf::Texture dt1;
    (void)dt1.loadFromFile(DeealersHandPtr->getCardPathname(0));
    
    sf::Sprite ds1(dt1);
    ds1.scale(sf::Vector2f(0.35f, 0.35f));
    ds1.setPosition({
        windowWidth / 4 - (ds1.getLocalBounds().size.x * 0.35f) / 2 + 5.f,
        windowHeight / 2 - (ds1.getLocalBounds().size.y * 0.35f) / 2 - 150.f
    });
    
    sf::Texture dt2;
    (void)dt2.loadFromFile(backImage);
    
    sf::Sprite ds2(dt2);
    ds2.scale(sf::Vector2f(0.35f, 0.35f));
    ds2.setPosition({
        windowWidth / 4 - (ds2.getLocalBounds().size.x * 0.35f) / 2 + 5.f + 40.f,
        windowHeight / 2 - (ds2.getLocalBounds().size.y * 0.35f) / 2 - 150.f
    });
    
    sf::Texture dt3;
    (void)dt2.loadFromFile(backImage);
    
    sf::Sprite ds3(dt3);
    ds3.scale(sf::Vector2f(0.35f, 0.35f));
    ds3.setPosition({
        windowWidth / 4 - (ds3.getLocalBounds().size.x * 0.35f) / 2 + 5.f + 80.f,
        windowHeight / 2 - (ds3.getLocalBounds().size.y * 0.35f) / 2 - 150.f
    });

    
    
    sf::Texture pt1;
    (void)pt1.loadFromFile(myHandptr->getCardPathname(0));
    
    sf::Sprite ps1(pt1);
    ps1.scale(sf::Vector2f(0.35f, 0.35f));
    ps1.setPosition({
        windowWidth / 4 - (ps1.getLocalBounds().size.x * 0.35f) / 2 + 5.f,
        windowHeight / 2 - (ps1.getLocalBounds().size.y * 0.35f) / 2 + 190.f
    });
    
    sf::Texture pt2;
    (void)pt2.loadFromFile(myHandptr->getCardPathname(1));
    
    sf::Sprite ps2(pt2);
    ps2.scale(sf::Vector2f(0.35f, 0.35f));
    ps2.setPosition({
        windowWidth / 4 - (ps2.getLocalBounds().size.x * 0.35f) / 2 + 40.f,
        windowHeight / 2 - (ps2.getLocalBounds().size.y * 0.35f) / 2 + 190.f
    });
    
    sf::Texture pt3;
    (void)pt3.loadFromFile(placeholder);
    
    sf::Sprite ps3(pt3);
    ps3.scale(sf::Vector2f(0.35f, 0.35f));
    ps3.setPosition({
        windowWidth / 4 - (ps2.getLocalBounds().size.x * 0.35f) / 2 + 80.f,
        windowHeight / 2 - (ps3.getLocalBounds().size.y * 0.35f) / 2 + 190.f
    });
    
    sf::Texture pt4;
    (void)pt4.loadFromFile(placeholder);
    
    sf::Sprite ps4(pt4);
    ps4.scale(sf::Vector2f(0.35f, 0.35f));
    ps4.setPosition({
        windowWidth / 4 - (ps2.getLocalBounds().size.x * 0.35f) / 2 + 120.f,
        windowHeight / 2 - (ps3.getLocalBounds().size.y * 0.35f) / 2 + 190.f
    });
    
    sf::Texture pt5;
    (void)pt5.loadFromFile(placeholder);
    
    sf::Sprite ps5(pt5);
    ps5.scale(sf::Vector2f(0.35f, 0.35f));
    ps5.setPosition({
        windowWidth / 4 - (ps5.getLocalBounds().size.x * 0.35f) / 2 + 160.f,
        windowHeight / 2 - (ps5.getLocalBounds().size.y * 0.35f) / 2 + 190.f
    });
    
   
    
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            PlayerScore.setString(to_string(myHandptr->GetHandValue()));
            DealerScore.setString(to_string(DeealersHandPtr->GetHandValueIndex(0)));
            wonScore.setString(to_string(Winning));
            lostScore.setString(to_string(losing));
            
            if (event->is<sf::Event::Closed>())
                window.close();
            
            if (const auto* keyPress = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPress->code)
                {
                    case sf::Keyboard::Key::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Key::Num1:
                        //hit
                        cout << "HIT" << endl;
                        myHandptr->AddCard(myDeckptr->dealCard());
                        hitClicked++;
                        if (hitClicked == 1)
                        {
                            (void)pt3.loadFromFile(myHandptr->getCardPathname(2));
                        }
                        else if (hitClicked == 2)
                        {
                            (void)pt4.loadFromFile(myHandptr->getCardPathname(3));
                        }
                        else if (hitClicked == 3)
                        {
                            (void)pt5.loadFromFile(myHandptr->getCardPathname(4));
                        }
                        
                        if (myHandptr->GetHandValue() > 21)
                        {
                            cout << "u lose" << endl;
                            cout << myHandptr->GetHandValue();
                            losing++;
                            gameOver = true;
                        }
                        else if (myHandptr->GetHandValue() == 21)
                        {
                            while (DeealersHandPtr->GetHandValue() < 17)
                            {
                                cout << "dealer adds card" << endl;
                                *DeealersHandPtr += myDeckptr->dealCard();
                                if(DeealersHandPtr->getHandSize() == 3)
                                {
                                    (void)dt3.loadFromFile(DeealersHandPtr->getCardPathname(2));
                                }
                                
                            }
                            
                            if(myHandptr->GetHandValue() != DeealersHandPtr->GetHandValue())
                            {
                                cout <<" u win blackjack" << endl;
                                Winning++;
                            }
                            else
                            {
                                cout << "push on blackjack" << endl;
                            }
                            
                            gameOver = true;
                        }
                            
                        
                        cardIndex--;
                        break;
                    case sf::Keyboard::Key::Num2:
                        //stand
                        cout << "stand" << endl;
                        //runs until 17+
                        
                        DealerScore.setString(to_string(DeealersHandPtr->GetHandValue()));
                        
                        while (DeealersHandPtr->GetHandValue() < 17)
                        {
                            cout << "dealer adds card" << endl;
                            *DeealersHandPtr += myDeckptr->dealCard();
                            if(DeealersHandPtr->getHandSize() == 3)
                            {
                                (void)dt3.loadFromFile(DeealersHandPtr->getCardPathname(2));
                            }
                            
                        }
                        
                        // condition for dealer
                        if (DeealersHandPtr->GetHandValue() > 21)
                        {
                            cout << "Dealer Busts you win" << endl;
                            Winning++;
                            gameOver= true;
                        }
                        else if (DeealersHandPtr->GetHandValue() > myHandptr->GetHandValue())
                        {
                            cout << "You lose dealer wins" << endl;
                            losing++;

                            gameOver = true;
                        }
                        else if (myHandptr->GetHandValue() > DeealersHandPtr->GetHandValue())
                        {
                            cout << "you win" << endl;
                            Winning++;
                            gameOver = true;
                        }
                        else
                        {
                            cout << "Push tie" << endl;
                            gameOver = true;
                        }

                        break;
                    case sf::Keyboard::Key::Num3:
                        //double
                        cout << "doub" << endl;
                        break;
                    case sf::Keyboard::Key::Num4:
                        //split
                        cout << "split" << endl;
                        break;
                    default:
                        break;
                }
            }
                
        }
        
        if (gameOver)
        {
            hitClicked = 0;
            cardIndex = 47;
            
            StartGame(myDeckptr, myHandptr, DeealersHandPtr);
            
            (void)pt1.loadFromFile(myHandptr->getCardPathname(0));   // reload same texture object
            (void)pt2.loadFromFile(myHandptr->getCardPathname(1));
            (void)pt3.loadFromFile(placeholder);
            (void)pt4.loadFromFile(placeholder);
            (void)pt5.loadFromFile(placeholder);
            (void)dt1.loadFromFile(DeealersHandPtr->getCardPathname(0));
            (void)dt2.loadFromFile(backImage);
            (void)dt3.loadFromFile(placeholder);
            gameOver = false;
            cout << "ran" << endl;

        }
        
        
        window.clear(sf::Color::Black);
        window.draw(ds1);
        window.draw(ds2);
        window.draw(ds3);
        window.draw(ps1);
        window.draw(ps2);
        window.draw(ps3);
        window.draw(ps4);
        window.draw(ps5);
        window.draw(dealerText);
        window.draw(PlayerText);
        window.draw(PlayerScore);
        window.draw(DealerScore);
        window.draw(won);
        window.draw(wonScore);
        window.draw(lost);
        window.draw(lostScore);
        window.display();
    }
    
    delete myDeckptr;
    delete myHandptr;
    delete DeealersHandPtr;
    
    
    return 0;
}
void StartGame(Deck*& d, Hand*& mh, Hand*& dh)
{
    delete d;
    delete mh;
    delete dh;
    
    d = new Deck;
    mh = new Hand;
    dh = new Hand;
    
    d->shuf();
    d->print();
    
    mh->AddCard(d->dealCard());
    dh->AddCard(d->dealCard());
    mh->AddCard(d->dealCard());
    dh->AddCard(d->dealCard());
}

