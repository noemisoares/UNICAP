package AVL;

class AVLNode <T extends Comparable<T>> {
    private AVLNode <T> left;
    private AVLNode <T> right;
    private T info;
    private int fatBal;

    AVLNode(T info){
        this.info = info;
    }

    T getInfo() {
        return this.info;
    }

    void setInfo(T info) {
        this.info = info;
    }

    AVLNode<T> getLeft(){
        return this.left;
    }

    void setLeft(AVLNode<T> left){
        this.left = left;
    }

    AVLNode<T> getRight(){
        return this.right;
    }

    void setRight(AVLNode<T> right){
        this.right = right;
    }

    int getFatBal(){
        return this.fatBal;
    }

    void setFatBal(int fatBal){
        this.fatBal = fatBal;
    }
}