package AVL;
import Fila.Queue;

public class AVLTree <T extends Comparable<T>> {
    private AVLNode<T> root;
    private boolean status;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void insert(T valor){
        if(isEmpty() == true){
            this.root = new AVLNode<T>(valor);
        } else {
            this.root = insertNode(this.root, valor);
            this.status = false;
        }
    }

    private AVLNode<T> insertNode(AVLNode<T> raiz, T valor){
        if(raiz == null){
            raiz = new AVLNode<T>(valor);
            this.status = true;
        }
        else if(raiz.getInfo().compareTo(valor) > 0){
            raiz.setLeft(insertNode(raiz.getLeft(), valor));
            if(this.status == true){
                switch(raiz.getFatBal()) {
                    case 1:
                        raiz.setFatBal(0);
                        this.status = false;
                        break;
                    case 0:
                        raiz.setFatBal(-1);
                        break;
                    case -1:
                        raiz = rotateRight(raiz);
                        break;
                }
            }
        } else {
            raiz.setRight(insertNode(raiz.getRight(), valor));
            if(this.status == true){
                switch(raiz.getFatBal()) {
                    case -1:
                        raiz.setFatBal(0);
                        this.status = false;
                        break;
                    case 0:
                        raiz.setFatBal(1);
                        break;
                    case 1:
                        raiz = rotateLeft(raiz);
                        break;
                }
            }
        }
        return raiz;
    }

