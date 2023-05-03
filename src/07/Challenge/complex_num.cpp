#include "complex_num.h"

complex_num::complex_num(double r, double i)
{
    // Write your code here
    mReal = r;
    mImaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here

    z.mReal = mReal + w.mReal;
    z.mImaginary = mImaginary + z.mImaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z.mReal = mReal - w.mReal;
    z.mImaginary = mImaginary - z.mImaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here

    z.mReal = (mReal * w.mReal) - (mImaginary * w.mImaginary);
    z.mImaginary = (mReal * w.mImaginary) + (mImaginary * w.mReal);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    double newReal = ((mReal * w.mReal) + (mImaginary * w.mImaginary)) / ((w.mReal*w.mReal) + (w.mImaginary*w.mImaginary));
    double newImaginary = ((mImaginary * w.mReal) - (mReal * w.mImaginary)) / ((w.mReal*w.mReal) + (w.mImaginary*w.mImaginary));

    z.mReal = newReal;
    z.mImaginary = newImaginary;
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    os << mReal;

    if (mImaginary >= 0.0){
        os << " + " << mImaginary << "i";
    } else {
        os << " - " << (mImaginary*-1) << "i";
    }
}