struct complex  //creating a structure of type complex
{
    float ip,rp;
};
struct complex addComplex(struct complex x, struct complex y)   //addition of 2 complex numbers
{
    struct complex z;
    z.rp=x.rp+y.rp;
    z.ip=x.ip+y.ip;
    return z;
}
struct complex subComplex(struct complex x, struct complex y)   //subtraction of 2 complex numbers
{
    struct complex z;
    z.rp=x.rp-y.rp;
    z.ip=x.ip-y.ip;
    return z;
}
struct complex mulComplex(struct complex x,struct complex y)    //multiplication of 2 complex numbers
{
    struct complex z;
    z.rp=(x.rp*y.rp)-(x.ip*y.ip);
    z.ip=(x.rp*y.ip)+(x.ip*y.rp);
    return z;
}
struct complex divComplex(struct complex x, struct complex y)   //division of 2 complex numbers
{
    struct complex z;
    float d=((y.rp)*(y.rp))+((y.ip)*(y.ip));
    z.rp=(float)((x.rp*y.rp)+(x.ip*y.ip))/d;
    z.ip=(float)((x.rp*y.rp)-(x.ip*y.ip))/d;
    return z;
}

