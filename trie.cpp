#include <bits/stdc++.h>

using namespace std;

struct Trie {
    unordered_map<char, Trie*> tree;
    int counter;
};

ifstream f("trie.in");
ofstream g("trie.out");

Trie* initialize() {
    Trie* node = new Trie();
    node->counter = 0;
    return node;
}

void adauga(Trie* radacina, string cuvant) {
    Trie* nod = radacina;
    for (char litera : cuvant) {
        if (nod->tree.find(litera) == nod->tree.end()) {
            nod->tree[litera] = initialize();
        }

        nod = nod->tree[litera];
    }
    nod->counter++;
}

int prefix(Trie* radacina, string cuvant) {
    Trie* nod = radacina;
    int lungime = 0;
    for (char litera : cuvant) {
        if (nod->tree.find(litera) == nod->tree.end()) {
            break;
        }
        lungime++;
        nod = nod->tree[litera];
    }
    return lungime;
}

int nrAparitii(Trie* radacina, string cuvant) {
    Trie* nod = radacina;
    for (char litera : cuvant) {
        if (nod->tree.find(litera) == nod->tree.end()) {
            return 0;
        }
        nod = nod->tree[litera];
    }
    return nod->counter;
}

bool stergeCuvant(Trie* nod, string& cuvant, int nivel) {

    if (nod) {
        if (nivel == cuvant.length()) {
            if (nod->counter > 0) {
                nod->counter--;
                return true;
            }
            return false;
        }
        char literaUrmatoare = cuvant[nivel];
        if (nod->tree.find(literaUrmatoare) != nod->tree.end()) {
            bool nodDeSters = stergeCuvant(nod->tree[literaUrmatoare], cuvant, nivel++);
            if (nodDeSters) {
                if (nod->tree[literaUrmatoare]->counter == 0 && nod->tree[literaUrmatoare]->tree.empty()) {
                    delete nod->tree[literaUrmatoare];
                    nod->tree.erase(literaUrmatoare);
                }
                return nod->tree.empty();
            }
        }
    }
    return false;
}

void sterge(Trie* radacina, string cuvant) {
    if (cuvant.empty())
        return;

    stergeCuvant(radacina, cuvant, 0);
}

int main() {
    Trie* radacina = initialize();
    int operatie;
    string cuvant, linie;

    while(getline(f, linie)) {
        istringstream in(linie);

        in>>operatie>>cuvant;
        switch(operatie) {
            case 0:
                adauga(radacina, cuvant);
                break;
            case 1:
                sterge(radacina, cuvant);
                break;
            case 2:
                g<<nrAparitii(radacina, cuvant)<<endl;
                break;
            case 3:
                g<<prefix(radacina, cuvant)<<endl;
                break;
            default:
                break;
        }
    }

    f.close();
    g.close();
    return 0;
}
