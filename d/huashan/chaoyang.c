// Room: /d/huashan/chaoyang.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
int do_kan(string arg);
void create()
{
       set("short", "������");
       set("long", @LONG
������ǻ�ɽ�Ķ��塪�����壬춴˸���ƺ����Զ������������С��
�屳��ɽ�ӡ����������ϣ�����һ��������ӡ���ഫΪ��������项��ɽʱ��
���µġ�������һƬ���֣���ľ���������˲������롣
LONG
        );
       set("exits", ([ 
                  "westdown" : __DIR__"zhenyue",
        ]));

        set("objects", ([ 
                __DIR__"npc/daoke" : 1,
        ]));
 
       set("outdoors", "��ɽ" );

  
     set("coor/x",80);
  set("coor/y",40);
   set("coor/z",60);
   setup();
}

void init()
{
        object me = this_player();
        object weapon = me->query_temp("weapon");
        if (me->query("family/family_name") == "��ɽ��" 
        &&  me->query_int() >= 32 
        &&  !me->query("hs/getchongling")
       &&  weapon 
        &&  weapon->query("skill_type") == "sword"
       &&  me->query_skill_mapped("sword") == "huashan-jianfa"
        &&  me->query("kar") <= 20 
        &&  me->query_skill("sword") > 70
        &&  me->query_skill("huashan-jianfa") > 70
        &&  me->query("neili") > 1000
        &&  me->query_skill("zixia-gong") > 70 
        &&  random(10) <= 7 ) {
        tell_object(me, YEL"��վ�ڳ����嶥�����¸�����ɽ�����ķ羰��ͻȻ����һ�����������轣��\n"NOR);
        me->set("hs/getchongling", 1);
       me->start_busy(random(15));
        call_out("do_wujian", 4, me);
        }
//      add_action("do_toukui","bihua");
        add_action("do_kan","kan");
} 

void do_wujian(object me)
{
//      object weapon = me->query("weapon");
//      object name = weapon->query("name");
        if (me && present(me, this_object())) tell_object(me, YEL"�����סҲ���űȻ�������\n"NOR);
}

int do_kan(string arg)
{
        object me,ob;
        int i,j;
        
        me = this_player();
        ob = me->query_temp("weapon");

        if ( !arg || arg != "��" )
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy())
                return notify_fail("��������æ����!\n");
        if( !ob || ob->query("id") != "chai dao")
                return notify_fail("��Ҫ��ʲô��������ô��\n");
        if ( !me->query_temp("hs/kc_job"))
                return notify_fail("�����ĵػ���񵶣����ҿ�����Щ��ľ��\n");
        if ( me->query("jing")< 100) return notify_fail ("������̫���ˡ�\n");
         if ( me->query_temp("kc_job/ok")) return notify_fail ("��ȥ֪ͨ������ȡ��̰ɡ�\n");

        i = random((int)me->query("con")/3);
        j = random((int)me->query("str")/3);
        if((int)me->query("jingli") < i
         ||(int)me->query("qi") < j){
                message_vision(HIR"$Nһ��С�ģ��������Լ����ϡ�\n"NOR,me);
                me->unconcious();
                return 1;
        }        
        
        me->receive_damage("jingli", i);
        me->add("qi", -j);       
        
        if(((int)me->query_temp("kc_job/kan") > 15 + random(5))){
                me->set_temp("kc_job/ok",1);
                tell_object(me, "��ѵ��ϵĲ������һ���������û�ȥ�ˡ�\n");
                return 1;
        }
        message_vision("$N����񵶣�����һƬ��ľ���������һ�ԡ�\n",me);
        me->start_busy(1);
        me->add_temp("kc_job/kan",1);
        
        if((int)me->query_skill("blade", 1) < 31
         && random(10) > 6 ){
          write(HIM"�ڿ���Ĺ����У�����ڵ��Ļ����÷���������Щ��ᡣ\n"NOR);
          me->improve_skill("blade", (int)(me->query("int") / 10));
        }
        return 1;
}
