fun vector(x, y) {
    fun handler(f) {
        return f(x, y);
    }
    return handler;
}

fun getX(v) {
    fun getIt(x, y) {
        return x;
    }
    return v(getIt);
}

fun getY(v) {
    fun getIt(x, y) {
        return y;
    }
    return v(getIt);
}

fun add(v1, v2) {
    var x = getX(v1) + getX(v2);
    var y = getY(v1) + getY(v2);
    return vector(x, y);
}

var v1 = vector(1, 2);
var v2 = vector(3, 4);
var v3 = add(v1, v2);
print getX(v3);
print getY(v3);
