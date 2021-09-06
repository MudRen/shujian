// add quest by yanyang 2000/8/25 , about a armor


inherit ROOM;
#include <ansi.h>
string look_bei();
void close_passage();
void create()
{
        set("short", HIR"��Ȼ��Ѩ"NOR);
        set("long", @LONG
��ʯ��ϵ��Ȼ���ɣ���֮�����˹������ʯ�Ҵ���ʮ������������ȥ����
�ڹ���ʮ��ߺ��ǣ��������ԣ���̬���в�ͬ���еĺ���ɢ���ڵأ��е�ȴ��
��������Σ�����Щ��̳��λ֮����ÿ�ߺ���֮�Զ����ű��У��������þߣ�
�䱦������ڴ�����һ��ʯ��(bei)��
LONG
        );

        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));

        set("item_desc",([
        "bei"         :       (: look_bei :),
        ]));

        set("objects", ([
            __DIR__"obj/haigu" : 1,  
//            __DIR__"obj/ycj" : 1,  by tangfeng
        ]));

        set("no_clean_up", 0);
        setup();

}
string look_bei()
{
        return
        "\n"
"    �   �ö�������Ʒ��\n"    
        "\n"
HIR"        ����Ī�֣�    \n"NOR
        "\n";
}

void init()
{
        add_action("do_move", "move");
        add_action("do_find", "find");
}

int do_move(string arg)
{
      object me;
      me=this_player();

      if ((int)me->query_temp("marks/baowu")) 
      {
      if ((int)me->query_str() < 30)
          return notify_fail("��������������޷���ʯ���ƿ���\n");
      if (!arg || arg !="bei") 
          return notify_fail("��Ҫ��ʲô����\n");
      write("������������������˿�������ʯ�������������ƿ���\n");
      message("vision",me->name() + "˫���������������ʯ����������ƿ�������¶��һ���ڶ�������ڡ�\n", environment(me),({me}));
      set("exits/enter", __DIR__"taijie-1");
      remove_call_out("close_passage");
      call_out("close_passage", 5);
      return 1;
      }
      return notify_fail("��������\n");
}

int do_find(string arg)
{
      object me=this_player();
      object kaijia;
      mapping fam = me->query("family");
      
      if(!fam || fam["family_name"] != "���ư�" || fam["master_name"] != "�Ϲٽ���" || !me->query_temp("marks/baowu")){
        write(HIR"�����صأ��ö�������Ʒ������Ī�֣�\n"NOR);
        return 1;
        }

      if (!arg || arg != "baowu")
        return notify_fail("��Ҫ��ʲô��\n");
      if(me->query("jingli")<100) return notify_fail("��û�о������Ҷ����ˣ�\n");
      if(me->is_busy()) return notify_fail("���������黹û��ƽ��������\n");
      if(random(10)>6) {
        me->start_busy(2);
        return notify_fail(BLU"ͻȻ���㷢����ߵ�һ�ߺ��Ǻ�����һ�£��㱻�ų���һ���亹��\n"NOR);
        }
      if(random(10)!=6) {
        me->add("jingli",-100);
        return notify_fail("��С���������ź�����ϸ��Ѱ���š�\n"); 
        }
      kaijia = unew(ARMOR_D("yuxue-kaijia"));
      if(!clonep(kaijia)) { 
        write("��������˰��죬��û�ҵ�һ�������Ķ���������\n");
        return 1;
        }  
      write("���ڣ�����һ�ߺ����Է���һ��Ѫ��ɫ�����ס�\n");
      message_vision("$N������С�ĵ����𣬿��������������\n",me);
      kaijia->move(me);
      return 1;
}

void close_passage()
{
      if( !query("exits/enter") ) return;
      message("vision", "ʯ������¡¡�������������ƻ�ԭ����\n", this_object() );
      delete("exits/enter");
}
