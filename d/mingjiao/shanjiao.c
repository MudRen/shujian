// shanjiao.c ɽ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <wanted.h>
inherit ROOM;
void create()
{
    set("short", GRN"ɽ����"NOR);
    set("long",@LONG
����������ɽ���£����Զ���Ϳ��Կ��������޾�������ɽ����������ɽ��
���ܼ�����ɽ�������ѩ������֮����ãã��һ��Ƭ����˵�������ǣ�������
����Ҳ�������Է�Խ��������������ʮ���£������������У�����ƾ�������ӣ�
���ֱܷ��������ʥ�����ڣ����ߺ�����һ��С·��ͨ����ɽ֮·��������ͨ
�����ص�ɽ·��
LONG);
    set("exits",([
        "eastup" : __DIR__"sshanlu1",
        "westup" : "/d/kunlun/zhenyuanqiao",
        "south" : __DIR__"shejing",
    ]));
    set("objects",([
         __DIR__"npc/f-dizi" :   1,
         __DIR__"npc/m-dizi" :   1,
    ]));
    set("outdoors", "���̹�����");
    set("coor/x",-340);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-340);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "eastup" && is_wanted(me))
		return 0;
    if ( me->query("id") == "yin li" &&  dir != "westup" ) return 0;
    return ::valid_leave(me, dir);
}
