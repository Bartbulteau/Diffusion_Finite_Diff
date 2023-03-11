#ifndef PARAMS_HPP
#define PARAMS_HPP

#define L 200
#define DELTA_T 20

#define D 0.1

#define ALPHA float(D*L*L)/float(4*D*L*L+DELTA_T)
#define BETA float(DELTA_T)/float(4*D*L*L+DELTA_T)

#define N 3000

#define FRAME_RATE 30
#define H_PARAM float(1500)/float(L)

#endif