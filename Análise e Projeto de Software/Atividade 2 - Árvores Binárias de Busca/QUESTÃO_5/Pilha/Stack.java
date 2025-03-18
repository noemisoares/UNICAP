package Pilha;

public class Stack<T> {
    private StackNode<T> topo;

    public Stack() {
        this.topo = null;
    }

    public boolean isEmpty() {
        return topo == null;
    }

    public void push(T valor) {
        StackNode<T> novoNo = new StackNode<>(valor);
        novoNo.setProx(topo);
        topo = novoNo;
    }

    public T pop() {
        T valor = topo.getInfo();
        topo = topo.getProx();
        return valor;
    }

    public T peek() {
        return topo.getInfo();
    }
}