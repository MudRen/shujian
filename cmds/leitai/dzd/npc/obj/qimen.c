// /d/dzd/obj/qimen.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"���Ű���ͼ��"NOR,({"qimenbagua tupu","tupu"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long","����һ�������žŹ����԰��ص�ͼ�ף���˵�������˻���а��������Ѫ��
���ѧѧ��Ӧ�����Լ�����(buzhen)������(chezhen)�˰ɡ�\n");
		set("value",100);
		set("material","paper");
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_buzhen","buzhen");
	add_action("do_chezhen","chezhen");
}

int do_buzhen()
{
	object ob;	
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(me->query_temp("dzd_quest/buzhen"))
		return notify_fail("���Ѿ������ˡ�\n");
	if(present("qimenbagua zhenxing",environment(me)))
		return notify_fail("�Ѿ����������ﲼ���ˡ�\n");
	message_vision(HIY"$N����һ�飬����һ�飬��һ��Ͱ�ͼ����ʾ����һ�����׵����У�\n"NOR,me);
	me->set_temp("dzd_quest/buzhen",1);
       me->start_busy(1+random(2));
	ob = new(__DIR__"zhenxing");
	ob->set_temp("zhen_master",this_object() );
	ob->move(environment(me));
	return 1;
}

int do_chezhen(string arg)
{
	object ob;
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg) arg = "qimenbagua zhenxing";
	ob = present(arg,environment(me));
	if(!ob)
		return notify_fail("��û�������ﲼ��\n");
	if(ob->query_temp("zhen_master") != this_object()  )
		return notify_fail("�ⲻ���㲼����\n");
	message_vision(HIY"$N����������ͰѸող��õļ�ª���γ����ˣ�\n"NOR,me);
	me->delete_temp("dzd_quest/buzhen");
	destruct(ob);
	return 1;
}
