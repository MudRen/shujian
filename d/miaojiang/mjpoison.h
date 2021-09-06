void init() 
{
	object ob=this_player();
	if (interactive(ob) 
	 && !ob->query_temp("wdj/�ⶾһ")
	 && userp(ob)
	 && !ob->query_skill("jiuyang-shengong"))
		ob->add_condition("man_poison", 50);
}
