// OBJ: ling.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_baifang", "baifang");
}

void create()
{
        set_name("����", ({"ling pai", "ling"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("long", HIY "���ǿ��һ��������ƣ��Ѿ��ܳ¾��ˣ��Ľ�ĥ�ĺ�Բ����\n" NOR );
              set("value", 10000);
//              set("no_drop", 1);
              set("no_get", 1);
        }
        setup();
}

int do_baifang(string str)
{
        object my_object,me = this_player();
	if (!str)
	        return notify_fail("��Ҫ�ݷ�˭����\n");
        if (!(my_object = present(str, environment(me))))
		return notify_fail("��Ҫ�ҵ��˲������ȥ�����ҿ��ɡ�\n");
	if ( str != "huang yaoshi")
		return notify_fail(my_object->query("name")+"˵����"+RANK_D->query_respect(me)+"Զ�������������룬�����룡\n");
        if (!living(my_object))
		return notify_fail("Ŷ������Ȱ���Ū����˵��\n");
	tell_object(me, HIC + my_object->query("name")+"�����̾�˿�����\n");
	tell_object(me, HIC + my_object->query("name")+"˵����Ĭ�����ǵ���Ҳ�����˱��˵�ǣ����û�뵽����񻹼ǵ������ʦ����\n" NOR);
	tell_object(me, HIC + RANK_D->query_respect(me)+"��ظ�������˵�����ٴ�������ʦ�ţ�\n" NOR);

	me->delete_temp("ylj/step6");
	me->set_temp("ylj/stepend", 1);
	return 1;
}
