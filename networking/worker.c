/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:47:57 by scollet           #+#    #+#             */
/*   Updated: 2017/05/05 18:48:03 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void  recieve_work(int fd)
{
  char      buffer[256];
  ssize_t   count;

  for (;;)
  {
      if (0 > (count = read(fd, buffer, sizeof(buffer))))
      {
        if (errno != EINTR) fprintf(stderr, "%s", strerror(errno));
      }
      else if (count == 0)
        break;
      else
        write(STDOUT_FILENO, buffer, count);
  }
  close(fd);
}

void  launch_worker()
{
  const char      *hostname = 0; /* localhost */
  const char      *portname = "4242";
  struct addrinfo hints;
  struct addrinfo *res = 0;
  int             err;
  int             fd;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;
  hints.ai_flags = AI_ADDRCONFIG;
  if ((err = getaddrinfo(hostname, portname, &hints, &res)))
    fprintf(stderr, "failed to resolve remote socket address (err=%d)", err);
  if (0 > (fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)))
    fprintf(stderr, "%s", strerror(errno));
  if (0 > (connect(fd,res->ai_addr, res->ai_addrlen)))
    fprintf(stderr, "%s", strerror(errno));
  freeaddrinfo(res);
  recieve_work(fd);
}
