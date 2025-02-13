#include <arpa/inet.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <threads.h>

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

      send (client, "Enter two integers:\0", (size_t)20, 0);
      int non_numeric = 0;
      int c = 0;

      int n[2] = {0};
      do
        {
          non_numeric = 0;
          recv (client, buffer, 256, 0);
          *(buffer + strlen(buffer) - 1) = '\0';
          for (char *cur = buffer; *cur; cur++)
            {
              if (!isdigit (*cur))
                {
                  non_numeric = 1;
                }
            }
          if (!non_numeric) {
            char *endptr;
            n[c++] = strtol(buffer, &endptr, 10); // Convert string to int (base 10)

            if (*endptr != '\0') {
              printf("Conversion failed: invalid characters in input\n");
              c--;
            }
          }
        }
      while (non_numeric || c < 2);

      char *sum = (char*)malloc(sizeof(char) * 32);
      snprintf(sum, 32, "sum is: %d", n[0] + n[1]);
      send (client, sum, strlen(sum) + 1, 0);
      return 0;
    }
}
