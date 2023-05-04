#include <stdio.h>
#include <string.h>

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
