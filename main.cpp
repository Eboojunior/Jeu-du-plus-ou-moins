#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;
void regle();
void jeu(std::string prenom[]);
void PlusOumoins(int nbEntrer, int nbMystere, int nbCoups, bool *boucle);

 void regle()
    {
        cout << "les regles sont:" << endl;
        cout << "l'ordinateur va choisir un nombre mystere entre o et 100 pour le niveau facile, 0 et 1000 pour le niveau moyen, 0 et 10000 pour le niveau difficile" << endl;
        cout << "vous devez entre le nombre mystere" << endl;
    }

     void PlusOumoins(int nbEntrer,int nbMystere,int nbCoups,bool *boucle)
     {
        if(nbEntrer > nbMystere)
        {
            cout << "trop grand" << endl;
        }
        else if(nbEntrer < nbMystere)
        {
            cout << "trop petit" << endl;
        }
        else
        {
            cout << "bravo vous avez trouver le nombre mystere en : "<< nbCoups << "coup(s) !" << endl;
            *boucle = true;
        }
     }

     void jeu(std::string prenom[])
    {
        int nbCoups = 0, MAX = 0;
        const int MIN = 0;
        cout << "choisissez le niveau de la difficultee" << endl;
        cout << "1. De 0 a 100 pour le niveau facile" << endl;
        cout << "2. De 0 a 1000 pour le niveau moyen" << endl;
        cout << "3. De 0 a 10000 pour le niveau difficile" << endl;
        int choixDiff;
        cin >> choixDiff;
        if(choixDiff == 1)
        {
            MAX = 100;
        }
        else if(choixDiff == 2)
        {
            MAX = 1000;
        }
        else if(choixDiff == 3)
        {
            MAX = 10000;
        }
        else
        {
            MAX = 100; // on choisis un nombre par "defaut"
        }

        bool boucle = false;
        int nbMystere = (rand() % (MAX - MIN + 1)) + MIN;
        cout << "le jeu commence!" << endl;
        while(boucle == false)
        {
            cout << *prenom << " Entrez un nombre entre " << MIN << " et " << MAX << endl;
            int nbEntrer;
            cin >> nbEntrer;
            nbCoups++;
            PlusOumoins(nbEntrer, nbMystere, nbCoups, &boucle);
        }
    }

int main()
{
    std::srand(time(NULL));

    char* OuiRecommenceOuNon;

    OuiRecommenceOuNon = new char[100];

    cout << "salut et bienvenue dans le jeu du plus ou moins" << endl;
    cout << "Entrez votre prenom s'il vous plait" << endl;
    std::string *prenom;
    prenom = new std::string[1000];
    cin >> *prenom;

    cout << "ok " << *prenom << " on va pouvoir commencer le jeu" << endl;

    do
    {
        cout << "----------------le jeu du plus ou moins----------------" << endl;
        cout << "vous connaissez les regles de ce jeu?" << endl;
        cout << "Entrer oui ou non" << endl;
        char OuiOuNon[5];
        cin >> OuiOuNon;
        if (strcmp (OuiOuNon, "oui") == 0 || strcmp (OuiOuNon, "OUI") == 0)
        {
            cout << "ok on va pouvoir commencer" << endl;
            jeu(prenom);
        }
        else if(strcmp(OuiOuNon, "non") == 0 || strcmp(OuiOuNon, "NON") == 0)
        {
            cout << "ok voici les regles" << endl;
            regle();
            jeu(prenom);
        }
        else
        {
            cout << "vous vous etes tromper..." << endl;
        }
        cout << "voulez vous recommencer?" << endl;
        cout << "Entrer oui ou non" << endl;
        cin >> OuiRecommenceOuNon;
        system("cls");
    }
    while( strcmp (OuiRecommenceOuNon, "oui") == 0 || strcmp(OuiRecommenceOuNon, "OUI") == 0);
    delete[] prenom;
    delete[] OuiRecommenceOuNon;

    return 0;
}
