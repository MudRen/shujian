inherit ITEM;

#include <ansi.h>

int do_chang(string);

void create() 
{
	set_name(HIY "�ĳ��" NOR,({"gao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һ���������̵�"+this_object()->query("name")+"��������(chang)ζ����\n");
		set("unit","��");
		set("no_drop", 1);
		set("no_get", 1);
		set("no_give", 1);
	}
	setup();
}

void init()
{
	add_action("do_chang", "chang");
}

int do_chang(string arg)
{
	object me=this_object();
	object who=this_player();
	int job;
	mapping fam=who->query("family");

	job = who->query("job_time/����") + who->query("job_time/������ͽ")+ who->query("job_time/���ް���");

	if( who->is_busy())
		return notify_fail("����æ���ء�\n");

	if( !this_object()->id(arg) )
		return notify_fail("���볢ɶ��\n");

	message_vision("$N����"+me->query("name")+"����һ�ڵĳ�����ȥ��\n", who);

	if (!fam || fam["family_name"] !="������")
		return notify_fail("�㲻�����޵��ӣ�������"+me->name()+"���ж��ġ�\n");

	if ( me->query("prices")<= 0  || me->query("xx/owner")!=who)
		message_vision("��ʲô��ζҲû��������\n", who);

	else if (who->query("combat_exp") > 2000000 || who->query_skill("huagong-dafa", 1) < 10){
		if ( job < 500 && who->query("combat_exp") > 2000000){
			message_vision("$N������������ǿ����û�³�����\n", who);
			tell_object(who,"��ֻ�е�����������ʮ��С���������Ҵ̣���ʹ�����������Ž���ҩ��ҩ����ȫ���⡣\n");
			who->add("job_time/���ް���", 4);
		}
		else {
			message_vision("$Nֻ�е�һ����ģ�������ת��\n", who);
			who->unconcious();
		}
	}
	else {
		message_vision("$N������������ǿ����û�³�����\n", who);
		tell_object(who,"��ֻ�е�����������ʮ��С���������Ҵ̣���ʹ�����������Ž���ҩ��ҩ����ȫ���⡣\n");
		who->add("combat_exp",me->query("prices"));
		who->add("potential",me->query("prices")/5);
		who->add("job_time/���ް���", 4);
		if(who->query("potential") > who->query("max_pot")) 
		who->set("potential",who->query("max_pot"));
		who->add_busy(1);
		tell_object(who, YEL "��ľ���������"+chinese_number(me->query("prices"))+"�㣬"+
				"Ǳ��������"+chinese_number(me->query("prices")/5)+"�㣡\n" NOR);
		log_file( "job/chong",sprintf("%8s%-10s��%5d�ΰ�ҩ���񣬵õ�����:%3d��Ǳ�ܣ�%2d���־��飺%d��\n",
	                who->name(),"("+who->query("id")+")",who->query("job_time/���ް���"),me->query("prices"),me->query("prices")/5,
	                who->query("combat_exp")), who);
	}
	destruct(me);
	return 1;
}
