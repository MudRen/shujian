// include for lao denuo

string ask_me()
{
        object me, ob, book;

        ob = this_object();
        me = this_player();

        if((random(10) < 6) || me->is_fighting() )
                return "�Բ���������Ҳ�������㻹������ʦ��ȥ�ɣ�\n";

	if (me->query_temp("hs/askzixia",1)){
		message("vision", YEL "����������㶼֪���ˣ�������ȥ���ɣ�\n"
			"�͵�ŵʹ���������������棬�����ޱȣ�һ������Ц�����ģ����\n" NOR, me, ob);
		ob->set_temp("apply/attack",  50);
		ob->set_temp("apply/defense", 50);
		ob->set_temp("apply/damage",  50);
		ob->set("wmmpy", 80);
		me->delete_temp("hs/askzixia");
		book = unew(__DIR__"obj/zixia");
		if( clonep(book) ){
			book->move(ob);
		}
		ob->kill_ob(me);
		me->fight(ob);
		return "�Ҵ���Ͷʦ�����踺�أ��㾹�Ҵ��ҵ����⣬ȥ���ɣ�\n";
	}
	return "��ʦ��˵�ؼ����������С��͵���ˣ�\n";
}

string ask_px()
{
	if (random(10) < 8)
                return "��а��������˵��������������û������\n";
	return "������Ҳ�������㻹������ʦ��ȥ�ɣ�\n";
}

string ask_zuo()
{
	object me = this_player();

	if (random(10) < 5)
                return "�������������ɵ�������\n";
	if (me->query("family/family_name")=="��ɽ��"){
		command("whisper "+me->query("id")+" ʦ�������˼�����ɺã������ʺ������˼ң�");
		return "�������������µ��Ӷ��ܳ�ɫ��\n";
	}
	return "ʦ���д�˵©���죬��˵�һ�ɽ�ɵĴ�о�������ˣ�\n";
}
