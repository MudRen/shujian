// zhihe.c ֽ��
// By River@SJ 
inherit COMBINED_ITEM;
#include <ansi.h> 

void create()
{
	set_name(HIW"ֽ��"NOR, ({ "zhihe", "he" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����˼���ֽ�ף��ǳ����£���˵�ռ���һǧֻ���Դ������ˡ�\n");
		set("base_value", 500);
		set("value", 500);
		set("base_unit", "ֻ");
		set("unit", "Щ");
		set("base_weight", 5);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("material", "paper");
	}
	set_amount(1);
}

void init()
{
	add_action("do_give", "song");
	add_action("do_tear", ({"si", "tear"}));
}

int do_give(string arg)
{
	string target, item;
	object me, obj, who;

	me = this_player();
	obj = this_object();

	if (!arg) return 0;

	if( sscanf(arg, "%s to %s", item, target)==2
	 || sscanf(arg, "%s %s", target, item)==2);
	else return notify_fail("ָ���ʽ : song <��Ʒ����> to <ĳ��> �� : song <ĳ��> <��Ʒ����>\n");
	
	if ( item != "zhihe")
		return notify_fail("ָ���ʽ : song <��Ʒ����> to <ĳ��> �� : song <ĳ��> <��Ʒ����>\n");

	if (!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if ( who == me) return notify_fail("���Լ���\n");

	if ( me->is_busy()) return notify_fail("����æ���ء�\n");

	if ( who->query("env/no_accept"))
		return notify_fail("�Է����ڲ������κζ�����\n");

	if ( who->query_temp("make_zhihe/get"))
		return notify_fail(who->query("name")+"�Ѿ���ֽ���ˡ�\n");

	if ( query_amount() < 1000)
		return notify_fail("�㻹û�д���һǧֻֽ���ء�\n");
	
	message_vision("$N����$nһЩ"+obj->query("name")+"��\n", me, who);
	me->delete_temp("make_zhihe");
	who->set_temp("make_zhihe/get", 1);
	obj->move(who);
	return 1;
}

int do_tear(string arg)
{
	object me = this_player();
	
	if(!id(arg)) return 0;
	
	message_vision(HIW"$N������վ�ţ������е�ֽ�׿����ֿ���ͻȻһҧ�������½�ֽ��˺����Ƭ��\n"+
			"����ƬƬ����ڷ��з��裬������ˮ���������\n"NOR, me);
	EMOTE_D->do_emote(me,"cry", me->query("id"));
	me->delete_temp("make_zhihe");
	me->delete_temp("zhihe");
	call_out("dest", 1, this_object());
	return 1;
}

void dest(object obj)
{
	if (!obj) return;
	destruct(obj);
}
