#include "loja_heranca.h"

void ListaLivro::ler(istream &I){
  Livro L;
  L.Ler(I);
  incluir(L);
}

void ListaLivro::ler(istream &I){
  CD C;
  C.Ler(I);
  incluir(L);
}

void ListaLivro::ler(istream &I){
  DVD D;
  D.Ler(I);
  incluir(L);
}
