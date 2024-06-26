/*
 * filename: event_queue.c
 * date: 2024/04/27 15:07 
 * author: Jakub Kornel
 * email: kornejak@fel.cvut.cz
 * inspired by: Jan Faigl
*/

#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#include "event_queue.h"

#ifndef QUEUE_CAPACITY
#define QUEUE_CAPACITY 32
#endif

typedef struct {
  event queue[QUEUE_CAPACITY];
  int in;
  int out;
  bool quit;
  pthread_mutex_t mtx;
  pthread_cond_t cond;

} queue;

static queue q = {
  .in = 0,
  .out = 0
};

void queue_init(void)
{
  pthread_mutex_init(&q.mtx, NULL); // initialize mutex
  pthread_cond_init(&q.cond, NULL); //initialize condition
}

void queue_cleanup(void)
{
  while (q.in != q.out) {
    event ev = queue_pop();
    if (ev.data.msg)
      free(ev.data.msg);
  }
}

event queue_pop(void)
{
  event ev = { .type = EV_TYPE_NUM };
  pthread_mutex_lock(&(q.mtx));

  while (!q.quit && q.in == q.out)
    pthread_cond_wait(&(q.cond), &(q.mtx));

  if (q.in != q.out) {
    ev = q.queue[q.out];
    q.out = (q.out + 1) % QUEUE_CAPACITY;
    pthread_cond_broadcast(&(q.cond));
  }
  pthread_mutex_unlock(&(q.mtx));
  return ev;
}

void queue_push(event ev)
{
  pthread_mutex_lock(&(q.mtx));
  while( (q.in + 1) % QUEUE_CAPACITY == q.out)
    pthread_cond_wait(&(q.cond), &(q.mtx));
  
  q.queue[q.in] = ev;
  q.in = (q.in + 1) % QUEUE_CAPACITY;
  pthread_cond_broadcast(&(q.cond));
  pthread_mutex_unlock(&(q.mtx));
}

bool is_quit(void)
{
  bool quit;
  pthread_mutex_lock(&(q.mtx));
  quit = q.quit;
  pthread_mutex_unlock(&(q.mtx));
  return quit;
}

void set_quit(void)
{
  pthread_mutex_lock(&(q.mtx));
  q.quit = true;
  pthread_mutex_unlock(&(q.mtx));
}
