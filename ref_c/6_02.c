struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
} screen;

void func1(struct rect);
void func2(struct rect *);

int main(void)
{
    func1(screen);
    func2(&screen);

    return 0;
}

void func1(struct rect r)
{
    r.pt1;
    r.pt2;
}

void func2(struct rect *r)
{
    r->pt1;
    r->pt2;
}
