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
                if (graph->matrix[i])
                    free(graph->matrix[i]);
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

static void        init_matrix(t_mat_graph *graph)
{
    unsigned long   rowlen;
    unsigned long   i;

    i = 0;
    rowlen = ((graph->size / CHAR_BIT) + 1);
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

void		print_bits(char b)
{
	char i;

	i = 0;
	while (i < CHAR_BIT)
	{
		printf("%d ", !!((b << i) & 0x80));
		++i;
	}
}

void		print_matrix(t_mat_graph *graph)
{
	unsigned long rowlen;
	unsigned int i;
	unsigned int e;

	i = 0;
	rowlen = ((graph->size / CHAR_BIT) + 1);
	printf("--  ");
	e = 0;
	while (e < (rowlen * CHAR_BIT))
	{
		printf("%d ", (e % CHAR_BIT));
		++e;
	}
	printf("\n");
	while (i < graph->size)
	{
		e = 0;
		printf("%d : ", i);
		while (e < rowlen)
		{
			print_bits(graph->matrix[i][e]);
			++e;
		}
		printf("\n");
		++i;
	}
}

void	set_link(t_mat_graph *graph, unsigned int src, unsigned int dst, char
oriented)
{
	unsigned char valmod;

	valmod = (dst % CHAR_BIT);
	printf("dd: %d\n", (dst / CHAR_BIT));
	if (valmod)
		graph->matrix[src][dst / CHAR_BIT] |= 1 << (CHAR_BIT - (valmod));
	else if ((dst / CHAR_BIT) == 0)
		graph->matrix[src][(dst / CHAR_BIT)] |= 1 << CHAR_BIT - 1;
	else
		graph->matrix[src][((dst / CHAR_BIT) - 1)] |= 1;
	if (!oriented)
		set_link(graph, dst, src, 1);
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
	t_mat_graph *graph;

	graph = new_mat_graph(10); 
//	set_link(graph, 1, 2, 1);
	set_link(graph, 8, 0, 1);
//	set_link(graph, 7, 1, 1);
//	set_link(graph, 7, 2, 1);
//	set_link(graph, 7, 3, 1);
//	set_link(graph, 7, 4, 1);
//	set_link(graph, 7, 5, 1);
//	set_link(graph, 7, 6, 1);
	set_link(graph, 8, 7, 1);
	set_link(graph, 8, 8, 1);
//	set_link(graph, 8, 9, 1);
	set_link(graph, 8, 15, 1);
	set_link(graph, 8, 16, 1);
//	set_link(graph, 7, 9, 1);
//	set_link(graph, 3, 1, 1);
	print_matrix(graph);
	del_mat_graph(graph);
    return 0;
}
