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

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

int has_link(t_mat_graph *graph, unsigned int src, unsigned int dst)
{
	unsigned char valmod;
	int byte;

	valmod = (dst % CHAR_BIT);
	if (valmod)
	{
		byte = graph->matrix[src][dst / CHAR_BIT];
		printf("byteindex1: %d\n", (dst / CHAR_BIT));
	}
	else if ((dst / CHAR_BIT) == 0)
	{
		byte = graph->matrix[src][(dst / CHAR_BIT)];
		printf("byteindex2: %d\n", ((dst / CHAR_BIT)));
	}
	else
	{
		byte = graph->matrix[src][((dst / CHAR_BIT) - 1)];
		printf("byteindex3: %d\n", ((dst / CHAR_BIT)  - 1));
	}
	print_bits(byte);
	printf("\nvalmod: %d\n", valmod);
	printf("bit value: %d\n", !!((byte << (valmod) & 0x80)));
}

void	set_link(t_mat_graph *graph, unsigned int src, unsigned int dst, char
oriented)
{
	unsigned char valmod;

	valmod = (dst % CHAR_BIT);
	if (valmod)
		graph->matrix[src][dst / CHAR_BIT] |= 1 << (CHAR_BIT - (valmod));
	else
		graph->matrix[src][(dst / CHAR_BIT)] |= (1 << (CHAR_BIT - 1));
//	else
//		graph->matrix[src][((dst / CHAR_BIT) - 1)] |= 1;
	if (!oriented)
		set_link(graph, dst, src, 1);
}

void	unset_link(t_mat_graph *graph, unsigned int src, unsigned int dst, char
oriented)
{
	unsigned char valmod;

	valmod = (dst % CHAR_BIT);
	if (valmod)
		graph->matrix[src][dst / CHAR_BIT] &= ~(1 << (CHAR_BIT - (valmod)));
	else if ((dst / CHAR_BIT) == 0)
		graph->matrix[src][(dst / CHAR_BIT)] &= ~(1 << (CHAR_BIT - 1));
	else
		graph->matrix[src][((dst / CHAR_BIT) - 1)] &= ~(1);
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

//int minDistance(t_mat_graph *graph, int dist[], char sptSet[])
//{
//	int min = INT_MAX;
//	int min_index;
//
//	for (int v = 0; v < graph->size; v++)
//	{
//		if (sptSet[v] == 0 && dist[v] <= min)
//		{
//			min = dist[v];
//			min_index = v;
//		}
//	}
//	return (min_index);
//}

//void dijkstra(t_mat_graph *graph, unsigned int src, unsigned int dst)
//{
//	int		dist[graph->size];
//	int		u;
//	char	sptSet[graph->size];
//
//	for (int i = 0; i < graph->size; i++)
//	{
//		dist[i] = INT_MAX;
//		sptSet[i] = 0;
//	}
//	dist[src] = 0;
//	for (int count = 0; count < (graph->size - 1); count++)
//	{
//		u = minDistance(graph, dist, sptSet);
//		sptSet[u] = 1;
//		for (int v = 0; v < graph->size; v++)
//		{
//			if (sptSet[v] == 0 && )
//		}
//	}
//}

int main() {
	t_mat_graph *graph;

	graph = new_mat_graph(16);
//	set_link(graph, 1, 2, 1);
	set_link(graph, 8, 0, 1);
	set_link(graph, 8, 1, 1);
//	set_link(graph, 7, 2, 1);
//	set_link(graph, 7, 3, 1);
//	set_link(graph, 7, 4, 1);
//	set_link(graph, 7, 5, 1);
//	set_link(graph, 7, 6, 1);
//	set_link(graph, 8, 7, 1);
	set_link(graph, 8, 7, 1);
	set_link(graph, 8, 8, 1);
//	set_link(graph, 8, 9, 1);
	set_link(graph, 8, 15, 1);
	set_link(graph, 8, 16, 1);
	printf("8-0 %d\n\n", has_link(graph, 8, 0));
	printf("8-1 %d\n\n", has_link(graph, 8, 1));
	printf("8-2 %d\n\n", has_link(graph, 8, 2));
	printf("8-3 %d\n\n", has_link(graph, 8, 3));
	printf("8-4 %d\n\n", has_link(graph, 8, 4));
	printf("8-5 %d\n\n", has_link(graph, 8, 5));
	printf("8-6 %d\n\n", has_link(graph, 8, 6));
	printf("8-7 %d\n\n", has_link(graph, 8, 7));
	printf("8-8 %d\n\n", has_link(graph, 8, 8));
	printf("8-9 %d\n\n", has_link(graph, 8, 9));
	printf("8-15 %d\n\n", has_link(graph, 8, 15));
	printf("8-16 %d\n\n", has_link(graph, 8, 16));
//	set_link(graph, 7, 9, 1);
//	set_link(graph, 3, 1, 1);
	print_matrix(graph);
	del_mat_graph(graph);
    return 0;
}
