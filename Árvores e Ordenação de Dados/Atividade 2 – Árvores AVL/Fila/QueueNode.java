package Fila;

class QueueNode <T> {
    private QueueNode<T> prox;
    private T info;

    QueueNode(T info){
        this.prox = null;
        this.info = info;
    }

    QueueNode<T> getProx(){
        return this.prox;
    }

    void setProx(QueueNode<T> prox){
        this.prox = prox;
    }

    T getInfo(){
        return this.info;
    }

    void setInfo(T info){
        this.info = info;
    }
}