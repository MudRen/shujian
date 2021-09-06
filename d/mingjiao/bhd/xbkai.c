// xbkai.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"С����"NOR);
	set("long", @LONG
����һ��С�����������ֻ�(hua)��������Զ֮������һ����ʯ(yanshi)��
��������Ե���½�ء�
LONG);	
        set("no_fight", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1); 
	set("outdoors","����");
	setup();
}

void init()
{
        object me, ob, *obj;
        int i;
        me = this_player();
        ob = this_object();
        obj = all_inventory(ob);
        if(!this_player()->query_condition("cold_wind") && !wizardp(me))
        this_player()->apply_condition("cold_wind", 1);
        for(i= 0;i< sizeof(obj);i++){
             if(obj[i]==me ) continue;
             if(obj[i]->is_character()){
                 message_vision(HIR"ֻ��С�����͵�һ�𣬳��º�ȥ��\n"NOR, ob);
                 obj[i]->unconcious();
                 obj[i]->move(__DIR__"dbshan");
                 me->unconcious();
                 me->move(__DIR__"dbshan");
                 message("vision", "һ�����Բ��ѵ��˱���ˮ����������\n",environment(me), ({me}) );
             }
        }
        delete("hua_trigger");
	add_action("do_pa","pa");
	add_action("do_hua","hua");
}

int do_hua()
{
      object ob=this_player();
      if(ob->is_busy()) return notify_fail("����æ���ء�\n");
      if(ob->query_temp("marks/��1")) return notify_fail("���Ѿ�������ʯ���ˡ�\n");
      message_vision("$N�ֽŻ������������򱱱ߵ���ʯ��ȥ��\n",ob);
      ob->start_busy(1);      
      if((int)query("hua_trigger")>=7){
            message_vision("�������ڱ�$N��������ʯ���Աߡ�\n", ob);
	    delete("hua_trigger");
	    ob->set_temp("marks/��1",1);
            }
      else add("hua_trigger", 1);
      return 1;
}

int do_pa(string arg)
{
	object ob;
	ob=this_player();	
	if (!ob->query_temp("marks/��1"))
		return notify_fail("����������ʯ����Զ�ء�\n");
        if (!arg  || arg !="yanshi")
		return notify_fail("��Ҫ�������\n");
	message("vision", ob->name() + "���ѵ���������ʯ��\n", environment(ob), ({ob}));
        ob->move(__DIR__"yanshi");
        message("vision", ob->name() + "�Ӹ���������������������ˮ��\n",environment(ob), ({ob}) );
        EMOTE_D->do_emote(ob,"cold", ob->query("id"));
        EMOTE_D->do_emote(ob,"cold");
        ob->delete_temp("marks/��1");
        ob->start_busy(2);
        return 1;
}
