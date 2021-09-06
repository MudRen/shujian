// kuloutou.c ����ͷ
// Last modify by Yanyang because erroneous word

inherit ITEM;
void destroying(object obj, object me);
void create()
{
        set_name("����ͷ", ({ "kulou tou", "kulou", "tou" }) );
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 20);
                set("long", "����һ����ͷ���ú��γɵ�����ͷ�����������ָ������������ɭɭ�ġ�\n");
        }
        setup();
}

void init()
{
	add_action("do_cha",({"cha","insert"}));
}

int do_cha(string arg)
{
	object me=this_player();
	if( !arg) return 0;
	if ( arg!="kulou" && arg!="kulou tou" && arg!="����ͷ" && arg!="����" && arg!="tou")
		return 0;
	if( me->is_fighting() || me->is_busy() )
		return notify_fail("����æ���ء�\n");
	if( me->query_skill("claw", 1) > 100)
		return notify_fail("�㷢������ô��Ҳû�����ˡ�\n");
	me->add("jing", -(20 + random(40)));
	me->add("jingli", - random(40));
	me->add("shen", -random(80));
	me->improve_skill("claw", (int)me->query_int()+random((int)me->query_skill("claw")));
	message_vision("$N�������ָ��������ͷ�ϵ����ָ�ס�\n", me);
        tell_object(me, "���Ȼ���������ָ���ò����ָ�ף����ﲻ�������ز���һ��а�\n");
        if ( !random(30))
        	destroying(this_object(), me);
	return 1;
}

void destroying(object obj, object me)
{     
	if ( !obj || !me) return;
	tell_object(me, "�������ָ�ݺݽо�����������ͷ�����������ˡ�\n");
	message_vision("$N��ָ�о���ֻ����һ�����죬��������ͷ����$N����÷��顣\n", me);
	destruct(obj);
	return;
}
