#include <iostream>
using namespace std;

char choice = 0;

int main() {
    
    cout << "Once upon a time, there was a happy, loyal dog named Rufus, and an independent, fun cat named Mindy. Their owner leaves early that day.\n";
    cout << "Rufus looks at his human owner walking away with sad puppy-dog eyes, and Mindy meows for attention to no avail.\n";
    cout << "The world wrinkles and grows tense, as though it were being pulled in three directions. The air everywhere grows still.\n";
    cout << "Rufus starts indiscriminately barking at his surroundings, and Mindy hisses in fear.\n";

    cout << "(1) Inspect surroundings (2) Inspect yourself: ";
    cin >> choice;

    // inspect surroundings
    if (choice == '1') { 
        cout << "All around the world, there seems to be rips and crackles, as though the very fabric of reality itself is crumbling apart\n";
        cout << "The blue sky is breaking into pieces, as though it had been punched through, and is shattering away like a glass dome\n";
        cout << "In place of the normal earthly blues, in these tears there is an eeirie blood-red and violet background\n";
        
        cout << "(1) Inspect the cracks in the sky (2) Comfort the pets: ";
        cin >> choice;

        // Inspect the cracks in the sky
        if (choice == '1') {
            cout << "The glob looks up toward the rips in the sky. Using something vaguely resembling an arm, it reaches toward the sky.\n";
            cout << "The ground trembles, and the sky comes down to meet it. As the two come to meet, the surroundings begin to turn all white...\n";
            cout << "THE END\n";
        
        // Comfort the pets
        } else {
            cout << "As you go toward the animals, they run away, frightened by you\n";
            
            cout << "(1) Inspect yourself (2) Inspect the damage: ";
            cin >> choice;
            
            // inspect yourself
            if (choice == '1') {
                cout << "When looking down, all that can be found is a shadowy, levitating dark mass with globby, melting arms\n";
                
                cout << "(1) Try to comprehend yourself (2) Get out of this plane of existence: ";
                cin >> choice;
                
                // Try to comprehend yourself
                if (choice == '1') {
                    cout << "The glob appears to be some sort of spiritual entity that is distorting reality itself\n";

                    cout << "(1) Snap (2) Clap: ";

                    // Snap
                    if (choice == '1') {
                        cout << "At first, half of all living things fade into dust, but then the other half crumples away too, along with the earth and the stars\n";
                        cout << "As the wallpaper of the universe crumples into dust, it reveals a white server room, and several monitors showing another normal day on Earth\n";
                        cout << "THE END\n";
 
                    // Clap
                    } else {
                        cout << "A giant, invisible sound burst cascades away from the glob, making everything it touches smear like a badly rendered video\n";
                        cout << "Droplets coming down from the heavens and up from hell wash away this smear, until the only color left is a glossy white and an out of place shadow\n";
                        cout << "THE END\n";
                    }

                // Get out of this plane of existence
                } else {
                    cout << "...Successful. By flying straight into a nearby crack of reality, the glob managed to disappear from the earthly realm\n";
                    cout << "THE END\n";
                }

            // inspect the damage
            } else {
                cout << "The glob appears to be the one causing the tears in the fabric of reality\n";

                cout << "(1) Jump (2) Fall: ";
                cin >> choice;
                
                // Jump
                if (choice == '1') {
                    cout << "By imitating a jump by floating up and then down, the material around the glob moved becomes wave-like with concrete, steel, and window panes \n all melding together and moving as though it were liquid\n";
                    cout << "As the material waves grow higher and higher, they take everything in their path, leaving nothing behind except a dull white plane\n";
                    cout << "THE END\n";

                // Fall
                } else {
                    cout << "The blob dips into the Earth's crust. By doing so, their shadowy darkness spread to every corner of the globe, and then every light in the sky\n";
                    cout << "The cracks appear in every place, and then they tear free, pieces of black fabric falling everywhere. The fabric flies away with the wind, revealing a bright white server room\n";
                    cout << "THE END\n";
                    }
            }
        }

    // inspect yourself
    } else { 
        cout << "When looking down, all that can be found is a shadowy, levitating dark mass with globby, melting arms\n";

        cout << "(1) Inspect immediate surroundings (2) Stay still: ";
        cin >> choice;

        // inspect immediate surroundings
        if (choice == '1') {
            cout << "The immediate vicinity around this glob appears to have the most tears in the fabric of reality\n";

            cout << "(1) Approach the shattered sky (2) Touch the wall: ";
            cin >> choice;

            // approach the shattered sky
            if (choice == '1') { 
                cout << "As the blob gets closer and closer to the sky, the surroundings grow more and more white, until the blob is alone in a white room\n";
                cout << "Oddly, as it walks around, there appears to be a large labrynth of servers. On one monitor shows a view of Earth looking perfectly normal.\n";
                cout << "THE END\n";

            // Touch the wall
            } else {
                cout << "The wall instantly shatters, and the world around the blob shatters from that single contact point. Earth has become dust.\n";
                cout << "Luckily for Earth's denizens, this was merely one of thousands of simulations conducted by the Earth Dystopia Research Association\n";
                cout << "THE END\n";
            }

        // Stay still
        } else {
            cout << "While staying stationary, the blob, and its cracks in reality it has formed, begin to evaporate away. Reality begins to take hold once more.\n";
            cout << "(1) Blink (2) Scream: ";
            cin >> choice;

            // Blink
            if (choice == '1') {
                cout << "...and in a blink, the murky shadow disappears. The cracks in reality fill in, and the world collectively forgets about the anomaly\n";
                cout << "Unfortunately, no one will ever know the truth of this world\n";
                cout << "THE END\n";
            
            // Scream
            } else {
                cout << "A piercing scream tore through the air. Unfortunately, to everyone else, it was quieter than a pin drop. The shadows receded away, and the blob was no more.\n";
                cout << "THE END\n";

            }
        }
    }
}
