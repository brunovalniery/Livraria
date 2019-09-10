#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;
//Está completa, não é necessário alterar
class Produto
{
private:
  string nome;
  unsigned preco;
public:
  inline Produto(const string& N="", unsigned P=0): nome(N), preco(P) {}

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void digitar();
  // Define a funcao imprimir como sendo salvar em cout
  inline void imprimir() const {salvar(cout);}
};

inline istream& operator>>(istream &I, Produto &P) {P.digitar(); return I;} //utiliza método público, por isso não é necessário a palavra reservada friend.
inline ostream& operator<<(ostream &O, const Produto &P) {P.salvar(O); return O;}

// =========================================
// Inclua aqui as classes Livro, CD e DVD
// =========================================
class Livro : public Produto{
private:
    string autor;
public:
    bool ler(istream &I){Produto::ler()};
    void salvar(ostream &O) const Produto::salvar();
    void digitar() Produto::digitar();
    inline void imprimir() const {salvar(cout); Produto::imprimir()}
};

class CD : public Produto{
private:
    int numfaixas;
public:
    bool ler(istream &I) Produto::ler();
    void salvar(ostream &O) const Produto::salvar();
    void digitar() Produto::digitar();
    inline void imprimir() const {salvar(cout); Produto::imprimir()}
};

class DVD : public Produto{
private:
    int duracao;
public:
    bool ler(istream &I) Produto::ler();
    void salvar(ostream &O) const Produto::salvar();
    void digitar() Produto::digitar();
    inline void imprimir() const {salvar(cout); Produto::imprimir()}
};

class ListaLivro //classe que envolve alocação dinâmica de memória
{
private:
  Livro *x; //array dinâmico de livros
  unsigned N; //guardar a dimensão do array
public:
  // Inclua os construtores, destrutor e operadores necessarios
  void incluir(const Livro &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

// =========================================
// Inclua aqui as classes ListaCD e ListaDVD
// =========================================
class ListaCD{
private:
public:

};

class ListaDVD{
private:
public:

};

class Loja
{
private:
  ListaLivro LL;
  ListaCD LC;
  ListaDVD LD;
public:
  inline Loja(): LL(), LC(), LD() {}

  inline void incluirLivro(const Livro &X) {LL.incluir(X);}
  inline bool excluirLivro(unsigned id) {return LL.excluir(id);}
  inline void incluirDVD(const DVD &X) {LD.incluir(X);}
  inline bool excluirDVD(unsigned id) {return LD.excluir(id);}
  inline void incluirCD(const CD &X) {LC.incluir(X);}
  inline bool excluirCD(unsigned id) {return LC.excluir(id);}

  bool ler(const string& arq);
  bool salvar(const string& arq) const;
  void imprimir() const;
};
#endif // _LOJA_H_
