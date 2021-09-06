// /d/city/npc/shan.c

inherit NPC;

int do_look(string);
int ask_me();
string ask_beauty();
string ask_ugly();
string ask_age();
string ask_exp();
string ask_marriage();
string ask_fat();
string ask_pk();
string ask_balance();
int env_cmp(object o1, object o2);

void create()
{
	set_name("˫��", ({ "shuang er", "shuang", "girl" }) );
	set("long", "�����������ڿ�����������ʱ���ˣ��������С����֪������ͦ�ࡣ\n"+
		"���������������\n"+
		"������������ª�������䡿�����顿����顿\n"+
		"����ġ���ɱ�ˡ������������������顿\n"+
		"�����ѡ���Ů�ѡ�����顿���ɷ򡿡����ӡ�\n");
	set("title", "��Ů");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("no_get", "˫���������̫���ˡ�\n");
	set("str", 18);
	set("int", 23);
	set("con", 19);
	set("dex", 20);
	set("per", 30);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 400);
	set("max_neili", 400);
	set("combat_exp", 80000);

	set_skill("literate", 100);
	set_skill("dodge", 30);
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);

	set("inquiry", ([
		"name" : "�Ҿ���˫������" ,
		"here" : "��������ͤ��������������д����ָ�ϵĻ������Ҷ���ģ�",
		"����" : "����˵���������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"kiss" : "�����Ĳ����İ������ǻ��������������ߴ�ط��˰ɡ�",
		"sex" : (: ask_me :),
		"make love" : (: ask_me :),
		"love" : "�̣ϣ֣ţ����������˿��̶�������������" ,
		"ΤС��" : "������Ҳ֪���Ҽ�С�๫���þ�û�����ˣ���֪������ȥ�Ļ����ˡ�" ,
		"����" : "���飿���������˿��̶�������������" ,
		"boyfriend" : "�����ѣ���ǧ��Ҫ��˵��ϲ���������µ����˺���ѻһ��ڡ�" ,
		"����" : "�����ѣ���ǧ��Ҫ��˵��ϲ���������µ����˺���ѻһ��ڡ�" ,
		"girlfriend" : "�뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"Ů��" : "�뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"wife" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"����" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"�ɷ�" : "������˵�ˣ��ɷ����һ�������ް���" ,
		"husband" : "������˵�ˣ��ɷ����һ�������ް���" ,
		"���" : "��飬����������Ŀ�ʼ�ˡ�" ,
		"divorce" : "��飬����������Ŀ�ʼ�ˡ�" ,
		"����" : (: ask_beauty :),
		"beauty" : (: ask_beauty :),
		"��ª" : (: ask_ugly :),
		"ugly" : (: ask_ugly :),
		"����" : (: ask_age :),
		"age" : (: ask_age :),
		"����" : (: ask_exp :),
		"exp" : (: ask_exp :),
		"���" : "���˵�һ����Ů�ˣ��������ǰ���ķ�Ĺ��" ,
	       "���" : (: ask_fat :),
	       "fat" : (: ask_fat :),
	       "ɱ��" : (: ask_pk :),
	       "pk" : (: ask_pk :),
	       "���" : (: ask_balance :),
	       "balance" : (: ask_balance :),
	]) );

	setup();
	carry_object("d/city/obj/pink_cloth")->wear();
	carry_object("d/city/obj/flower_shoe")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_look","kiss1");
	add_action("do_look","kick");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int ask_me()
{
	object me;

	me = this_player();
	switch( random(5) ) {
		case 0:
			message("vision", "˫����" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
			command("slap " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
			break;
		case 1:
			message("vision", "˫����" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
			command("kick " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
			break;
		case 2:
			command("faint " + me->query("id"));
			break;
		case 3:
			command("rascal " + me->query("id"));
			command("kick2 " + me->query("id"));
			break;
		case 4:
			command("xixi " + me->query("id"));
			command("benger " + me->query("id"));
	}
	return 1;
}

int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="shuang" || target=="shuang er")
	if ((string)me->query("gender") != "Ů��") {
		message("vision", "˫����" + me->name() +"���������Ĳ�����ѽ��\n", me );
		switch( random(5) ) {
			case 0:
				command("club " + me->query("id"));
				remove_call_out("kicking");
				call_out("kicking", 1, me);
				break;
			case 1:
				command("kick " + me->query("id"));
				remove_call_out("kicking");
				call_out("kicking", 1, me);
				break;
			case 2:
				command("faint " + me->query("id"));
				break;
			case 3:
				command("stare " + me->query("id"));
				break;
			case 4:
				command("rascal " + me->query("id"));
				command("kick2 " + me->query("id"));
		}
	}
	return 0;

}

void kicking(object me)
{
	if (!me || environment(me) != environment()
	|| environment(this_object())->query("short") != "����ͤ")
		return;

	me->move("/d/city/yueqidian");
	message("vision","ֻ�����ء���һ����������" +  me->query("name") +
		"������ͤ����˳���������һ������ӡ��ƨ������һ��СЬӡ��\n", environment(me), me);
}

int env_cmp(object o1, object o2)
{
	string env1, env2;
	object where;
	env1 = (where = environment(o1)) ? base_name(where) : "none";
	env2 = (where = environment(o2)) ? base_name(where) : "none";
	return strcmp(env1, env2);
}

int sort_per(object ob1, object ob2)
{
	int p1 = ob1->query_per();
	int p2 = ob2->query_per();

	reset_eval_cost();
	if (wizardp(ob1)) return 1;
	if (wizardp(ob2)) return -1;
	return p2 - p1;
}

string ask_beauty()
{
	object *obj1, *ob_list;
	string msg,tmp_str;
	int i, per;
	int count;

	msg ="���������ڡ��齣������";
	ob_list = filter_array(children(USER_OB), (: userp :));
	obj1 = filter_array(ob_list, (: $1->query("gender") == "Ů��" :));
	obj1 = sort_array(obj1, (: sort_per :));
	if (count=sizeof(obj1)) {
		per = obj1[0]->query_per();
		if (count>20)
		{
			count=20;
			tmp_str=",����ͷƯ���Ĵ����Խ��Խ���ˣ��������Ҽ��๫�᲻����ġ�";
				
		}
		for( i = 0; i < count; i++) {
			if (obj1[i]->query_per() < per)
				break;
			msg += obj1[i]->query("name")+"("+capitalize(obj1[i]->query("id"))+")��";
		}
		msg = msg[0..<3] + "��Ư��";
	}

	obj1 = ob_list - obj1;
	reset_eval_cost();
	obj1 = sort_array(obj1, (: sort_per :));
	if (count=sizeof(obj1)) {
		msg += "��";
		per = obj1[0]->query_per();
		if (count>20)
		{
			count=20;
			tmp_str=",����ͷӢ����С����̫���ˣ���������������";
				
		}
		for( i = 0; i < count; i++) {
			if (obj1[i]->query_per() < per)
				break;
			msg += obj1[i]->query("name")+"("+capitalize(obj1[i]->query("id"))+")��";
		}
		msg = msg[0..<3] + "��Ӣ��"+tmp_str;
	}
	return msg+"��";
}

string ask_ugly()
{
	object *obj1, *ob_list;
	string msg;
	int i, per;

	msg ="���������ڡ��齣������";
	ob_list = filter_array(children(USER_OB), (: userp :));
	obj1 = filter_array(ob_list, (: $1->query("gender") != "Ů��" :));
	obj1 = sort_array(obj1, (: sort_per :));
	if (sizeof(obj1)) {
		for (i = 1;i <= sizeof(obj1); i++)
			if (!wizardp(obj1[<i])) break;
		per = obj1[<i]->query_per();
		for(;i <= sizeof(obj1); i++) {
			if (wizardp(obj1[<i])) continue;
			if (obj1[<i]->query_per() > per)
				break;
			msg += obj1[<i]->query("name")+"("+capitalize(obj1[<i]->query("id"))+")��";
		}
		msg = msg[0..<3] + "�������";
	}

	return msg;
}

string ask_age()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, age = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > 1000
		&& !wizardp(ob_list[i])
		&& ob_list[i]->query("mud_age") > age
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			age = obj->query("mud_age");
		}
	}

	if ( !obj ) {
		msg ="�ף�զû�����أ�\n";
		return msg;
	}

	obj->set_temp("oldest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="������������ʦ�⣬���ڡ��齣������"+name+"������";

	return msg;
}

