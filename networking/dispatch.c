/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_protocol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:12:32 by scollet           #+#    #+#             */
/*   Updated: 2017/05/03 15:12:33 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//# define PORT somenum;

void  handle_session(int session_fd)
{
    time_t  now = time(0);
    char    buffer[80];
    size_t  length;
    size_t  index;
    ssize_t count;

    if (!(length = strftime(buffer, sizeof(buffer), "%a %b %d %T %Y\r\n", localtime(&now))))
        snprintf(buffer, sizeof(buffer), "Error: buffer overflow\r\n");
    index = 0;
    while (index < length)
    {
        //TODO : find proper method to send a message;
        if (0 > (count = write(session_fd, buffer + index, length - index)))
        {
            if (errno == EINTR) continue;
            fprintf(stderr, "failed to write to socket (errno = %d)", errno);
        }
        else
          index += count;
    }
    return ;
}

void    handle_request(int server_fd)
{
  pid_t   pid;
  int     session_fd;

  for (;;)
  {
    if (0 > (session_fd = accept(server_fd, 0, 0)))
    {
        if (errno == EINTR) continue;
        fprintf(stderr, "failed to accept connection (errno = %d)", errno);
    }
    if (0 > (pid = fork()))
        fprintf(stderr, "failed to create child process (errno = %d)", errno);
    else if (pid == 0)
    {
      close(server_fd);
      handle_session(session_fd);
      close(session_fd);
      _exit(0);
    }
    else
      close(session_fd);
  }
  return ;
}

void    launch_dispatch()
{
  const char      *hostname = 0; /* wildcard */
  const char      *portname = "4242";
  struct addrinfo hints;
  struct addrinfo *res = 0;
  int             err;
  int             server_fd;
  int             reuseaddr;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
  if ((err = getaddrinfo(hostname, portname, &hints, &res)))
    fprintf(stderr, "Dispatch: failed to resolve local socket address (err = %d)", err);
  printf("Dispatch: Test 0\n");
  if (0 > (server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)))
    fprintf(stderr, "%s", strerror(errno));
  reuseaddr = 1;
  printf("Dispatch: Test 1\n");
  if (0 > (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr))))
    fprintf(stderr, "%s", strerror(errno));
  printf("Dispatch: Test 2\n");
  if (0 > (bind(server_fd, res->ai_addr, res->ai_addrlen)))
    fprintf(stderr, "%s", strerror(errno));
  printf("Dispatch: Test 3");
  freeaddrinfo(res);
  if (listen(server_fd, SOMAXCONN))
    fprintf(stderr, "failed to listen for connections (errno = %d)", errno);
  handle_request(server_fd);
  return ;
}

//TURN BACK NOW, NOTHING BUT DEATH AND BROKEN CODE BELOW;

/*void    launch_worker()
{
  const char      *hostname = 0; //wildcard
  const char      *portname = "daytime";
  struct addrinfo hints;
  struct addrinfo *res = 0;
  int             err;
  int             fd;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
  if((err = getaddrinfo(hostname, portname, &hints, &res)))
    die("failed to resolve local socket address (err = %d)", err);
  if (0 > (fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)))
    die("%s", strerror(errno));
  if (0 > (connect(fd, res->ai_addr, res->ai_addrlen))))
    die("%s", strerror(errno));
  freeaddrinfo(res);
  stream_dat();

//  int   fd;

//  if ((fd = socket()))
  set sock;
  bind;
  listen;
  accept;
  connect;
  send partitions of octree;
  verify;
  send current data to master;
  exit;
}

// void    launch_TCP()
// {
//   if (data && data needs to be sent)
//     launch_dispatch();
//   else if (processes are NULL && data needs to be receieved)
//     launch_worker();
//   else
//     idk?
// }





 PSEUDO CODE



init_client()
{
  query server for work;
  if connect
    recieve data
  else
    query server again;
}

init_server()
{
  create and bind socket;
  listen for requests to consume;
  accept client connection;
  send stream;
  iterate through function while frames_left > 0;
  discard socket and free memory;
}




void  listen_TCP()
{

}

void   deploy_TCP()
{
  const char      *hostname = 0; //wildcard
  const char      *portname = "daytime";
  struct addrinfo hints;
  struct addrinfo *res = 0;
  int             err;
  int             fd;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
  if((err = getaddrinfo(hostname, portname, &hints, &res)))
    die("failed to resolve local socket address (err = %d)", err);
  return (res);
  if (0 > (fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol)))
    die("%s",strerror(errno));
  if (0 > (connect(fd,res->ai_addr,res->ai_addrlen))))
    die("%s",strerror(errno));
  freeaddrinfo(res);
}
*/
