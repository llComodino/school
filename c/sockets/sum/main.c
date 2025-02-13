#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int
main (int argc, char **argv)
{
  int server_fd = socket (AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in saddr
      = { .sin_family = AF_INET,
          .sin_port = htons (8080),
          (struct in_addr){ .s_addr = htonl (INADDR_LOOPBACK) } };

  if (bind (server_fd, (struct sockaddr *)&saddr, sizeof (saddr)) < 0)
    {
      perror (strerror (errno));
      exit (2);
    }

  listen (server_fd, 1);
  puts ("Server Listening...");

  struct sockaddr_in caddr
      = { .sin_family = AF_INET,
          .sin_port = htons (8080),
          .sin_addr = (struct in_addr){ .s_addr = htonl (INADDR_ANY) } };

  int client = 0;
  socklen_t len = sizeof (caddr);
  if ((client = accept (server_fd, (struct sockaddr *)&caddr, &len)) < 0)
    {
      perror (strerror (errno));
      exit (2);
    }
  else
    {
      char *buffer = (char *)malloc (sizeof (char) * 256);

      while (recv (client, buffer, 256, 0))
        {
          printf ("received: %s\n", buffer);
        }
    }

  send (client, "connected\0", 10, 0);
  return 0;
}
