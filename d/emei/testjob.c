// houdian.c ���

inherit ROOM;
void create()
{
	set("short", "���");
	set("long",@long
���Ƕ���ɽ�����ֵĺ��Ƕ����������˴��̵��ӹ���ĵط������﹩
��һ���������������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š���������
���򼸸�Ů���Ӵ����书��
long);
	set("exits",([
		"north" : __DIR__"daxiong",
	]));
        set("objects",([
//                CLASS_D("emei") + "/mie-jue" : 1,
	]));
//	create_door("north", "С��", "south", DOOR_CLOSED);
        setup();
}

void reset()
{
	object here=this_object();
	if (here->query("fighting") != 1) {
		if (here->query("count") != 1)
			here->set("count", random(4) );
		if ((int)here->query("count") == 1){
			remove_call_out("test");
			call_out("test", 5, here);
		}
	}
	::reset();
}

int sort(object obj1, object obj2)
{
	int temp1,temp2;
	temp1 = obj1->query("em_job1");
	temp2 = obj2->query("em_job1");
	if (temp1 > temp2) return 1;
	else if (temp1 < temp2) return -1;
	else return 0;
}

void test(object here)
{
	string s;
	object ob, ling, where;
	object *list, *selected, *sorted;
	int num0, num1, num2, num3;
	int i, cnt = 0;
	string* tgt= ({ "/d/emei/houshanty", "/d/emei/baoguosi", "/d/emei/sheshenya",
                        "/d/emei/zhongfengsi", "/d/emei/qianfoan", "/d/emei/chunyangdian",
                        "/d/emei/guanyinqiao", "/d/emei/jietuopo", "/d/emei/xianfengsi" });
	string* tgtname= ({ "̿Ҥ", "������", "������", "�з���", "ǧ����",
                            "������", "������", "������", "�ɷ���"});
	num0 = -1;
	num2 = -1;
	num3 = -1;
	num1 = -1;
	num0 = random(sizeof(tgt));
	num1 = random(sizeof(tgt));
	while (num0 == num1) {
		num1 = random(sizeof(tgt));
	}
	num2 = random(sizeof(tgt));
	while (num0 == num2 || num1 == num2) {
		num2 = random(sizeof(tgt));
	}
	num3 = random(sizeof(tgt));
	while (num0 == num3 || num1 == num3 || num2 == num3) {
		num3 = random(sizeof(tgt));
	}
	if (!(ob = present("miejue shitai", here))) return;
	list = filter_array(users(), (: $1->query_temp("emhsjob"):));
	sorted = sort_array(list, (: sort :));
	i = sizeof( sorted );
	while( i-- ) {
		if (!environment(list[i]) ) continue;
		if (wizardp(list[i]) || list[i]->query("env/invisibility")) continue;
		if ( !interactive(list[i]) ) continue;
		if (query_idle(list[i]) > 2000) continue;
		cnt++;
		list[i]->set_temp("selected", 1);
	}
	if ( cnt < 2 ) {
		here->set("count", random(2));
		return;
	}
	selected = filter_array(list, (: $1->query_temp("selected") == 1 :));
	i = 1;
	if (!(where = find_object("fang ping")))
		ling = new("/d/emei/npc/fang");
	else ling = present("fang ping", where);
	ling->move("/d/city/yltw");
	ling->set("pl", selected[0]);
	s = selected[0]->query("name")+"�Ͻ�����������ͤ�ѷ���ǰ����������";
	while( i < 5 ) { ling->set("pl"+i, ling); i++; }
	ling->set("pl1",selected[1]);
	ling->set("st1",tgt[num0]);
	s = s + selected[1]->query("name")+"��ס"+tgtname[num0]+"��";
	if( cnt > 2 ) {
		ling->set("pl2",selected[2]);
		ling->set("st2",tgt[num1]);
		s = s + selected[2]->query("name")+"��ס"+tgtname[num1]+"��";
	}
	if( cnt > 3 ) {
		ling->set("pl3",selected[3]);
		ling->set("st3",tgt[num2]);
		s = s + selected[3]->query("name")+"��ס"+tgtname[num2]+"��";
	}
	if( cnt > 4 ) {
		ling->set("pl4",selected[4]);
		ling->set("st4",tgt[num3]);
		s = s + selected[4]->query("name")+"��ס"+tgtname[num3]+"��";
	}
	CHANNEL_D->do_channel(ob, "chat", "Ԫ����ɽ��" + s + "�ȴ�Ԯ����ɱ�˵��ˣ�\n");
	ling->apply_condition("em_job1", 30);
	ling->apply_condition("job_busy", 30);
	here->set("fighting", 1);
	return;
}

void init()
{
	add_action("do_swear",  ({ "qishi", "fashi" }));
	add_action("do_huzhuo",  ({ "huzhuo" }));
	add_action("do_nod",  ({ "nod" }));
}

