// r-rose.c ��õ��
// update by cool
// update by Lklv 2001.9.28

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIR "��õ��" NOR, ({ "hong meigui", "meigui", "rose" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ���͸����˵ĺ�õ�壬������һ˿���顣���������ˣ������̲�ס����(wen)һ�¡�\n" NOR);
		set("value", 1020);
		set("wear_msg", HIM "$N����һЦ���ѻ������ڷ����ϣ�������Ů�·���\n" NOR);
		set("remove_msg", HIM "$N�ѻ����ӷ���ȡ�£����������ţ����ػ��С�\n" NOR);
		set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
	add_action("come_life","wen");
	call_out("dest", 18000);
}

int come_life(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();

	if( !ob || !me ) return 0;
	if( !arg ) return notify_fail("�������¿������о��������˵�ʲô��\n");
	if(arg == "rose" || arg == "meigui" || arg == "hong meigui" ){
		message_vision("$N��Сָ������ס��õ�壬����������������š�\n",me);
        	tell_object(me, HIY "�š�����������������ѽ��\n" NOR);
	}
	return 1;
}

void dest()
{
	object me, ob;
	me = this_player();
	ob = this_object();

	if( !ob || !me ) return 0;
	message_vision("$N���еĺ�õ�彥����ή�ˡ�\n",me);
	destruct(ob);
}
