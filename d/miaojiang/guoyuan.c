// /u/dubei/miaojiang
//tangfeng@sj 2004

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��԰");
        set("long", @LONG
���������˵Ĺ�԰������������ˮ���ֹ����м�λ���Ů���������¸ɻ
LONG
        );

        set("exits", ([
                "west" : __DIR__"jiedao5",               
        ]));
        set("objects",([
//    __DIR__"npc/obj/lanseyaohua" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "�置");
        setup();
}
void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
        object obj, me;
        int j;
        me = this_player();

        if( ! arg || (arg != "di"&& arg != "yao hua"&& arg != "lanse yaohua"&& arg != "yaohua"&& arg != "yaocao"))
          return notify_fail("��Ҫ��ʲ�᣿\n");
	      if( me->is_busy() )
		      return notify_fail("����һ��������û����ɣ�\n");
	     if( me->is_fighting() )
		      return notify_fail("�㻹��ר����ս�ɣ�\n");
        if ((int)me->query("jingli") < 500) 
           return notify_fail("��ľ�������������£�\n");  
      	message_vision(HIC"$N���ڵ��ϣ��Ĵ�Ѱ�ҡ�\n"NOR, me);
        me->start_busy(1);
        if(random(6)!=1) 
        {
           me->add("jingli",-200);
           tell_room(environment(me), me->name() + "���˰��죬ֻŪ��һ���ࡣ\n", ({ me }));
           return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
        }
        else
        {
        obj = new(__DIR__"npc/obj/lanseyaohua");
        message_vision(HIB"$N���ڷ���һ����ɫҩ����������ȥժ��������\n"NOR,me);
        me->add("jingli", -500);
        obj->set("owner",me->query("id"));
        obj->move(me);
        j=me->query_skill("force");
        if(random(2)) obj=new("/d/sld/npc/dushe");
        else obj=new("/clone/animal/langgou");
        message_vision(HIB"ͻȻ���ݴ������һֻ"+obj->name()+"��\n"NOR,me);
		    obj->set("combat_exp", me->query("combat_exp"));
		    obj->set("max_qi", me->query("max_qi")*4);
		    obj->set("eff_qi", me->query("max_qi")*4);
		    obj->set("qi", me->query("max_qi")*4);
		    obj->set("max_jing", me->query("max_jing"));
		    obj->set("jing", me->query("max_jing"));
		    obj->set("eff_jing", me->query("eff_jing"));
		    obj->set("eff_jingli", me->query("eff_jingli"));
		    obj->set("max_neili", me->query("max_neili"));
		    obj->set("jing", me->query("max_jing"));
		    obj->set("jingli", me->query("max_jingli"));
		    obj->set("neili", me->query("max_neili")*3/2);
		    obj->set("jiali", 200);
		    obj->set("str", me->query("str")*2);
		    obj->set("con", me->query("con"));
		    obj->set("dex", me->query("dex")*2);
		    obj->set("int", me->query("int")*2);
		    obj->set_skill("unarmed",j +random(50));
		    obj->set_skill("force",j + random(50));
		    obj->set_skill("dodge",j + random(50));
		    obj->set_skill("parry",j + random(50));
		    obj->move(environment(me));
		    obj->set_leader(me);
		    obj->kill_ob(me);
		    message_vision(RED"$N������$nһ���ж���\n"NOR,obj,me);
        return 1;
       }
}