int do_swear()
{
	object ob, me = this_player();
	object where = environment(me);
	if( !(ob = present("miejue shitai", where) ) )
		return 0;
	if( me->query_temp("jiuyin140") < 5 )
		return 0;
	if( me->query("gender") == "Ů��" )
		message_vision("$N˵����СŮ��" + me->query("name") + "�������ģ��պ�������ħ�̽������޼�����ͽ�Ĵ氮Ľ��\n"+
			"����������ɷ򸾣�������ĸ���ڵ��£�ʬ�ǲ��ð��ȣ���ʦ�����ʦ̫�س�����\n"+
			"����һ����ҹ�����������������¶�Ů�����Ӵ���Ϊū��Ů������Ϊ潡�\n", me);
	else
		tell_room(where, me->query("name")+"˵��������" + me->query("name") + "һ��Ҫʵ��ʦ̫������Ը�����������ӣ�\n"+
			"�⸴����ɽ�ӣ��������������Ⱥ�ף��ǹ����֡��䵱����Ϊ��ԭ�����еĵ�һ���ɡ�\n"+
			"��Υ����������������򽣴�����������֮�ء�\n");
	tell_room(where, "���ʦ̫����¶��һ˿Ц�ݡ�\n");
	me->set_temp("jiuyin140", 6);
	tell_room(where, "���ʦ̫˵������Ů������������֮ǰ���͹�����������һ����������д�˱������书��\n"+
			"��Ҫ���ֱ���ڵ���֮�С��������вص����Ǳ������˵���Ϊ������������Ϊ�պ����˵�\n"+
			"�����б��飬�����������ӣ�ɱ�����ӻʵۡ����콣�вص�������ѧ���ţ�������Ϊ����\n"+
			"�ģ�����һ���������澭����һ��������ʮ�����Ʒ����塯����������ϰ�ý����书����\n"+
			"���е���Ϊ�������\n");
	tell_room(where, "���ʦ̫˵������ȡ�������������콣�����������һ��ִ����һ�ֳֽ�������������\n"+
			"�Ե������(huzhuo)�����������㼴ͬʱ���ۣ�����ȡ�����ڵ���ͽ����е����š�����\n"+
			"ȡ�����ŵ�Ψһ���ţ��Ǳ���������Ҳ�Ӵ˻��ˡ����ס��ô��\n");
	return 1;
}

int do_nod()
{
	object me=this_player();
	if( me->query_temp("jiuyin140") != 6 ) return 0;
	me->set_temp("jiuyin140", 7);
	message_vision("$Nֻ���û�����Ѫ���ڣ�һ�ɺ�Ȼ�����������ؽ�\n", me);
	me->add("shen", me->query("combat_exp")/3);
	return 0;
}

int do_huzhuo()
{
	object ob, me=this_player();
	object ob1, ob2, where = environment(me);
	if( me->query_temp("jiuyin140") < 6 ) return 0;
	if( !(ob1 = present("yitian jian", me)) ) return 0;
	if( !(ob2 = present("tulong dao", me)) ) return 0;
	if( me->query_temp("jiuyin140") != 7 )
		return notify_fail("���Ӧ�����ʦ̫��Ҫ������\n");
	if ( !me->query("jiuyin/emeipass") || !me->query("jiuyin/emeijump"))
		return notify_fail("�ٺ٣�������ô��\n");
	if( !(ob = present("miejue shitai", where) ) )
		return notify_fail("���ʦ̫�������������ȱ���������\n");
	message_vision("ֻ��$Nһ��ִ����һ�ֳֽ���������������������\n"+
			"ֻ�������ꡯ��һ�����죬�����Ѿ�����˫�������������콣�ʹ���ʧ�ˡ�\n", me);
	destruct(ob1);
	destruct(ob2);
	message_vision("���ʦ̫�Ӷϵ��Ͻ���ȡ���˼��Ų������˼��ۣ��ó�һ�Ų�������$N��\n", me);
	if( me->query_skill("xianglong-zhang", 1) > 0)
	        tell_room(where, "���ʦ̫˵��������ʮ�������Ѿ�ѧ�ˣ����ž����׹�צ���������ȥѧ�ɡ�\n");
	else
		tell_room(where, "���ʦ̫˵���������ѧ·���뽵��ʮ���Ƶĸ����������������ž����׹�צ���������ȥѧ�ɡ�\n");
	tell_room(where, "���ʦ̫˵���������ٵ�һ���ĵ����ơ����Ϊ����־ʿ�������鴫��������Ҫ������������²��\n");
	tell_room(where, "���ʦ̫��˵�����ҿ��⻹�����ȱ��ܣ��������Ҫ��ʱ������Ҫ�ɡ�\n");
	me->set("jiuyin/emei",1);
	log_file("quest/jiuyin",sprintf("%-18s�ڶ�ü��������ʧ��%s�κ�ɹ������ʦ̫���õ���ü������\n",
		me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("jiuyin/emeifail"))), me);
	me->delete_temp("jiuyin140");
	return 1;
}