    private AVLNode<T> rotateRight(AVLNode<T> a){
        AVLNode<T> b, c;
        b = a.getLeft();
        if(b.getFatBal() == -1){
            a.setLeft(b.getRight());
            b.setRight(a);
            a.setFatBal(0);
            a = b;
        } else {
            c = b.getRight();
            a.setLeft(c.getRight());
            b.setRight(c.getLeft());
            c.setLeft(b);
            c.setRight(a);

            if(c.getFatBal() == -1){
                a.setFatBal(1);
            } else {
                a.setFatBal(0);
            }
            
            if(c.getFatBal() == 1){
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

    private AVLNode<T> rotateLeft(AVLNode<T> a){
        AVLNode<T> b, c;
        b = a.getRight();
        if(b.getFatBal() == 1){
            a.setRight(b.getLeft());
            b.setLeft(a);
            a.setFatBal(0);
            a = b;
        } else {
            c = b.getLeft();
            a.setRight(c.getLeft());
            b.setLeft(c.getRight());
            c.setRight(b);
            c.setLeft(a);

            if(c.getFatBal() == 1){
                a.setFatBal(-1);
            } else {
                a.setFatBal(0);
            }
            
            if(c.getFatBal() == -1){
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

    public T find(T valor){
        if(isEmpty()){
            return null;
        } else {
            return findNode(this.root, valor);
        }
    }

    private T findNode(AVLNode<T> raiz, T valor){
        int resultado = valor.compareTo(raiz.getInfo());
        if(resultado == 0){
            return raiz.getInfo();
        } 
        else if(resultado < 0){
            if(raiz.getLeft() == null){
                return null;
            } else {
                return findNode(raiz.getLeft(), valor);
            }
        } 
        else {
            if(raiz.getRight() == null){
                return null;
            } else {
                return findNode(raiz.getRight(), valor);
            }
        }
    }

    public void emOrdem(){
        if(isEmpty()){
            System.out.println("Árvore vazia!");
        } else {
            passeioEmOrdem(this.root);
        }
    }

    private void passeioEmOrdem(AVLNode<T> raiz){
        if(raiz != null){
            passeioEmOrdem(raiz.getLeft());
            System.out.println(raiz.getInfo());
            passeioEmOrdem(raiz.getRight());
        }
    }

    public void porNivel(){
        if(isEmpty()){
            System.out.println("Árvore vazia!");
        } else {
            passeioPorNivel(this.root);
        }
    }

    private void passeioPorNivel(AVLNode<T> raiz){
        Queue<AVLNode<T>> fila = new Queue<>();
        fila.enQueue(raiz);
        while (fila.isEmpty() == false) {
            int qtd = fila.getQtd();
            boolean nulo = false;
            for (int i = 0; i < qtd; i++) {
                raiz = fila.deQueue();
                if (raiz != null) {
                    System.out.print(raiz.getInfo() + "["+ raiz.getFatBal() +"]" + " ");
                    fila.enQueue(raiz.getLeft());
                    fila.enQueue(raiz.getRight());
                    if (raiz.getLeft() != null || raiz.getRight() != null) {
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

    public void remove(T valor){
        if(isEmpty()){
            System.out.println("Árvore vazia!");
        } else {
            this.root = this.removeNode(this.root, valor);
            this.status = false;
        }
    }

    private AVLNode<T> removeNode(AVLNode<T> raiz, T valor) {
        if (raiz != null) {
            int encontrar = valor.compareTo(raiz.getInfo());

            if (encontrar < 0) {
                raiz.setLeft(removeNode(raiz.getLeft(), valor));
                if (this.status == true) {
                    switch (raiz.getFatBal()) {
                        case -1:
                            raiz.setFatBal(0);
                            break;
                        case 0:
                            raiz.setFatBal(1);
                            this.status = false;
                            break;
                        case 1:
                            AVLNode<T> b = raiz.getRight();
                            if (b.getFatBal() <= 0) {
                                raiz.setRight(b.getLeft());
                                b.setLeft(raiz);
                                if (b.getFatBal() == 0) {
                                    raiz.setFatBal(1);
                                    b.setFatBal(-1);
                                    this.status = false;
                                } else {
                                    raiz.setFatBal(0);
                                    b.setFatBal(0);
                                }
                                raiz = b;
                            } else {
                                raiz = rotateLeft(raiz);
                            }
                            break;
                    }
                }
            }
            else if (encontrar > 0) {
                raiz.setRight(removeNode(raiz.getRight(), valor));
                if (this.status == true) {
                    switch (raiz.getFatBal()) {
                        case 1:
                            raiz.setFatBal(0);
                            break;
                        case 0:
                            raiz.setFatBal(-1);
                            this.status = false;
                            break;
                        case -1:
                            AVLNode<T> b = raiz.getLeft();
                            if (b.getFatBal() <= 0) {
                                raiz.setLeft(b.getRight());
                                b.setRight(raiz);
                                if (b.getFatBal() == 0) {
                                    raiz.setFatBal(-1);
                                    b.setFatBal(1);
                                    this.status = false;
                                } else {
                                    raiz.setFatBal(0);
                                    b.setFatBal(0);
                                }
                                raiz = b;
                            } else {
                                raiz = rotateRight(raiz);
                            }
                            break;
                    }
                }
            } 
            else {
                this.status = true;
                if(raiz.getLeft() == null && raiz.getRight() == null) {
                    raiz = null;
                }
                else if(raiz.getLeft() == null) {
                    raiz = raiz.getRight();
                }
                else if(raiz.getRight() == null) {
                    raiz = raiz.getLeft();
                }  
                else {
                    AVLNode<T> pai, filho;
                    pai = raiz;
                    filho = raiz.getLeft();
                    
                    if(filho.getRight() != null) {
                        while(filho.getRight() != null) {
                            pai = filho;
                            filho = filho.getRight();
                        }
                        pai.setRight(filho.getLeft());
                    }
                    else {
                        pai.setLeft(filho.getLeft());
                    }
                    raiz.setInfo(filho.getInfo());

                    if(pai != raiz){
                        if(pai.getFatBal() == 0 && pai.getRight() == null){
                            pai.setFatBal(-1);
                        }
                        if(pai.getLeft() == null && pai.getRight() == null){
                            pai.setFatBal(0);
                        }
                        if(pai.getLeft() != null && pai.getRight() != null){
                            pai.setFatBal(0);
                        }
                        if(pai.getLeft() == null && pai.getRight() != null){
                            pai.setFatBal(1);
                        }
                    }

                    if (this.status == true) {
                        switch (raiz.getFatBal()) {
                            case -1:
                                if(pai.getLeft() != null && pai.getRight() != null){
                                    raiz.setFatBal(0);
                                }
                                break;
                            case 0:
                                if(pai == raiz){
                                    if(pai.getLeft() == null && pai.getRight() != null){
                                        raiz.setFatBal(1);
                                        this.status = false;
                                    }
                                } else if(pai.getLeft() != null && pai.getRight() != null){
                                    raiz.setFatBal(1);
                                    this.status = false;
                                }
                                break;
                            case 1:
                                AVLNode<T> b = raiz.getRight();
                                if (b == null) {
                                    raiz.setFatBal(0);
                                    this.status = false;
                                }
                                else if (b.getFatBal() >= 0) {
                                    raiz.setRight(b.getLeft());
                                    b.setLeft(raiz);
                                    if (b.getFatBal() == 0) {
                                        raiz.setFatBal(-1);
                                        b.setFatBal(1);
                                        this.status = false;
                                    } else {
                                        raiz.setFatBal(0);
                                        b.setFatBal(0);
                                    }
                                    raiz = b;
                                } else {
                                    raiz = rotateLeft(raiz);
                                }
                                break;
                        }
                    }
                }
            }
        }
        return raiz;
    }
}