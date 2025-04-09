package AVLTree;
import Queue.Queue;

public class AVL <T extends Comparable<T>> {
    private AVLNode<T> root;
    private boolean status;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void insert(T valor){
        if(isEmpty()){
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
        } else if(valor.compareTo(raiz.getInfo()) < 0){
            raiz.setLeft(insertNode(raiz.getLeft(), valor));
                if(this.status == true){
                    switch(raiz.getFatBal()) {
                        case 1:
                            raiz.setFatBal(0);
                            status = false;
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
                            status = false;
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
            c.setRight(a);
            c.setLeft(b);
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
            c.setLeft(a);
            c.setRight(b);
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

    public AVL<T> copiarArvore(){
        AVL<T> nova = new AVL<T>();
        nova.root = copiar(this.root);
        return nova;
    }

    private AVLNode<T> copiar(AVLNode<T> raiz){
        if(raiz == null){
            return null;
        }

        AVLNode<T> novo = new AVLNode<T>(raiz.getInfo());
        novo.setFatBal(raiz.getFatBal());
        novo.setLeft(copiar(raiz.getLeft()));
        novo.setRight(copiar(raiz.getRight()));
        return novo;
    }


    public void esvaziarArvore(){
        if(isEmpty()){
            System.out.println("ja esta vazia");
        } else {
            esvaziar(this.root);
            this.root = null;
        }
    }

    private void esvaziar(AVLNode<T> raiz){
        if(raiz != null){
            esvaziar(raiz.getLeft());
            esvaziar(raiz.getRight());

            raiz.setLeft(null);
            raiz.setRight(null);
        }
    }

    public void desbalanceados(){
        if(isEmpty()){
            System.out.println("Arvore vazia");
        } else {
            nosDesbalanceados(this.root);
        }
    }

    private void nosDesbalanceados(AVLNode<T> raiz){
        if(raiz != null){
            nosDesbalanceados(raiz.getLeft());
            if(raiz.getFatBal() != 0){
                System.out.println(raiz.getInfo() + "[" + raiz.getFatBal() + "]");
            }
            nosDesbalanceados(raiz.getRight());
        }
    }

    public int alturaArvore(){
        if(isEmpty()){
            return 0;
        } else {
            return altura(this.root);
        }
    }

    private int altura(AVLNode<T> raiz){
        int qtd = -1;

        while(raiz != null){
            if(raiz.getFatBal() < 0){
                raiz = raiz.getLeft();
            } else {
                raiz = raiz.getRight();
            }
            qtd++;
        }

        return qtd;
    }

    public int alturaNo(T valor){
        if(isEmpty()){
            return 0;
        } else {
            return noAltura(this.root, valor);
        }
    }
    
    private int noAltura(AVLNode<T> raiz, T valor){
        while(valor.compareTo(raiz.getInfo()) != 0){
            if(valor.compareTo(raiz.getInfo()) < 0){
                raiz = raiz.getLeft();
            } else {
                raiz = raiz.getRight();
            }
        }

        int qtd = -1;

        while(raiz != null){
            if(raiz.getFatBal() < 0){
                raiz = raiz.getLeft();
            } else {
                raiz = raiz.getRight();
            }
            qtd++;
        }
        return qtd;
    }

    public boolean compararArvores(AVL<T> arvore){
        return comparar(this.root, arvore.root);
    }

    private boolean comparar(AVLNode<T> raiz1, AVLNode<T> raiz2){
        if(raiz1 == null && raiz2 == null){
            return true;
        }
        if(raiz1 == null || raiz2 == null){
            return false;
        }
        if(!raiz1.getInfo().equals(raiz2.getInfo())){
            return false;
        }
        return comparar(raiz1.getLeft(), raiz2.getLeft()) && comparar(raiz1.getRight(), raiz2.getRight());
    }
}
