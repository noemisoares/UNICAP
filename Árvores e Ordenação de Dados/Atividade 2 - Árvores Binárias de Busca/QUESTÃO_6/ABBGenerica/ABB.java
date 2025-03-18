package ABBGenerica;

import java.util.Stack;

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

    public int NosRecursivo() {
        if(isEmpty() == true){
            return 0;
        } else {
            return contarNosRecursivo(this.root);
        }
    }

    private int contarNosRecursivo(ABBNode<T> node) {
        if (node == null) {
            return 0;
        }
        return 1 + contarNosRecursivo(node.getLeft()) + contarNosRecursivo(node.getRight());
    }

    public int NosNaoRecursivo() {
        if (isEmpty() == true) {
            return 0;
        }
        
        int count = 0;
        Stack<ABBNode<T>> stack = new Stack<>();
        stack.push(this.root);
        
        while (stack.isEmpty() != true) {
            ABBNode<T> node = stack.pop();
            count++;
            if (node.getRight() != null) {
                stack.push(node.getRight());
            }
            if (node.getLeft() != null) {
                stack.push(node.getLeft());
            }
        }
        return count;
    }

    public int FolhasRecursivo() {
        if(isEmpty() == true){
            return 0;
        } else {
            return contarFolhasRecursivo(this.root);
        }
    }

    private int contarFolhasRecursivo(ABBNode<T> node) {
        if (node == null) {
            return 0;
        }
        if (node.getLeft() == null && node.getRight() == null) {
            return 1;
        }
        return contarFolhasRecursivo(node.getLeft()) + contarFolhasRecursivo(node.getRight());
    }

    public int FolhasNaoRecursivo() {
        if (this.isEmpty()) {
            return 0;
        }
        
        int count = 0;
        Stack<ABBNode<T>> stack = new Stack<>();
        stack.push(this.root);
        
        while (stack.isEmpty() != true) {
            ABBNode<T> node = stack.pop();
            if (node.getLeft() == null && node.getRight() == null) {
                count++;
            }
            if (node.getRight() != null) {
                stack.push(node.getRight());
            }
            if (node.getLeft() != null) {
                stack.push(node.getLeft());
            }
        }
        return count;
    }

    public int NaoTerminaisRecursiva() {
        if(isEmpty() == true){
            return 0;
        } else {
            return contarNaoTerminaisRecursiva(this.root);
        }
    }

    private int contarNaoTerminaisRecursiva(ABBNode<T> node) {
        if (node == null) {
            return 0;
        }
        if (node == null || (node.getLeft() == null && node.getRight() == null)) {
            return 0;
        }
        return 1 + contarNaoTerminaisRecursiva(node.getLeft()) + contarNaoTerminaisRecursiva(node.getRight());
    }

    public int NaoTerminaisNaoRecursiva() {
        if (this.isEmpty()) {
            return 0;
        }
        
        int count = 0;
        Stack<ABBNode<T>> stack = new Stack<>();
        stack.push(this.root);
        
        while (stack.isEmpty() != true) {
            ABBNode<T> node = stack.pop();
            if (node.getLeft() != null || node.getRight() != null) {
                count++;
            }
            if (node.getRight() != null) {
                stack.push(node.getRight());
            }
            if (node.getLeft() != null) {
                stack.push(node.getLeft());
            }
        }
        return count;
    }
}