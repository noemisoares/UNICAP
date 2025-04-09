package ABBTree;
import Queue.Queue;

public class ABB <T extends Comparable<T>>{
    private ABBNode<T> root;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void insert(T valor){
        if(isEmpty()){
            this.root = new ABBNode<T>(valor);
        } else {
            insertNode(this.root, valor);
        }
    }

    private void insertNode(ABBNode<T> raiz, T valor){
        if(raiz != null){
            if(valor.compareTo(raiz.getInfo()) < 0){
                if(raiz.getLeft() != null){
                    insertNode(raiz.getLeft(), valor);
                } else {
                    ABBNode<T> novo = new ABBNode<T>(valor);
                    raiz.setLeft(novo);
                }
            } else {
                if(raiz.getRight() != null){
                    insertNode(raiz.getRight(), valor);
                } else {
                    ABBNode<T> novo = new ABBNode<T>(valor);
                    raiz.setRight(novo);
                }
            }
        }
    }

    public T find(T valor){
        if(isEmpty()){
            return null;
        } else {
            return findNode(this.root, valor);
        }
    }

    private T findNode(ABBNode<T> raiz, T valor){
        if(valor.compareTo(raiz.getInfo()) == 0){
            return raiz.getInfo();
        }  else if(valor.compareTo(raiz.getInfo()) < 0){
            if(raiz.getLeft() == null){
                return null;
            } else {
                return findNode(raiz.getLeft(), valor);
            }
        } else {
            if(raiz.getRight() == null){
                return null;
            } else {
                return findNode(raiz.getRight(), valor);
            }
        }
    }

    public void emOrdem(){
        if(isEmpty()){
            System.out.println("arvore vazia");
        } else {
            passeioEmOrdem(this.root);
        }
    }

    public void passeioEmOrdem(ABBNode<T> raiz){
        if(raiz != null){
            passeioEmOrdem(raiz.getLeft());
            System.out.println(raiz.getInfo());
            passeioEmOrdem(raiz.getRight());
        }
    }

    private ABBNode<T> copia(ABBNode<T> raiz) {
        if (raiz == null) {
            return null;
        }
    
        ABBNode<T> novo = new ABBNode<>(raiz.getInfo());
        novo.setLeft(copia(raiz.getLeft()));
        novo.setRight(copia(raiz.getRight()));
        return novo;
    }
    
    public ABB<T> copiarArvore() {
        ABB<T> novaArvore = new ABB<>();
        novaArvore.root = copia(this.root);
        return novaArvore;
    }

    public int nos(){
        if(isEmpty()){
            return 0;
        } else {
            return contarNos(this.root);
        }
    }

    private int contarNos(ABBNode<T> raiz){
        if(raiz == null){
            return 0;
        }
        return 1 + contarNos(raiz.getLeft()) + contarNos(raiz.getRight());
    }

    public int folhas(){
        if(isEmpty()){
            return 0;
        } else {
            return contarFolhas(this.root);
        }
    }

    private int contarFolhas(ABBNode<T> raiz){
        if(raiz == null){
            return 0;
        }
        if(raiz.getLeft() == null && raiz.getRight() == null){
            return 1;
        }
        return contarFolhas(raiz.getLeft()) + contarFolhas(raiz.getRight());
    }

    public int naoTerminais(){
        if(isEmpty()){
            return 0;
        } else {
            return contarNaoTerminais(this.root);
        }
    }

    private int contarNaoTerminais(ABBNode<T> raiz){
        if(raiz == null){
            return 0;
        }
        if(raiz.getLeft() == null && raiz.getRight() == null){
            return 0;
        }
        return 1 + contarNaoTerminais(raiz.getLeft()) + contarNaoTerminais(raiz.getRight());
    }

    public int encontrarRepetidos(T valor){
        if (isEmpty()) {
            return 0;
        } else {
            return valoresRepetidos(this.root, valor);
        }
    }

    private int valoresRepetidos(ABBNode<T> raiz, T valor){
        if (raiz == null) {
            return 0;
        }
        int k = 0;
        if(valor.compareTo(raiz.getInfo()) == 0){
            k = 1;
        }
        return k + valoresRepetidos(raiz.getLeft(), valor) + valoresRepetidos(raiz.getRight(), valor);
    }

    public int soma(){
        if(isEmpty()){
            return 0;
        } else {
            return somar(this.root);
        }
    }

    private int somar(ABBNode<T> raiz){
        if(raiz == null){
            return 0;
        }
    
        int valor = (Integer) raiz.getInfo();
        return valor + somar(raiz.getLeft()) + somar(raiz.getRight());
    }

    public int multiplica(){
        if(isEmpty()){
            return 0;
        } else {
            return multiplicar(this.root);
        }
    }

    private int multiplicar(ABBNode<T> raiz){
        if(raiz == null){
            return 1;
        }
    
        int valor = (Integer) raiz.getInfo();
        return valor * multiplicar(raiz.getLeft()) * multiplicar(raiz.getRight());
    }

    public void esvaziarArvore(){
        if(isEmpty()){
            System.out.println("Ja se encontra vazia");
        } else {
            esvaziar(this.root);
            this.root = null;
        }
    }

    private void esvaziar(ABBNode<T> raiz){
        if(raiz != null){
            esvaziar(raiz.getLeft());
            esvaziar(raiz.getRight());

            raiz.setLeft(null);
            raiz.setRight(null);
        }
    }

    public int alturaArvore(){
        if(isEmpty()){
            return 0;
        } else {
            return altura(this.root);
        }
    }

    private int altura(ABBNode<T> raiz){
        Queue<ABBNode<T>> fila = new Queue<>();
        fila.enQueue(raiz);
        int alt = 0;
        while (fila.isEmpty() == false) {
            int qtd = fila.getQtd();
            boolean nulo = false;
            for (int i = 0; i < qtd; i++) {
                raiz = fila.deQueue();
                if (raiz != null) {
                    fila.enQueue(raiz.getLeft());
                    fila.enQueue(raiz.getRight());
                    if (raiz.getLeft() != null || raiz.getRight() != null) {
                        nulo = true;
                    }
                } else {
                    fila.enQueue(null);
                    fila.enQueue(null);
                }
            }
            alt++;
            if(!nulo){
                break;
            }
        }
        return alt - 1;
    }
}