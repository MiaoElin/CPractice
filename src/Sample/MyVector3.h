#ifndef MyVector3_H
#define MyVector3_H

typedef struct MyVector3 {
    float x;
    float y;
    float z;
} MyVector3;

MyVector3 NewVector3(float x, float y, float z) {
    MyVector3 vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

MyVector3 MyVector3Add(MyVector3 v1, MyVector3 v2) {
    MyVector3 v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    return v;
}
#endif
