package REDBLACK;
import Fila.Queue;

public class RedBlack <T extends Comparable<T>> {
    private boolean RED = true;
    private boolean BLACK = false;
    private RBNode<T> root;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void insert(T valor){
        if(isEmpty() == true){
            this.root = new RBNode<T>(valor);
            this.root.setColor(BLACK);
        } else {
            insertNode(this.root, valor);
            this.root.setColor(BLACK);
        }
    }

    private void insertNode(RBNode<T> raiz, T valor) {
        RBNode<T> P = null;

        while (raiz != null) {
            P = raiz;
            if (valor.compareTo(raiz.getInfo()) < 0) {
                raiz = raiz.getLeft();
            } else {
                raiz = raiz.getRight();
            }
        }

        RBNode<T> K = new RBNode<T>(valor);
        K.setFather(P);
        if (valor.compareTo(P.getInfo()) < 0) {
            P.setLeft(K);
        } else {
            P.setRight(K);
        }

        while (K != root && K.getFather().getColor()) {
            RBNode<T> G = P.getFather();

            if (P == G.getLeft()) {
                RBNode<T> S = G.getRight();
                if (S != null && S.getColor()) {
                    P.setColor(BLACK);
                    S.setColor(BLACK);
                    G.setColor(RED);
                    K = G;
                } else {
                    if (K == P.getRight()) {
                        K = P;
                        rotateLeft(K);
                    }
                    P = K.getFather();
                    G = P.getFather();
                    P.setColor(BLACK);
                    G.setColor(RED);
                    rotateRight(G);
                }
            } else {
                RBNode<T> S = G.getLeft();
                if (S != null && S.getColor()) {
                    P.setColor(BLACK);
                    S.setColor(BLACK);
                    G.setColor(RED);
                    K = G;
                } else {
                    if (K == P.getLeft()) {
                        K = P;
                        rotateRight(K);
                    }
                    P = K.getFather();
                    G = P.getFather();
                    P.setColor(BLACK);
                    G.setColor(RED);
                    rotateLeft(G);
                }
            }
        }
    }

    private void rotateRight(RBNode<T> G) {
        RBNode<T> P = G.getLeft();
        G.setLeft(P.getRight());
        if (P.getRight() != null) {
            P.getRight().setFather(G);
        }
        P.setFather(G.getFather());
    
        if (G.getFather() == null) {
            this.root = P;
        } else if (G == G.getFather().getLeft()) {
            G.getFather().setLeft(P);
        } else {
            G.getFather().setRight(P);
        }
    
        P.setRight(G);
        G.setFather(P);
    }    

    private void rotateLeft(RBNode<T> G) {
        RBNode<T> P = G.getRight();
        G.setRight(P.getLeft());
        if (P.getLeft() != null) {
            P.getLeft().setFather(G);
        }
        P.setFather(G.getFather());
    
        if (G.getFather() == null) {
            this.root = P;
        } else if (G == G.getFather().getLeft()) {
            G.getFather().setLeft(P);
        } else {
            G.getFather().setRight(P);
        }
    
        P.setLeft(G);
        G.setFather(P);
    }

    public void emOrdem(){
        if(isEmpty()){
            System.out.println("Árvore vazia!");
        } else {
            passeioEmOrdem(this.root);
            System.out.println();
        }
    }

