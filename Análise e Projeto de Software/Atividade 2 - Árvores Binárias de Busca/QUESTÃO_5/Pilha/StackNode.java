package Pilha;

public class StackNode<T> {
    private T info;
    private StackNode<T> prox;

    public StackNode(T info) {
        this.info = info;
        this.prox = null;
    }

    public T getInfo() {
        return info;
    }

    public StackNode<T> getProx() {
        return prox;
    }

    public void setProx(StackNode<T> prox) {
        this.prox = prox;
    }
}