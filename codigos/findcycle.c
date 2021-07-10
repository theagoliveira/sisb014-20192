process_edge(int x, int y)
{
  if (discovered[y] && (parent[x] != y)) {   /* found back edge */
		printf("Cycle from %d to %d:",y,x);
		find_path(y,x,parent);
		printf("\n\n");
		finished = TRUE;
	}
}
