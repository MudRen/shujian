// tiebagua.c ������

inherit ITEM;
#include <ansi.h>

void setup()    {}
void init()
{
        add_action("do_strike", "pai");
}

void create()
{
        set_name(HIG"������"NOR, ({ "tie bagua","bagua"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long","����һö�һ��������õ������ԡ�\n");
                set("value", 7000);
                set("unique", 3);
                set("material", "iron");
         }
        setup();
}

int do_strike(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô?\n");

        if( me->query_skill("qimen-bagua",1)<30 )
                return notify_fail("������Ű�����Ϊ����������ʹ��������������\n")
;

        if( me->query("family/family_name")!="�һ���" )
               return notify_fail("ֻ���һ������Ӳ�������������������\n");
        if ( me->query("family/family_name") == "�һ���" )
	{
		if (me->query_skill("strike", 1) <= 30)
		{
			if (me->query("eff_qi")>30)
				me->add("eff_qi", -30);
			return notify_fail("���������������ԣ�ֻ����'ž'��һ�����㻢�����ѣ�ʹ���㼸��������ȥ��\n");
		}
                if (me->query_skill("strike", 1) >=100)
		{
			return notify_fail("���������������ԣ��������Ѳ������������ˡ�\n");
		}
		if ((me->query("jingli")<=20) || (me->query("qi")<=30))
			return notify_fail("��̫���ˣ���Ϣһ��ɡ�\n");
		message_vision("$N�������������ԣ��Ծ����������������档\n", me);
		me->add("jingli", -(10+random(me->query_skill("strike",1))/6));
		me->improve_skill("strike", random(me->query_int()/2)+me->query_int()/2);
	} 	
	return 1;
}
