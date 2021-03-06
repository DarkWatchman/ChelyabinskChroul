#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "TXLib.h"
#include "AABB.hpp"

class Platform
{
private:
    AABB fixture;
    HDC sprite;
public:
    // всякие конструкторы, деструкторы и прочая шелуха
    Platform(AABB _fixture, HDC _sprite);
    ~Platform();
    Platform(const Platform& r);
    // этот вроде бы не нужный
    Platform& operator= (const Platform& r);
    // нормальные мужыцкие методы для мужиков
    inline AABB get_fixture() { return fixture; };
    void draw();
};

Platform::Platform(AABB _fixture, HDC _sprite) :
    fixture(_fixture), sprite(_sprite)
{
    assert(sprite != nullptr);
}

Platform::~Platform()
{
    txDeleteDC(sprite);
}

//
// TODO: проверить, дабловые ли здесь аргументы или интовые
//

Platform::Platform(const Platform& r) :
    fixture(r.fixture),
    sprite(txCreateCompatibleDC(fixture.maximum.x, fixture.minimum.y))
{
    txBitBlt(sprite, 0, 0, 0, 0, r.sprite);
}

Platform& Platform::operator= (const Platform& r)
{
    this->fixture = r.fixture;
    this->sprite = r.sprite;
    return *this;
}

void Platform::draw()
{
    Win32::TransparentBlt(txDC(), static_cast < int > (fixture.minimum.x),
    static_cast < int > (fixture.minimum.y), 0, 0, sprite, 0, 0,
    static_cast < int > (fixture.maximum.x - fixture.minimum.x),
    static_cast < int > (fixture.maximum.y - fixture.minimum.y), TX_BLACK);
}
#endif // __PLATFORM_H__
