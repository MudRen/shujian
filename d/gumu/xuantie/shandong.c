// shandong.c
// By River 98/09 
inherit ROOM;

#include <ansi.h>

string mu(object);
string zi(object);
string tai(object);

void create()
{
        set("short", HIB"��ɽ��"NOR);
        set("long", @LONG
�ⶴ��ʵ��ǳ���в������ɣ��ѵ־�ͷ�����г���һ��ʯ����һ��ʯ��֮
����ޱ��������һ����ʯ���𣬼���һ����Ĺ���������ƺ�д�����֣�ֻ
�ǳ���̦�Σ��ڰ����Ʋ������
LONG
        );

        set("item_desc", ([        
           "deng" : "һ����ͨ��ʯ�ʣ������ܾ�û�������ˣ��������ǻҳ���\n",
           "mu" : (: mu :),
           "qingtai" : (: tai :),
           "tai" : (: tai:),
           "zi" : (: zi :)
        ]));

        set("exits", ([ 
            "out"  : __DIR__"dongkou",
        ]));
    
        setup();
}

string tai(object me)
{
      if(!me->query_temp("xuantie/light"))
          return "�����������ģ���ʲôҲ���������\n";
      if((int)me->query_skill("force", 1) < 100)
          return  "����������̦�ͻҳ���\n";
          me->set_temp("xuantie/qingtai", 1);
          me->delete_temp("xuantie/light");
          return  "����������̦�ͻҳ�����̦�����ƺ�����һЩС�֡�\n";
}

string zi(object me)
{ 
      if(!me->query_temp("xuantie/qingtai"))
         return "��Ҫ��ʲô��\n";
      if(!me->query_temp("xuantie/mo"))
         return "����������̦�ͻҳ������޷�������ЩС�֡�\n";
         me->delete_temp("xuantie");
         me->set_temp("xuantie/zi", 1);
         return HIY"\n\t�ݺὭ����ʮ���أ�ɱ����ܣ��ܾ�Ӣ�ۣ����¸��޿��֡�\n"+
                "\t�޿��ͺΣ�Ω������ȣ��Ե�Ϊ�ѡ�\n"+
                "\t�غ�����ƽ��һ���ֶ����ɵã��ϼ����ѿ�Ҳ��\n\n"+ 
                "\t\t\t\t\t\t��ħ�������\n"NOR;
}

string mu(object me)
{
     if( !me->query_temp("xuantie/zi"))
        return  "���վ�������������˭�ķ�Ĺ��\n";
     else {
        me->set_temp("xuantie/mu", 1);
        me->delete_temp("xuantie/zi");
        return "�Ǹ�ʯ�ѵķ�Ĺ��Ҳ��������ǣ�������λ����������ᣬ�������ʯ������ʬ��֮�ϡ�\n";
        }
}

void init()
{ 
      add_action("do_zuan","zuan");
      add_action("do_use", "dian");
      add_action("do_mo", ({"mo", "clean"}));
      add_action("do_kneel",({"kneel", "guibai"}));
}

int do_use(string arg)
{
      object me=this_player(), ob;
      if(me->is_busy() || me->is_fighting())
         return notify_fail("����æ���ģ�\n");
      if(!(ob=present("xiao shuzhi", me)) )
         return notify_fail("��û������֮�\n");
      if(! present("fire", me ))
         return notify_fail("����ʲô���\n");
      if( arg == "shuzhi"){
      message_vision(HIR"$N��ȼ��С��֦����Χ��������������\n"NOR, me);
      me->set_temp("xuantie/light", 1);
      me->start_busy(1);
      destruct(ob);
      return 1;
      }
      return notify_fail("��Ҫ��ȼʲô��\n");
}

int do_mo(string arg)
{
      object me=this_player();
      if(me->is_busy() || me->is_fighting())
         return notify_fail("����æ���ģ�\n");
      if( !arg || arg !="qingtai") return 0;
      if(!me->query_temp("xuantie/qingtai"))
         return notify_fail("����������̦��Ĩ�˼��£���С��Ū�����֡�\n");
       tell_room(environment(me), me->name() + "��������������Ĩȥ�����ϵ���̦��\n"NOR, ({ me }));
       me->set_temp("xuantie/mo", 1);
       me->start_busy(1);
       write("��Ĩȥ��̦���ֳ������������ּ��ʻ���ϸ����ʯȴ�Ǽ�������ü������ı��л��ɡ�\n");
       return 1;
}

int do_kneel(string arg)
{
      object me = this_player();      
      if(me->is_busy() || me->is_fighting())
         return notify_fail("����æ���ģ�\n");
      if((!arg) || (arg != "mu")) return 0;
      if(!(int)me->query_temp("xuantie/mu"))
         return notify_fail("��Ҫ����¹��\n");
       tell_room(environment(me), me->name() + "��ʯĹ֮ǰ��ݣ������İݡ�\n"NOR, ({ me }));
       write("�����һ���񣬲��Խ�����ʯĹ֮ǰ��ݣ������İݡ�\n");
       write(HIW"\n���֮�ʺ�Ȼ����ɽ�������ƺ��и����ڣ�͸����һ˿������\n"NOR);
       me->delete_temp("xuantie");
       me->set_temp("xuantie/mu1", 1);
       me->start_busy(1);
       return 1;
}

int do_zuan(string arg)
{
       object me=this_player(),*ob;
       int i;
       if (!me->query_temp("xuantie/mu1")) return 0;
       if (me->is_busy() || me->is_fighting())
         return notify_fail("����æ���ģ�\n");
       if ( !arg || arg != "dong")
         return notify_fail("���������갡��\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
          return notify_fail("���ڲ���������ֻ������һ��ʵ������ͨ����\n");
       tell_room(environment(me), me->name() + "�������"YEL"���"NOR"���˳�ȥ��\n"NOR, ({ me }));
       me->move(__DIR__"shanlu7");
       me->delete_temp("xuantie");
       me->start_busy(1);
       write(HIW"\n��һ������С���������ᣬֻ����ľ�Դ䣬ɽ����ѡ�\n"NOR);
       tell_room(environment(me), me->name() + "��"HIB"��ɽ��"NOR"�����˳�����\n"NOR, ({ me }));
       return 1;
}
