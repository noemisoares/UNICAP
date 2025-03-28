package AVL;
import Fila.Queue;

public class AVL <T extends Comparable <T>> {
    private AVLNode <T> root;
    private boolean status;

    public boolean isEmpty() {
        return this.root == null;
    }

    public void insert(T valor){
        if(isEmpty() == true){
            this.root = new AVLNode<T>(valor);
        } else {
            this.root = insertNode(this.root, valor);
            status = false;
        }
    }
    
    private AVLNode <T> insertNode(AVLNode<T> raiz, T valor) {
        if(raiz == null){
            raiz = new AVLNode<T>(valor);
            this.status = true;
        }
        else if(raiz.getInfo().compareTo(valor) > 0){
            raiz.setLeft(insertNode(raiz.getLeft(), valor));
            if(this.status == true){
                switch (raiz.getFatBal()) {
                    case 1:
                        raiz.setFatBal(0);
                        this.status = false;
                        break;
                    case 0:
                        raiz.setFatBal(-1);
                        break;
                    case -1:
                        raiz = this.rotateRight(raiz);
                        break;
                }
            }
        } 
        else {
            raiz.setRight(insertNode(raiz.getRight(), valor));
            if(this.status == true){
                switch (raiz.getFatBal()) {
                    case -1:
                        raiz.setFatBal(0);
                        this.status = false;
                        break;
                    case 0:
                        raiz.setFatBal(1);
                        break;
                    case 1:
                        raiz = this.rotateLeft(raiz);
                        break;
                }
            }
        }
        return raiz;
    }

    private AVLNode<T> rotateRight (AVLNode<T> a) {
        AVLNode<T> b, c;
        b = a.getLeft();

        if (b.getFatBal() == -1) {
            a.setLeft(b.getRight());
            b.setRight(a);
            a.setFatBal(0);
            a = b;
        }
        else {
            c = b.getRight();
            b.setRight(c.getLeft());
            c.setLeft(b);
            a.setLeft(c.getRight());
            c.setRight(a);
            if (c.getFatBal() == -1) {
                a.setFatBal(1);
            } else {
                a.setFatBal(0);
            }
            if (c.getFatBal() == 1) {
                b.setFatBal(-1);
            } else {
                b.setFatBal(0);
            }
            a = c;
        }
        a.setFatBal(0);
        this.status = false;
        return a;
    }

    private AVLNode<T> rotateLeft (AVLNode<T> a) {
        AVLNode<T> b, c;
        b = a.getRight();

        if (b.getFatBal() == 1) {
            a.setRight(b.getLeft());
            b.setLeft(a);
            a.setFatBal(0);
            a = b;
        }
        else {
            c = b.getLeft();
            b.setLeft(c.getRight());
            c.setRight(b);
            a.setRight(c.getLeft());
            c.setLeft(a);
            if (c.getFatBal() == 1) {
                a.setFatBal(-1);
            } else {
                a.setFatBal(0);
            }
            if (c.getFatBal() == -1) {
                b.setFatBal(1);
            } else {
                b.setFatBal(0);
            }
            a = c;
        }
        a.setFatBal(0);
        this.status = false;
        return a;
    }

    public void emOrdem(){
        if(isEmpty()){
            System.out.println("Árvore vazia!");
        } else {
            this.passeioEmOrdem(this.root);
        }
    }

    private void passeioEmOrdem(AVLNode <T> raiz){
        if(raiz != null){
            passeioEmOrdem(raiz.getLeft());
            System.out.println(raiz.getInfo());
            passeioEmOrdem(raiz.getRight());
        }
    }

    public void passeioPorNivel(){
        Queue<AVLNode<T>> fila = new Queue<>();
        if(!isEmpty()){
            fila.enQueue(this.root);
            while (fila.isEmpty() == false) {
                int tamanho = fila.getQtd();
                boolean nulo = false;
                for (int i = 0; i < tamanho; i++) {
                    AVLNode<T> aux = fila.deQueue();
                    if (aux != null) {
                        System.out.print(aux.getInfo() + " ");
                        fila.enQueue(aux.getLeft());
                        fila.enQueue(aux.getRight());
                        if (aux.getLeft() != null || aux.getRight() != null) {
                            nulo = true;
                        }
                    } else {
                        System.out.print("null ");
                        fila.enQueue(null);
                        fila.enQueue(null);
                    }
                }
                System.out.println();
                if(!nulo){
                    break;
                }
            }
        }
        else { 
            System.out.println("Árvore vazia"); }
    }
}