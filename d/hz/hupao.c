// /u/beyond/hz/hupao.c ����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",MAG"����"NOR);
        set("long", @LONG
�����������ϵĴ��ɽ´�͵��˻��ܡ�������ɽ���㣬Ϫ�����ȣ���ľ
��ï���������š�Ȫ�Ժ�ɽ��ʯӢ��������������һС�����У���䣴���
�������µ���Ȫ֮�ơ��ഫ��ʱ�Կպ����������ˣ��������㣬���ڴ˽�
�£���������ˮ����Ҫȥʱ������������桰��������ͯ��Ȫ����Ǵ������
�������ڶ����Ȼ�������ܵ���Ѩ��ӿ����Ȫ�������ɴ˵������û���Ȫ��
�����裬������Ƣ����Ϊ����˫����
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
]));
        set("exits", ([
            "northeast" : __DIR__"yuhuang",
"north" : __DIR__"hubian2",
"northwest" : __DIR__"longjing",
]));
        set("coor/x",90);
  set("coor/y",-360);
   set("coor/z",0);
   setup();
}
