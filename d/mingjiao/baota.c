// Room: /u/qingyun/mingjiao/baota.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"��������"NOR);
	set("long", @LONG
���������̹������ϵ�һ�������������еı�������ÿ���д�š�������
�������֡��������������Ƴ�ʱ�ʵ�Ϊ���������Ĺ����±�����������Ϊ����
�������̶�ʢʱ�ڶ�����������㣬ÿ�������ש���ɣ���Ȼ��ʱ�����Զ��
����Ȼ����ޱȡ��������ϾͿ����ݹ۹������ϵĽ���Ⱥ�ˡ�
LONG);
	set("exits", ([ 
            "southdown" : __DIR__"sht",
            "enter" : __DIR__"baota0",
        ]));
        set("outdoors","���̹�����");
	set("coor/x",-290);
  set("coor/y",240);
   set("coor/z",140);
   set("coor/x",-290);
 set("coor/y",240);
   set("coor/z",140);
   setup();
}
