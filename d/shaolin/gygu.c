#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short","��Ԫ��");
       set("long", @LONG
�߳�ʯ�ң�ֻ����һ���֮�ڡ�ǰ��һ���߷���·���εض���,
ֱ����롣���ܷ��Ͷ���������Ҿ�������ڲ���ʮĶ��Բ���棬��
����ʯ�����겻ͬ����Ƥ���ף�����֦�������ٷ��ȥ��
LONG
     );
	set("exits", ([
                "southeast" : __DIR__"xclang",
              //"west"  : __DIR__"nxaju",
            //  "north" : __DIR__"dmtang",
            //  "northwest" : __DIR__"gygu",	
       ]));
        set("coor/x",40);
  set("coor/y",430);
   set("coor/z",130);
   setup();
}
  void init()
            {
              add_action("do_chop","kan");
             }
   int do_chop(string arg)
    {
       object me,weapon;
       me=this_player();
       weapon=me->query_temp("weapon");
       if (!arg) return 0;
       if (arg!="tree") return 0;
       if (!(me->query("pass_xin"))) return 0;
       if (!weapon || weapon->query("id")!="chai dao")
        return notify_fail("��Ҫ�ò�������\n");
    if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");
       if ((int)me->query("jingli",1)<50)
          return notify_fail("��ľ���������\n");
       if ((int)me->query("neili",1)<100)
          return notify_fail("�������������\n"); 
if( me->query_skill("weituo-chu",1)>0 || me->query_skill("riyue-bian",1)>0)
return notify_fail("�������д�Ħ�������Ϊ������ͬʱ��ϰ������������\n");
      message_vision(RED"$Nʹ���񵶶�׼�±߹��ɣ�һ������ȥ��\n"
                         "��ľ���ͣ���������֮�£������Ľ�������\n"
                         "�ٰ�ȼ��֮����\n" NOR,me);
 me->receive_damage("jingli",30);
  me->receive_damage("neili",30);          
           me->improve_skill("ranmu-daofa", ((int)me->query_skill("blade",1))/4);
           me->improve_skill("blade",1);
           return 1;
      }
