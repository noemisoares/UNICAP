package REDBLACK;

class RBNode <T extends Comparable<T>> {
    private RBNode <T> left;
    private RBNode <T> right;
    private RBNode <T> father;
    private T info;
    private boolean color;

    RBNode(T info){
        this.info = info;
        this.color = true;
    }

    boolean getColor() {
        return this.color;
    }

    void setColor(boolean color) {
        this.color = color;
    }

    T getInfo() {
        return this.info;
    }

    void setInfo(T info) {
        this.info = info;
    }

    RBNode<T> getFather(){
        return this.father;
    }

    void setFather(RBNode<T> father){
        this.father = father;
    }

    RBNode<T> getLeft(){
        return this.left;
    }

    void setLeft(RBNode<T> left){
        this.left = left;
    }

    RBNode<T> getRight(){
        return this.right;
    }

    void setRight(RBNode<T> right){
        this.right = right;
    }
}