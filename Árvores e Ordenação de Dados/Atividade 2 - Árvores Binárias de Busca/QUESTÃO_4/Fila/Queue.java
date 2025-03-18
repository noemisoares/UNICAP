package Fila;

public class Queue<T> {
    private QueueNode<T> atual;
    private QueueNode<T> ant;

    public Queue() {
        this.atual = null;
        this.ant = null;
    }

    public boolean isEmpty() {
        return atual == null;
    }

    public void enQueue(T value) {
        QueueNode<T> newNode = new QueueNode<>(value);
        if (isEmpty()) {
            atual = newNode;
        } else {
            ant.setProx(newNode);
        }
        ant = newNode;
    }

    public T deQueue() {
        T value = atual.getInfo();
        atual = atual.getProx();
        if (atual == null) {
            ant = null;
        }
        return value;
    }
}