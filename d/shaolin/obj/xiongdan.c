// xiongdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}

/*void destdan()
{
	object ob;
	message_vision("$N�������紵�ţ�һ��Ͳ��������ˡ�\n",this_object());
	ob = new(__DIR__"xiongdan1");
	ob->move(environment(this_object()));
	destruct(this_object());
}*/

void create()
{
	set_name(HIG"�ܵ�"NOR, ({"dan", "xiong dan"}));
	set("unit", "��");
	set("long", GRN"����һ���ܵ����Ѿ���̫�����ˣ�����Ȼʮ������,��������֮��������˻��ȡ�\n"NOR);
	setup();
}

int do_eat(string arg)
{
        mapping fam;	
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="dan")
	{
         if((int)me->query_condition("medicine"))
         return notify_fail("���ŵ�һ��Ѫ�ȵ�ζ������������޷���ڣ�\n"); 		
        if ( mapp(fam = me->query("family")) 
	&& (fam["family_name"] == "ؤ��"||fam["family_name"]=="������"||fam["family_name"]=="������"))
        {
         	me->add("max_neili",2);
	//me->set("neili",me->query("max_neili"));
	//	me->set("qi",me->query("eff_qi"));
                message_vision("$N����һ���ܵ���ֻ���þ���������������ԴԴ��������Ѫ��ӯ��\n",me);
                me->apply_condition("medicine",60);
		destruct(this_object());
	        return 1;    
	}
	else {
	   message_vision("$N���˶����ҩ���������ƻ��µĵ��У�ǿ����ë��Ѫ�������ñ���\n",me); 
	   me->unconcious();               
	   me->add("max_neili",-10);
	   me->apply_condition("medicine",60);
	   destruct(this_object()); 
	    return 1;
	    }
          }
	return 1;
}
