//sshanlu1.c ɽ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", GRN"ɽ·"NOR);
    set("long",@LONG
����һ��һխ�ֶ���ɽ·��ɽ·���Գ����ָ����ӵ��Ҳ���������û��ͷ��
ż�����м�֦������ס���ȥ·��һ��С����ᱻ����ˡ�
LONG);
    set("exits",([
        "westdown" : __DIR__"shanjiao",
        "southup" : __DIR__"sshanlu2",
    ]));	
    set("outdoors", "���̹�����");
    set("coor/x",-330);
  set("coor/y",100);
   set("coor/z",10);
   set("coor/x",-330);
 set("coor/y",100);
   set("coor/z",10);
   setup();
}
