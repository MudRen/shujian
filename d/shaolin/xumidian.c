#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN"���ֵ�"NOR);
        set("long", @LONG
һ����ķ���ıڿյ����ģ�������һ����ʯ���磬����һ������
���Ƶ��շ壬�������ƣ����������һö���ӡ�����ȡ������ֽ���֮��
�ʣ�����Ϊ�ɽ�����֮���������֮�С�����ǰ���ż������ţ���λɮ
�����Զ������練�����ӣ������ڹ���
LONG
 );
        set("exits", ([
            "east" :__DIR__ "dabeidia",
        ]));

        set("objects",([
		__DIR__"obj/muchui" : 1,
	]));
 
        setup();

}

void init()
{
	add_action("do_neishi", "neishi");
}

int do_neishi()
{
        object me;

        me = this_player();
        message_vision("$N��ϥ���±�Ŀ�������ص��������ڹ���\n", me);
        if ((int)me->query("jing")<20)
     {
	write(RED"��̫���ˣ������޷����С�\n"NOR);
       return 1;
      } 
      
    if ((int)me->query_skill("force", 1) >= 30 
    && (int)me->query_skill("force", 1) <= 100 
    && present("xisui jing", me) )
        {
           me->receive_damage("jing", 20);
           me->improve_skill("force", me->query("int"));
         //  if ( random(5) == 0 )
           tell_object(me, RED"�����Ӿ���һ����Ϣ�����ǣ��м�����Ԫ��ʯ��ֱͨ���ϡ�
����һ��С�������������������С�\n"NOR);
       }
    else
       tell_object(me,RED"��Խ��Խ��Ϳ����Ϣ�Ҵܣ�ֻ��վ��������\n"NOR);
       return 1;
}
