// Francisco Valdemi Leal Costa Junior - 485325
#include <bits/stdc++.h>

using namespace std;

enum EntryType{
    ACTIVE,
    EMPTY,
    DELETED
}; // Definition of type EntryType

template <typename Tkey, typename Tvalue>
class HashTable{
public:
    explicit HashTable(int size = 101){// Constructor
        currentSize = 0;
        vec.resize(size);
    } 

    bool contains(const Tkey &x) const{// Verifica se a chave passada está na tabela e está ativa
        for(int i = 0; i < vec.size(); i++){
            size_t j = hashFunction(x, i);
            if(vec[j].status == ACTIVE && vec[j].element.first == x){
                return true;
            }
        }

        return false;
    }

    int get_current(){// Retorna quantos elementos tem na tabela
        return currentSize;
    }

    void makeEmpty(){// Torna todas as posições ta tabela vazia 
        currentSize = 0;
        
        for(auto &myvec : vec){
            myvec.status = EMPTY;
        }
    }

    bool insert(const Tkey &x, const Tvalue &v){// Inseri um pair na tabela 
        int i = 0;

        do{
            size_t j = hashFunction(x, i);// Define a posição em que vai ser inserido
            if(vec[j].status == EMPTY || vec[j].status == DELETED){
                vec[j].element = make_pair(x, v);
                vec[j].status = ACTIVE;
                currentSize++;
                return true;
            }else{
                i++;
            }
            
        } while (i < vec.size());
        
        return false;
    }

    bool remove(const Tkey &x){// Remove um elemento da tabela
        int i = 0;

        do{
            size_t j = hashFunction(x, i);// Recebe as posições que vão ser verificadas
            if(vec[j].status == ACTIVE){
                if(vec[j].element.first == x){
                    vec[j].status = DELETED;
                    currentSize--;
                    return true;
                }
            }else if(vec[j].status == EMPTY){
                return false;
            }else{
                i++;
            }
        } while (i < vec.size());
        
        return false;
    }

    int size() const{// Retorna o tamanho da minha tabela
        return vec.size();
    }

    bool search(const Tkey &x, Tvalue &result){// Busca por uma chave e atribui o seu valor no result
        for(int i = 0; i < vec.size(); i++){
            size_t j = hashFunction(x, i);
            if(vec[j].status == ACTIVE && vec[j].element.first == x){
                result = vec[j].element.second;
                return true;
            }
        }

        return false;
    }

    void print(){// Printa os elementos da tabela
        for(auto &myvec : vec){
            if(myvec.status == ACTIVE){
                cout << myvec.element.first << "," << myvec.element.second << endl;
            }
        }
    }

private:
    struct HashEntry{// Estrutura da tabela
        pair<Tkey, Tvalue> element;
        EntryType status;

        HashEntry(const Tkey &x = Tkey{}, const Tvalue &v = Tvalue{}, EntryType i = EMPTY)
            : element(make_pair(x, v)), status(i) {}
    };

    vector<HashEntry> vec;
    int currentSize;

    size_t hashFunction(const Tkey &x, int i) const{// Função que determina os indices por meio da operação
        hash<Tkey> hf;
        return (hf(x) % vec.size() + i * (1 + (hf(x) % (vec.size() - 1)))) % vec.size();
    }
};

