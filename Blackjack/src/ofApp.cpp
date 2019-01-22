#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    money = 2000;
    
    for(int i = 0; i < 52; i++)
    {
        std::string number = to_string(i+1);
        
        faces[i].load("/Users/abhaysinghal/Documents/XCode Projects/Blackjack/bin/data/" + number + ".jpeg");
        
        faces[i].resize((int) (ofGetWidth()/6), (int) (ofGetWidth()/6 * 98/73));
    }
    
    started = finished = false;
    
    reset();
    
    b[0] = Button(ofGetWidth()/3, 0.80 * ofGetHeight(), ofGetHeight()/16, "Hit");
    b[1] = Button(2*ofGetWidth()/3, 0.80 * ofGetHeight(), ofGetHeight()/16, "Stay");
    b[2] = Button(ofGetWidth()/12, 0.50 * ofGetHeight(), ofGetHeight()/16, "Bet");
    b[3] = Button(ofGetWidth()/2, 0.8*ofGetHeight(), ofGetHeight()/16, "Restart");
    
    name[0] = "Player";
    name[1] = "House";
}

//--------------------------------------------------------------
void ofApp::update()
{
    if(started)
    {
        for(int i = 0; i < 2; i++)
        {
            p[i].update();
        }
    
        if(turn == 1)
        {
            if(p[1].getValue() < 17)
            {
                int r = (int) ofRandom(deck.size());
            
                p[1].addCard(r, faces[r]);
            
                deck.erase(deck.begin() + r);
            }
            else
            {
                finished = true;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    if(!started)
    {
        std::string moola = to_string(money);
        
        ofDrawBitmapString("Money = $" + moola, ofGetWidth()/2, ofGetHeight()/3);
        
        ofDrawBitmapString("Bet = $" + bet, ofGetWidth()/2, 2*ofGetHeight()/3);
        
        b[3].display();
    }

    
    if(!finished && started)
    {
        p[turn].displayCards(1.5, name[turn]);
        
        for(int i = 0; i < 2; i++)
        {
            b[i].display();
        }
    }
    else if(finished && started)
    {
        compare();
        
        b[2].display();
    }
    
    ofDrawBitmapString(command, ofGetWidth()/4, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    /*switch(key)
    {
        case OF_KEY_RETURN:
            
            if(command == "Hit" || command == "hit")
            {
                int r = (int) ofRandom(deck.size());
            
                p[0].addCard(r);
            
                deck.erase(deck.begin() + r);
                
                command = "";
            }
        
            else if(command == "Stay" || command == "stay")
            {
                if(turn == 0)
                {
                    turn++;
                    
                    command = "";
                }
            
                else if(turn == 1)
                {
                    command = "";
                    finished = true;
                }
            }
            
            if(finished)
            {
                if(command == "Reset" || command == "reset")
                {
                    reset();
                }
            }
        break;
        
        case OF_KEY_BACKSPACE:
            command.pop_back();
        break;
        
        default:
            command.push_back(key);
        break;
    }*/
    
    if(!started)
    {
        switch(key)
        {
            case OF_KEY_RETURN:
                
//                for (string::size_type i=0; i < bet.length(); ++i)
//                {
//                    bet += std::tolower(bet[i] , loc);
//                }
                
                if(bet == "") bet = to_string(money);
                
                wager = stoi(bet);
                
                if(wager > money)
                {
                    wager = money;
                }
                
                started = true;
                break;
                
            case OF_KEY_BACKSPACE:
                bet.pop_back();
                break;
                
            default:
                if(isdigit(key)) bet.push_back(key);
                break;
                
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    if(!started)
    {
        if(b[3].isPressed(x, y))
        {
            restart();
        }
    }

    if(!finished && started)
    {
        if(b[0].isPressed(x, y) && !p[turn].isBust())
        {
            int r = (int) ofRandom(deck.size());
            
            p[turn].addCard(r, faces[r]);
            
            deck.erase(deck.begin() + r);
        }
        else if(b[1].isPressed(x, y))
        {
            if(turn == 0)
            {
                turn++;
            }
            
            else if(turn == 1)
            {
                finished = true;
                
                for(int i = 0; i < 2; i++)
                {
                    p[i].resize();
                }
            }
        }
    }
    else if(finished && started)
    {
       if(b[2].isPressed(x, y))
       {
           reset();
       }
    }

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::compare()
{
    for(int i = 0; i < 2; i++)
    {
        p[i].displayCards((1.5*i + 1.25), name[i]);
    }
}

void ofApp::reset()
{
    if(!p[0].isBust() && p[1].isBust()) money += wager;
    if(p[0].isBust() && !p[1].isBust()) money -= wager;
    if(!p[0].isBust() && !p[1].isBust() && p[0].getValue() < p[1].getValue()) money -= wager;
    if(!p[0].isBust() && !p[1].isBust() && p[0].getValue() > p[1].getValue()) money += wager;
    
    bet = "";
    wager = 0;
    
    started = false;
    finished = false;
    
    turn = 0;
    command = "";
    
    deck.clear();
    
    for(int i = 0; i < 52; i++)
    {
        deck.push_back(Card((i+1), &faces[i]));
    }
    
    for(int i = 0; i < 2; i++)
    {
        p[i].emptyHand();
    
        for(int j = 0; j < 2; j++)
        {
            int r = (int) ofRandom(deck.size());
            
            p[i].addCard(r, faces[r]);
            
            deck.erase(deck.begin() + r);
        }
    }
}

void ofApp::restart()
{
    bet = "";
    wager = 0;
    
    started = false;
    finished = false;
    
    turn = 0;
    command = "";
    
    deck.clear();
    
    for(int i = 0; i < 52; i++)
    {
        deck.push_back(Card((i+1), &faces[i]));
    }
    
    for(int i = 0; i < 2; i++)
    {
        p[i].emptyHand();
    
        for(int j = 0; j < 2; j++)
        {
            int r = (int) ofRandom(deck.size());
            
            p[i].addCard(r, faces[r]);
            
            deck.erase(deck.begin() + r);
        }
    }
    
    money = 1000;
}

bool IsNumber(char c)
{
    for(int i = 48; i < 58; i++)
    {
        if(c == i)
        {
            return true;
        }
    }
    
    return false;
}
