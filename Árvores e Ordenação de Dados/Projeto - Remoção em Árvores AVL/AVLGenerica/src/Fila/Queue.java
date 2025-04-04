package Fila;

public class Queue<T>{
    private QueueNode<T> inicio;
    private QueueNode<T> fim;
    private int qtd;

    public Queue(){
        this.inicio = null;
        this.fim = null;
        this.qtd = 0;
    }

    public int getQtd(){
        return this.qtd;
    }

    public boolean isEmpty(){
        return this.inicio == null;
    }

    public void enQueue(T info){
        QueueNode<T> novo = new QueueNode<>(info);
        if(isEmpty()){
            inicio = novo;
        }
        else {
            fim.setProx(novo);
        }
        fim = novo;
        qtd++;
    }

    public T deQueue(){
        T info = inicio.getInfo();
        inicio = inicio.getProx();  
        if(inicio == null){
            fim = null;
        }
        qtd--;
        return info;
    }
}