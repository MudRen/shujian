// By River@SJ 2001/9  

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"�����"NOR);
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·���������������������,����һƬ�ݴԡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([ 
                "south" : __DIR__"nroad1",
                "northwest" : __DIR__"nroad3",
        ]));

set("�Ͳ�С��", 1);

        setup();
}

void init()
{
 add_action("do_search", "search");
 
}

int do_search(string arg)
{
object me = this_player();
object ob;
mapping fam;
fam = me->query("family");

if ( me->is_busy() || me->is_fighting())
  return notify_fail("����æ���ģ�\n");
if( !arg || arg != "�ݴ�" ) return 0;
if( arg == "�ݴ�" ){
 if (!fam || fam["family_name"] != "������") 
                return notify_fail("�㲦�˲��ݴԣ���û��ʲô���֣�������Щ��Ȼ��\n");
if (me->query("quest/bingcan/fail") > 3 && me->query("registered") < 3 ) 
return notify_fail("�㲦�˲��ݴԣ���û��ʲô�ر��֣�������Щ��Ȼ��\n");
if ( present("youbu xiaobao", this_player()))
return notify_fail("�㲦�˲��ݴԣ���û�б��ʲô���֣�������Щ��Ȼ��\n");
if (query("�Ͳ�С��") <1  ) 
return notify_fail(HIR"�������ˣ��Ͳ�С���Ѿ�����ȡ���ˡ�\n"NOR);
ob = unew("clone/misc/xiaobao");
this_object()->add("�Ͳ�С��",-1);


            message_vision(HIC"$N���˲���Χ�Ĳݴԣ��������ײݴ����и��Ͳ�С��,����ʰ��\n"NOR, me);
ob->set_temp("owner",me->query("id"));
     ob->move(me);

       
              return 1; 
        }
}


