#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        int width;
        int height;
        int x;
        int y;
        Box(int width, int height, int x, int y);
        virtual ~Box();
    protected:
    private:
};

#endif // BOX_H
