int main(object me, string arg)
{
  object *ob;
  int i;

	write(sscanf("zzzz12345w", "%*([a-z]{3,8}[0-9]{1,10})")+"\n");
	write(sscanf("zzzz12345w", "zzz%*d")+"\n");
	write(sscanf("zzzz12345w", "zzzzz%*d")+"\n");
  if (!arg) return 0;
  ob = users();
  for (i=0;i<sizeof(ob);i++) if (ob[i]->query(arg)) printf("%O %O %s\n", ob[i], ob[i]->query(arg), ob[i]->short());
  return 1;
}