string ask_exp()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, exp = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > exp
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			exp = obj->query("combat_exp");
		}
	}

	if ( !obj ) {
		msg ="�ף�������ôһ�����ֶ�û���ˣ�\n";
		return msg;
	}

	obj->set_temp("highhand",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="�������ڡ��齣������"+name+"���书��ߣ�\n";

	return msg;
}

string ask_fat()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, fat = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->max_food_capacity() > fat
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			fat = obj->max_food_capacity();
		}
	}

	if ( !obj ) {
		msg ="�ף����ڵ�����ô����ô�ݣ�\n";
		return msg;
	}

	obj->set_temp("fat",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="���������ڡ��齣������"+name+"���ܳԡ�\n";

	return msg;
}

string ask_pk()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, pk = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("PKS") > pk
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			pk = obj->query("PKS");
		}
	}

	if ( !obj ) {
		msg ="��������û��ɱ���ˡ�\n";
		return msg;
	}

	obj->set_temp("pk_most",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������������"+name+"ɱ������࣡\n";

	return msg;
}

string ask_balance()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, balance = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("balance") > balance
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			balance = obj->query("balance");
		}
	}

	if ( !obj ) {
		msg ="��������û��ɱ���ˡ�\n";
		return msg;
	}

	obj->set_temp("richest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������"+name+"����Ǯ��\n";

	return msg;
}
