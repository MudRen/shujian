int ask_ji()
{
	object me = this_player();

	if (!me->query_temp("marks/jiaohua-ji")){
		command("say "+RANK_D->query_respect(me)+"���Ҹ�����ɣ���������óԵĽл��������ض��Ǹ�СѾͷ���ģ�");
		command("say �����ⱿС�Ӳ�֪������ȥ�ˣ�����ȥ�������Ҵ�ֻ�����þ�Ҳ��������");
		me->set_temp("marks/jiaohua-ji",1);
		return 1;
	}
	command("say ��Ҳ�����");
	return 1;
}

int kanglong(object me, object ob)
{
	if(!ob || !me || !living(ob) || !living(me)
		|| environment(ob) != environment(me)
		|| ob->is_fighting() || me->is_fighting())
		return 0;

	command("consider");
	command("say �����������ǲ������������ͻ�Ѿͷͬ���õ���ζ����");
	if ( random((int)me->query_con()) > 15 ){
		command("say ��Ҳ���ܰ׳�����Ĳˣ������ɡ�");
		command("whisper "+me->query("id")+" ��ȥ����"YEL"��ɳɽ"NOR"ס��һ���ӣ���û���컯�Ϳ����Լ��ˡ�");
		me->set_temp("xlz/hang", 1);
		return 1;
	}
	command("say ����ļ��������������ģ��´μǵ��ٸ���Ū��ֻ����");
	return 1;
}

int ask_wugou()
{
	int i, j, x;
	object me = this_player();

	i = me->query("gb/baih7g");
	j = me->query("combat_exp");
	x = me->query("dgb/wugou");

	if ( x >= 5 || me->query_temp("get_wugou") ) {
		command("knock "+me->query("id")+"");
		return 1;
	}
	if ( me->query_temp("noget_wugou") && !wizardp(me)) {
		if (me->query_temp("noget_wugou") > 10) {
			command("say ȥȥ��С����һ����ȥ��");
			command("kick3 "+me->query("id")+"");
			me->delete_temp("get_wugou");
			me->delete_temp("get_wugou2");
			tell_room(environment(), "\n���߹���������һ�ţ���"+ me->name()+ "�߷ɳ����⣡\n"NOR, ({ me }));
			me->move("/d/gb/pomiao");
			me->add_busy(2);
			tell_room(environment(me), "\nֻ��"+ me->name()+ "ƨ���ϴ��Ÿ����ӡ�����һ�����˹�����ˤ�˸�����ʺ��\n"NOR, ({ me }));
			return 1;
		}
		if (me->query_temp("noget_wugou") > 8) {
			command("say ����Ǵ򹷰����������ó���һ�У��������޹����� ");
			command("club "+me->query("id")+"");
		}
		else switch( random(8) ){
			case 7 :
				command("dunno "+me->query("id")+"");
				break;
			case 6 :
				command("nip "+me->query("id")+"");
				break;
			case 5 :
				command("bored "+me->query("id")+"");
				break;
			case 4 :
				command("heng "+me->query("id")+"");
				break;
			case 3 :
				command("look "+me->query("id")+"");
				break;
			case 2 :
				command("hehe "+me->query("id")+"");
				break;
			case 1 :
				command("oh "+me->query("id")+"");
				break;
			case 0 :
				command("mimi "+me->query("id")+"");
				break;
		}
		me->add_temp("noget_wugou", 1);
		return 1;
	}
	if ( (!i || me->query("family/family_name") !="ؤ��") && !wizardp(me) ) {
		command("en "+me->query("id"));
		me->add_temp("noget_wugou", 1);
		return 1;
	}
	if ( x && x < 5 ){
		command("kick2 "+me->query("id")+"");
		switch(random(2)){
			case 1:
			command("say �����û�գ�������������");
			break;
			case 0:
			command("say ���������������û�ա�");
		}
		me->set_temp("get_wugou2", 1);
		if(random(2)) me->add_temp("noget_wugou", 1);
		return 1;
	}
	x = localtime(TIME_TICK)[2];
	if ((x >= 12 && x <= 21
	 && random(i) > 200000 && random(j+i) > 1000000) || wizardp(me)) {
		command("nod "+me->query("id"));
		command("whisper "+me->query("id")+" ����������д򹷰�������ʽ����������ʱ���㵽������ǹ����ң����˼ǵú���һ����");
		me->set_temp("get_wugou", time() + 27 * 60);	// �ж�ʱ��Ϊ�����ҹ
		return 1;
	}
	command("look "+me->query("id"));
	switch(random(3)){
		case 2 :
			command("consider");
			break;
		case 1 :
			command("nip");
			break;
		case 0 :
			command("pei");
			break;
	}
	me->add_temp("noget_wugou", 1);
	return 1;
}
