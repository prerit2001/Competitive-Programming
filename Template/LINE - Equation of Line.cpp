// equation = ax + by + c = 0
struct line{
    ll a, b, c;
    void build(pii p1, pii p2){
        a = p1.S - p2.S;
        b = p2.F - p1.F;
        c = - b * p1.S - a * p1.F;
        ll p = __gcd(abs(a), abs(b));
        p = __gcd(p, abs(c));
        a /= p, b /= p, c /= p;
        if(a < 0){
            a *= -1;
            b *= -1;
            c *= -1;
        }else if(a == 0 && b < 0){
            a *= -1;
            b *= -1;
            c *= -1;
        }
    }
    bool check(pii p){
        return (((p.S * b) + (p.F * a) + c) == 0);
    }
    pair<pll, ll> point(){
        return mp(mp(a, b), c);
    }
};