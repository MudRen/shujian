int do_lingwu(string arg)
{
	object me=this_player();
	object who=this_object();
	int i = me->query_skill("douzhuan-xingyi", 1);
        int lv = me->query("max_pot")-100;
	if( !living(who))
		return notify_fail("慕容复现在的状况，看来无法回答你任何问题。\n");

	if ( me->query("family/family_name") != "姑苏慕容")
		return notify_fail("你非我慕容弟子，向我讨教什么啊？\n");

	if (!arg || arg !="douzhuan-xingyi" ){
		message_vision("$N向$n讨教一些关于武学上的疑问。\n", me, who);
		command("dunno "+me->query("id"));
		return 1;
	}
	if (me->is_busy() || me->is_fighting()){
		command("say 你正忙着干别的事情呢，忙完了再说吧。");
		return 1;
	}
	if( me->query("jing") < 10)
		return notify_fail("你太累了，还是休息一会吧。\n");
	if((int)me->query("potential", 1) < 1 )
		return notify_fail("你潜能不够。\n");
	if ( i <= 50 ){
		command("say 你的斗转星移等级不够，还不能从我这里学到什么。");
		return 1;
	}
	write("你向慕容复讨教关于「" + to_chinese(arg) + "」的疑问。\n");
	write(HIC"你听了慕容复的指点，领悟到斗转星移的精髓所在。\n");
	write(HIR"你的[斗转星移]提高到了你目前实战经验限制的最高级别！\n");
      me->set_skill("douzhuan-xingyi", lv);

       if (i >= lv -1)
         {
		command("say 你的实战经验不够，无法领悟到什么。");
		return 1;
	}
        
	return 1;
}