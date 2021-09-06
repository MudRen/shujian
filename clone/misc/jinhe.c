// jinhe.c ��ֽ��
// By River@SJ 

inherit ITEM;
#include <ansi.h> 

void create()
{
	set_name(HIY"��ֽ��"NOR, ({ "jin zhihe", "jin", "zhihe" }));
	set("weight", 50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���������Ľ�ɫֽ�ף���ϸ��ȥ��ԭ���������־����۵�(zhedie)���ɵġ�\n");
                set("value", 500);
		set("unit", "ֻ");
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("material", "paper");
	}
	setup();
}

void init()
{
	add_action("do_zhedie", "zhedie");
}

void he_done(object me,object ob,string msg,int i)
{
	object he;

	if(! me || !ob ) return;

	message_vision(msg, me);
	if (! wizardp(me))
		me->add_busy(random(i/5)+1);
	he = new(MISC_D("zhihe"));
        he->set("name", HIW+me->query("name")+"����ֽ��"NOR);
	he->set("id", me->query("id")+"'s zhihe");
	he->set("long", he->query("long") +"������"+me->query("name")+"("+capitalize(me->query("id"))+")�����۵����ɵġ�\n");
	he->set_amount(i);
	he->move(me);
	destruct(ob);
}

int do_zhedie(string arg)
{
	object ob, me = this_player();
	string msg;
	int i =1;

	if (! arg || arg != "zhihe")
		return notify_fail("�����۵�ʲô��\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( ! objectp( ob =present("bai zhi", me)))
		return notify_fail("��û��һ�Ÿɾ��İ�ֽ����ʲô���۵�����\n");
	
	if ( !wizardp(me) && query("owner") != me->query("id"))
		return notify_fail("�������õ��Ľ�ֽ�װ���\n");

	if ( me->query_temp("make_zhihe/done"))
		return notify_fail("���Ѿ���һǧֻֽ���ˡ�\n");

	if (me->query_temp("zhihe") < 50) {
		me->add_temp("zhihe", i);
		msg = "$N����һ�Ű�ֽ�����Ž�ֽ�׵����ӿ�ʼ�������ڵ�����һֻ��ͻȻ�����Լ����Ǵ����졣\n"; 
		he_done(me, ob, msg, i);
		return 1;
	}
	if (me->query_temp("zhihe") >= 50 && me->query_temp("zhihe") < 300 ) {
		i = 3 + random(5);
		me->add_temp("zhihe", i);
		msg = "$N���Ű�ֽ��ʼ���ף�������ʼ������������һ��͵�����"+chinese_number(i)+"ֻ��\n"; 
		he_done(me, ob, msg, i);
		return 1;
	}
	if (me->query_temp("zhihe") >= 300 && me->query_temp("zhihe") < 550) {
		i = 5 + random(10);
		me->add_temp("zhihe", i);
		msg = "$N���Ű�ֽ���ǳ��������۵��������ܿ���ۺ���"+chinese_number(i)+"ֻֽ�ס�\n"; 
		he_done(me, ob, msg, i);
		return 1;
	}
	if (me->query_temp("zhihe") >= 550 && me->query_temp("zhihe") < 800) {
		i = 10 + random(20);
		me->add_temp("zhihe", i);
		msg = "$N�����ֽ���������۵��ţ���������ĳ���ˣ����ɵĺ�Ҳ�����Ե��������ˡ�\n"; 
		he_done(me, ob, msg, i);
		return 1;
	}
	if (me->query_temp("zhihe") >= 800 && me->query_temp("zhihe") < 1000) {
		i = 20 + random(30);
		if ( i + me->query_temp("zhihe") > 1000)
			i = 1000 - me->query_temp("zhihe");
		me->add_temp("zhihe", i);
		msg = "$Nһ�ߵ��Ű�ֽ��һ���Ҹ���΢Ц�ţ����ɵ�ֽ��Ҳ�����鶯���·����Ͼͻ�ɵ���һ���˵���ߡ�\n"; 
		he_done(me, ob, msg, i);
		return 1;
	}
	if (me->query_temp("zhihe") >= 1000 ) {
		msg = HIW"\n$N�յ�����ֻ�ף�ͻȻ�����������Ҳ���������һЩ��ԭ�������Ѿ�������һǧֻֽ�ס�\n"NOR;
		message_vision(msg, me);
		me->delete_temp("zhihe");
		me->set_temp("make_zhihe/done", 1);
		call_out("dest", 1, this_object());
		return 1;
	}
	return 1;
}

void dest(object obj)
{
	if (!obj) return;
	destruct(obj);
}
