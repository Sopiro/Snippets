'use strict'

function map(v, a, b, min, max)
{
    const per = v / (b - a);
    return lerp(min, max, per);
}

function lerp(a, b, per)
{
    return a + (b - a) * per;
}

function clamp(v, min, max)
{
    if (v < min) return min;
    else if (v >= max) return max;
    else return v;
}

// Return line intersection
function getIntersect(x1, y1, x2, y2, x3, y3, x4, y4)
{
    let x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    let y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    return { x: x, y: y };
}