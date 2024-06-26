/*
 * filename: computation.h
 * date: 2024/05/01 07:52 
 * author: Jakub Kornel
 * email: kornejak@fel.cvut.cz
*/

#ifndef __COMPUTATION_H__
#define __COMPUTATION_H__

#include <stdbool.h>
#include "messages.h"

// Getters for GUI
double get_range_re_min(void);
double get_range_re_max(void);
double get_range_im_min(void);
double get_range_im_max(void);
double get_c_re(void);
double get_c_im(void);
int get_n(void);

// Setters for GUI
void set_range_re_min(double new_value);
void set_range_re_max(double new_value);
void set_range_im_min(double new_value);
void set_range_im_max(double new_value);
void set_c_re(double new_value);
void set_c_im(double new_value);
void set_n(int new_value);

// Functions for hanling user input
void clean_buffer(void);
void reset_cid(void);

void get_grid_size(int *w, int *h);
void set_grid_size(int w, int h);

bool is_computing(void);
bool is_done(void);
bool is_abort(void);
bool is_background(void);

void abort_comp(void);
void end_computing(void);
void enable_comp(void);
void compute_background(void);

void increase_n(void);
void decrease_n(void);

// Computation functions
void computation_init(void);
void computation_cleanup(void);

bool set_compute(message *msg);
bool compute(message* msg);

void update_image(int w, int h, unsigned char *img);
void update_data(const msg_compute_data *compute_data);

#endif

/* end of computation.h */