    private void passeioEmOrdem(RBNode<T> raiz){
        if(raiz != null){
            passeioEmOrdem(raiz.getLeft());
            if(raiz.getColor() == RED){
                System.out.print(raiz.getInfo() + "[RED]" + " ");
            } else {
                System.out.print(raiz.getInfo() + "[BLACK]" + " ");
            }
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

    private void passeioPorNivel(RBNode<T> raiz){
        Queue<RBNode<T>> fila = new Queue<>();
        fila.enQueue(raiz);
        while (fila.isEmpty() == false) {
            int qtd = fila.getQtd();
            boolean nulo = false;
            for (int i = 0; i < qtd; i++) {
                raiz = fila.deQueue();
                if (raiz != null) {
                    if(raiz.getColor() == RED){
                        System.out.print(raiz.getInfo() + "[RED]" + " ");
                    } else {
                        System.out.print(raiz.getInfo() + "[BLACK]" + " ");
                    }
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

    private RBNode<T> findNode (RBNode<T> r, T value) {
        if (value.compareTo(r.getInfo()) == 0) {
            return r;
        }
        else if (value.compareTo(r.getInfo()) < 0) {
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

    public void remove(T value) {
        if(isEmpty()){
            return;
        } else {
            RBNode<T> raiz = findNode(this.root,value);
            if(raiz == null) return;
            removeNode(raiz);
        }
    }

    private void removeNode(RBNode<T> z) {
        RBNode<T> y = z;
        boolean yCor = y.getColor();
        RBNode<T> x;

        if (z.getLeft() == null) {
            x = z.getRight();
            transplant(z, z.getRight());
        }
        else if (z.getRight() == null) {
            x = z.getLeft();
            transplant(z, z.getLeft());
        } 
        else {
            RBNode<T> menor = z.getRight();
            while (menor.getLeft() != null) {
                menor = menor.getLeft();
            }
            y = menor;
            yCor = y.getColor();
            x = y.getRight();

            if (y != z.getRight()) {
                transplant(y, y.getRight());
                y.setRight(z.getRight());
                y.getRight().setFather(y);
            }

            transplant(z, y);
            y.setLeft(z.getLeft());
            y.getLeft().setFather(y);
            y.setColor(z.getColor());
        }

        if (yCor == BLACK) {
            corrigeRemove(x);
        }
    }

    private void transplant(RBNode<T> z, RBNode<T> x) {
        if (z.getFather() == null) {
            this.root = x;
        } else if (z == z.getFather().getLeft()) {
            z.getFather().setLeft(x);
        } else {
            z.getFather().setRight(x);
        }
        x.setFather(z.getFather());
    }

    private void corrigeRemove(RBNode<T> x) {
        while (x != this.root && (x == null || x.getColor() == BLACK)){
            if (x == x.getFather().getLeft()) {
                RBNode<T> s = x.getFather().getRight();                
                if (s != null && s.getColor() == RED) {
                    s.setColor(BLACK);
                    x.getFather().setColor(RED);
                    rotateLeft(x.getFather());
                    s = x.getFather().getRight();
                }                
                if ((s.getLeft() == null || s.getLeft().getColor() == BLACK) &&
                    (s.getRight() == null || s.getRight().getColor() == BLACK)) {
                    if (s != null) s.setColor(RED);
                    x = x.getFather();
                } else {
                    if (s.getRight() == null || s.getRight().getColor() == BLACK) {
                        if (s.getLeft() != null) s.getLeft().setColor(BLACK);
                        s.setColor(RED);
                        rotateRight(s);
                        s = x.getFather().getRight();
                    }                    
                    if (s != null) {
                        s.setColor(x.getFather().getColor());
                        if (s.getRight() != null) s.getRight().setColor(BLACK);
                    }
                    x.getFather().setColor(BLACK);
                    rotateLeft(x.getFather());
                    x = this.root;
                }
            } else {
                RBNode<T> s = x.getFather().getLeft();
                if (s != null && s.getColor() == RED) {
                    s.setColor(BLACK);
                    x.getFather().setColor(RED);
                    rotateRight(x.getFather());
                    s = x.getFather().getLeft();
                }
                if ((s.getRight() == null || s.getRight().getColor() == BLACK) &&
                    (s.getLeft() == null || s.getLeft().getColor() == BLACK)) {
                    if (s != null) s.setColor(RED);
                    x = x.getFather();
                } else {
                    if (s.getLeft() == null || s.getLeft().getColor() == BLACK) {
                        if (s.getRight() != null) s.getRight().setColor(BLACK);
                        s.setColor(RED);
                        rotateLeft(s);
                        s = x.getFather().getLeft();
                    }
                    if (s != null) {
                        s.setColor(x.getFather().getColor());
                        if (s.getLeft() != null) s.getLeft().setColor(BLACK);
                    }
                    x.getFather().setColor(BLACK);
                    rotateRight(x.getFather());
                    x = this.root;
                }
            }
        }
        
        if (x != null) {
            x.setColor(BLACK);
        }
    }
}