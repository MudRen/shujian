//sshanlu2.c ɽ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", YEL"ɽ·"NOR);
	set("long",@LONG
����һ��һխ�ֶ���ɽ·��ɽ·���Գ����ָ����ӵ��Ҳ���������û��ͷ��
ż�����м�֦������ס���ȥ·��һ��С����ᱻ����ˡ�
LONG);
	set("exits",([
        	"northdown" : __DIR__"sshanlu1",
        	"westup"  : __DIR__"sshanlu3",
    	]));
        set("objects",([
               __DIR__"npc/you" : 2,
        ]));
        set("outdoors", "���̹�����");
    	set("coor/x",-330);
  set("coor/y",90);
   set("coor/z",20);
   set("coor/x",-330);
 set("coor/y",90);
   set("coor/z",20);
   setup();
}
