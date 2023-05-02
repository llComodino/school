#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 16

void worldInfo(void);
void classInfo(const char levels[4][BUFFER], int);
int battle(const char[], const char [4][BUFFER], const char [4][BUFFER], const char [4][BUFFER], int);

int main(void)
{
    system("cls");
    srand(time(NULL));
    
    int map;
    int class;

    char levels[4][BUFFER] = {
        {"Erisia"},
        {"The Dephts"},
        {"Layer Two"},
        {"Starswept"}
    };

    char enemies[4][BUFFER] = {
        {"Bandit"},
        {"Gigamed"},
        {"Carbunkler"},
        {"Thresher"}
    };

    char death[4][BUFFER] = {
        {"stabbed"},
        {"killed"},
        {"eaten"},
        {"mauled"}
    };

    worldInfo();

    printf("Selecting number:");
    scanf("%d", &map);
    printf("\n\n\n");

    system("cls");

    classInfo(levels, map);

    printf("Choose your class:");
    scanf("%d", &class);
    printf("\n\n");

    system("cls");
    
    char name[BUFFER];
    printf("Choose your name (max 16): ");
    scanf("%s", name);
    printf("\n\n\n");

    system("cls");

    while (battle(name, levels, enemies, death, map))
    {
        char choice;
        do {
            printf("%s, do you wish to try again? (s/n) > ", name);
            scanf("%s", &choice);
        } while (choice != 's' && choice != 'n' && choice != 'S' && choice != 'N');
        
        if (choice == 'n' || choice == 'N')
            return 1;
    }

    printf("congratulations, you win\nFor now...\n\n");
    return 0;
}

void worldInfo(void)
{
    printf("Thato Kehinde\n-------------\n"
    "Noxus is a powerful empire with a fearsome reputation.\n"
    "To those beyond its borders, it is brutal, expansionist, and threatening,\n"
    "yet those who look past its warlike exterior see an unusually inclusive society,\n"
    "where the strengths and talents of its people are respected and cultivated.\n\n"

    "The Noxii were once fierce barbarian tribes,\n"
    "until they stormed the ancient city that now lies at the heart of their domain.\n"
    "Under threat from all sides, they aggressively took the fight to their enemies,\n"
    "pushing their borders outward with each passing year.\n"
    "This struggle for survival has made modern Noxians a deeply proud people who value\n"
    "strength above all—though that strength can manifest in many different forms.\n\n"

    "Anyone can rise to a position of power and respect within Noxus if they display the necessary aptitude,\n"
    "regardless of social standing, background, homeland, or wealth. Those who are able to wield magic are held in particularly high esteem,\n"
    "and are actively sought out in order that their special talents may be honed and best harnessed for the benefit of the empire.\n\n"
    
    "But in spite of this meritocratic ideal, the old noble houses still wield considerable power…\n"
    "and some fear that the greatest threat to Noxus comes not from its enemies, but from within.\n\n\n\n");


    printf("Chanda Sung\n-----------\n"
    "Surrounded by treacherous seas, Chanda Sung is made up of a series of allied provinces scattered across the great archipelago of the Ancient Lands.\n"
    "Because Chanda Sung\'s culture has long been shaped by the pursuit of balance,\n"
    "the line between the material and spiritual realms is more porous here, especially in the forests and mountains.\n\n"

    "Though the enchantments of these lands are fickle and the creatures are dangerous and fey, Sungi have thrived there for centuries.\n"
    "The warrior monasteries, provincial militias, and Chanda Sung's own land had been protection enough.\n\n"

    "Everything changed twelve years ago, when Noxus attacked the Oldlands.\n"
    "The endless troops of the empire devastated Chanda Sung and were only defeated after many years... and at great cost.\n\n"

    "Now Chanda Sung lives in an uneasy peace. Different reactions to the war have divided the region.\n"
    "Some groups, such as the Shojin monks of Kinkou, would like to return to an isolationist pacifism and rural traditions.\n"
    "Other more radical factions, such as the Navori Brotherhood and the Order of the Shadow, are calling for a militarization of land magic,\n"
    "to create a single united nation capable of taking revenge against Thato Kehinde.\n\n"

    "Chanda Sung's fate is in a delicate balance that hardly anyone dares to touch, but which everyone perceives as precarious.\n\n\n\n");

    printf("Soul Society\n------------\n"
    "Society of the soul represents the place where they go,\n"
    "the souls of human beings whose actions do not lead them to hell, to death.\n\n"
    "Its appearence is similar to that of Edo period Japan.\n"
    "Although one does not feel hungry in this place due to the fact that it is haunted by spirits,\n"
    "and in Rukia's words nine times out of ten Soul Society is better than the world of the living,\n"
    "It's far from the vision of Heaven that it is usually to have.\n\n"
    "Being in the Soul Society does not mean being immortal, as souls grow old in it,\n"
    "although at a much slower pace than in the world of the living.\n"
    "Souls can have children, and there are families of Shinigami\n"
    "whose ancestors have been born in Soul Society for many generations,\n"
    "which makes them noble. Also, they can die of old age, disease, assassination, or in combat.\n"
    "When that happens, they reincarnate into the world of the living as new people.\n\n\n\n");

    return;
}

