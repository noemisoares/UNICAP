package ABBGenerica;
import Pilha.Stack;

public class ABB <T extends Comparable<T>> {
    private ABBNode<T> root;

    public boolean isEmpty () {
        if (this.root == null) {
            return true;
        }
        else {
            return false;
        }
    }

    public void insert (T valor) {
        if (this.isEmpty() == true) {
            this.root = new ABBNode<T>(valor);
        }
        else {
            inserir(this.root, valor);
        }
    }

    private void inserir(ABBNode<T> node, T valor) {
        int retorno;
        if (node != null) {
            retorno = valor.compareTo(node.getInfo());
            if (retorno == 0) {
                System.out.println("Valor repetido!\n");
                return;
            }
            else if (retorno < 0) {
                if (node.getLeft() != null) {
                    inserir(node.getLeft(), valor);
                } else {
                    ABBNode<T> novo = new ABBNode<T>(valor);
                    node.setLeft(novo);
                    System.out.println("Valor inserido com sucesso!");
                }
            }
            else {
                if (node.getRight() != null) {
                    inserir(node.getRight(), valor);
                } else {
                    ABBNode<T> novo = new ABBNode<T>(valor);
                    node.setRight(novo);
                    System.out.println("Valor inserido com sucesso!");
                }
            }
        }
    }

    public T find (T value) {
        if (this.isEmpty() == true) {
            return null;
        }
        else {
            return findNode(this.root, value);
        }
    }

    private T findNode (ABBNode<T> r, T value) {
        int result = value.compareTo(r.getInfo());
        if (result == 0) {
            return r.getInfo();
        }
        else if (result < 0) {
            if (r.getLeft() == null) {
                return null;
            }
            else {
                return findNode (r.getLeft(),value);
            }
        }
        else {
            if (r.getRight() == null) {
                return null;
             }
            else {
                return findNode (r.getRight(),value);
            }
        }
    }

    public void emOrdem () {
        if (this.isEmpty() == true) {
            System.out.println("Arvore vazia.\n");
        }
        else {
            this.percorrerEmOrdem(this.root);
        }
    }

    private void percorrerEmOrdem(ABBNode<T> raiz){
        Stack<ABBNode<T>> stack = new Stack<>();
        ABBNode<T> atual = this.root;

        while (atual != null || stack.isEmpty() != true) {
            while (atual != null) {
                stack.push(atual);
                atual = atual.getLeft();
            }
            atual = stack.pop();
            System.out.println(atual.getInfo());
            atual = atual.getRight();
        }
    }
}