int main(object me, string arg)
{
	object ob = new("/kungfu/class/gaibang/pot_target");

	ob->move(environment(me));
	for (int i = 0; i < 5; i++) ob->random_move();
	return 1;
}
