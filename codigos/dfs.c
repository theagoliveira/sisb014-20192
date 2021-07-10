dfs(graph *g, int v)
{
	edgenode *p;			/* temporary pointer */
	int y;				/* successor vertex */

	if (finished) return;		/* allow for search termination */

	discovered[v] = TRUE;
  time = time + 1;
  entry_time[v] = time;
  /*printf("entered vertex %d at time %d\n",v, entry_time[v]);*/

	process_vertex_early(v);

	p = g->edges[v];
	while (p != NULL) {
		y = p->y;
		if (discovered[y] == FALSE) {
			parent[y] = v;
			process_edge(v,y);
			dfs(g,y);
		}
		else if (((!processed[y]) && (parent[v]!=y)) || (g->directed))
			process_edge(v,y);

		if (finished) return;

		p = p->next;
	}

	process_vertex_late(v);

  time = time + 1;
  exit_time[v] = time;
  /*printf("exit vertex %d at time %d\n",v, exit_time[v]);*/

	processed[v] = TRUE;
}
