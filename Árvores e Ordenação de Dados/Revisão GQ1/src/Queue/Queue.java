package Queue;

public class Queue<T> {
    private QueueNode<T> inicio;
    private QueueNode<T> fim;
    private int qtd;

    public int getQtd() {
        return qtd;
    }

    public boolean isEmpty(){
        return inicio == null;
    }

    public void enQueue(T valor){
        QueueNode<T> novo = new QueueNode<T>(valor);
        if(isEmpty()){
            inicio = novo;
        } else {
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