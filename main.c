#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct      s_mat_graph
{
    unsigned long   size;
    char            **matrix;
}                   t_mat_graph;

void        del_mat_graph(t_mat_graph *graph)
{
    unsigned long i;

    if (graph)
    {
        i = 0;
        if (graph->matrix)
        {
            while (i < graph->size)
            {
                if (graph[i])
                    free(graph[i]);
                ++i;
            }
            free(graph->matrix);
            graph->matrix = NULL;
        }
        free(graph);
        graph = NULL;
    }
}

void	ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
        ((char*)s)[i++] = 0;
}

static void        *init_matrix(t_mat_graph *graph)
{
    unsigned long   rowlen;
    unsigned long   i;

    i = 0;
    rowlen = ((graph->size / sizeof(char)) + 1);
    while (i < graph->size)
    {
        if (!(graph->matrix[i] = (char*)malloc(sizeof(char) * (rowlen + 1))))
        {
            del_mat_graph(graph);
            break;
        }
        ft_bzero(graph->matrix[i], rowlen);
        ++i;
    }
}

t_mat_graph *new_mat_graph(unsigned long size)
{
    t_mat_graph     *graph;

    graph = NULL;
    if (size > 0)
    {
        if ((graph = (t_mat_graph *)malloc(sizeof(t_mat_graph))))
        {
            graph->size = size;
            graph->matrix = NULL;
            if ((graph->matrix = (char**)malloc(sizeof(char*) * (size))))
				init_matrix(graph);
            else
                del_mat_graph(graph);
        }
    }
    return (graph);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}