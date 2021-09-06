
#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{	
	set_name(HIW"ˮ������"NOR, ({ "box","li he" }) );
	set("long", "һ����ˮ�����ɵ�С���ӡ�\n");
	set("unit","��");
	set("no_drop",1);
        set("no_give",1);
        set("no_cun",1);
	
	setup();
}

void init()
{
	if((this_player() == environment()) && (this_player()->query_temp("token/maker")))
	{
		set("long", "һ��װ�������ˮ������,����԰�������(present)��������ѡ�\n");
	}


	add_action("do_apply", "apply");
	add_action("do_present", "present");

}

int do_present(string arg)
{
	object ob,me = this_player();
	
	if (!me->query_temp("token/maker"))
		return notify_fail("�����������ת�͡�\n");
		
	if (!arg)
		return notify_fail("��Ҫ�Ѷ������͸�˭����\n");

if(me->query("age")<18 && arg!= me->query("id"))
             return notify_fail("СС��;Ϳ�ʼ̸��˵���������Ʒ�������㻹�������Լ��ðɡ�\n");
	if (!(ob = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	
	if (!userp(ob))
		return notify_fail("�㻹�ǲ�Ҫ���������ˡ�\n");

	if (!living(ob))
		return notify_fail("����Ȱ��˼�Ū��ѽ��\n");
	
	if (ob->query_temp("token/apply"))
		return notify_fail(ob->query("name")+"�Ѿ��յ�һ��������,��ȵ����Ͱɡ�\n");
		
	if (mapp(ob->query("token/"+query("token/id"))))
		return notify_fail(ob->query("name")+"�Ѿ�������һ��ͬ��ļ���Ʒ,�����ٽ�����������ˡ�\n");

		
	set("long", "����"+this_player()->query("name")+"���͸����"+query("name")+"����Խ���(apply)����\n");

	me->delete_temp("token");
	ob->set_temp("token/apply",1);
	this_object()->move(ob);
	tell_object(me, "���С�ĵشӻ����ó�һ��"+query("name")+"����"+ob->query("name")+"��\n");
	tell_object(ob,me->query("name")+"��С�ĵشӻ����ó�һ��"+query("name")+"�����㡣\n");
	return 1;
}

int do_apply()
{
	object ob,me = this_player();

	if (!me->query_temp("token/apply"))
		return notify_fail("�Ѿ�װ���˾Ͳ�Ҫ�ٿ��˰ɡ�\n");
		
	if (mapp(me->query("token/"+query("token/id"))))
		return notify_fail("���Ѿ�������һ������Ʒ,�����ٽ��ܱ��˵������ˡ�\n");
			
	me->delete_temp("token");
	me->set("token/"+query("token/id")+"/desc",query("token/desc"));
	if (query("token/parry"))
		me->set("token/"+query("token/id")+"/parry",query("token/parry"));
	if (query("token/dodge"))
		me->set("token/"+query("token/id")+"/dodge",query("token/dodge"));
	ob=new("clone/spec/item/"+query("token/id")+".c");
	ob->move(me);
	tell_object(me, "���ˮ�����Ӿ���ط����������һ"+ob->query("unit")+ob->query("name")+",�㿪�ĵĴ�����"+ob->query("name")+",���ְ�ˮ�����Ӷ���һ�ߡ�\n");	
	destruct(this_object());
	return 1;
}