void classInfo(const char levels[][BUFFER], int x)
{
    printf("To face %s we are going to give you few different powerful classes, choose carefully one:\n\n\n", levels[x - 1]);

    printf("1. Saber\nKnight of the sword and heroic spirit of the sword.\n"
    "A jack-of-all-trades warrior. Agile and powerful in close quarters; extremely adepts at swordmanship.\n\n");

    printf("2. Archer\nKnight of the Bow and Heroic Spirit of the Bow.\n"
    "Excellent scouts that excel in possessing powerful Noble Phantasms. Masters of long ranged warfare.\n\n");

    printf("3. Assassin\nSilent Killer and Heroic Spirit of Assassinations.\n"
    "Extremely skilled at covert, stealthy, and silent operations.\n\n");

    printf("4. Caster\nMagus and Heroic Spirit of Spells and Sorcery.\n"
    "Adept in magecraft, being one of the few able to use sorceries of the highest caliber.\n\n");

    return;
}

int battle(const char name[BUFFER], const char levels[][BUFFER], const char enemies[][BUFFER], const char death[][BUFFER], int x)
{
    int enemy = 100;
    int you = 100;
    int roll;

    for (int i = 0; you > 0 && enemy > 0; i++)
    {
        printf("Turn %d\n", i + 1);
        printf("------\n");
        
        roll = 1 + rand() % 20;
        
        if (i % 2 != 0)
        {
            printf("\nYour turn\n\n");
            printf("Rolling dice..\n");
            

            if (roll == 20)
            {
                printf("\n\n!!! Critical hit !!!\nDamage multiplied\n\n");
                roll *= 2;
            }
            
            else
                printf("%d rolled out!\n", roll);

            printf("%d damage dealt to %s, HP decreased from %d to %d\n", roll, enemies[x], enemy, enemy - roll < 0 ? 0 : enemy - roll);
            enemy -= roll;
        }

        else
        {
            printf("\n%s attacks\n\n", enemies[x]);
            printf("Rolling dice..\n");
            
            if (roll == 20) 
            {
                printf("\n\n!!! Critical hit !!!\nDamage multiplied\n\n");
                roll *= 2;
            }

            else
                printf("%d rolled out!\n", roll);

            printf("You got damaged by %d damage, HP decreased from %d to %d\n", roll, you, you - roll < 0 ? 0 : you - roll);
            you -= roll;
        }
        printf("\nPress to continue ... ");
        getch();
        system("cls");
    }

    printf("\n\n");

    if(you > enemy)
    {
        printf("You successfully got onto the next level!\n");
        return 0;

    } else {

        if (you < enemy) 
        {
            printf("You got %s by a %s.\n", death[x], enemies[x]);
            return 1;
        }
    }
}
