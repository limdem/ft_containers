#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

void  execute_ft_binary()
{
  char ft_bin[] = "ft_exec";
  char* args_ft[] = {ft_bin, NULL};
  FILE *ft_output_fd;

  ft_output_fd = fopen("ft_output.txt", "w+");
  if (!ft_output_fd)
  {
    std::cerr << "fopen failed" << std::endl;
    exit(1);
  }
  if (dup2(fileno(ft_output_fd), STDOUT_FILENO) == -1)
  {
    std::cerr << "fopen failed" << std::endl;
    fclose(ft_output_fd);
    exit(1);
  };
  fclose(ft_output_fd);
  execve(args_ft[0], args_ft, NULL);
  std::cout << "FT_EXEC FAILED" << std::endl;
  exit(1);  
}

void  execute_stl_binary()
{
  char stl_bin[] = "stl_exec";
  char* args_stl[] = {stl_bin, NULL};
  FILE *stl_output_fd;

  stl_output_fd = fopen("stl_output.txt", "w+");
  if (!stl_output_fd)
  {
    std::cerr << "fopen failed" << std::endl;
    exit(1);
  }
  if (dup2(fileno(stl_output_fd), STDOUT_FILENO) == -1)
  {
    std::cerr << "fopen failed" << std::endl;
    fclose(stl_output_fd);
    exit(1);
  };
  fclose(stl_output_fd);
  execve(args_stl[0], args_stl, NULL);
  exit(1);
}

int execute_binaries()
{
    int pid1;
    int pid2;
    int status1;
    int status2;

    pid1 = fork();
    if (pid1 == -1)
    {
      std::cerr << "fork 1 failed" << std::endl;
      return 1;
    }
    if (!pid1)
      execute_ft_binary();
    pid2 = fork();
    if (pid2 == -1)
    {
      std::cerr << "fork 2 failed" << std::endl;
      return 1;
    }
    if (!pid2)
     execute_stl_binary();
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    if (WEXITSTATUS(status1) != 0 || WEXITSTATUS(status2) != 0)
      return 1;
    return 0;
}

int compare_outputs()
{
  std::ifstream ft_output_f;
  std::ifstream stl_output_f;
  char  c_ft;
  char  c_stl;
  
  ft_output_f.open("ft_output.txt");
  if (!ft_output_f.is_open())
  {
    std::cerr << "open failed" << std::endl;
    return 1;
  }
  stl_output_f.open("stl_output.txt");
  if (!stl_output_f.is_open())
  {
    std::cerr << "open failed" << std::endl;
    ft_output_f.close();
    return 1;   
  }
  while (ft_output_f.get(c_ft) && stl_output_f.get(c_stl))
  {
    if (c_ft != c_stl)
    {
      std::cout << "KO" << std::endl;
      ft_output_f.close();
      stl_output_f.close();
      return 2;
    }
  }
  ft_output_f.close();
  stl_output_f.close();
  std::cout << "OK" << std::endl;
  return 0;
}

int compare_performances()
{
  std::ifstream ft_perf_f;
  std::ifstream stl_perf_f;
  std::string line_ft;
  std::string line_stl;
  int ft_time;
  int  stl_time;

  ft_perf_f.open("ft_perf.txt");
  if (!ft_perf_f.is_open())
  {
    std::cerr << "open failed" << std::endl;
    return 1;
  }
  stl_perf_f.open("stl_perf.txt");
  if (!stl_perf_f.is_open())
  {
    std::cerr << "open failed" << std::endl;
    ft_perf_f.close();
    return 1;
  }
  while (std::getline(ft_perf_f, line_ft) && std::getline(stl_perf_f, line_stl))
  {
    std::istringstream  iss_ft(line_ft);
    iss_ft >> ft_time;
    std::istringstream iss_stl(line_stl);
    iss_stl >> stl_time;
    if (stl_time == 0)
      stl_time++;
    if (ft_time > stl_time * 20)
    {
      std::cout << "KO" << std::endl;
      ft_perf_f.close();
      stl_perf_f.close();
      return 1;
    }   
  }
  std::cout << "OK" << std::endl;
  ft_perf_f.close();
  stl_perf_f.close();
  return 0;
}

int main()
{
  int ret;
  if (execute_binaries())
  {
    std::cerr << "execute_binaries failed" << std::endl;
    return 1;
  }
  std::cout << "Compare outputs..." << std::endl;
  ret = compare_outputs();
  if (ret == 1)
  {
    std::cerr << "compare_outputs failed" << std::endl;
    return 1;
  }
  if (ret == 2)
    return 0;
  std::cout << "Compare performances..." << std::endl;
  compare_performances();

  return 0;
}

